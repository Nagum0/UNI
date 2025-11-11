from fastapi.responses import JSONResponse, RedirectResponse
from fastapi import FastAPI, HTTPException, Request, Response, Cookie
from fastapi import APIRouter

from schemas.schema import User, Basket, Item
from data.filereader import load_token
from data.filehandler import add_user

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

@routers.post('/adduser', response_model=User)
def adduser(user: User, request: Request) -> User:
    header_token = request.headers.get("token")
    auth_token = load_token()

    if header_token != auth_token:
        raise HTTPException(status_code=401, detail="Invalid or expired authorization token")
    
    add_user(user.model_dump())

    return user

@routers.post('/addshoppingbag')
def addshoppingbag(userid: int) -> str:
    pass

@routers.post('/additem', response_model=Basket)
def additem(userid: int, item: Item) -> Basket:
    pass

@routers.put('/updateitem')
def updateitem(userid: int, itemid: int, updateItem: Item) -> Basket:
    pass

@routers.delete('/deleteitem')
def deleteitem(userid: int, itemid: int) -> Basket:
    pass

@routers.get('/user')
def user(userid: int) -> User:
    pass

@routers.get('/users')
def users() -> list[User]:
    pass

@routers.get('/shoppingbag')
def shoppingbag(userid: int) -> list[Item]:
    pass

@routers.get('/getusertotal')
def getusertotal(userid: int) -> float:
    pass



