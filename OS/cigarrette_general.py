numTobacco = numPaper = numMatch = 0

tobaccoSem = Semaphore(0)
paperSem = Semaphore(0)
matchSem = Semaphore(0)


def pusherA():
    tobacco.wait()
    mutex.wait()
        if numPaper: # If true, it knows that Pusher B has already run
            numPaper -= 1
            match.signal()
        elif numMatch:
            numMatch -= 1
            paper.signal()
        else
            numTobacco += 1
    mutex.signal()
