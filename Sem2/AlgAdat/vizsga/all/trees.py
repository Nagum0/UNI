from typing import *

class Node:
    def __init__(self, key: Any = None) -> None:
        self.left: 'Node' = None
        self.right: 'Node' = None
        self.key: Any = key

    def __str__(self) -> str:
        if self.left and self.right:
            return f"({self.left.key}) {self.key} ({self.right.key})"
        elif self.left:
            return f"({self.left.key}) {self.key} ()"
        elif self.right:
            return f"() {self.key} ({self.right.key})"
        else:
            return f"() {self.key} ()"

def h(t: Node) -> int:
    if t.left and t.right:
        return 1 + max(h(t.left), h(t.right))
    elif t.left:
        return 1 + h(t.left)
    elif t.right:
        return 1 + h(t.right)
    else:
        return 0

def inorder(t: Node) -> None:
    if t.left:
        inorder(t.left)
    print(t.key)
    if t.right:
        inorder(t.right)

def preorder(t: Node) -> None:
    print(t.key)
    if t.left:
        preorder(t.left)
    if t.right:
        preorder(t.right)

def postorder(t: Node) -> None:
    if t.left:
        preorder(t.left)
    if t.right:
        preorder(t.right)
    print(t.key)

def levelOrder(t: Node) -> None:
    if t is not None:
        q: List[Node] = [t]

        while len(q) != 0:
            s: Node = q.pop(0)
            print(s.key)
            if s.left:
                q.append(s.left)
            if s.right:
                q.append(s.right)
    else:
        return

def preorder_h(t: Node, level: int, max: int) -> None:
    while t is not None:
        level += 1

        if level > max:
            max = level
        
        preorder_h(t.left, level, max)
        t = t.right

def h2(t: Node) -> int:
    level, max = -1
    preorder_h(t, level, max)
    return max

def search(t: Node, k: Any) -> Node:
    while t is not None and t.key != k:
        if k < t.key:
            t = t.left
        else:
            t = t.right
    return t

def insert(t: Node, k: Any) -> None:
    if t is None:
        t = Node(k)
    else:
        if t.key > k:
            insert(t.left, k)
        elif t.key < k:
            insert(t.right, k)
        elif t.key == k:
            return

def min(t: Node) -> Node:
    while t.left is not None:
        t = t.left
    
    return t

if __name__ == "__main__":
    root: Node = Node(10)
    root.left = Node(5)
    root.right = Node(30)

    k: Node = search(root, 10)
    print(k)
    print(min(root))