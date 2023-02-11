N = int(input())

cnt = 0
i = 0
while N>=cnt:
    i += 1
    if '666' in str(i):
        cnt += 1
        if N == cnt:
            print(i)
