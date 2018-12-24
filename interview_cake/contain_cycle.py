class LinkedListNode(object):

    def __init__(self, value):
        self.value = value
        self.next  = None

    def add(self, node):
        self.next = node

# def recursive(visited, node):
#     if node.next == None:
#         return False
#     if node.next == visited:
#         return True
#     else:
#         return recursive(visited,node.next)

def contains_cycle(node):
    slow = node
    fast = node
    while fast is not None and slow.next is not None:
        slow = slow.next
        fast = fast.next

        if fast is slow:
            return True
    return False
    # return recursive(node, node.next)

node1 = LinkedListNode(1)
node2 = LinkedListNode(2)

node1.add(node2)
node2.add(node1)

print(contains_cycle(node1))
