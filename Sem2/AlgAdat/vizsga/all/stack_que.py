from typing import *

def doubleFullArray(A: List[Any]) -> None:
    if len(A) == 0:
        n = 1
    else:
        n = len(A) * 2

    A.extend([None for _ in range(n - len(A))])

class StackUnderflow(Exception):
    def __init__(self, *args: object) -> None:
        super().__init__(*args)

class Stack:
    def __init__(self, size: int) -> None:
        self.m0: Final[int] = size
        self.A: List[Any] = [None for _ in range(self.m0)]
        self.n: int = 0

    def __str__(self) -> str:
        return f"{self.A} Top: {self.A[self.n - 1]}"
        
    def push(self, x: Any) -> None:
        if self.n == len(self.A):
            doubleFullArray(self.A)

        self.A[self.n] = x
        self.n += 1
    
    def pop(self) -> Any:
        if self.n <= 0:
            raise StackUnderflow
        
        self.n -= 1
        return self.A[self.n]
    
    def top(self) -> Any:
        if self.n <= 0:
            raise StackUnderflow
        
        return self.A[self.n - 1]
    
    def isEmpty(self) -> bool:
        return self.n == 0
    
    def setEmpty(self) -> None:
        for i in range(self.n):
            self.A[i] = None
        
        self.n = 0

def doubleFullQueueArray(A: List[Any], k: int) -> None:
    n0: int = len(A)
    n: int = 2 * len(A)
    A.extend([None for _ in range(n - len(A))])
    A[n0:n0 + k] = A[0:k]
    
    for i in range(0, k):
        A[i] = None

class QueueUnderflow(Exception):
    def __init__(self, *args: object) -> None:
        super().__init__(*args)

class Queue:
    def __init__(self, m: int) -> None:
        self.m0 = m
        self.Z: List[Any] = [None for _ in range(m)]
        self.k = 0
        self.n = 0

    def __str__(self) -> str:
        return f"k: {self.k} n: {self.n}\t{self.Z}"

    def add(self, x: Any) -> None:
        if self.n == len(self.Z):
            doubleFullQueueArray(self.Z, self.k)

        self.Z[(self.k + self.n) % len(self.Z)] = x
        self.n += 1

    def rem(self) -> Any:
        if self.n <= 0:
            raise QueueUnderflow

        self.n -= 1
        i: int = self.k
        self.k = (self.k + 1) % len(self.Z)
        x = self.Z[i]
        self.Z[i] = None
        return x

    def first(self) -> Any:
        if self.n <= 0:
            raise QueueUnderflow
        
        return self.Z[self.k]

if __name__ == "__main__":
    

    """ q: Queue = Queue(4)
    print(q)

    q.add(5)
    print(q)
    
    q.add(3)
    print(q)

    q.rem()
    print(q)

    q.rem()
    print(q)

    q.add(7)
    print(q)

    q.add(2)
    print(q)

    q.add(4)
    print(q)

    q.add(1)
    print(q)

    q.add(6)
    print(q)

    q.add(8)
    print(q)

    q.add(11)
    print(q)

    q.add(13)
    print(q)

    q.add(69)
    print(q)

    print(q.rem())
    print(q)

    q.add(420)
    print(q) """