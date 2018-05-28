def max_prefix(array):
    total = array[0]
    max = array[0]

    for i in range(1, len(array)):
        total = total + array[i]
        if( total > max):
            max = total
    return max

array = [1,2,3,4,6,-100,9,10]
print(max_prefix(array))
