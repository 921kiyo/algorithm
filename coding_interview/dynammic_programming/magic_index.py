def magic_index(array, min, max):
    if(min > max):
        return -1
    middle = (max + min)/2
    if(middle == array[middle]):
        return middle
    if(array[middle] < middle):
        return magic_index(array, middle+1, max)

    if(array[middle] > middle ):
        return magic_index(array, min, middle-1)


array1 = [-23, -4, 0, 2, 19, 56, 100, 120]
print(magic_index(array1, 0, len(array1)-1))
