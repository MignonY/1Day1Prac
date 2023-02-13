import sys
input = sys.stdin.readline

N = int(input())
for i in range(N):
    stack = []
    ls = input()
    Flag = True
    for l in ls:
        if l == '(':
            stack.append('(')
        elif l == ')':
            if stack:
                stack.pop()
            else:
                Flag = False
                break
 
    if stack:
        Flag = False

    if Flag:
        print("YES")
    else:
        print("NO")