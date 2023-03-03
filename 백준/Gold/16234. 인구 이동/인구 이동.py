N,L,R = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(N)]
visit = [[0]*N for _ in range(N)]



def DFS(y,x):
    global saveyx
    visit[y][x] =1
    for dy, dx in ((-1,0),(1,0),(0,-1),(0,1)):
        ny = y + dy
        nx = x + dx
        if 0<= ny<N and 0<= nx < N and visit[ny][nx] == 0:
            if L <= abs(arr[ny][nx] - arr[y][x]) <= R:
                saveyx.append((ny,nx))
                visit[ny][nx] = 1
                DFS(ny,nx)


def eedong(y,x):
    global saveyx, cnt

    saveyx = [(y,x)]
    DFS(y,x)
    S = len(saveyx)
    sumv = 0
    for i in range(S):
        sumv += arr[saveyx[i][0]][saveyx[i][1]]
    for i in range(S):
        arr[saveyx[i][0]][saveyx[i][1]] = sumv // S

    # for i in range(N):
    #     print(arr[i],'d')
    # print()


cnt = 0
while True:
    Flag = True
    for i in range(N):
        for j in range(N):
            for dy, dx in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                ny = i + dy
                nx = j + dx
                if 0 <= ny < N and 0 <= nx < N and visit[i][j]==0:
                    if L <= abs(arr[ny][nx] - arr[i][j]) <= R:
                        Flag = False
                        # print(i, j, (ny, nx))
                        # for i in range(N):
                        #     print(arr[i])
                        # print()
                        eedong(i,j)
    for i in range(N):
        for j in range(N):
            visit[i][j] = 0

    if Flag:
        print(cnt)
        break
    # for i in range(N):
    #     print(arr[i])
    # print()
    cnt +=1

# print(arr)
# print(cnt)
