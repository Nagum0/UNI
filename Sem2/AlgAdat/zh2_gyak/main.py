from Node import Node

def bfs(root: Node):
    if root is None:
        raise Exception("Empty tree...")
    
    que = []
    que.append(root)

    while que:
        node = que.pop(0)
        print(node.key, end=" ")
        
        if node.left is not None:
            que.append(node.left)

        if node.right is not None:
            que.append(node.right)

    print()

def in_order(root: Node):
    if root.left is not None:
        in_order(root.left)
    
    print(root.key, end=" ")

    if root.right is not None:
        in_order(root.right)

def is_max_heap(root: Node):
    def inf_on_null(node: Node):
        if node is not None:
            return node.key
        else:
            return -1

    if root is None:
        return True
    
    return is_max_heap(root.left) and is_max_heap(root.right) and root.key >= inf_on_null(root.left) and root.key >= inf_on_null(root.right) 

def max_in_tree(root: Node):
    if root is None:
        raise Exception("Empty tree...")
    
    max = root.key
    que = []
    que.append(root)

    while que:
        current_node = que.pop(0)
        
        if current_node.key >= max:
            max = current_node.key

        if current_node.left is not None:
            que.append(current_node.left)

        if current_node.right is not None:
            que.append(current_node.right)

    return max

def one_child_count(root: Node):
    if root is None:
        return

    que = [root]
    count = 0

    while que:
        curr_node = que.pop(0)

        if (curr_node.left is not None and curr_node.right is None) or (curr_node.left is None and curr_node.right is not None):
            count += 1

        if curr_node.left is not None:
            que.append(curr_node.left)
        
        if curr_node.right is not None:
            que.append(curr_node.right)

    return count

def h(node: Node) -> int:
    if node is None:
        return 0
    
    return max(h(node.left), h(node.right)) + 1

def is_stable(root: Node) -> bool:
    if root is None:
        return True
    
    return h(root.left) - h(root.right) <= 1

def how_many_odds(root: Node) -> int:
    if root is None:
        return count

    que = [root]
    count = 0

    while que:
        node = que.pop(0)

        if node.key % 2 != 0:
            count += 1
        
        if node.left is not None:
            que.append(node.left)

        if node.right is not None:
            que.append(node.right)

    return count

def level_count(root: Node) -> int:
    if root is None:
        return -1
    
    return level_count(root.left) + 1

""" 
       6
      / \
     5   3
    / \   \
   69  2   1
  /
 25 
"""
root = Node(
    6, 
    Node(
        5, 
        Node(
            69,
            Node(
                25,
                None,
                None
            ),
            None
        ),
        Node(
            2,
            None,
            None
        )
    ), 
    Node(
        3,
        Node(
            1,
            None,
            None
        ),
        None
    )
)

bfs(root)
in_order(root)
print()
print(is_max_heap(root))
print(max_in_tree(root))
print(one_child_count(root))
print(h(root))
print(is_stable(root))
print(how_many_odds(root))
print(level_count(root))