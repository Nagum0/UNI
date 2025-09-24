line = "Shoe shoe shoe Shoe shoe shoe"
len([1 for i in line.split(" ") if i.lower() == "shoe"])

def remove_dups(lst: list[int]) -> list[int]:
    d = {}

    for i in lst[:]:
        d[i] = d[i] + 1 if i in d.keys() else 1
        
        if d[i] >= 2:
            lst.remove(i)

    return lst

print(remove_dups([1, 2, 1, 2, 3, 3, 3, 2, 1, 2, 4, 5, 13, 5, 6]))

def caesar_encode(txt: str, s: int) -> str:
    out = ""

    for i in txt.upper():
        m = ord(i) + s
        out += chr((m % 90) + 64 if m > 90 else m)

    return out

print(caesar_encode("xyz", 1))

def caesar_decode(txt: str, s: int) -> str:
    out = ""

    for i in txt.upper():
        m = ord(i) - s
        out += chr()
    
    return out

print(caesar_decode("bcd", 1))
print(caesar_decode(caesar_encode("abc", 1), 1))

print(ord("A"), ord("Z"))
print(ord("A"), chr((91 % 90) + 64))
print(chr(90))
