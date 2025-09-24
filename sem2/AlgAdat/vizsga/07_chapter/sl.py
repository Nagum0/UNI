from typing import *

class E1:
	def __init__(self, key: Any) -> None:
		self.key: Any = key
		self.next: E1 = None

	def insert(self, key: Any) -> None:
		p = self
		pe = p.next

		while p is not None:
			pe = p
			p = p.next
		
		q: E1 = E1(key)
		pe.next = q

	def remove(self, key: Any) -> None:
		p = self
		pe = p.next

		if self.key == key:
			self.key = self.next.key
			self.next = self.next.next
			self = self.next
			return

		while p is not None and p.key != key:
			pe = p
			p = p.next

		if p is None:
			return
		
		pe.next = p.next
		del p

	def length(self) -> int:
		n: int = 1
		p = self

		while p is not None:
			p = p.next
			n += 1

		return n

	def cut(self, n: int) -> 'E1':
		p = self

		while p is not None and n > 1:
			p = p.next
			n -= 1
		
		q: E1 = p.next
		p.next = None
		return q

	@staticmethod
	def read() -> 'E1':
		h: E1 = E1(None)
		v = h.next
		ins: Any = ""

		while ins != "!q":
			ins = input("> ")
			v = E1(ins)
			v = v.next
		
		return h

	def __str__(self) -> str:
		output: str = "[ " + str(self.key)
		p = self.next

		while p is not None:
			output += f" -> {p.key}"
			p = p.next

		output += " -> None ]"

		return output

if __name__ == "__main__":
	fst: E1 = E1(69)
	snd: E1 = E1(420)
	thrd: E1 = E1(1280)
	fst.next = snd
	snd.next = thrd

	print(fst.__str__())
	fst.insert(10)
	fst.insert(100)
	fst.insert(6969)
	print(fst.__str__())
	print(fst.cut(3).__str__())

	xs: E1 = E1.read()
	print(xs.__str__())