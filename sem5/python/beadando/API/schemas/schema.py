from typing import List
from pydantic import BaseModel, field_validator
import re

'''

Útmutató a fájl használatához:

Az osztályokat a schema alapján ki kell dolgozni.

A schema.py az adatok küldésére és fogadására készített osztályokat tartalmazza.
Az osztályokban az adatok legyenek validálva.
 - az int adatok nem lehetnek negatívak.
 - az email mező csak e-mail formátumot fogadhat el.
 - Hiba esetén ValuErrort kell dobni, lehetőség szerint ezt a 
   kliens oldalon is jelezni kell.

'''

ShopName='Bolt'

class User(BaseModel):
    id: int
    name: str
    email: str

    @field_validator("id")
    def check_id(cls, id) -> int:
        if id < 0:
            raise ValueError("id cannot be negative")

        return id

    @field_validator("email")
    def check_email(cls, email) -> str:
        regex = r"[a-zA-Z0-9_.+-]+@[a-zA-Z0-9_.+-]+\.[a-zA-Z]+"
        if not re.match(regex, email):
            raise ValueError("email format incorrect")
        
        return email

class Item(BaseModel):
    item_id: int
    name: str
    brand: str
    price: float
    quantity: int

    @field_validator("item_id")
    def check_item_id(cld, item_id):
        if item_id < 0:
            raise ValueError("item_id cannot be negative")

        return item_id

    @field_validator("price")
    def check_price(cls, price):
        if price < 0:
            raise ValueError("price cannot be negative")

        return price

    @field_validator("quantity")
    def check_quantity(cls, quantity):
        if quantity < 0:
            raise ValueError("quantity cannot be negative")

        return quantity

class Basket(BaseModel):
    id: int
    user_id: int
    items: List[Item]

    @field_validator("id")
    def check_id(cls, id):
        if id < 0:
            raise ValueError("id cannot be negative")

        return id

    @field_validator("user_id")
    def check_user_id(cls, user_id):
        if user_id < 0:
            raise ValueError("user_id cannot be negative")

        return user_id
