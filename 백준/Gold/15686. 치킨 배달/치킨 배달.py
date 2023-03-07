N, M = map(int,input().split())
arr = [list(map(int,input().split()))for _ in range(N)]
queue = [0 for _ in range(10000)]
visit = [[0]*N for _ in range(N)]

# def BFS(arr,y,x):
#     global visit
#     for i in range(N):
#         for j in range(N):
#             visit[i][j] = 0
#     rear = -1
#     front = 0
#     dis = 0
#     rear += 1
#     queue[rear] = (y,x,dis)
#     visit[y][x] = 1
#     sumd = []
#     while rear +1 != front:
#         y, x, dis = queue[front]
#         front += 1
#         if arr[y][x] == 2:
#             sumd.append(dis)
#             sumd.sort()
#             break
#
#         # if sumd and dis>sumd[0]:
#         #     break
#         for dy, dx in ((-1,0),(1,0),(0,-1),(0,1)):
#             ny = y + dy
#             nx = x + dx
#             if 0<=nx<N and 0<=ny<N and visit[ny][nx] == 0:
#                 rear += 1
#                 queue[rear] = (ny,nx,dis+1)
#                 visit[ny][nx] = visit[y][x] +1
#     return sumd[0]


house = []
chick = []
for i in range(N):
    for j in range(N):
        if arr[i][j] == 2:
            chick.append([i, j])
            arr[i][j] = 0
        if arr[i][j] == 1:
            house.append([i, j])

arr_ori = list(map(list,arr))

ls = [i for i in range(len(chick))]
temp = []
fans = 100000
def Combi(cnt, depth,begin):
    global fans
    if cnt == depth:
        chick_fin = []

        for i in range(len(temp)):
            chick_fin.append(chick[temp[i]])

        mans = 0
        for j in range(len(house)):
            savea = 100
            for k in range(len(chick_fin)):
                ans = abs(house[j][0]-chick_fin[k][0]) + abs(house[j][1]-chick_fin[k][1])
                savea = min(savea, ans)
            mans += savea

        fans = min(mans,fans)
        return
    for idx in range(begin, len(ls)):
        temp.append(ls[idx])
        Combi(cnt+1, depth, idx+1)
        temp.pop()

Combi(0,M,0)

print(fans)