def init():
    mutex = Semaphore(1)
    oxgen = 0 # counter for oxgen threads
    hydrogen = 0 # counter for hydrogen threads
    barrier = Barrier(3) # three threads meet after invoking bond and allow the next set of threads to proceed.
    oxyQueue = Semaphore(0) # oxgen wait
    hydroQueue = Semaphore(0)

def oxgen():
    mutex.wait()
    oxgen += 1
    if hydrogen >= 2:
        hydroQueue.signal(2)
        hydrogen -= 2
        oxyQueue.signal()
        oxgen -= 1
    else:
        mutex.signal()

    oxyQueue.wait()
    bond()
    # after bonding, threads wait until all three threads have bonded
    barrier.wait()
    # We don't know which thread holds the mutex, but it does not matter as long as only one of them releases it. 
    mutex.signal()

def hydrogen():
    mutex.wait()
    hydrogen += 1
    if hydrogen >= 2 and oxgen >= 1:
        hydroQueue.signal(2)
        hydrogen -= 2
        oxyQueue.signal()
        oxgen -= 1
    else:
        mutex.signal()

    hydroQueue.wait()
    bond()

    barrier.wait()
