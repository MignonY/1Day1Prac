def BFS(arr, y, x):
    rear = -1
    front = 0

    rear += 1
    queue[rear] = (y, x)
    visit[y][x] = 1

    while rear + 1 != front:
        y, x = queue[front]
        front += 1
        for dy, dx in ((-1, -2), (-2, -1), (-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2)):
            ny = y + dy
            nx = x + dx
            if 0 <= ny < N and 0 <= nx < N and visit[ny][nx] == 0:
                rear += 1
                queue[rear] = ny, nx
                visit[ny][nx] = 1 + visit[y][x]
                if arr[ny][nx] == 3:
                    return


T = int(input())
for test_case in range(T):
    N = int(input())
    si,sj = map(int,input().split())
    gi,gj = map(int,input().split())
    arr = [[0]*N for _ in range(N)]
    visit = [[0]*N for _ in range(N)]
    queue = [0 for _ in range(100000)]
    arr[si][sj] = 2
    arr[gi][gj] = 3
    #
    # for i in range(N):
    #     print(arr[i])

    BFS(arr,si,sj)
    # print()
    # for i in range(N):
    #     print(visit[i])
    if si == gi and sj == gj:
        print(0)
    else:
        print(visit[gi][gj]-1)