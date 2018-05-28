def is_unique(string):
    if len(string) > 128:
        return False

    char_set = [False for _ in range(128)]

    for i in string:
        val = ord(i)

        if char_set[val]:
            return False
        char_set[val] = True
    return True
