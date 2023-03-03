M,N = map(int,input().split())
arr = [[0]*M for _ in range(N)]
K = int(input())

#시계반대방향
# 하 - 우 - 상 - 좌
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
# 0 1 2 3

i = 0
y = 0 ; x = 0
cnt = N*M
num = 1
arr[y][x] = num

if K > M*N:
    print(0)
elif K == 1:
    y=x=1
    print(x,y)
else:
    while cnt > 0:
        ny = y + dy[i % 4]
        nx = x + dx[i % 4]
        Flag = False
        while 0<=ny<N and 0<=nx<M and arr[ny][nx] == 0:
            y = ny
            x = nx
            ny = y + dy[i % 4]
            nx = x + dx[i % 4]
            num += 1
            arr[y][x] = num
            if num == K:
                Flag = True
                break
        if Flag:
            break
        i += 1
        cnt -=1
    print(x + 1, y + 1)

# for i in range(N):
#     print(arr[i])


