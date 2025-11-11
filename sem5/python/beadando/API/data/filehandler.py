import json
from typing import Dict, Any

from data.fileconsts import USER_JSON_FILE_PATH, DATA_JSON_FILE_PATH, USERS, BASKETS
from data.filereader import get_basket_by_user_id, load_json, load_users_json

def save_json(data: Dict[str, Any]) -> None:
    with open(DATA_JSON_FILE_PATH, "w", encoding="utf-8") as file:
        json.dump(data, file, indent=4, ensure_ascii=False)

def save_users_json(data: Dict[str, Any]) -> None:
    with open(USER_JSON_FILE_PATH, "w", encoding="utf-8") as file:
        json.dump(data, file, indent=4, ensure_ascii=False)

def add_user(user: Dict[str, Any]) -> None:
    data = load_json()
    users = load_users_json()
    data[USERS].append(user)
    users[USERS].append(user)
    save_json(data)
    save_users_json(users)
    
def add_basket(basket: Dict[str, Any]) -> None:
    data = load_json()
    data[BASKETS].append(basket)
    save_json(data)

def add_item_to_basket(user_id: int, item: Dict[str, Any]) -> None:
    try:
        basket = get_basket_by_user_id(user_id)
        basket["items"].append(item)
        data = load_json()
        data[BASKETS][basket["id"]] = basket
        save_json(data)
    except KeyError:
        raise ValueError(f"Cannot add an item to a nonexistent basket by user_id: {user_id}")
