from typing import *
from random import randint
from sl import E1

def naive_insertion_sort(A: List[int]) -> None:
	for i in range(1, len(A)):
		j = i

		while j > 0 and A[j - 1] > A[j]:
			# Swap
			temp = A[j - 1]
			A[j - 1] = A[j]
			A[j] = temp
			j -= 1

def insertion_sort(A: List[int]) -> None:
	# 5 2 6 1 69 0 | x = 2, i = 1
	# 5 5 6 1 69 0 | x = 2, i = 1, j = -1
	# 2 5 6 1 69 0 | x = None, i = 2
	# 2 5 6 1 69 0 | x = None, i = 3
	# 2 5 6 6 69 0 | x = 1, i = 3, j = 1
	# 2 5 5 6 69 0 | x = 1, i = 3, j = 0
	# 2 2 5 6 69 0 | x = 1, i = 3, j = -1
	# 1 2 5 6 69 0 | x = None, i = 4
	# 1 2 5 6 69 0 | x = 0, i = 5
	# 1 2 4 6 69 69 | x = 0, i = 5, j = 3
	# 1 2 4 6 6 69 | x = 0, i = 5, j = 2
	# 1 2 4 4 6 69 | x = 0, i = 5, j = 1
	# 1 2 2 4 6 69 | x = 0, i = 5, j = 0
	# 1 1 2 4 6 69 | x = 0, i = 5, j = -1
	# 0 1 2 4 6 69 DONE!!!
	for i in range(1, len(A)):
		if A[i - 1] > A[i]:
			x = A[i]
			A[i] = A[i - 1]
			j = i - 1

			while j >= 0 and A[j] > x:
				A[j + 1] = A[j]
				j -= 1

			A[j + 1] = x

def merge_sort(A: List[int]) -> None:
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
	
def partition(A: List[int], p: int, r: int) -> int:
	i: int = randint(p, r)
	# Swap:
	temp = A[r]
	A[r] = A[i]
	A[i] = temp
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
		temp = A[r]
		A[r] = A[i]
		A[i] = temp

	return i

def prac_naive_ins_sort(A: List[int]) -> None:
	for i in range(1, len(A)):
		j = i

		while j > 0:
			if A[j - 1] > A[j]:
				A[j], A[j - 1] = A[j - 1], A[j]
			j -= 1

def prac_ins_sort(A: List[int]) -> None:
	for i in range(1, len(A)):
		if A[i - 1] > A[i]:
			x = A[i]
			A[i] = A[i - 1]
			j = i - 1

			while j >= 0 and A[j - 1] > x:
				A[j + 1] = A[j]
				j -= 1

			A[j + 1] = x

def prac_quick_sort(A: List[int]) -> None:
	qs(A, 0, len(A) - 1)

def qs(A: List[int], p: int, r: int) -> None:
	if p < r:
		q: int = prac_partition(A, p, r)
		qs(A, p, q - 1)
		qs(A, q + 1, r)
	else:
		return
	
def prac_partition(A: List[int], p: int, r: int) -> int:
	i = randint(p, r)
	A[r], A[i] = A[i], A[r]
	i = p

	while i < r and A[i] <= A[r]:
		i += 1

	if i < r:
		j = i + 1

		while j < r:
			if A[j] < A[r]:
				A[j], A[i] = A[i], A[i]
				i += 1
			j += 1
		
		A[i], A[r] = A[r], A[i]

	return i

def h1l_insertion_sort(H: E1) -> None:
	r = H.next

	if r is not None:
		s = r.next

		while s is not None:
			if r.key <= s.key:
				r = s
			else:
				r.next = s.next
				p = H
				q = H.next

				while q.key <= s.key:
					p = q
					q = p.next
				
				s.next = q
				p.next = s
			
			s = r.next
	else:
		return

def prac_merge_sort(A: List[int]) -> None:
	B: List[int] = A.copy()
	prac_ms(B, A, 0, len(A))

def prac_ms(B: List[int], A: List[int], u: int, v: int) -> None:
	if v - u > 1:
		m = int((u + v) / 2)
		prac_ms(A, B, u, m)
		prac_ms(A, B, m, v)
		prac_merge(B, A, u, m, v)
	else:
		return
	
def prac_merge(B: List[int], A: List[int], u: int, m: int, v: int) -> None:
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

def s1l_merge_sort(L: E1) -> None:
	s1l_ms(L, L.length() - 1)

def s1l_ms(L: E1, n: int) -> None:
	if n > 1:
		n1 = int(n / 2)
		L2 = L.cut(n1)
		s1l_ms(L, n1)
		s1l_ms(L2, n - n1)
		L = s1l_merge(L, L2)
	else:
		return

def s1l_merge(L1: E1, L2: E1) -> E1:
	if L1.key <= L2.key:
		L = t = L1
		L1 = L1.next
	else:
		L = t = L2
		L2 = L2.next

	while L1 is not None and L2 is not None:
		if L1.key <= L2.key:
			t.next = L1
			t = t.next
			L1 = L1.next
		else:
			t.next = L2
			t = t.next
			L2 = L2.next
		
	if L1 is not None:
		t.next = L1
	else:
		t.next = L2

	return L

if __name__ == "__main__":
	xs: List[int] = [5,2,6,1,69,0]
	print(xs)
	prac_merge_sort(xs)
	print(xs)

	ys: E1 = E1(5)
	ys.insert(2)
	ys.insert(6)
	ys.insert(1)
	ys.insert(69)
	ys.insert(0)
	print(ys)
	s1l_merge_sort(ys)
	print(ys)
	print("test")