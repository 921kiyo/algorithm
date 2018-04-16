
servings = 0
fullPot = Semaphore(1) # maximum limit to check if full
emptyPot = Semaphore(0) # Initially the pot is empty
mutex = Semaphore(1)

def Savage(): # Consumer
    while(true):
            mutex.wait()
                if servings == 0:
                    fullPot.wait()
                    emptyPot.signal()
                    servings = M
            mutex.wait()
                getServingFromPot()
                servings-=1
            mutex.signal()
            fullPot.signal()

def Cooker(): # Producer
    while(true):
        mutex.wait()
            putServingsInPot()
            servings+=1
        mutex.signal()
        emptyPot.signal()
