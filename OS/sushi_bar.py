def init():
    eating = waiting = 0
    mutex = Semaphore(1)
    block = Semaphore(0)
    must_wait = False # the bar is full


def Sushi():
    mutex.wait()
    if must_wait:
        waiting += 1
        mutex.signal()
        block.wait()
    else:
        eating += 1
        must_wait = (eating == 5)
        mutex.signal()

    # Eat sushi

    mutex.wait()
    eating -= 1
    if eating == 0:
        n = min(5, waiting)
        waiting -= n
        eating += n
        must_wait = (eating == 5)
        block.signal()
    mutex.signal()
