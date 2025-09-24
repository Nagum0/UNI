from typing import *

class Node:
    def __init__(self, key: Any) -> None:
        self.left: Node = None
        self.right: Node = None
        self.key = key

    def process(self) -> None:
        print(self.key)

    def inorder(self) -> None:
        if self.left is not None:
            self.left.inorder()

        self.process()

        if self.right is not None:
            self.right.inorder()

    def preorder(self) -> None:
        self.process()

        if self.left:
            self.left.preorder()

        if self.right:
            self.right.preorder()

    def postorder(self) -> None:
        if self.left:
            self.left.preorder()

        if self.right:
            self.right.preorder()

        self.process()

    def level_order(self) -> None:
        q: List[Node] = [self]

        while len(q) != 0:
            s: Node = q.pop(0)
            s.process()

            if s.left:
                q.append(s.left)
            
            if s.right:
                q.append(s.right)

    def h(self) -> int:
        if self.left and self.right:
            return 1 + max(self.left.h(), self.right.h())
        elif self.left:
            return 1 + self.left.h()
        elif self.right:
            return 1 + self.right.h()
        else:
            return 1

    @staticmethod
    def preorder_t(t: 'Node') -> None:
        while t:
            t.process()

            if t.left:
                Node.preorder_t(t.left)
            
            if t.right:
                t = t.right
            else:
                return

    def max(self) -> int:
        if self is None:
            return -1
        
        m: int = self.key
        lm: int = self.left.max()
        rm: int = self.right.max()

        if lm > m:
            return lm
        elif rm > m:
            return rm
        else:
            return m

    
if __name__ == "__main__":
    root: Node = Node(10)
    l1: Node = Node(20)
    r1: Node = Node(30)
    root.left = l1
    root.right = r1
    l1.left = Node(40)
    print(f"Height: {root.h()}")
    Node.preorder_t(root)
    print(root.max())