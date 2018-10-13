# def triple_step(n):
#     memo = [-1]*(n+1)
#     return recursive(n, memo)
#
# def recursive(n, memo):
#     if(n < 0):
#         return 0
#     memo[0] = 1
#
#     if(n == 0):
#         return 1
#     return recursive(n-1) + recursive(n-2) + recursive(n-3)
#
# print(triple_step(3))

def foo(a,b):
    x = a
    y = b
    while(x!=y):
        if(x>y):
            x = x-y
        if(x<y):
            y = y-x

    return x,y

result1, result2 = foo(2437,875)

print(result1)
print(result2)
