import sys
N = int(sys.stdin.readline())
ls = [sys.stdin.readline().strip().split() for _ in range(N)]

ls.sort(key=lambda x: int(x[0]))

for i in range(len(ls)):
    print(ls[i][0], ls[i][1])