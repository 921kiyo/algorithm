Sem barberReady = 0
Sem accessWRSeats = 1
Semaphore custReady = 0 # of customers in the waiting room

int numberOfFreeSeats = N

def Barber(): # Consumer
    while true:
        wait(custReady)
        wait(accessWRSeats)
        numberOfFreeSeats+=1
        signal(barberReady)
        signal(accessWRSeats)
        # Start cutting hair

def Customer(): # Producer
    wait(accessWRSeats)
    if numberOfFreeSeats > 0:
        numberOfFreeSeats -=1
        signal(custReady)
        signal(accessWRSeats)
        wait(barberReady)
        # Getting hair cut
    else:
        signal(accessWRSeats)
        # Leave without a haircut
