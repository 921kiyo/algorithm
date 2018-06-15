class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def show(self):
        print(self.data)

class LinkedList:
    def __init__(self):
        self.head = None

    def show(self):
        temp = self.head
        while(temp):
            temp.show()
            temp = temp.next

    def push(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def append(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return

        last = self.head
        while(last.next):
            last = last.next

        last.next = new_node

    def insertAfter(self, prev_node, new_data):
        if prev_node is None:
            print("prev_node is NULL")
            return

        new_node = Node(new_data)

        new_node.next = prev_node.next
        prev_node.next = new_node

    def delete(self, key):
        temp = self.head
        prev = None

        while(temp is not None):
            if temp.data == key:
                break
            prev = temp
            temp = temp.next

        if(temp == None):
            return

        if prev is not None:
            prev.next = temp.next
        else:
            temp = self.head
            self.head = temp.next


        temp = None

if __name__ == "__main__":

    llist = LinkedList()

    llist.head = Node(1)
    llist.push(2)
    llist.push(3)
    llist.append(0)
    llist.insertAfter(llist.head.next, 8)
    llist.show()
    llist.delete(8)
    print("after")
    llist.show()
