
def init():
    Emutex = Semaphore(1)
    Wmutex = Semaphore(1)
    e_baboon = 0
    w_baboon = 0
    bridge_free = Semaphore(1)

def Earrive():
    Emutex.down()
    e_baboon += 1
    if(e_baboon == 1):
        bridge_free.down()
    Emutex.up()

def Edepart():
    Emutex.down()
    e_baboon -= 1
    if(e_baboon == 0):
        bridge_free.up()
    Emutex.up()


def Warrive():
    Wmutex.down()
    w_baboon += 1
    if(w_baboon == 1):
        bridge_free.down()
    Wmutex.up()

def Edepart():
    Emutex.down()
    w_baboon -= 1
    if(w_baboon == 0):
        bridge_free.up()
    Emutex.up()
