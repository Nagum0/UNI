from typing import *
from math import floor
from random import randint

""" ----------------------------- PRQUEUE ----------------------------- """

def doubleFullArray(A: List[Any]) -> None:
    if len(A) == 0:
        n = 1
    else:
        n = len(A) * 2

    A.extend([None for _ in range(n - len(A))])

def parent(j: int) -> int:
    return floor((j - 1) / 2)

def left(i: int) -> int:
    return 2 * i + 1

def right(i: int) -> int:
    return left(i) + 1

def sink(A: List[Any], k: int, n: int) -> None:
    i = k
    j = left(i)
    b = True

    while j < n and b:
        if j + 1 < n and A[j + 1] > A[j]:
            j += 1
        
        if A[i] < A[j]:
            A[i], A[j] = A[j], A[i]
            i = j
            j = left(j)

class PrQueueUnderflow(Exception):
    def __init__(self, *args: object) -> None:
        super().__init__(*args)

class PrQueue:
    def __init__(self) -> None:
        self.A: List[Any] = []
        self.m0: Final[int] = 16
        self.n: int = 0

    def __str__(self) -> str:
        return f"{self.A[0:self.n]} Size: {self.n}"

    def max(self) -> Any:
        return self.A[0]
    
    # O(log n)
    def add(self, x: Any) -> None:
        if self.n == len(self.A):
            doubleFullArray(self.A)

        j = self.n
        i = parent(j)
        self.n += 1
        self.A[j] = x

        while j > 0 and self.A[i] < x:
            self.A[j], self.A[i] = self.A[i], self.A[j]
            j = i
            i = parent(i)

    def remMax(self) -> Any:
        if self.n == 0:
            raise PrQueueUnderflow()
        
        max = self.A[0]
        self.n -= 1
        self.A[0] = self.A[self.n]
        sink(self.A, 0, self.n)

        return max

""" ----------------------------- O(nlogn) sorts ----------------------------- """

def quickSort(A: List[int]) -> None:
    qs(A, 0, len(A) - 1)

def qs(A: List[int], p: int, r: int) -> None:
    if p < r:
        q: int = partition(A, p, r)
        qs(A, p, q - 1)
        qs(A, q + 1, r)
    else:
        return
    
def partition(A: List[int], p: int, r: int) -> None:
    i: int = randint(p, r)
    A[i], A[r] = A[r], A[i]
    i = p

    while i < r and A[i] <= A[r]:
        i += 1

    if i < r:
        j = i + 1

        while j < r:
            if A[j] < A[r]:
                A[i], A[j] = A[j], A[i]
                i += 1
            j += 1

        A[i], A[r] = A[r], A[i]

    return i

def mergeSort(A: List[int]) -> None:
    B: List[int] = A.copy()
    ms(B, A, 0, len(A))

def ms(B: List[int], A: List[int], u: int, v: int) -> None:
    if v - u > 1:
        m: int = floor((u + v) / 2)
        ms(A, B, u, m)
        ms(A, B, m, v)
        merge(B, A, u, m, v)
    else:
        return
    
def merge(B: List[int], A: List[int], u: int, m: int, v: int) -> None:
    i, k, j = u, u, m

    while i < m and j < v:
        if B[i] <= B[j]:
            A[k] = B[i]
            i += 1
        else:
            A[k] = B[j]
            j += 1
        k += 1

    if i < m:
        A[k:v] = B[i:m]
    else:
        A[k:v] = B[j:v]

""" ----------------------------- STACK & QUEUE (Array) ----------------------------- """
class StackUnderflow(Exception):
    def __init__(self, *args: object) -> None:
        super().__init__(*args)

class Stack:
    def __init__(self, m: int) -> None:
        self.m0: int = m
        self.A: List[Any] = [None for _ in range(m)]
        self.n = 0

    def __str__(self) -> str:
        return f"Top: {self.A[self.n]}\tSize: {self.n}\t\t{self.A}"
    
    def push(self, x: Any) -> None:
        if self.n == len(self.A):
            doubleFullArray(self.A)

        self.A[self.n] = x
        self.n += 1

    def pop(self) -> Any:
        if self.n > 0:
            self.n -= 1
            return self.A[self.n]
        else:
            raise StackUnderflow
        
    def top(self) -> Any:
        if self.n > 0:
            return self.A[self.n - 1]
        else:
            raise StackUnderflow
        
    def isEmpty(self) -> bool:
        return self.n == 0
    
    def setEmpty(self) -> None:
        self.A = [None for _ in range(self.m0)]
        self.n = 0

def doubleFullQueueArray(A: List[Any], k: int) -> None:
    n0: int = len(A)
    n: int = 2 * len(A)
    A.extend([None for _ in range(n - n0)])
    A[n0:n0 + k] = A[0:k]

    for i in range(0, k):
        A[i] = None

class QueueUnderflow(Exception):
    def __init__(self, *args: object) -> None:
        super().__init__(*args)

class Queue:
    def __init__(self, m: int) -> None:
        self.m0: int = m
        self.Z: List[Any] = [None for _ in range(m)]
        self.n: int = 0
        self.k: int = 0

    def __str__(self) -> str:
        return f"k: {self.k} n: {self.n}\t{self.Z}"
    
    def add(self, x: Any) -> None:
        if self.n == len(self.Z):
            doubleFullQueueArray(self.Z, self.k)

        self.Z[(self.k + self.n) % len(self.Z)] = x
        self.n += 1

    def rem(self) -> Any:
        if self.n > 0:
            self.n -= 1
            i: int = self.k
            k = (k + 1) % len(self.Z)
            return self.Z[i]
        else:
            raise QueueUnderflow
        
    def first(self) -> Any:
        if self.n > 0:
            return self.Z[self.k]
        else:
            raise QueueUnderflow

""" ----------------------------- Insertion Sort (O(n)) ----------------------------- """
def naiveInsertionSort(A: List[Any]) -> None:
    for i in range(len(A)):
        j = i

        while j > 0 and A[j - 1] > A[j]:
            A[j - 1], A[j] = A[j], A[j - 1]
            j -= 1

def insertionSort(A: List[Any]) -> None:
    for i in range(1, len(A)):
        if A[i - 1] > A[i]:
            j = i - 2
            x = A[i]
            A[i] = A[i - 1]

            while j >= 0 and A[j] > x:
                A[j + 1], A[j] = A[j], A[j + 1]
                j -= 1

            A[j + 1] = x

""" ----------------------------- Linked Lists ----------------------------- """
class E1:
    def __init__(self, key: Any = None) -> None:
        self.key = key
        self.next = None

def S1L_print(L: E1) -> None:
    p = L

    while p is not None:
        print(f"{p.key} -> ", end="")
        p = p.next

    print("∅")

def H1L_print(H: E1) -> None:
    print("∅ -> ", end="")
    S1L_print(H.next)

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
                q = H.next

                while q.key <= s.key:
                    p = q
                    q = p.next

                s.next = q
                p.next = s

            s = r.next
    else:
        return

def cut(L: E1, n: int) -> E1:
    p: E1 = L

    while p is not None and n > 1:
        p = p.next
        n -= 1
        
    L2: E1 = p.next
    p.next = None
    return L2

def S1L_length(L: E1) -> int:
    p: E1 = L
    n: int = 0

    while p is not None:
        p = p.next
        n += 1

    return n

def S1L_mergeSort(L: E1) -> None:
    n: int = S1L_length(L)
    S1L_ms(L, n)

def S1L_ms(L, n: int) -> None:
    if n > 1:
        n1: int = floor(n / 2)
        L2: E1 = cut(L, n1)
        S1L_ms(L, n1)
        S1L_ms(L2, n - n1)
        L = S1L_merge(L, L2)
    else:
        return

def S1L_merge(L1: E1, L2: E1) -> E1:
    if L1.key <= L2.key:
        t: E1 = L1
        L = t
        L1 = L1.next
    else:
        t: E1 = L2
        L = t
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
        self.next: 'E2' = None
        self.prev: 'E2' = None
        self.key: Any = key

    def __str__(self) -> str:
        out: str = f"<- {self.key} <-> "
        p: E2 = self.next

        while p is not self.prev:
            out += f"{p.key} <-> "
            p = p.next

        return f"{out} {p.key} ->"

def precede(q: E2, r: E2) -> None:
    p: E2 = r.prev
    q.next = r
    q.prev = p
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
    q.next = q
    q.prev = q
    p.next = r
    r.prev = p

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
    print(c1)
    precede(E2(42), c2)
    print(c1)
    follow(c2, E2(6969))
    print(c1)
    unlink(c2)
    print(c1)