from typing import *
from random import randint

def Quicksort(A: List[Any]) -> None:
	quickSort(A, 0, len(A) - 1)

def quickSort(A: List[Any], p: int, r: int) -> None:
	if p < r:
		q = partition(A, p, r)
		quickSort(A, p, q - 1)
		quickSort(A, q + 1, r)
	else:
		return

def partition(A: List[Any], p: int, r: int) -> int:
	i = randint(p, r)
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

if __name__ == "__main__":
	A: List[int] = [4, 5, 3, 2, 6, 1]
	print(A)
	Quicksort(A)
	print(A)