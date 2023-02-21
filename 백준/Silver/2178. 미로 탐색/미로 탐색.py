import sys
input = sys.stdin.readline
N, M = map(int,input().split())
arr = [list(map(int, input().strip())) for _ in range(N)]
visit = [[0] * M for _ in range(N)]
queue = [0 for _ in range(10000)]
# print(N,M)
# for i in range(N):
#     print(arr[i])
# print()

def BFS(arr,y,x):
    rear = -1
    front = 0

    rear += 1
    queue[rear] = (y,x)
    visit[y][x] = 1

    while rear +1 != front:
        y,x = queue[front]
        front += 1
        for dy, dx in ((-1,0),(1,0),(0,-1),(0,1)):
            ny = y + dy
            nx = x + dx
            if 0<=ny<N and 0<=nx<M and visit[ny][nx] == 0 and arr[ny][nx] !=0:
                rear += 1
                queue[rear] = (ny,nx)
                visit[ny][nx] = 1 + visit[y][x]

BFS(arr,0,0)
# for i in range(len(visit)):
#     print(visit[i])

print(visit[N-1][M-1])