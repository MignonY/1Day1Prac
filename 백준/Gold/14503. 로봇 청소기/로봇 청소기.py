# 0 북/ 1 동/ 2 남 / 3 서
# 북>서(0>3)/동>북(1>0)/남>동(2>1)/서>남(3>2)

N, M = map(int, input().split())
Y, X, D = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
visit = [[0] * M for _ in range(N)]

DY = [-1, 0, 1, 0]
DX = [0, 1, 0, -1]

BY = [1, 0, -1, 0]
BX = [0, -1, 0, 1]

def dir(n):
    if n == 0:
        return 3
    else:
        return n - 1


cnt = 101
def func(Y,X):
    global cnt,N,M,D,DY,DX,BY,BX
    while True:
        if arr[Y][X] == 0:      #1번
            arr[Y][X] = cnt
        #
        # for i in range(N):
        #     print(arr[i])
        # print()
        Flag = True
        for dy, dx in ((-1,0),(1,0),(0,-1),(0,1)):
            ny, nx = Y+dy, X+dx
            if 0<=ny<N and 0<=nx<M and arr[ny][nx]!=1:
                if arr[ny][nx] == 0:
                    Flag = False
                    break
        if not Flag:        #청소되지 않은 빈 칸이 있는경우
            D = dir(D)
            ndy, ndx = Y + DY[D], X + DX[D]
            if 0<=ndy<N and 0<=ndx<M and arr[ndy][ndx]!=1:
                if arr[ndy][ndx] == 0:
                    cnt +=1
                    Y, X = ndy, ndx
                else:
                    while True:
                        D = dir(D)
                        ndy, ndx = Y + DY[D], X + DX[D]
                        if arr[ndy][ndx] == 0:
                            cnt += 1
                            Y, X = ndy,ndx
                            break
        else:   #청소되지 않은 빈 칸이 없는경우 (상하좌우 모두 0값아닌경우)  - 2번케이스
            nby, nbx = Y + BY[D], X + BX[D]
            if 0<= nby< N and 0<= nbx < M and arr[nby][nbx]!= 1:
                Y,X = nby, nbx
                continue
            else:
                return



func(Y,X)
print(cnt-100)
