def init():
    riders = 0
    mutex = semaphore)(1)
    multi = sem(50)
    bus = sem(0)
    allaboard = sem(0)

def bus():
    mutex.wait()
    if riders > 0:
        bus.signal()
        allaboard.wait()
    mutex.signal()
    depart()

def riders():
    multi.wait()
    mutex.wait()
    riders += 1
    mutex.signal()
    bus.wait()

    multi.signal()

    boardBus()
    riders -= 1
    if riders == 0:
        allaboard.signal()
    else:
        bus.signal()
