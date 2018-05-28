def check_perm(string1, string2):
    # O(N log N ) version
    # string1= ''.join(sorted(string1))
    # string2= ''.join(sorted(string2))
    # return string1 == string2

    # If the length is
    if len(string1) != len(string2):
        return False

    char_set =[0 for _ in range(128)]

    for i in string1:
        val = ord(i)
        char_set[val] += 1

    for i in string2:
        val = ord(i)
        if char_set[val] < 0:
            return False
        char_set[val] -= 1

    return True


print(check_perm("hello", "llohe"))
