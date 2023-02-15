import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

# def DFS(start_v):
#     visited = []
#     stack = [start_v]
#     while stack:
#         v = stack.pop()
#         if v not in visited:
#             visited.append(v)
#             for i in graph[v]:
#                 stack.append(i)
#     return visited


N,M,R = map(int, input().split())
graph = [[] for _ in range(N+1)]
visit = [0 for _ in range(N+1)]



for i in range(M):
    S,G = map(int, input().split())
    graph[S].append(G)
    graph[G].append(S)

for i in range(len(graph)):
    graph[i].sort()

visited = []
def DFS(n):
    visit[n] = True
    visited.append(n)
    for i in graph[n]:
        if visit[i] == False:
            DFS(i)
DFS(R)

arr = [0 for _ in range(N+1)]

for i in range(len(visited)):
    arr[visited[i]] = i+1

for i in range(1,len(arr)):
    print(arr[i])
