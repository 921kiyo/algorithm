def quickSort(array, L, R):
    if(R < L + 2):
        return
    p = Partition(array, L, R)
    quickSort(array, L, p)
    quickSort(array, p, R)

def Partition(array, L, R):
    i=j=L
    pivot = R
    while i < pivot:
        if(array[i] < array[pivot]):
            swap(array, i, j)
            j+=1
        i+=1
        print("array", array)
    swap(array, pivot, j)

    return j
def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp

# Driver code to test above
arr = [10, 7, 8, 9, 1, 5]
n = len(arr)
quickSort(arr,0,n-1)
print ("Sorted array is:")
for i in range(n):
    print ("%d" %arr[i]),
