import math

def crossoff(flags, prime):
    for i in range(prime*prime, len(flags), prime):
        flags[i] = False

def get_next_prime(flags, prime):
    next = prime + 1
    while next < len(flags) and not flags[next]:
        next += 1
    return next

# all non-prime numbers are divisible by a prime number
def prime_list(length):
    flags = [True]*length
    prime = 2
    flags[0] = False
    flags[1] = False
    while prime <= math.sqrt(length):
        crossoff(flags, prime)
        prime = get_next_prime(flags, prime)
    return flags

def check_prime(x):
    if x < 2:
        return False
    sq = int(math.sqrt(x))
    for i in range(2,sq):
        if x % i == 0:
            return False
    return True

# greatest common divisor
def gcd(x,y):
    pass

# least common multiple
def lcm(x,y):
    pass

print(check_prime(11))
print(check_prime(12))

print(prime_list(12))
