from typing import *
from random import randint

def merge_sort(A: List[int]) -> None:
	B: List[int] = A.copy()
	ms(B, A, 0, len(A))

def ms(B: List[int], A: List[int], u: int, v: int) -> None:
	if v - u > 1:
		m: int = int((u + v) / 2)
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
			j += 1
		k += 1
	
	if i < m:
		A[k:v] = B[i:m]
	else:
		A[k:v] = B[j:v]

def quick_sort(A: List[int], p: int, r: int) -> None:
	if p < r:
		q: int = partition(A, p, r)
		quick_sort(A, p, q - 1)
		quick_sort(A, q + 1, r)
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
				temp = A[i]
				A[i] = A[j]
				A[j] = temp
				i += 1
			j += 1

		# Swap:
		temp = A[i]
		A[i] = A[r]
		A[r] = temp

	return i

xs: List[int] = [420, 0, 1, -1, 69]
print(xs)
quick_sort(xs, 0, len(xs) - 1)
print(xs)