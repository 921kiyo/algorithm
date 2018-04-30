def init():
    riders = 0
    multiplex = Semaphore(50)
    mutex = Semaphore(1)
    bus_arrive = Semaphore(0)
    allBoard = Semaphore(0)

def rider():
    bus_arrive.wait()
    allBoard.wait()
    boardBus()

def bus():
    bus_arrive.signal()
    multiplex.wait()
    mutex.wait()
    riders += 1
    if(riders == 50):
        allBoard.signal()
    mutex.signal()
