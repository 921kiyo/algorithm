def minProduct(a, b):
    bigger = b if a < b else a
    smaller = a if a < b else b
    return minProductHelper(smaller, bigger)

def minProductHelper(smaller, bigger):
    if smaller == 0:
        return 0
    elif smaller == 1:
        return bigger
    s = smaller >> 1
    print("smaller ", smaller)
    print("s ", s)
    halfProd = minProductHelper(s, bigger)
    if smaller % 2 == 0:
        return halfProd + halfProd
    else:
        return halfProd + halfProd + bigger

print(minProduct(4,5))
