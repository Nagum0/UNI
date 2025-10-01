line = "Shoe shoe shoe Shoe shoe shoe"
len([1 for i in line.split(" ") if i.lower() == "shoe"])

# -- 3.

def remove_dups(lst: list[int]) -> list[int]:
    d = {}

    for i in lst[:]:
        d[i] = d[i] + 1 if i in d.keys() else 1
        
        if d[i] >= 2:
            lst.remove(i)

    return lst

# -- 4.

def caesar_encode(word: str, shift_num: int, shift_direction: str) -> str:
    if shift_num <= 0 or shift_num > 26:
        shift_num %= 26 

    shift_dir_multiplier = 1
    if shift_direction.lower() == "left":
        shift_dir_multiplier = -1
    elif shift_direction.lower() == "right":
        pass
    else:
        print("Hibás irány! Használd a left vagy right szót!")
        return

    encoded = ""

    for letter in word:
        if not letter.isalpha(): 
            continue 

        letter = letter.upper() 
        code = ord(letter) + shift_num * shift_dir_multiplier 

        if code > ord("Z"):
            code -= 26
        elif code < ord("A"):
            code += 26
        
        encoded += chr(code)

    return encoded

# -- 5.

files = ["py.py", "py.py.txt", "hello.docx", "music.json", "names.txt", "doctor_x.xlsx", "voorhees.json"]
file_dict = {}
for file in files:
    file_parts = file.split(".")
    file_extension = file_parts[len(file_parts) - 1]
    file_dict[file_extension] = [file] if file_extension not in file_dict.keys() else file_dict[file_extension] + [file]

for ext, files in file_dict.items():
    print(f"{ext}: {files} ({len(files)})")

# -- 6.
from math import radians

def to_rad(deg: int) -> float:
    return radians(deg)

# -- 7.

def to_rads(deg: int):
    inner_deg: int = deg

    def inner_rag() -> float:
        nonlocal inner_deg
        inner_deg += deg
        print(inner_deg)
        return radians(inner_deg)
    
    return inner_rag

# deg = to_rads(360)
# print(deg())
# print(deg())

# -- 8.

def jaccard_index(a: set[any], b: set[any]) -> float:
    numer = len(a & b)
    denom = len(a | b)
    return numer / denom

# a = set([1, 3, 5])
# b = set([2, 4, 5])
# print(jaccard_index(a, b))

# -- 9.

def fib(n: int) -> int:
    if n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)

# print(fib(7))

# -- 10.
mx = [ [1,2,3], [4,5,6], [7,8,9] ]
_ = [[print(j) for j in i] for i in mx]

# -- 11.
qs = lambda list: qs([x for x in list[1:] if x <= list[0]]) + [list[0]] + qs([x for x in list if x > list[0]]) if list else []

# -- 12.

from sys import getsizeof

print(getsizeof(None))