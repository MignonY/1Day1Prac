import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)

def DFS(arr,y,x):
    visit[y][x] = 1
    for dy, dx in ((1, 0), (-1, 0), (0, 1), (0, -1)):
        ny = y + dy
        nx = x + dx
        if 0<=ny<N and 0<=nx<M:
            if visit[ny][nx] != 1 and arr[ny][nx] ==1:
                DFS(arr,ny,nx)



T = int(input())
for test_case in range(1,T+1):
    M,N,K = map(int,input().split())
    baechu = [[0]* M for _ in range(N)]
    visit = [[0]*M for _ in range(N)]
    for i in range(K):
        X, Y = map(int,input().split())
        baechu[Y][X] = 1

    # for i in range(N):
    #     print(baechu[i])


    cnt = 0
    for i in range(N):
        for j in range(M):
            if baechu[i][j] == 1 and visit[i][j]==0:
                DFS(baechu, i, j)
                cnt += 1


    print(cnt)

