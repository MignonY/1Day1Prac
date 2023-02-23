N = int(input())
visit = [0 for _ in range(N+1)]
graph = [[] for _ in range(N+1)]
ans = [0 for _ in range(N+1)]
queue = [0 for _ in range(101000)]
for i in range(N-1):
    u, v = map(int,input().split())
    graph[u].append(v)
    graph[v].append(u)

# print(graph)

def BFS(start_v):
    rear = -1
    front = 0
    rear +=1
    queue[rear] = start_v
    visit[start_v] = 1
    while rear +1 != front:
        current =queue[front]
        front +=1
        for i in graph[current]:
            if visit[i] ==0:
                # print(i)
                rear += 1
                queue[rear] = i
                visit[i] = 1
                ans[i] = current

BFS(1)
for i in range(2,len(ans)):
    print(ans[i])

