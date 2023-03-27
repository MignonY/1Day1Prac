def solution(rectangle, characterX, characterY, itemX, itemY):
    global queue, visit, N,arr, goalY, goalX, zero
    N = 110
    queue = [0 for _ in range(15000)]
    visit = [[0]*N for _ in range(N)]
    arr = [[0]*N for _ in range(N)] # 55로 바꿔주기 마지막에
    # for i in range(10):
    #     print(arr[i])
    answer = 0
    goalY = itemY
    goalX = itemX
    zero = []
    for i in range(len(rectangle)):
        for j in range(rectangle[i][0]*2, rectangle[i][2]*2+1):
            for k in range(rectangle[i][1]*2, rectangle[i][3]*2+1):
                if k == rectangle[i][1]*2 or k == rectangle[i][3]*2 or j== rectangle[i][0]*2 or j == rectangle[i][2]*2:
                    if arr[k][j] == 0:
                        arr[k][j] = 2
                else:
                    arr[k][j] = 1
    # arr[characterY*2][characterX*2] = 3
    # arr[goalY*2][goalX*2] = 4
    # for i in range(N):
    #     print(arr[i],i)
    # print()
    answer = BFS(characterY*2, characterX*2,0) // 2
    # print(answer,'ans')
    return answer

def BFS(y,x,depth):
    rear = -1
    front = 0

    rear +=1
    queue[rear] = (y,x,depth)
    arr[y][x] = 3

    while rear +1 != front:
        y, x, depth = queue[front]
        front += 1
        for dy, dx in ((-1,0),(1,0),(0,-1),(0,1)):
            ny = y + dy
            nx = x + dx
            if 0<=ny<N and 0<=nx<N and arr[ny][nx] == 2:
                rear += 1
                queue[rear] = (ny,nx, depth+1)
                arr[ny][nx] = 3

                if ny == goalY*2 and nx == goalX*2:
                    # print(y,x,(ny,nx))
                    # arr[goalY][goalX] = 3
                    # for i in range(N):
                    #     print(arr[i])
                    # print()
                    return depth + 1
        #
        # for i in range(N):
        #     print(arr[i])
        # print()

# solution([[1,1,7,4],[3,2,5,5],[4,3,6,9],[2,6,8,8]],1,3,7,8)
# solution([[1,1,8,4],[2,2,4,9],[3,6,9,8],[6,3,7,7]],9,7,6,1)