def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        size = len(digits)
        digits[size-1] += 1
        for i in range(size, -1):
            print(digits[i])
            if digits[i] == 10:
                digits[i] = 0
                digits[i-1] += 1
        return digits