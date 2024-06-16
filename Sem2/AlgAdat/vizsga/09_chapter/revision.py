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

if __name__ == "__main__":
    xs: List[int] = [9, 8, 7, 6, 4, 5]
    ys: List[int] = xs.copy()
    print(f"Unsorted xs:\t{xs}")
    quickSort(xs)
    print(f"Quicksorted xs:\t{xs}")
    print(f"Unsorted ys:\t{ys}")
    mergeSort(ys)
    print(f"Mergesorted ys:\t{ys}")