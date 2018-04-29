
def init():
    mutex = Semaphore(1)
    barrier = Semaphore(4)
    hackers = 0
    serfs = 0
    hackerQueue = Semaphore(0)
    serfQueue = Semaphore(0)
    local isCaptain = False # indicate which thread should invoke row

def hackers():
    mutex.wait()
    hackers += 1
    if(hackers == 4):
        hackerQueue.signal(4)
        hackers = 0
        isCaptain = True
    elif hackers == 2 and serfs >= 2:
        hackerQueue.signal(2)
        serfQueue.signal(2)
        serfs -= 2
        hackers = 0
        isCaptain = True
        # Hold the mutex to bar additional threads until the boat has sailed.
    else:
        mutex.signal() # captain keeps the mutex

    hackerQueue.wait()

    board()
    barrier.wait() # Keeps track of how many threads have boarded.

    if isCaptain:
        rowBoart()
        mutex.signal()
