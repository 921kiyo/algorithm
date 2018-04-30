
servings = 0
fullPot = Semaphore(1) # maximum limit to check if full
emptyPot = Semaphore(0) # Initially the pot is empty
mutex = Semaphore(1)

def Student(): # Consumer
    while(true):
            mutex.wait()
                if servings == 0:
                    emptyPot.signal()
                    fullPot.wait()
                servings -=1
            mutex.signal()

def Cooker(): # Producer
    while(true):
        emptyPot.wait()
        mutex.wait()
            putServingsInPot()
            servings = M
        mutex.signal()
        fullPot.signal()
