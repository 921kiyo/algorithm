# My first attempt
def string_comp(original_string):
    prev = original_string[0]
    # print("prev ", prev)
    count = 1
    comp_string = ""
    for i in range(1, len(original_string)):
        # print("afd ", original_string[i])
        if prev == original_string[i] and i != len(original_string)-1:
            count += 1
        elif(prev != original_string[i] and i != len(original_string)-1):
            comp_string += prev
            comp_string += str(count)
            count = 1
        else:
            comp_string += prev
            comp_string += str(count)

        prev = original_string[i]

    for i in range(1, len(comp_string), 2):
        if(comp_string[i] != "1"):
            return comp_string
    return original_string


# This is better version
def string_comp2(string):
    compressed = []
    counter = 0

    for i in range(len(string)):
        if(i != 0 and string[i] != string[i-1]):
            compressed.append(string[i-1] + str(counter))
            counter = 0
        counter += 1

    compressed.append(string[-1] + str(counter))

    comp_string = ''.join(compressed)
    for i in range(1, len(comp_string), 2):
        if(comp_string[i] != "1"):
            return comp_string
    return string

print(string_comp2("aabcccccaaa"))
print(string_comp2("abcd"))
print(string_comp2("aabb"))
