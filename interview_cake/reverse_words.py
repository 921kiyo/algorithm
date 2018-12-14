def inplace_reverse(message, left_index, right_index):
    while left_index < right_index:
        message[left_index], message[right_index]= message[right_index], message[left_index]
        left_index += 1
        right_index -= 1

def reverse_words(message):
    inplace_reverse(message, 0, len(message) - 1)
    
    left_index = 0
    right_index = None
    print("reversed message, ", message)
    for i in range(len(message)):
        if message[i] == ' ':
            inplace_reverse(message, left_index, right_index)
            left_index = i+1
        right_index = i

        if i == len(message) -1:
            print("right ", right_index, left_index)
            inplace_reverse(message, left_index, right_index)

        

# all words are separated by one space

message = [ 'c', 'a', 'k', 'e', ' ',
            'p', 'o', 'u', 'n', 'd', ' ',
            's', 't', 'e', 'a', 'l' ]

reverse_words(message)
# # Prints: 'steal pound cake'
print(''.join(message))

# character = ["h","e", "l", "l", "o"]

# reverse_words(character)
# # Prints: 'steal pound cake'
# print(''.join(character))
