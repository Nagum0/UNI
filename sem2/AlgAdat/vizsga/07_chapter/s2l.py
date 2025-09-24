from typing import *

class E2:
	def __init__(self, key: Any) -> None:
		self.key: Any = key
		self.prev: E2 = self
		self.next: E2 = self

	def __str__(self) -> str:
		output: str = f"[ {self.key}"
		p = self.next

		while p != self:
			output += f" -> {p.key}"
			p = p.next

		output += " ]"

		return output

	def precede(self, q: 'E2') -> None:
		p = self.prev
		q.prev = p
		q.next = self
		p.next = self.prev = q

	def follow(self, q: 'E2') -> None:
		p = self.next
		q.prev = self
		q.next = p
		self.next = p.prev = q

	@staticmethod
	def unlink(q: 'E2') -> None:
		p = q.prev
		r = q.next
		p.next = r
		r.prev = p
		q.next = q
		q.prev = q

if __name__ == "__main__":
	l: E2 = E2(10)
	f: E2 = E2(21)
	l.precede(f)
	f.precede(E2(4))
	f.follow(E2(10))
	l.precede(E2(69))
	l.follow(E2(50))
	E2.unlink(f)
	print(l)
	print(f)