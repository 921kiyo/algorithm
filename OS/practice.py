def init():
    isTobacco = isPaper = isMatch = False
    tobaccoSem = Semaphore(0)
    paperSem = Semaphore(0)
    matchSem = Semaphore(0)

def pusherA():
    tobacco.wait()
    mutex.wait()
        if isPaper:
            isPaper = False
            matchSem.signal()
        elif isMatch:
            isMatch = False
            paperSem.signal()
        else
            isTobacco = True
    tobacco.signal()

def tobacco():
    if(isTobacco)
    tobaccoSem.signal()
