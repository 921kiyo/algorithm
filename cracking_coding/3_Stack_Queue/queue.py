class Queue():
    def __init__(self):
        self.queue = list()

    def enqueue(self, x):
        self.queue.insert(0,x)

    def dequeue(self):
        if len(self.queue) > 0:
            return self.queue.pop()
        return ("Queue is empty")

TheQueue = Queue()
TheQueue.enqueue("Mon")
TheQueue.enqueue("Tue")
TheQueue.enqueue("Wed")
print(TheQueue.dequeue())
print(TheQueue.dequeue())
