import sys
input = sys.stdin.readline
V = int(input())  # vertex
E = int(input())  # edge
graph = [[] for _ in range(V+1)]
visit = [0 for _ in range(V+1)]
visited = []
for i in range(E):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

# print(graph)

def DFS(n):
    visit[n] = 1
    visited.append(n)
    for i in graph[n]:
        if visit[i] == 0:
            DFS(i)

DFS(1)
print(len(visited)-1)