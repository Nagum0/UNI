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

def doubleFullQueueArray(A: List[Any]) -> None:
    n: int = 2 * len(A)
    A.extend([None for _ in range(n - len(A))])

class QueueUnderflow(Exception):
    def __init__(self, *args: object) -> None:
        super().__init__(*args)

class Queue:
    def __init__(self, m: int) -> None:
        self.m0 = m
        self.Z: List[Any] = [None for _ in range(m)]
        self.k = 0
        self.n = 0

    

if __name__ == "__main__":
    s: Stack = Stack(8)
    s.push(69)
    s.push(120)
    s.push(420)
    print(s)
    s.pop()
    print(s)
    print(s.top())
    s.push(180)
    print(s)
    