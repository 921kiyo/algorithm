def init():
    reindeer = 0
    elves = 0
    santaSem = Semaphore(0)
    reindeerSem = Semaphore(0)
    elfTex = Semaphore(1)
    mutex = Semaphore(1)

def santa():
    mutex.wait()
    if reindeer >= 9:
        prepareSleigh()
        reindeerSem.signal(9) # signal reindeerSem 9 times to allow the reindeer to invoke getHitched
        reindeer -=9
    else if elves == 3:
        helpElves()
    santaSem.wait()

def Elves():
    elfTex.wait()
    mutex.wait()
        elves += 1
        if elves == 3: # the last elf holds elfTex, barring other elves from entering until all three elves have invoked getHelp
            santaSem.signal()
        else:
            elfTex.signal()
    mutex.singal()

    getHelp()

    mutex.wait()
        elves -= 1
        if elves == 0:
            elfTex.signal()
    mutex.signal()


def Reindeer():
    mutex.wait()
    reindeer+= 1
    if reindeer == 9: # 9th reindder signals Santa
        santaSem.signal()
    mutex.singal()

    reindeerSem.wait()
    getHitched()
