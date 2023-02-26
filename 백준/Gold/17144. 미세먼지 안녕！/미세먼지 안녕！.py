Y, X, T  = map(int,input().split())
arr = [list(map(int,input().split()))for _ in range(Y)]
queue = [0 for _ in range(3000000)]

temp = []
for i in range(Y):
    for j in range(X):
        if arr[i][j] == -1:
            temp.append((i,j))
upi = temp[0][0] ; upj = temp[0][1]
downi = temp[1][0] ; downj = temp[1][1]

def cir(arr):
    for i in range(upi-1,-1,-1): #위>아래 (좌)
        arr[i][0] = arr[i-1][0]
    for j in range(X-1): # 오른쪽> 왼쪽 (상)
        arr[0][j] = arr[0][j+1]
    for i in range(upi): # 아래> 위 (우)
        arr[i][X-1] = arr[i+1][X-1]
    for j in range(X-1,0,-1): # 왼쪽> 오른쪽 (하)
        arr[upi][j] = arr[upi][j-1]
    arr[upi][upj + 1] = 0

    for i in range(downi+1,Y-1): # 아래> 위 (좌)
        arr[i][0] = arr[i+1][0]
    for j in range(X-1): # 오른쪽> 왼쪽 (하)
        arr[Y-1][j] = arr[Y-1][j+1]
    for i in range(Y-1,downi-1,-1): #위>아래 (우)
        arr[i][X-1] = arr[i-1][X-1]
    for j in range(X-1,0,-1): #왼쪽>오른쪽
        arr[downi][j] = arr[downi][j-1]
    arr[downi][downj +1] = 0


def BFS(arr):
    visit = [[0] * X for _ in range(Y)]
    arr_copy = [[0] * X for _ in range(Y)]
    for i in range(Y):
        for j in range(X):
            arr_copy[i][j] = arr[i][j]
    svy=[]
    svx=[]
    for i in range(Y):
        for j in range(X):
            if arr[i][j] != 0 and arr[i][j] != -1:
                svy.append(i)
                svx.append(j)
    rear = -1
    front = 0
    cnt = 0
    for i in range(len(svy)):
        rear += 1
        queue[rear] = (svy[i], svx[i])
        visit[svy[i]][svx[i]] = 1
    while rear +1 != front:
        y,x = queue[front]

        front += 1
        spread = 0
        for dy,dx in ((-1,0),(1,0),(0,-1),(0,1)):
            ny = y + dy
            nx = x + dx
            if 0<=ny<Y and 0<=nx<X and arr[y][x] != -1 and arr[ny][nx] != -1:
                arr[ny][nx] += arr_copy[y][x]//5
                spread += 1
                if visit[ny][nx] == 0:
                    rear += 1
                    queue[rear] = (ny,nx)
                    visit[ny][nx] = 1

        arr[y][x] -= arr_copy[y][x]//5 * spread

        if front != 0 and front % len(svy) == 0:
            cnt += 1
            cir(arr)
            for i in range(Y):
                for j in range(X):
                    arr_copy[i][j] = arr[i][j]
            for i in range(Y):
                for j in range(X):
                    visit[i][j] = 0

            svy = [] ; svx = []
            for i in range(Y):
                for j in range(X):
                    if arr[i][j] != 0 and arr[i][j] != -1:
                        svy.append(i)
                        svx.append(j)
            rear = -1
            front = 0
            for i in range(len(svy)):
                rear += 1
                queue[rear] = (svy[i], svx[i])
                visit[svy[i]][svx[i]] = 1

        if cnt == T:
            break


BFS(arr)

ans = 0
for i in range(Y):
    for j in range(X):
        if arr[i][j] != 0 and arr[i][j] != -1:
            ans += arr[i][j]
print(ans)