N, K = map(int,input().split())
belt = [[[0,0]for _ in range(N)] for _ in range(2)]

# for i in range(2):
#     print(belt[i])

ls = list(map(int,input().split()))

# print(ls)

for i in range(N):
    belt[0][i][0] = ls[i]
    belt[1][N-1-i][0] = ls[i+N]

# for i in range(2):
#     print(belt[i])
# print()


def movebelt(arr):
    global zcnt
    y = 0
    x = N-1
    # sy = y
    # sx = x
    savels = arr[y][x]
    while x > 0:
        arr[y][x] = arr[y][x-1] # 벨트회전
        if arr[y][N - 1][1] == 1:
            arr[y][N - 1][1] = 0  # 내리는위치에 들어오면 바로내림
        x -= 1


    x = N-1
    while x > 0:
        if arr[y][x - 1][1] == 1 and arr[y][x][1] == 0 and arr[y][x][0] >= 1:
            arr[y][x][1] = 1    #로봇이동 좌>우 (우시점)
            if arr[y][N - 1][1] == 1:
                arr[y][N - 1][1] = 0  # 내리는위치에 들어오면 바로내림
            arr[y][x-1][1] = 0  #로봇이동 좌>우 (좌시점)
            arr[y][x][0] -= 1   #내구도-1
            if arr[y][x][0] == 0:
                zcnt += 1
        x -= 1

    arr[y][x] = arr[y+1][x]
    y += 1
    while x < N-1:
        arr[y][x] = arr[y][x+1]
        x += 1
    arr[y][x] = savels

    return arr
# print(belt)



depth = 0
zcnt = 0
while True:
    depth += 1
    # for i in range(2):
    #     print(belt[i],'bfm')
    # print()

    movebelt(belt)

    if belt[0][0][0] != 0:
        # print('yes')
        belt[0][0][1] = 1
        belt[0][0][0] -= 1
        if belt[0][0][0] == 0:
            zcnt += 1

    #
    # for i in range(2):
    #     print(belt[i],'moved')
    # print(f'depth:{depth}, zcnt:{zcnt}')
    # print()

    if zcnt >= K:
        print(depth)
        break
