def palindrome_perm(string):
    # Make it lowercase first
    # string = string.lower()
    table = [0 for _ in range(ord('z')-ord('a')+1)]

    count_odd = 0
    for c in string:
        x = char_number(c)

        if x != -1:
            table[x] += 1
            if table[x] % 2:
                count_odd += 1
            else:
                count_odd -= 1

    return count_odd <= 1


def char_number(c):
    a = ord('a')
    z = ord('z')
    A = ord('A')
    Z = ord('Z')

    val = ord(c)

    if a <= val <= z:
        return val - a

    if A <= val <= Z:
        return val - A
    return - 1


print(palindrome_perm("Tact Coa"))
