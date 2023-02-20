import sys
input = sys.stdin.readline

N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
visit = [0 for _ in range(N+1)]
queue = [0 for _ in range(1000000)]
visited = []
fin = [0 for _ in range(N+1)]
for i in range(M):
    u, v = map(int,input().split())
    graph[u].append(v)
    graph[v].append(u)



for i in range(len(graph)):
    graph[i].sort()
# print(graph)

def BFS(start_v):
    rear = -1
    front = 0
    visit[start_v] = 1
    rear += 1
    queue[rear] = start_v
    while rear + 1 != front:
        current = queue[front]
        visited.append(current)
        front += 1
        for i in graph[current]:
            if visit[i] == 0:
                rear += 1
                queue[rear] = i
                visit[i] = 1


BFS(R)
# print(visited)
# print(fin)
for i in range(len(visited)):
    fin[visited[i]] = i+1

# print(fin)

for i in range(1,len(fin)):
    print(fin[i])