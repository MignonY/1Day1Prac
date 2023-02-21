# M N 구분 잘하자
import sys
input = sys.stdin.readline

M, N = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(N)]
queue = [0 for _ in range(3000000)]
# for i in range(N):
#     print(arr[i])

def BFS(arr,y,x):
    rear = -1
    front = 0
    cnt = 0
    for i in range(len(y)):
        queue[i] = (y[i],x[i])
        arr[y[i]][x[i]] = 1
        cnt += 1
    rear +=cnt
    # print(rear)
    # print(front)
    while rear +1 != front:
        y,x = queue[front]
        # print(queue)
        front += 1
        for dy, dx in ((-1,0),(1,0),(0,-1),(0,1)):
            ny = y + dy
            nx = x + dx
            if 0<=ny<N and 0<=nx<M and arr[ny][nx] == 0:
                rear += 1
                queue[rear] = ny,nx
                arr[ny][nx] = 1 + arr[y][x]
                # print(queue)
si = []
sj = []
for i in range(N):
    for j in range(M):
        if arr[i][j] == 1:
            si.append(i)
            sj.append(j)
# print(si)
# print(sj)
BFS(arr,si,sj)
# print()
# for i in range(len(arr)):
#     print(arr[i])

Flag = True
maxv = -500
for i in range(N):
    for j in range(M):
        if arr[i][j] == 0:
            Flag = False
            break
        if maxv < arr[i][j]:
            maxv = arr[i][j]

if Flag:
    print(maxv-1)
elif not Flag:
    print(-1)
elif Flag and maxv == 1:
    print(0)