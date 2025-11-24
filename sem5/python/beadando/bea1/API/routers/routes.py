from fastapi.responses import JSONResponse, RedirectResponse
from fastapi import FastAPI, HTTPException, Request, Response, Cookie
from fastapi import APIRouter

from schemas.schema import User, Basket, Item
from data.filereader import get_all_baskets, get_all_users, get_basket_by_user_id, get_user_by_id, load_token, get_total_price_of_basket, load_users_json
from data.filehandler import add_basket, add_user, add_item_to_basket, clear_basket, delete_item, delete_user, update_item
from data.fileconsts import USERS

routers = APIRouter()

@routers.get("/setauthcookie")
def setauthcookie(res: Response, auth_cookie: str | None = Cookie(default=None)) -> JSONResponse:
    """Sets the auth cookie if not already set."""
    if auth_cookie is not None:
        return JSONResponse(content={"message": "Auth cookie has already been set."})
    
    res = JSONResponse(content={"message": "Auth cookie set."})
    res.set_cookie(key="auth_cookie", value=load_token())
    return res

@routers.post('/adduser', response_model=User)
def adduser(user: User, auth_cookie: str | None = Cookie(default=None)) -> User:
    """Adds a new user. Auth cookie required."""
    auth_token = load_token()
    if auth_cookie is None or auth_cookie != auth_token:
        raise HTTPException(status_code=401, detail="Invalid or expired authorization token")
    
    add_user(user)

    return user

@routers.post('/addshoppingbag')
def addshoppingbag(userid: int, auth_cookie: str | None = Cookie(default=None)) -> str:
    """Creates a basket for the user. Fails if already exists."""
    auth_token = load_token()
    if auth_cookie is None or auth_cookie != auth_token:
        raise HTTPException(status_code=401, detail="Invalid or expired authorization token")

    try:
        user = get_user_by_id(userid)
    except KeyError:
        raise HTTPException(status_code=404, detail=f"User by id {userid} does not exist.")

    try:
        get_basket_by_user_id(userid)
        raise HTTPException(status_code=400, detail=f"A basket already exists for user {user.name}")
    except KeyError:
        basket = Basket(id=userid, user_id=userid, items=[])
        add_basket(basket)

    return "Sikeres kosár hozzárendelés."

@routers.post('/additem', response_model=Basket)
def additem(userid: int, item: Item) -> Basket:
    """Adds an item to the user's basket."""
    try:
        add_item_to_basket(userid, item)
    except KeyError as e:
        raise HTTPException(status_code=404, detail=str(e))

    return get_basket_by_user_id(userid)

@routers.put('/updateitem', response_model=Basket)
def updateitem(userid: int, itemid: int, updateItem: Item) -> Basket:
    """Updates an item in the user's basket."""
    try:
        basket = get_basket_by_user_id(userid)
        update_item(basket, itemid, updateItem)
    except KeyError as e:
        raise HTTPException(status_code=404, detail=str(e))
    
    updated_basket = get_basket_by_user_id(userid)
    return updated_basket

@routers.delete('/deleteitem', response_model=Basket)
def deleteitem(userid: int, itemid: int) -> Basket:
    """Deletes an item from the user's basket."""
    try:
        basket = get_basket_by_user_id(userid)
        delete_item(basket, itemid)
    except KeyError as e:
        raise HTTPException(status_code=404, detail=str(e))

    updated_basket = get_basket_by_user_id(userid)
    return updated_basket

@routers.delete("/deleteall", response_model=str)
def deleteall(userid: int, auth_cookie: str | None = Cookie(default=None)) -> str:
    """Deletes all items from the basket. Auth required."""
    auth_token = load_token()
    if auth_cookie is None or auth_cookie != auth_token:
        raise HTTPException(status_code=401, detail="Invalid or expired authorization token")

    try:
        basket = get_basket_by_user_id(userid)
        clear_basket(basket)
    except KeyError as e:
        raise HTTPException(status_code=404, detail=str(e))

    return "Successful deletion of all items."

@routers.get('/user', response_model=User)
def user(userid: int, auth_cookie: str | None = Cookie(default=None)) -> User:
    """Returns a user by ID. Auth required."""
    auth_token = load_token()
    if auth_cookie is None or auth_cookie != auth_token:
        raise HTTPException(status_code=401, detail="Invalid or expired authorization token")

    try:
        user = get_user_by_id(userid)
    except KeyError as e:
        raise HTTPException(status_code=404, detail=str(e))

    return user

@routers.get('/users', response_model=list[User])
def users(auth_cookie: str | None = Cookie(default=None)) -> list[User]:
    """Returns all users. Auth required."""
    auth_token = load_token()
    if auth_cookie is None or auth_cookie != auth_token:
        raise HTTPException(status_code=401, detail="Invalid or expired authorization token")
    
    return get_all_users()

@routers.get('/shoppingbag', response_model=list[Item])
def shoppingbag(userid: int) -> list[Item]:
    """Returns all items in the user's basket."""
    try:
        basket = get_basket_by_user_id(userid)
    except KeyError as e:
        raise HTTPException(status_code=404, detail=str(e))

    return basket.items

@routers.get('/getusertotal', response_model=float)
def getusertotal(userid: int) -> float:
    """Returns the total price of the user's basket."""
    try:
        total = get_total_price_of_basket(userid)
    except KeyError as e:
        raise HTTPException(status_code=404, detail=str(e))

    return total

@routers.delete("/deleteuser", response_model=str)
def deleteuser(userid: int, auth_cookie: str | None = Cookie(default=None)) -> str:
    """Deletes the user if their basket is empty. Auth required."""
    auth_token = load_token()
    if auth_cookie is None or auth_cookie != auth_token:
        raise HTTPException(status_code=401, detail="Invalid or expired authorization token")
    
    try:
        basket = get_basket_by_user_id(userid)
        if basket.items:
            raise HTTPException(status_code=400, detail="Basket for user is not empty.")
    except KeyError as e:
        raise HTTPException(status_code=404, detail=str(e))

    delete_user(userid)

    return "Successful deletion of user."
