class Queue():
    def __init__(self):
        self.in_stack = []
        self.out_stack = []
        self.is_enqueue = True
    
    def enqueue(self, x):
        self.in_stack.append(x)
    
    def dequeue(self):
        if len(self.out_stack) == 0:
            while len(self.in_stack) > 0:
                x = self.in_stack.pop()
                self.out_stack.append(x)
            
            if len(self.out_stack) == 0:
                raise IndexError("cannot dequeue")

        return self.out_stack.pop()

queue = Queue()

queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
print(queue.dequeue())
print(queue.dequeue())
queue.enqueue(4)
print(queue.dequeue())
