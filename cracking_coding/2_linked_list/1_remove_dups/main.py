class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
class LinkedList:
    def __init__(self):
        self.head = None

    def push(self, new_data):
        new_node = Node(new_data)
        if self.head is None:
            self.head = new_node
            return


        temp = self.head
        self.head = new_node
        new_node.next = temp
    def show(self):
        temp = self.head
        while(temp):
            print(temp.data)
            temp = temp.next

    def remove_dups(self):

        table = dict()
        temp = self.head
        if temp == None:
            return

        while(temp != None):
            if(temp.data not in table):
                table[temp.data] = True
            else:
                self.delete(temp.data)
            temp = temp.next

    def remove_dups2(self):
        temp1 = self.head
        if temp1 == None:
            return

        temp2 = self.head.next

        while(temp1 != None):

            while(temp2 != None):
                if(temp1.data == temp2.data):
                    self.delete(temp1.data)

                temp2 = temp2.next
            temp1 = temp1.next

    def delete(self, key):
        temp = self.head
        prev = None

        while(temp is not None):
            if temp.data == key:
                break
            prev = temp
            temp = temp.next

        if(temp == None):
            print("cannot find a node to be deleted")
            return

        if prev is not None:
            prev.next = temp.next
        else:
            temp = self.head
            self.head = temp.next
        temp = None


if __name__=="__main__":
    llist = LinkedList()
    llist.push(3)
    llist.push(1)
    llist.push(2)
    llist.push(3)
    llist.remove_dups2()
    llist.show()
