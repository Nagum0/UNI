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

if __name__ == "__main__":
    q: Queue = Queue()
    q.add(E1(10))
    q.add(E1(69))
    q.add(E1(42))
    print(q)
    
    s: Stack = Stack()
    s.push(85)
    s.push(69)
    s.push(420)
    S1L_print(s.top)
    print(s.pop())
    S1L_print(s.top)