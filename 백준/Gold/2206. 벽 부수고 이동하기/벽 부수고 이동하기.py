import sys
input= sys.stdin.readline
N, M = map(int, input().split())

arr = [input().strip() for i in range(N)]
visit = [[[0 for _ in range(M)] for _ in range(N)] for _ in range(2)]

QUEUE_SIZE = 500000
queue = [0 for _ in range(QUEUE_SIZE)]

front = 0
rear = -1


visit[0][0][0] = 1
visit[1][0][0] = 1

rear += 1
queue[rear] = (0, 0, 0, 1)

answer = -1
while (rear + 1) % QUEUE_SIZE != front:
    y = queue[front][0]
    x = queue[front][1]    
    z = queue[front][2]
    count = queue[front][3]

    if y == N - 1 and x == M - 1:
        answer = count
        break
    
    front = (front + 1) % QUEUE_SIZE

    for dy, dx in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        ny = y + dy
        nx = x + dx
        if 0 <= ny and ny < N and 0 <= nx and nx < M:
            if arr[ny][nx] == '0' and visit[z][ny][nx] == 0:
                rear = (rear + 1) % QUEUE_SIZE
                visit[z][ny][nx] = 1
                queue[rear] = (ny, nx, z, count + 1)

            elif z == 0 and arr[ny][nx] == '1':
                rear = (rear + 1) % QUEUE_SIZE
                visit[1][ny][nx] = 1
                queue[rear] = (ny, nx, 1, count + 1)

print(answer)
            
