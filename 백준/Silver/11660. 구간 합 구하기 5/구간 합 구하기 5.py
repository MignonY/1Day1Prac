import sys
N, M = map(int, sys.stdin.readline().split())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]




pfx = [[0] * (N+1) for _ in range(N+1)]

for i in range(1,N+1):
    for j in range(1,N+1):
        pfx[i][j] = pfx[i][j-1] + pfx[i-1][j] - pfx[i-1][j-1] + arr[i-1][j-1]

for k in range(M):
    A, B, C, D = map(int, sys.stdin.readline().split())
    ans = pfx[C][D] - pfx[C][B-1] - pfx[A-1][D] + pfx[A-1][B-1]

    print(ans)