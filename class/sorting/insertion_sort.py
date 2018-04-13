def insertionSort(array):
    for i in range(len(array)):
        next = array[i]
        j = i
        while j > 0 and next < array[j-1]:
            array[j] = array[j-1]
            j-=1
        array[j] = next

# Driver code to test above
arr = [12, 11, 13, 5, 6]
insertionSort(arr)
print ("Sorted array is:")
for i in range(len(arr)):
    print ("%d" %arr[i])
