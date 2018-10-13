def is_anagram(input1, input2):
    char_set = [0 for _ in range(256)]
    for i in input1:
        val = ord(i)
        char_set[val] += 1
    for i in input2:
        val = ord(i)
        char_set[val] -= 1
        if char_set[val] < 0:
            return False
    for i in char_set:
        if i != 0:
            return False
    return True

def is_palindrome(input):
    char_set = [False for _ in range(128)]
    for i in input:
        val = ord(i.lower())
        if(val >= ord("a") and val <= ord("z")):
            if char_set[val] == False:
                char_set[val] = True
            else:
                char_set[val] = False
    odd_count = 0
    for i in char_set:
        if(i == True):
            odd_count += 1

    return odd_count == 1

exm1 = "algorithms"
exm2 = "logarithms"

# print(is_anagram(exm1, exm2))
print(is_palindrome("tact coa"))
