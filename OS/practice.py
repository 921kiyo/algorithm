def hydrogen():
    mutex.wait()
    hydrogen += 1
    if oxgen >= 1 and hydrogen >= 2:
        oxgenQueue.signal()
        oxgen -= 1
        hydroQueue.signal(2)
        hydrogen -= 2
    else:
        mutex.signal()

    oxyQueue.wait()
    hydroQueue.wait()

    bond()

    barrier.wait()
    mutex.signal()
