M = int(input())
arr = [[0]*105 for _ in range(105)]
N = len(arr)


for _ in range(M):
    X,Y = map(int,input().split())
    for i in range(Y,10+Y):
        for j in range(X,10+X):
            arr[i][j] = 1

cnt = 0
for i in range(N):
    for j in range(N):
        if arr[i][j] == 1:
            for dx, dy in ((-1,0),(1,0),(0,-1),(0,1)):
                ny = i + dy
                nx = j + dx
                if 0<=ny<N and 0<=nx<N and arr[ny][nx] == 0:
                    cnt += 1

print(cnt)
