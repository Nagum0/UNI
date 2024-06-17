from typing import *
from math import floor

def doubleFullArray(A: List[Any]) -> None:    
    if len(A) == 0:
        n = 1
    else:
        n: int = len(A) * 2
    
    A.extend([None for _ in range(n - len(A))])

class PrQueue:
    def __init__(self) -> None:
        self.A: List[Any] = []
        self.n: int = 0

    def __str__(self) -> str:
        return f"{self.A} Size: {self.n}"

    # O(log n)
    def add(self, x: Any) -> None:
        if self.n == len(self.A):
            doubleFullArray(self.A)
        
        j: int = self.n
        self.n += 1
        self.A[j] = x
        i: int = self.parent(j)

        while j > 0 and self.A[i] < x:
            self.A[i], self.A[j] = self.A[j], self.A[i]
            j = i
            i = self.parent(i)

    def max(self) -> Any:
        return self.A[0]

    def remMax(self) -> Any:
        if self.n > 0:
            max = self.A[0]
            self.n -= 1
            self.A[0] = self.A[self.n]
            self.sink(self.A, 0, self.n)
            return max
        else:
            raise Exception("PrQueueUnderflow")

    def parent(self, j: int) -> int:
        return int(floor((j - 1) / 2))
    
    def left(self, i: int) -> int:
        return 2 * i + 1
    
    def right(self, i: int) -> int:
        return self.left(i) + 1
    
    def sink(self, A: List[Any], k: int, n: int) -> None:
        i: int = k
        j: int = self.left(i)
        b: bool = True

        while j < n and b:
            if j + 1 < n and A[j + 1] > A[j]:
                j += 1

            if A[i] < A[j]:
                A[i], A[j] = A[j], A[i]

            i = j
            j = self.left(j)

if __name__ == "__main__":
    que: PrQueue = PrQueue()
    que.add(10)
    que.add(69)
    que.add(9)
    que.add(70)
    que.add(8)
    print(que.remMax())
    print(que)
    que.add(1)
    print(que)