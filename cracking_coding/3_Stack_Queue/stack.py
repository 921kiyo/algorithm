from sys import maxsize
class Stack():
    def __init__(self, limit):
        self.top = 0
        self.stack = []

    def push(self, x):
        self.stack.append(x)
        self.top += 1
        return True

    def pop(self):
        if(self.isEmpty()):
            return str(-maxsize - 1) # return negative infinity

        return self.stack.pop()

    def isEmpty(self):
        return len(self.stack) == 0

s = Stack(10)
s.push(10)
s.push(20)
s.push(30)

print(s.pop())
print(s.pop())
