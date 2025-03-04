import math

def calcPBk() -> float:
    return 1 - (1 / math.comb(90, 5))

def calcPA() -> float:
    return 1 - (calcPBk() ** 41000000)

def bin(n: float, k: float, p: float) -> float:
    return math.comb(n, k) * ((p) ** k) * ((1 - p) ** (n - k))

c: float = 0
for k in range(1, 7):
    b: float = bin(6, k, 1 / 2)
    c += b
    print(f"{k}: {b}")
print(c)
