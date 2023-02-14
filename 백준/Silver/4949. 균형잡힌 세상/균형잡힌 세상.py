dic = {'(':')', '[':']'}

while True:
    st = input()
    stack = []
    if st[0] == '.':
        break
    Flag = True
    for ch in st:
        if ch in dic:
            stack.append(dic[ch])
        elif ch in dic.values():
            if not stack or ch != stack.pop():
                Flag = False
                break


    if stack:
        Flag = False


    if Flag:
        print('yes')
    else:
        print('no')

