def init():
    empty = Semaphore(1)
    maleSwitch= LightSwitch()
    femaleSwitch= LightSwitch()
    maleMultiplex = Semaphore(3)
    femaleMultiplex = Semaphore(3)
    turnstile = Semaphore(1)

def male():
    turnstile.wait()
        maleSwitch.lock(empty)
    turnstile.signal()
        maleMultiplex.wait()
        # Bath room
        maleMultiplex.signal()
    maleSwitch.unlock(empty)

def female():
    femaleSwitch.lock(empty)
    femaleMultiplex.wait()
        # bath room
    femaleMultiplex.signal()
    femaleSwitch.unlock(empty)
