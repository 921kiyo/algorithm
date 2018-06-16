def check_sum(array, k):
    table = {}
    for i in array:
        pair = k - i
        if pair in table:
            return True
        table[i] = 1

    return False
array = [4,2,3,1,2,1]
# Valid case
print(check_sum(array, 7))
print(check_sum(array, 2))
# Invalid case
print(check_sum(array, 1))
print(check_sum(array, 10))
