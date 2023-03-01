N,M,T = map(int, input().split())
arr = [list(map(int,input().split())) for _ in range(N)]
cal = [[0]*M for _ in range(N)]

def diffusion():
    # calarr 초기화
    for i in range(N):
        for j in range(M):
            cal[i][j] = 0

    for i in range(N):
        for j in range(M):
            if arr[i][j] == -1:
                continue
            amount = arr[i][j] // 5
            if amount == 0:
                continue
            else:
                for dy,dx in ((-1,0),(1,0),(0,-1),(0,1)):
                    ny = i + dy
                    nx = j + dx
                    if 0<= ny < N and  0<= nx <M and arr[ny][nx] != -1:
                        cal[i][j] -= amount
                        cal[ny][nx] += amount
    # 확산계산
    for i in range(N):
        for j in range(M):
            if arr[i][j] != -1:
                arr[i][j] += cal[i][j]

def circulate(Y1,X1,Y2,X2):
    #up
    y = Y1-1
    x = X1
    while y > 0:
        arr[y][x] = arr[y-1][x]
        y -= 1
    while x < M-1:
        arr[y][x] = arr[y][x+1]
        x += 1
    while y < Y1:
        arr[y][x] = arr[y+1][x]
        y += 1
    while x > X1:
        arr[y][x] = arr[y][x-1]
        x -=1
    arr[y][x+1] = 0

    #down
    y = Y2+1
    x = X2
    while y < N-1:
        arr[y][x] = arr[y+1][x]
        y += 1
    while x < M-1:
        arr[y][x] = arr[y][x+1]
        x += 1
    while y > Y2:
        arr[y][x] = arr[y-1][x]
        y -= 1
    while x > X2:
        arr[y][x] = arr[y][x-1]
        x -=1
    arr[y][x+1] = 0





# 공청기위치
Y1 = 0 ; X1 = 0; Y2 = 0; X2 = 0
for i in range(N):
    for j in range(M):
        if arr[i][j] == -1:
            Y2 = i
Y1 = Y2 - 1


while T:
    diffusion()
    circulate(Y1,X1,Y2,X2)
    T -= 1


ans = 0
for i in range(N):
    for j in range(M):
        if arr[i][j] != -1:
            ans += arr[i][j]

print(ans)