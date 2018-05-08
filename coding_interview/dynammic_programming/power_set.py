def power_set(array):
    length = len(array)
    length = length - 1
    if(length <= 2):

    new_array = [0]*(length - 1)

    for i in range(length - 1):
        new_array[i] = array[i]

    power_set(new_array)




array = [1,2,3]
power_set(array)
