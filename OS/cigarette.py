# 4 threads: an agent and 3 smokers.
agentSem = Semaphore(1)
tobacco = Semaphore(0)
match = Semaphore(0)
paper = Semaphore(0)

isTobacco = isPaper = isMatch = False

# def tobacco_maker():
#     repeat:
#         if(isPaper and isMatch):
#             paper.wait()
#             match.wait()
#             # smoke
#             agentSem.signal()
#
#
# def match_maker():
#     repeat:
#         if(isPaper and isTobacco):
#             paper.wait()
#             tobacco.wait()
#             # smoke
#             agentSem.signal()
#
# def paper_maker():
#     repeat:
#         if(isTobacco and isMatch):
#             tobacco.wait()
#             match.wait()
#             # smoke
#             agentSem.signal()

def tobacco_maker():
    repeat:
        tobacco.wait()
        makeCigarrette()
        agentSem.signal()
        smoke()

def pusherA(): # wakes up anytime there is tobacco on the table
    tobacco.wait()
    mutex.wait()
        if isPaper: # If true, it knows that Pusher B has already run
            isPaper = False
            match.signal()
        elif isMatch:
            isMatch = False
            paper.signal()
        else
            isTobacco = True
    mutex.signal()

def pusherB(): # wakes up anytime there is tobacco on the table
    paper.wait()
    mutex.wait()
        if isTobacco: # If true, it knows that Pusher A has already run
            isTobacco = False
            match.signal()
        elif isMatch:
            isMatch = False
            tobacco.signal()
        else
            isPaper = True
    mutex.signal()
