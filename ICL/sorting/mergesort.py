
def merge(array, L, M, R):
    n1 = M - L +1
    n2 = R - M

    left = [0]*n1
    right = [0]*n2
    for i in range(0,n1):
        left[i] = array[L+i]

    for j in range(0,n2):
        right[j] = array[M+1+j]

    i=j=0
    k=L
    while i < n1 and j < n2:
        if left[i] <= right[j]:
            array[k] = left[i]
            i += 1
        else:
            array[k] = right[j]
            j += 1
        k+=1

    while i < n1:
        array[k] = left[i]
        i+=1
        k+=1
    while j < n2:
        array[k] = right[j]
        j+=1
        k+=1


def mergeSort(array, left, right):

    if(left < right):
        middle = (left + right)//2

        mergeSort(array, left, middle)
        mergeSort(array, middle+1, right)

        merge(array, left, middle, right)

# Driver code to test above
arr = [12, 11, 13, 5, 6, 7]
n = len(arr)
print ("Given array is")
for i in range(n):
    print ("%d" %arr[i]),

mergeSort(arr,0,n-1)
print ("\n\nSorted array is")
for i in range(n):
    print ("%d" %arr[i]),
