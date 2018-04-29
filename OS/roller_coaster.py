def init():
    mutex = Semaphore(1)
    mutex2 = Semaphore(1)
    boarders = 0
    unboarders = 0
    boardQueue = Semaphore(0)
    unboardQueue = Semaphore(0)
    allAbroard = Semaphore(0)
    allAshore = Semaphore(0)

def passenger():
    boardQueue.wait() # wait for boardQueue before boarding
    board()

    mutex.wait()
        boarders += 1
        if boarders == C:
            allAboard.signal()
            boarders = 0
    mutex.signal()

    unboardQueue.wait()
    unboard()

    mutex2.wait()
    unboarders+= 1
    if unboarders == C:
        allAshore.signal()
        unboarders = 0
    mutex2.signal()

def car():
    load()
    boardQueue.signal(C) # When the car arrives, waits for the last one to signal allAboard
    allAboard.wait()

    run()

    unload()
    unboardQueue.signal(C)
    allAshore.wait()
