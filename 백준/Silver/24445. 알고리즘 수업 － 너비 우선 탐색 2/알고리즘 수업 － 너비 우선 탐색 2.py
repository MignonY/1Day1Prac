import sys
input = sys.stdin.readline

N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
visit = [False for _ in range(N+1)]
visited = []
queue = [0 for _ in range(1000000)]
for i in range(M):
    u,v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)


for i in range(len(graph)):
    graph[i].sort(reverse=True)


def BFS(start_v):
    rear = -1
    front = 0

    visit[start_v] = True
    rear += 1
    queue[rear] = start_v

    while rear + 1 != front:
        current = queue[front]
        visited.append(current)
        front += 1
        for i in graph[current]:
            if visit[i] == False:
                visit[i] = True
                rear +=1
                queue[rear] = i

BFS(R)

fin = [0 for _ in range(N+1)]

for i in range(len(visited)):
    fin[visited[i]] = i+1


for i in range(1,len(fin)):
    print(fin[i])