class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.count = 0
        self.key = key

def search(root, key):
    if root is None or root.val == key:
        return root
    if root.val < key:
        return search(root.right, key)
    return search(root.left, key)

def insert(root, node):
    if root is None:
        root = node
    else:
        if root.key == node.key:
            node.count = 1 + root.count
            root == node
            print("jlkfsaj")
        if root.key < node.key:
            if root.right is None:
                root.right = node
            else:
                insert(root.right, node)
        else:
            if root.left is None:
                root.left = node
            else:
                insert(root.left, node)

def minValueNode(node):
    current = node

    while(current.left is not None):
        current = current.left
    return current

def delete(root, key):
    if root is None:
        return root

    if key < root.key:
        root.left = delete(root.left, key)
    else:

        # Node with only one child or no child
        if root.left is None:
            temp = root.right
            root = None
            return temp
        elif root.right is None:
            temp = root.left
            root = None
            return temp

        # Node with two children
        temp = minValueNode(root.right)  # get the smallest in the right subtree

        root.right = delete(root.right, temp.key)

    return root

def inorder(root):
    if root:
        inorder(root.left)
        print(root.key)
        inorder(root.right)

r = Node(50)
insert(r, Node(30))
insert(r, Node(30))
insert(r, Node(30))
insert(r, Node(20))
insert(r, Node(40))
insert(r, Node(70))
insert(r, Node(60))
insert(r, Node(80))

inorder(r)

# print("delete 20")
# root = delete(r, 20)
# inorder(r)
