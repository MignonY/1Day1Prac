def trans(ls):
    prior = {'*':3, '/':3, '+':2, '-':2, '(':1}
    stack = []
    temp = []
    for i in range(len(ls)):
        if ls[i].isalpha():
            temp.append(ls[i])
        elif ls[i] == '(':
            stack.append(ls[i])
        elif ls[i] == ')':
            while stack[-1] !='(':   #이떄 ifstack 안해도됨 괄호짝무조건있음
                temp.append(stack.pop())
            stack.pop()
        else:
            while stack and prior[ls[i]] <= prior[stack[-1]]:
                temp.append(stack.pop())
            stack.append(ls[i])

    while stack:
        temp.append(stack.pop())
    return temp

charr = list(input())
print("".join(trans(charr)))