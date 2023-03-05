
N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
visit = [[0]*N for _ in range(N)]
queue = [0 for _ in range(10000)]

def BFS(arr, y, x ,time,big):
    global eat, save
    for i in range(N):
        for j in range(N):
            visit[i][j] = 0
    rear = -1
    front = 0
    rear += 1
    dis = 0
    queue[rear] = (y, x, time,dis)
    visit[y][x] = 1
    sv = []
    while rear + 1 != front:
        y, x, time, dis = queue[front]
        front += 1
        # print(f'cur={y, x}, eat={eat}, big={big}, time = {time}, dis = {dis}')
        if arr[y][x] != 0 and arr[y][x] < big:
            sv.append([y,x,dis])
            if len(sv) >= 2:
                sv.sort(key=lambda x: (x[2], x[0], x[1]))
        if (sv and dis > sv[0][2]) or (sv and rear +1 == front):
            # print(sv)
            time += sv[0][2]
            eat = save
            eat += 1
            arr[sv[0][0]][sv[0][1]] = 0
            y = sv[0][0]
            x = sv[0][1]
            # print(f'(fin) cur={y, x}, eat={eat}, big={big}, time = {time}, dis = {dis}')
            break
        for dy, dx in ((-1, 0), (0, -1), (0, 1), (1,0)):
            ny = y + dy
            nx = x + dx
            if 0 <= ny < N and 0 <= nx < N and visit[ny][nx] == 0 and arr[ny][nx] <= big:
                rear += 1
                queue[rear] = (ny,nx,time, dis+1)
                visit[ny][nx] = 1
    return (time, y, x)

sy = 0 ; sx = 0
for i in range(N):
    for j in range(N):
        if arr[i][j] == 9:
            sy = i ; sx = j
            arr[i][j] = 0

big = 2
eat = 0
time = 0
y = sy ; x = sx

while True:
    # print(f'(BF), cur={y, x}, eat={eat}, big={big}, time = {time}')
    save = eat
    ret= BFS(arr, y, x, time, big)
    # print(visit)
    time = ret[0]; y = ret[1]; x = ret[2]
    if big == eat:
        big += 1
        eat = 0
    if save == eat:
        print(time)
        break

    # for i in range(N):
    #     print(arr[i])
    # print()