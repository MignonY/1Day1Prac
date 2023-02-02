import sys
N = int(sys.stdin.readline())
ls = [int(sys.stdin.readline()) for _ in range(N)]

ls.sort()

for i in range(N):
    print(ls[i])