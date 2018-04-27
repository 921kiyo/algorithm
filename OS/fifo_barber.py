def init():
    n = 4
    customers = 0
    mutex = Semaphore(1)
    customer = Semaphore(0)
    customerDone = Semaphore(0)
    barberDone = Semaphore(0)
    queue = []


def Barber():
    customer.wait()
    mutex.wait()
        sem = queue.pop(0)
    mutex.signal()

    sem.signal()

    # Cut hair

    customerDone.wait()
    barberDone.signal()


def Customer():
    self.sem = Semaphore(0)
    mutex.wait()
    if customers == n:
        mutex.signal()
        balk()
    customers += 1
    queue.append(self.sem)
    mutex.signal()

    customer.signal()
    self.sem.wait()

    # getHairCut()

    customerDone.signal()
    barberDone.wait()

    mutex.wait()
    customers -= 1
    mutex.signal()
