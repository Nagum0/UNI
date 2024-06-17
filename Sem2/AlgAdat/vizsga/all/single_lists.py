from typing import *

class E1:
    def __init__(self, key: Any = None) -> None:
        self.key = key
        self.next: 'E1' = None

def S1L_length(L: E1) -> int:
    n: int = 0
    p = L

    while p is not None:
        n += 1
        p = p.next

    return n

def S1L_print(L: E1) -> None:
    p = L

    while p is not None:
        print(f"{p.key} -> ", end="")
        p = p.next

    print("∅")

def H1L_length(H: E1) -> int:
    return S1L_length(H.next)

def H1L_print(H: E1) -> None:
    print("∅ -> ", end="")
    S1L_print(H.next)

def cut(L: E1, n: int) -> E1:
    p: E1 = L

    while n > 1:
        n -= 1
        p = p.next

    q: E1 = p.next
    p.next = None
    return q

def H1L_read() -> E1:
    H: E1 = E1()
    H.next = E1()
    v: E1 = H.next
    read: str = ""

    while True:
        read = str(input("> "))
        if read == "!q":
            break
        v.key = read
        v.next = E1()
        v = v.next

    return H

if __name__ == "__main__":
    l1: E1 = E1(8)
    
    l2: E1 = E1(10)
    l1.next = l2
    
    l3: E1 = E1(69)
    l2.next = l3

    l4: E1 = E1(420)
    l3.next = l4

    print(f"L length: {S1L_length(l1)}")
    S1L_print(l1)

    h0: E1 = E1()

    h1: E1 = E1(8)
    h0.next = h1

    h2: E1 = E1(10)
    h1.next = h2
    
    h3: E1 = E1(69)
    h2.next = h3

    h4: E1 = E1(420)
    h3.next = h4

    print(f"H length: {H1L_length(h0)}")
    H1L_print(h0)

    q: E1 = cut(l1, 2)
    S1L_print(l1)
    S1L_print(q)

    H: E1 = H1L_read()
    H1L_print(H)