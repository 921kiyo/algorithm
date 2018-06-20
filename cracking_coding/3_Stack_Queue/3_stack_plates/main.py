class Stack():
    def __init__(self, limit):
        self.top = 0
        self.stack = []
        self.limit = limit

    def pop(self):
        if self.top == 0:
            print("Stack underflow")
        temp = self.stack[top]
        top -= 1
        return temp

    def push(self, x):
        if self.top >= self.limit:
            print("Stack overflow")

        self.stack.append(x)
        self.top += 1

        return True
    def isEmpty():
        return len(self.stack) == 0

class SetOfStacks():

stacks = SetOfStacks(4)
stacks.push(1)
stacks.push(2)
stacks.push(3)
stacks.push(4)
stacks.push(5)
