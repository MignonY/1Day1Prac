import sys
input = sys.stdin.readline
N = int(input())
stack = []
stksv = []
maxv = 1

Flag = True
for i in range(N):
    num = int(input())
    if not stack or num > stack[-1]:
        for j in range(maxv,num+1):
                stack.append(j)
                stksv.append('+')
        if not stack:
            Flag = False
            break
        stack.pop()
        stksv.append('-')

    elif num <= stack[-1]:
        while stack[-1] > num:
            stack.pop()
            stksv.append('-')
        stack.pop()
        stksv.append('-')
        if len(stack) == 1:
            pass

    if maxv <= num:
        maxv = num+1

    # print(stack)

if Flag:
    for i in stksv:
        print(i)
else:
    print('NO')

