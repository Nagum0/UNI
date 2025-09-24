from typing import *
from random import randint

def quicksort(A: List[int], p: int, r: int) -> None:
	if p < r:
		q: int = partition(A, p, r)
		quicksort(A, p, q - 1)
		quicksort(A, q + 1, r)
	else:
		return
	
def partition(A: List[int], p: int, r: int) -> None:
	i: int = randint(p, r)
	# Swap:
	temp = A[i]
	A[i] = A[r]
	A[r] = temp
	i = p

	while i < r and A[i] <= A[r]:
		i += 1
	
	if i < r:
		j = i + 1

		while j < r:
			if A[j] < A[r]:
				# Swap:
				temp = A[j]
				A[j] = A[i]
				A[i] = temp
				i += 1
			j += 1

		# Swap:
		temp = A[r]
		A[r] = A[i]
		A[i] = temp

	return i

xs: List[int] = [420, 0, 1, -1, 69]
print(xs)
quicksort(xs, 0, len(xs) - 1)
print(xs)