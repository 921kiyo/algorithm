def binarySearch(array, l,r, t):
    if(l >= r):
        return False
    m = (l+r)//2
    if(t == array[m]):
        return m
    elif(array[m] < t):
        return binarySearch(array, m+1, r, t)
    else:
        return binarySearch(array, l, m, t)

# Test array
arr = [ 2, 3, 4, 10, 40 ]
x = 10

# Function call
result = binarySearch(arr, 0, len(arr)-1, x)

if result != -1:
    print ("Element is present at index", result)
else:
    print ("Element is not present in array")
