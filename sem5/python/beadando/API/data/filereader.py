import json
from typing import Dict, Any, List

from data.fileconsts import USER_JSON_FILE_PATH, DATA_JSON_FILE_PATH, USERS, BASKETS, AUTH_TOKEN_PATH
from schemas.schema import User, Basket

def load_token() -> str:
    with open(AUTH_TOKEN_PATH, "r") as file:
        return file.read()

def load_json() -> Dict[str, Any]:
    with open(DATA_JSON_FILE_PATH, "r", encoding="utf-8") as file:
        return json.load(file)

def load_users_json() -> Dict[str, Any]:
    with open(USER_JSON_FILE_PATH, "r", encoding="utf-8") as file:
        return json.load(file)

def get_user_by_id(user_id: int) -> User:
    users = load_users_json()

    for user in users[USERS]:
        if user_id == user["id"]:
            return User.model_validate(user)

    raise KeyError(f"User by id: {user_id} not found")

def get_basket_by_user_id(user_id: int) -> Basket:
    basket_data = load_json()

    for basket in basket_data[BASKETS]:
        if basket["user_id"] == user_id:
            return Basket.model_validate(basket)

    raise KeyError(f"Basket by user_id: {user_id} not found")

def get_all_users() -> List[User]:
    users = load_users_json()
    return [User.model_validate(user) for user in users[USERS]]

def get_all_baskets() -> List[Basket]:
    data = load_json()
    return [Basket.model_validate(basket) for basket in data[BASKETS]]

def get_total_price_of_basket(user_id: int) -> float:
    try:
        basket = get_basket_by_user_id(user_id)
        return sum([item.price * item.quantity for item in basket.items])
    except KeyError:
        raise KeyError(f"Cannot get total price of nonexistent basket by user_id: {user_id}")
