def partition(arr, low, high):
    i = low - 1
    pivot = arr[high]

    for j in range(low, high):
        
        if arr[j] <= pivot:
            i += 1
            arr[j], arr[i] = arr[i], arr[j]
    arr[high], arr[i+1] = arr[i+1], arr[high]
    return i+1
    
def quicksort(arr, low, high):
    if (low < high):
        pi = partition(arr, low, high)
        quicksort(arr, low, pi-1)
        quicksort(arr, pi+1, high)

def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m

    L = [0]*n1
    R = [0]*n2

    for i in range(0, n1):
        L[i] = arr[l+i]
    
    for j in range(0, n2):
        R[j] = arr[m+1+j]

    i = 0
    j = 0
    k = l

    while i < n1:
        arr[k] = L[i]
        i+= 1
        k+= 1

def mergeSort(arr, l, r):
    if l < r:
        m = (l+(r-1))/2
        mergeSort(arr, l, m)
        mergeSort(arr, m+1, r)
        merge(arr, l, m, r)