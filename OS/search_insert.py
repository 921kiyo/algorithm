def init():
    insertMutex = Semaphore(1) # ensure only one inserter in cs at a time
    noSeacher = Semaphore(1)
    noInserter = Semaphore(1)
    searchSwitch = LightSwitch()
    insertSwitch = LightSwich()

def searcher():
    searchSwitch.wait(noSeacher)
    # CS
    searchSwitch.signal(noSeacher)


def inserter():
    noInserter.wait(noInserter)
    insertMutex.wait()
    # CS
    insertMutex.signal()
    noInserter.signal(noInserter)

def deleter():
    noSeacher.wait()
    noInserter.wait()
    # CS
    noSeacher.signal()
    noInserter.signal()
