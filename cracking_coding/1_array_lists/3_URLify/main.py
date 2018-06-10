def urlify(string, length):
    string = list(string)
    count = 0
    for i in string:
        if i == ' ':
            count += 1

    new_length = len(string) + count*2
    for i in reversed(range(length)):
        if string[i] == ' ':
            # Replace spaces
            string[new_length - 3:new_length] = '%20'
            new_length -= 3
        else:
            # Move characters
            string[new_length - 1] = string[i]
            new_length -= 1

    output=''.join(string)
    return output

foo ="Mr John Smith  "
print(urlify(foo, len(foo)))
