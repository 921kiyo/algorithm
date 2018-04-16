# 1 Infinite buffer producer-consumer
# 2 Finite buffer producer-consumer

mutex = Semaphore(1)
items = Semaphore(0) # number of items in the buffer
spaces = Semaphore(buffer_size)
local event


def Producer():
    while true:
        event = waitForEvent()
        wait(spaces)
        wait(mutex)
        buffer.add(event)
        signal(mutex)
        signal(items)

def Consumer():
    while true:
        wait(items) # If items is zero or negative, the consumer blocks until a producer signals
        wait(mutex)
        event = buffer.get()
        signal(mutex)
        signal(spaces)
        event.process()
