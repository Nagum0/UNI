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

if __name__ == "__main__":
    s: Stack = Stack(8)
    s.push(10)
    s.push(69)
    s.push(420)
    print(s)
    print(s.pop())
    print(s)