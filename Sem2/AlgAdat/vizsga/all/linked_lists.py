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

from revision import QueueUnderflow, StackUnderflow

class Queue:
    def __init__(self) -> None:
        self.first: E1 = E1()
        self.trailer: E1 = self.first
        self.n: int = 0

    def __str__(self) -> str:
        out: str = f"First: {self.first.key} Length: {self.n}\t\t"
        p: E1 = self.first

        while p is not None:
            out += f"{p.key} -> "
            p = p.next

        out += "None"
        return out

    def add(self, x: Any) -> None:
        self.trailer.key = x
        self.trailer.next = E1()
        self.trailer = self.trailer.next
        self.n += 1

    def rem(self) -> Any:
        if self.n > 0:
            x = self.first.key
            self.n -= 1
            p: E1 = self.first
            self.first = self.first.next
            del p
            return x
        else:
            raise QueueUnderflow
        
    def first(self) -> Any:
        if self.n > 0:
            return self.first.key
        else:
            raise QueueUnderflow
        
    def setEmpty(self) -> None:
        while self.first is not self.trailer:
            p: E1 = self.first
            self.first = self.first.next
            del p

        self.n = 0

class Stack:
    def __init__(self) -> None:
        self.top: E1 = E1()
        self.n: int = 0

    def push(self, x: Any) -> None:
        node: E1 = E1(x)
        node.next = self.top
        self.top = node
        self.n += 1

    def pop(self) -> Any:
        if self.n > 0:
            self.n -= 1
            x = self.top.key
            p: E1 = self.top
            self.top = self.top.next
            del p
            return x
        else:
            raise StackUnderflow

def H1L_insertionSort(H: E1) -> None:
    r = H.next

    if r:
        s = r.next

        while s is not None:
            if r.key <= s.key:
                r = s
            else:
                r.next = s.next
                p = H
                q = p.next

                while q.key <= s.key:
                    p = q
                    q = p.next
                
                s.next = q
                p.next = s

            s = r.next
    else:
        return

from math import floor

def S1L_mergeSort(L: E1) -> None:
    S1L_ms(L, S1L_length(L))

def S1L_ms(L: E1, n: int) -> None:
    if n > 1:
        n1: int = floor(n / 2)
        L2: E1 = cut(L, n1)
        S1L_ms(L, n1)
        S1L_ms(L2, n - n1)
        L = S1L_merge(L, L2)
    else:
        return
    
def S1L_merge(L1: E1, L2: E1) -> None:
    if L1.key <= L2.key:
        t: E1 = L1
        L: E1 = t
        L1 = L1.next
    else:
        t: E1 = L2
        L: E1 = t
        L2 = L2.next

    while L1 is not None and L2 is not None:
        if L1.key <= L2.key:
            t.next = L1
            t = t.next
            L1 = L1.next
        else:
            t.next = L2
            t = t.next
            L2 = L2.next

    if L1 is not None:
        t.next = L1
    else:
        t.next = L2

    return L

class E2:
    def __init__(self, key: Any = None) -> None:
        self.next: 'E2' = self
        self.prev: 'E2' = self
        self.key = key
    
    def __str__(self) -> str:
        out: str = f"<- {self.key} <-> "
        p = self.next

        while p is not self.prev:
            out += f"{p.key} <-> "
            p = p.next

        out += f"{p.key} -> "
        return out

def precede(q: E2, r: E2) -> None:
    p: E2 = r.prev
    q.prev = p
    q.next = r
    r.prev = q
    p.next = q

def follow(p: E2, q: E2) -> None:
    r: E2 = p.next
    q.next = r
    q.prev = p
    p.next = q
    r.prev = q

def unlink(q: E2) -> None:
    p: E2 = q.prev
    r: E2 = q.next
    q.prev = q
    q.next = q
    p.next = r
    r.prev = p

def splice(p: E2, q: E2, r: E2) -> None:
    p1: E2 = p.prev
    q2: E2 = q.next
    p1.next = q2
    q2.prev = p1
    p1 = r.prev
    p.prev = p1
    q.next = r
    p1.next = p
    r.prev = q

def append(L: E2, H: E2) -> None:
    if H.next is not H:
        splice(H.next, H.prev, L)
    else:
        return

def H2L_insertionSort(H: E2) -> None:
    r: E2 = H.next
    s: E2 = r.next

    while s is not H:
        if r.key <= s.key:
            r = s
        else:
            unlink(s)
            p: E2 = r.prev

            while p is not H and p.key > s.key:
                p = p.prev

            follow(p, s)

        s = r.next

if __name__ == "__main__":
    c1 = E2(10)
    c2 = E2(12)
    c3 = E2(69)

    c1.next = c2
    c2.prev = c1
    c2.next = c3
    c3.prev = c2
    c1.prev = c3
    c3.next = c1
    precede(E2(420), c2)
    follow(c2, E2(100))
    print(c1)
    H2L_insertionSort(c1)
    print(c1)
