from math import floor

class Node:
	def __init__(self, key, left = None, right = None) -> None:
		self.key = key
		self.b = 0
		self.left = left
		self.right = right

def AVLinsert(t: Node, k: any, d: bool) -> None:
	if t == None:
		t = Node(k)
		d = True
	else:
		if k < t.key:
			AVLinsert(t.left, k, d)
			if d:
				leftSubTreeGrown(t, d)
			else:
				pass
		elif k > t.key:
			AVLinsert(t.right, k, d)
			if d:
				rightSubTreeGrown(t, d)
			else:
				pass
		else:
			d = False

def leftSubTreeGrown(t: Node, d: bool) -> None:
	if t.b == -1:
		l = t.left
		if l.b == -1:
			balanceMMm(t, l)
		else:
			balanceMMp(t, l)
		d = False
	else:
		t.b = t.b - 1
		d = (t.b < 0)

def rightSubTreeGrown(t: Node, d: bool) -> None:
	if t.b == 1:
		r = t.right
		if r.b == 1:
			balancePPp(t, r)
		else:
			balancePPm(t, r)
		d = False
	else:
		t.b = t.b + 1
		d = (t.b > 0)

def balancePPp(t: Node, r: Node) -> None:
	t.right = r.left
	r.left = t
	t.b = 0
	r.b = t.b
	t = r

def balanceMMm(t: Node, l: Node) -> None:
	t.left = l.right
	l.right = t
	t.b = 0
	l.b = t.b
	t = l

def balancePPm(t: Node, r: Node) -> None:
	l: Node = r.left
	t.right = l.left
	r.left = l.right
	l.left = t
	l.right = r
	t.b = floor((l.b + 1) / 2)
	r.b = floor((1 - l.b) / 2)
	l.b = 0
	t = l 

def balanceMMp(t: Node, l: Node) -> None:
	r: Node = l.right
	t.left = r.right
	l.right = r.left
	r.left = l
	r.right = t
	t.b = floor((r.b + 1) / 2)
	l.b = floor((1 - r.b) / 2)
	r.b = 0
	t = r

if __name__ == "__main__":
	pass
