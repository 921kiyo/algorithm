def check_parentheses(input):
    stack = []
    for i in input:
        if(i== "[" or i == "{" or i == "("):
            stack.append(i)
        if(i== "]" or i == "}" or i == ")"):
            if(not is_match(stack.pop(), i)):
                return False
    return True

def is_match(open_paren, close_paren):
    if(open_paren=="[" and close_paren=="]"):
        return True
    elif(open_paren=="{" and close_paren=="}"):
        return True
    elif(open_paren=="(" and close_paren==")"):
        return True
    else:
        return False

exp1 = "[()]\{\}{[()()]()}"
exp2 = "[(])"

print("exp1", check_parentheses(exp1))
print("exp2", check_parentheses(exp2))
