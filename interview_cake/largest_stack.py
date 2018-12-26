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

class MaxStack(object):
    def __init__(self):
        self.stack = Stack()
        self.max_stack = Stack()
    
    def push(self, item):
        self.stack.push(item)
        if self.max_stack.peek() is None or self.max_stack.peek() < item:
            self.max_stack.push(item)

    def pop(self):
        popping = self.stack.pop()

        if not popping:
            return None

        if popping == self.max_stack.peek():
            self.max_stack.pop()

        return popping

    def get_max(self):
        return self.max_stack.peek()

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