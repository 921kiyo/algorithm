class Stack(object):
    
    def __init__(self):
        """Initialize an empty stack"""
        self.items = []

    def push(self, item):
        """Push new item to stack"""
        self.items.append(item)

    def pop(self):
        """Remove and return last item"""
        # If the stack is empty, return None
        # (it would also be reasonable to throw an exception)
        if not self.items:
            return None

        return self.items.pop()

    def peek(self):
        """See what the last item is"""
        if not self.items:
            return None
        return self.items[-1]

class MaxStack(Stack):
    def __init__(self):
        super().__init__()
        self.max_int = None
        self.max_stack = []
        self.pointer = -1   
    
    def push(self, item):
        if self.max_int == None or self.max_int < item:
            self.max_int = item
            self.max_stack.append(item)
            self.pointer += 1

        super().push(item)

    def pop(self):
        
        popping = super().pop()

        if not popping:
            return None
        print("max stack ", self.max_stack)        

        if popping == self.max_int:
            self.max_stack.pop()
            self.pointer -= 1
            self.max_int = self.max_stack[self.pointer]

        return popping

    def get_max(self):
        return self.max_int

if __name__ == "__main__":
    max_stack = MaxStack()
    max_stack.push(1)
    max_stack.push(2)
    max_stack.push(3)
    max_stack.push(4)
    max_stack.pop()
    max_stack.pop()
    max_stack.pop()
    print(max_stack.get_max())