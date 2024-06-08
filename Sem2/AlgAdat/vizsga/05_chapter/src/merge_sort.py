from typing import *

def mergeSort(A: List[int]) -> None:
	B: List[int] = A.copy()
	ms(B, A, 0, len(A))

def ms(B: List[int], A: List[int], u: int, v: int) -> None:
	if v - u > 1:
		m = int((u + v) / 2)
		ms(A, B, u, m)
		ms(A, B, m, v)
		merge(B, A, u, m, v)
	else:
		return
	
def merge(B: List[int], A: List[int], u: int, m: int, v: int) -> None:
	k, i, j = u, u, m

	while i < m and j < v:
		if B[i] <= B[j]:
			A[k] = B[i]
			i += 1
		else:
			A[k] = B[j]
			j  += 1
		
		k += 1

	if i < m:
		A[k:v] = B[i:m]
	else:
		A[k:v] = B[j:v]

xs: List[int] = [420, 0, 1, -1, 69]
print(xs)
mergeSort(xs)
print(xs)