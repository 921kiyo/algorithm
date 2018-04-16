mutex = Semaphore(1)
int readers = 0
roomEmpty = Semaphore(1)

def Reader():
    mutex.wait()
        readers +=1
        if readers == 1:
            roomEmpty.wait()
    mutex.signal()

     # Critical section
    mutex.wait()
        readers -= 1
        if readers == 0:
            roomEmpty.signal()
    mutex.signal()


def Writer():
    roomEmpty.wait()
     # Critical section
    roomEmpty.signal()


# Above code starve the writer.

mutex = Semaphore(1)
int readers = 0
roomEmpty = Semaphore(1)
turnstile = Semaphore(1)

def Reader():
    turnstile.wait()
    turnstile.signal()
    mutex.wait()
        readers +=1
        if readers == 1:
            roomEmpty.wait()
    mutex.signal()

     # Critical section
    mutex.wait()
        readers -= 1
        if readers == 0:
            roomEmpty.signal()
    mutex.signal()


def Writer():
    turnstile.wait()
        writer.wait()
            roomEmpty.wait()
             # Critical section
    turnstile.signal()
            roomEmpty.signal()
