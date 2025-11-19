import json
from typing import Dict, Any

from data.fileconsts import USER_JSON_FILE_PATH, DATA_JSON_FILE_PATH, USERS, BASKETS
from data.filereader import get_basket_by_user_id, load_json, load_users_json
from schemas.schema import Basket, Item, User

def save_json(data: Dict[str, Any]) -> None:
    with open(DATA_JSON_FILE_PATH, "w", encoding="utf-8") as file:
        json.dump(data, file, indent=4, ensure_ascii=False)

def save_users_json(data: Dict[str, Any]) -> None:
    with open(USER_JSON_FILE_PATH, "w", encoding="utf-8") as file:
        json.dump(data, file, indent=4, ensure_ascii=False)

def add_user(user: User) -> None:
    data = load_json()
    users = load_users_json()
    data[USERS].append(user.model_dump())
    users[USERS].append(user.model_dump())
    save_json(data)
    save_users_json(users)
    
def add_basket(basket: Basket) -> None:
    data = load_json()
    data[BASKETS].append(basket.model_dump())
    save_json(data)

def update_item(basket: Basket, item_id: int, new_item: Item) -> None:
    found = False
    for idx, item in enumerate(basket.items):
        if item.item_id == item_id:
            basket.items[idx] = new_item
            found = True

    if not found:
        raise KeyError(f"Item by id: {item_id} does not exist in the basket.")
    
    _save_basket(basket)

def delete_item(basket: Basket, item_id: int) -> None:
    old_len = len(basket.items)
    for item in basket.items[:]:
        if item.item_id == item_id:
            basket.items.remove(item)
    
    if len(basket.items) == old_len:
        raise KeyError(f"Item by id: {item_id} does not exist in the basket")
    
    _save_basket(basket)

def delete_user(user_id: int) -> None:
    data = load_json()
    users = load_users_json()
    user_found = False

    for user in users[USERS][:]:
        if user["id"] == user_id:
            users[USERS].remove(user)
            user_found = True

    for user in data[USERS][:]:
        if user["id"] == user_id:
            data[USERS].remove(user)

    if not user_found:
        raise KeyError(f"User by id: {user_id} not found.")

    save_json(data)
    save_users_json(users)

def clear_basket(basket: Basket) -> None:
    basket.items = []
    _save_basket(basket)

def add_item_to_basket(user_id: int, item: Item) -> None:
    try:
        basket = get_basket_by_user_id(user_id)
        basket.items.append(item)
        _save_basket(basket)
    except KeyError:
        raise KeyError(f"Cannot add an item to a nonexistent basket by user_id: {user_id}")

def _save_basket(basket: Basket) -> None:
    data = load_json()
    for idx, b in enumerate(data[BASKETS]):
        if b["id"] == basket.id:
            data[BASKETS][idx] = basket.model_dump()
            break
    save_json(data)
