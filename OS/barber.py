def init():
    n = 4
    customers = 0 # the number of customers in the shop

    mutex = Semaphore(1)
    customer = Semaphore(0) # 0 means there is a customer
    barber = Semaphore(0)
    customerDone = Semaphore(0)
    barberDone = Semaphore(0)

def Barber():
    customer.wait()
    barber.signal()
    # cutHair()
    customerDone.wait()
    barberDone.signal()

def Customer():
    mutex.wait()
    if customer == n:
        mutex.signal()
        balk()
    customers += 1
    mutex.signal()

    customer.signal()
    barber.wait()
    # Get hair cut

    customerDone.signal()
    barberDone.wait()

    mutex.wait()
    customers -= 1
    mutex.signal()
