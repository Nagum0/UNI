from typing import *
from enum import Enum
from sl import E1

class HashMap:
    def __init__(self, size: int, h: Callable[[Any, int], int]) -> None:
        self.h = h
        self.t: List[E1] = [E1(None) for _ in range(size)]
        self.m = size

    @staticmethod
    def search(q: E1, k: Any) -> E1:
        while q and q.key != k:
            q = q.next

        return q

    def insert(self, p: E1) -> bool:
        k: Any = p.key
        s: int = self.h(k, self.m)

        if not self.search(self.t[s], k):
            p.next = self.t[s]
            self.t[s] = p
            return True
        
        return False
    
    def remove(self, k: Any) -> E1:
        s: int = self.h(k, self.m)
        p: E1 = E1(None)
        q: E1 = self.t[s]

        while q and q.key != k:
            p = q
            q = q.next
        
        if q:
            if p:
                self.t[s] = q.next
            else:
                p.next = q.next
            q.next = None

        return q
    
class GapType(Enum):
    E = 0,
    D = 1

class DoubleHashMap:
    def __init__(self, m: int, h1: Callable[[Any, int], int], h2: Callable[[Any, int], int]) -> None:
        self.T: List[Any] = [GapType.E for _ in range(m)]
        self.h1 = h1
        self.h2 = h2
        self.m = m

    def search(self, k: Any) -> int:
        i: int = 0
        j = self.h1(k, self.m)
        d = self.h2(k, self.m)
        b = True

        while b:
            if self.T[j] == k:
                return j
            i += 1
            b = self.T[j] != GapType.E and i < self.m
            j = (j + d) % self.m

        return -1
    
    def insert(self, k: Any) -> int:
        i: int = 0
        j = self.h1(k, self.m)
        d = self.h2(k, self.m)

        while i < self.m and (self.T[j] != GapType.E or self.T[j] != GapType.D):
            if self.T[j] == k:
                return -(j + i)
            
            i += 1
            j = (j + d) % self.m

        if i < self.m:
            ide: int = j
        else:
            return -(self.m + i)
        
        while i < self.m and self.T[j] != GapType.E:
            if self.T[j] == k:
                return -(j + 1)
            
            i += 1
            j = (j + d) % self.m

        self.T[ide] = k
        return ide

    def delete(self, k: Any) -> int:
        j: int = self.search(k)

        if j >= 0:
            self.T[j] = GapType.D

        return j