import sys
sys.setrecursionlimit(10000000)

input = sys.stdin.readline

N, M, R = map(int,input().split())
graph = [[] for _ in range(N+1)]
visit = [0 for _ in range(N+1)]
visited = []
for i in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

for i in range(len(graph)):
    graph[i].sort(reverse = True)

def DFS(r):
    visit[r] = 1
    visited.append(r)
    for i in graph[r]:
        if visit[i] == False:
            DFS(i)



DFS(R)

arr = [0 for _ in range(N+1)]
for i in range(len(visited)):
    arr[visited[i]] = i+1

for i in range(1, len(arr)):
    print(arr[i])

