def any_subarray(array):
    # max = array[len(array)-1]
    # s = array[len(array)-1]
    #
    # for i in range(len(array)-2, -1, -1):

    # LOOP FORWARD
    # max = array[0]
    # s = array[0]
    #
    # for i in range(1, len(array)):
        if s > 0:
            s = s + array[i]
        else:
            s = array[i]

        if s > max:
            max = s
    return max

array = [1,2,3,4,6,-100,9,5]
print(any_subarray(array))
