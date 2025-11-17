import json
from fastapi.responses import JSONResponse, RedirectResponse
from fastapi import FastAPI, HTTPException, Request, Response, Cookie
from fastapi import APIRouter

from schemas.schema import User, Basket, Item
from data.filereader import get_basket_by_user_id, get_user_by_id, load_token, get_total_price_of_basket
from data.filehandler import add_basket, add_user, add_item_to_basket, delete_item, update_item

'''

Útmutató a fájl használatához:

- Minden route esetén adjuk meg a response_modell értékét (típus)
- Ügyeljünk a típusok megadására
- A függvények visszatérési értéke JSONResponse() legyen
- Minden függvény tartalmazzon hibakezelést, hiba esetén dobjon egy HTTPException-t
- Az adatokat a data.json fájlba kell menteni.
- A HTTP válaszok minden esetben tartalmazzák a 
  megfelelő Státus Code-ot, pl 404 - Not found, vagy 200 - OK

'''

routers = APIRouter()

@routers.get("/setauthcookie")
def setauthcookie(res: Response, auth_cookie: str | None = Cookie(default=None)) -> JSONResponse:
    if auth_cookie is not None:
        return JSONResponse(content={"message": "Auth cookie has already been set."})
    
    res = JSONResponse(content={"message": "Auth cookie set."})
    res.set_cookie(key="auth_cookie", value=load_token())
    return res

@routers.post('/adduser', response_model=User)
def adduser(user: User, auth_cookie: str | None = Cookie(default=None)) -> User:
    auth_token = load_token()
    if auth_cookie is None or auth_cookie != auth_token:
        raise HTTPException(status_code=401, detail="Invalid or expired authorization token")
    
    add_user(user.model_dump())

    return user

@routers.post('/addshoppingbag')
def addshoppingbag(userid: int, auth_cookie: str | None = Cookie(default=None)) -> str:
    auth_token = load_token()
    if auth_cookie is None or auth_cookie != auth_token:
        raise HTTPException(status_code=401, detail="Invalid or expired authorization token")

    try:
        user = get_user_by_id(userid)
        user = User.model_validate(user)
    except KeyError:
        raise HTTPException(status_code=404, detail=f"User by id {userid} does not exist.")

    try:
        get_basket_by_user_id(userid)
        raise HTTPException(status_code=400, detail=f"A basket already exists for user {user.name}")
    except KeyError:
        # TODO: Implement a proper id creator function
        basket = Basket(id=0, user_id=userid, items=[])
        add_basket(basket.model_dump())

    return "Sikeres kosár hozzárendelés."

@routers.post('/additem', response_model=Basket)
def additem(userid: int, item: Item) -> Basket:
    add_item_to_basket(userid, item.model_dump())

    try:
        basket = Basket.model_validate(get_basket_by_user_id(userid))
    except KeyError:
        raise HTTPException(status_code=404, detail=f"No basket found for user {userid}.")

    return basket

@routers.put('/updateitem', response_model=Basket)
def updateitem(userid: int, itemid: int, updateItem: Item) -> Basket:
    try:
        basket = get_basket_by_user_id(userid)
        update_item(basket, itemid, updateItem.model_dump())
    except KeyError as e:
        raise HTTPException(status_code=404, detail=str(e))
    
    updated_basket = Basket.model_validate(get_basket_by_user_id(userid))
    return updated_basket

@routers.delete('/deleteitem', response_model=Basket)
def deleteitem(userid: int, itemid: int) -> Basket:
    try:
        basket = get_basket_by_user_id(userid)
        delete_item(basket, itemid)
    except KeyError as e:
        raise HTTPException(status_code=404, detail=str(e))

    updated_basket = Basket.model_validate(get_basket_by_user_id(userid))
    return updated_basket

@routers.delete("/deleteall", response_model=Basket)
def deleteall(userid: int) -> Basket:
    pass

@routers.get('/user')
def user(userid: int) -> User:
    pass

@routers.get('/users')
def users() -> list[User]:
    pass

@routers.get('/shoppingbag')
def shoppingbag(userid: int) -> list[Item]:
    try:
        basket = Basket.model_validate(get_basket_by_user_id(userid))
    except KeyError as e:
        raise HTTPException(status_code=404, detail=str(e))

    return basket.items

@routers.get('/getusertotal')
def getusertotal(userid: int) -> float:
    try:
        total = get_total_price_of_basket(userid)
    except KeyError as e:
        raise HTTPException(status_code=404, detail=str(e))

    return total
