import sys
n = int(sys.stdin.readline())
ls= [list(map(int, sys.stdin.readline().split())) for _ in range (n)]
ls.sort(key=lambda x: (x[0], x[1]))
for i in ls:
    print(i[0], i[1])