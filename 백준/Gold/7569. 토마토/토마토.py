import sys
input = sys.stdin.readline

M,N,H = map(int, input().split())
arr = [[(list(map(int, input().split()))) for _ in range(N)] for _ in range(H)]
visit = [[[0 for _ in range(M)]for _ in range(N)] for _ in range(H)]
queue = [0 for _ in range(1000000)]
#
# for h in range(H):
#     for i in range(N):
#         print(arr[h][i])

sh = []; si = []; sj = []
for h in range(H):
    for i in range(N):
        for j in range(M):
            if arr[h][i][j] ==1:
                sh.append(h)
                si.append(i)
                sj.append(j)

# print(sh,si,sj)

def BFS(arr,h,y,x):
    rear = -1
    front = 0
    cnt = 0
    for i in range(len(y)):
        queue[i] = (h[i],y[i],x[i])
        arr[h[i]][y[i]][x[i]] = 1
        cnt += 1
    rear += cnt
    # print(rear)
    # print(front)
    while rear +1 != front:
        # print(queue)
        h,y,x = queue[front]
        front += 1
        for dh,dy,dx in ((1,0,0),(-1,0,0),(0,-1,0),(0,1,0),(0,0,-1),(0,0,1)):
            nh = h + dh ; ny = y + dy; nx = x + dx;
            if 0<=nh<H and 0 <= ny <N and 0<= nx < M and arr[nh][ny][nx] ==0:
                rear += 1
                queue[rear] = (nh,ny,nx)
                arr[nh][ny][nx] = 1 + arr[h][y][x]
                # for h in range(H):
                #     for i in range(N):
                #         print(arr[h][i])



BFS(arr, sh,si,sj)



maxv = -500
Flag = True
for h in range(H):
    for i in range(N):
        for j in range(M):
            if arr[h][i][j] == 0:
                Flag = False
                break
            else:
                if maxv < arr[h][i][j]:
                    maxv = arr[h][i][j]

if Flag:
    print(maxv-1)
elif not Flag:
    print(-1)
elif Flag and maxv == 1:
    print(0)
