import sys
input = sys.stdin.readline

arr = [[] for i in range(101)]
visit = [0 for _ in range(101)]
queue = [0 for _ in range(200)]
N, M = map(int,input().split())
for i in range(N):
    x,y = map(int,input().split())
    arr[x].append(y)
for i in range(M):
    u,v = map(int,input().split())
    arr[u].append(v)


def BFS(start_v):
    rear = -1
    front = 0
    rear += 1
    queue[rear] =start_v
    visit[start_v] = 1
    while rear +1 != front:
        current = queue[front]
        front +=1
        for i in range(1,7):
            if 0<current+i <=100 and visit[current + i] ==0:
                if len(arr[current+i]) == 0:
                    rear +=1
                    queue[rear] = current + i
                    visit[current+i] = 1 + visit[current]
                if len(arr[current+i]) ==1 and visit[arr[current+i][0]] ==0:
                    rear += 1
                    queue[rear] = arr[current+i][0]
                    visit[current+i] = 1 + visit[current]
                    visit[arr[current+i][0]] = 1 + visit[current]
                if current+i == 100:
                    return
                # print(queue)
                # print(visit)




BFS(1)
# print(arr)
# print(visit)
if visit[100] == 0:
    print(0)
else:
    print(visit[100]-1)