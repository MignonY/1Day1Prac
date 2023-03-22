def solution(maps):
    global arr,visit,queue,N,M
    queue = [0 for _ in range(15000)]
    arr = maps
    N = len(arr)
    M = len(arr[0])
    visit = [[0]*M for _ in range(N)]
    answer = bfs(arr,0,0)
    # for i in range(N):
	#     print(arr[i])
    # print(answer)
    return answer


def bfs(arr,y,x):
    rear = -1
    front = 0

    rear += 1
    queue[rear] = (y,x)
    arr[y][x] = 2

    while rear +1 != front:
        # print(queue)
        y, x = queue[front]
        front += 1

        for dy, dx in ((-1,0),(1,0),(0,-1),(0,1)):
            ny = y + dy
            nx = x + dx
            if 0<=ny<N and 0<=nx<M and arr[ny][nx] == 1:
                rear += 1
                queue[rear] = (ny,nx)
                arr[ny][nx] = 1 + arr[y][x]

    if arr[N-1][M-1] != 1:
        # for i in range(N):
        #     print(arr[i], arr[N-1][M-1]-1)
        return arr[N-1][M-1]-1

    elif arr[N-1][M-1] == 1:
        # for i in range(N):
        #     print(arr[i], -1)
        return -1



# solution([[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]])
# solution([[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,0],[0,0,0,0,1]])

