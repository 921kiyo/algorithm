def countSort(array):
    output = [0]*256
    count = [0]*256
    answer = ["" for _ in array]

    for i in array:
        count[ord(i)] += 1

    for i in range(256):
        count[i] += count[i-1]

    for i in range(len(array)):
        output[count[ord(array[i])]-1] = array[i]
        count[ord(array[i])] -= 1

    for i in range(len(array)):
        answer[i] = output[i]
    return answer    

# Driver program to test above function
arr = "geeksforgeeks"
print(len(arr))
ans = countSort(arr)
print("Sorted character array is", ans)
