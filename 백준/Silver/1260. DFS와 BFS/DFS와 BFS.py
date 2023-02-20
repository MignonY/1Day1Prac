import sys
input = sys.stdin.readline

V, E, S = map(int, input().split())
graph = [[] for _ in range(V+1)]
visit = [0 for _ in range(V+1)]
visited = []

for i in range(E):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

# print(graph)
for i in range(len(graph)):
    graph[i].sort()

def DFS(n):
    visit[n] = 1
    visited.append(n)
    for i in graph[n]:
        if visit[i] == 0:
            visit[i] = 1
            DFS(i)

DFS(S)
print(*visited)

visit = [0 for _ in range(V+1)]
visited = []
queue = [0 for _ in range(100000)]
def BFS(start_v):
    rear = -1
    front = 0

    visit[start_v] = 1
    rear += 1
    queue[rear] = start_v

    while rear +1 != front:
        current = queue[front]
        front +=1
        visited.append(current)
        for i in graph[current]:
            if visit[i] ==0:
                visit[i] = 1
                rear += 1
                queue[rear] = i

BFS(S)
print(*visited)