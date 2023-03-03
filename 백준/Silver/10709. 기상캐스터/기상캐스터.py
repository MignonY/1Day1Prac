N, M = map(int, input().split())
arr = [list(input()) for _ in range(N)]

for i in range(N):
    si = -1; sj = -1
    for j in range(M):
        if arr[i][j] == 'c':
            si = i; sj = j
        if sj == -1:
            arr[i][j] = -1
        else:
            arr[i][j] = j - sj

for i in range(N):
    print(*arr[i])