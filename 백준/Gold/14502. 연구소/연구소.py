N, M = map(int, input().split())
arr_ori = [list(map(int, input().split())) for _ in range(N)]
visit = [[0]*M for _ in range(N)]
arr = [[0]*M for _ in range(N)]
for q in range(N):
    for w in range(M):
        arr[q][w] = arr_ori[q][w]
def DFS(arr,y,x):
    visit[y][x] = 1
    for dy,dx in ((-1,0),(1,0),(0,-1),(0,1)):
        ny = y + dy
        nx = x + dx
        if 0<=ny<N and 0<=nx<M and visit[ny][nx] != 1 and arr[ny][nx] == 0:
            visit[ny][nx] = 1
            arr[ny][nx] = 2
            DFS(arr,ny,nx)

svy = []; svx = []
for i in range(N):
    for j in range(M):
        if arr[i][j] == 2:
            svy.append(i)
            svx.append(j)

zeroy = [] ; zerox = []
for i in range(N):
    for j in range(M):
        if arr[i][j] == 0:
            zeroy.append(i)
            zerox.append(j)
ZN = len(zeroy)

ans = -10000
for i in range(ZN):
    for j in range(i+1,ZN):
        for k in range(j+1,ZN):
            # print(i,j,k)
            for q in range(N):
                for w in range(M):
                    arr[q][w] = arr_ori[q][w]
                    visit[q][w] = 0
            arr[zeroy[i]][zerox[i]] = 1
            arr[zeroy[j]][zerox[j]] = 1
            arr[zeroy[k]][zerox[k]] = 1
            for l in range(len(svy)):
                DFS(arr,svy[l],svx[l])
            cnt = 0
            for r in range(N):
                for c in range(M):
                    if arr[r][c] == 0:
                        cnt += 1
            # if cnt == 8:
            #     print(i,j,k,"?")
            ans = max(ans, cnt)

            # if i == 4 and j == 8 and k == 15:
            #     for p in range(N):
            #         print(arr[p])
            #     break


print(ans)


# for i in range(N):
#     print(arr[i])
