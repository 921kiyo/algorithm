def triple_step(x):
    if x < 0:
        return 0
    if x == 0:
        return 1
    if x == 1:
        return 1
    return triple_step(x-1) + triple_step(x-2) + triple_step(x-3)

def method2(x):
    memo = [-1]*(x+1)
    return triple_step2(x, memo)

def triple_step2(x, memo):
    if x < 0:
        return 0
    memo[0] = 1

    if x >= 1:
        memo[1] = 1
    if x >= 2:
        memo[2] = memo[1] + memo [0]
    if x > 2:
        for i in range(3, x + 1):
            memo[i] = memo[i-1] + memo[i-2] + memo[i-3]

    print(memo)
    return memo[x]

print(method2(1))
print(method2(2))
print(method2(3))
print(method2(4))
print(method2(5))
print(method2(6))
