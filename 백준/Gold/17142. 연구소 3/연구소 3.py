N, M = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(N)]
acopy = list(map(list,arr))
visit = [[0]*N for _ in range(N)]
queue = [0 for _ in range(10000)]

def BFS(arr,temp,depth,zcnt):
    global yls, xls
    rear = -1
    front = 0
    depth = 0
    for i in range(len(temp)):
        rear +=1
        queue[rear] = (yls[temp[i]], xls[temp[i]], depth)
        visit[yls[temp[i]]][xls[temp[i]]] = 1
    while rear + 1 != front:
        (y,x,depth) = queue[front]
        # print(queue)
        front += 1

        for dy,dx in ((-1,0),(1,0),(0,-1),(0,1)):
            ny = y + dy ; nx = x + dx
            if 0<=ny<N and 0<=nx<N and visit[ny][nx]== 0 and (arr[ny][nx] ==0 or arr[ny][nx]==2):
                if arr[ny][nx] == 0:
                    rear += 1
                    zcnt -=1
                    if zcnt == 0:
                        return depth+1
                    # print(zcnt,'zcnt')
                    queue[rear] = (ny,nx,depth+1)
                    visit[ny][nx] = 1
                    arr[ny][nx] = 3
                else:
                    rear += 1
                    queue[rear] = (ny, nx, depth + 1)
                    visit[ny][nx] = 1
                    arr[ny][nx] = 3

        # print(zcnt,'zero')
        # if temp == [0, 3, 4]:
        #     print(visit)
        #     for p in range(N):
        #         print(arr[p],depth, zcnt)
        #     print()

    return -1


yls = []
xls = []
for i in range(N):
    for j in range(N):
        if arr[i][j] == 2:
            yls.append(i)
            xls.append(j)

zcnt = 0
for i in range(N):
    for j in range(N):
        if arr[i][j]==0:
            zcnt += 1
savezc = zcnt

if zcnt == 0:
    print(zcnt)
else:
    temp= []
    minret = 100000
    ls = [i for i in range(len(yls))]
    def Combi(cnt,depth,begin):
        global minret
        if cnt == depth:
            # print(temp)
            zcnt = savezc
            for i in range(len(temp)):
                for q in range(N):
                    for w in range(N):
                        arr[q][w]= acopy[q][w]
                for q in range(N):
                    for w in range(N):
                        visit[q][w] = 0
                ret = BFS(arr,temp,0,zcnt)
                # print(ret)

                if ret != -1:
                    minret = min(ret, minret)

        for idx in range(begin,len(ls)):
            temp.append(ls[idx])
            Combi(cnt+1,depth,idx+1)
            temp.pop()


    Combi(0,M,0)

    if minret == 100000:
        print(-1)
    else:
        print(minret)
