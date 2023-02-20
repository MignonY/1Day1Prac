import sys
input = sys.stdin.readline

def DFS(arr,y,x):
    global cnt
    arr[y][x] = 0
    cnt +=1
    for dx, dy in ((-1, 0), (0, -1), (0, 1), (1, 0)):
        ny = y + dy
        nx = x + dx
        if 0<=ny<N and 0<=nx<N and arr[ny][nx] == 1:
            DFS(arr,ny,nx)




N = int(input())
arr = [list(map(int,input().strip())) for _ in range(N)]
ans = []
cnt = 0
dfs_cnt = 0
# for k in range(N):
#     print(arr[k])
# print()
# visit = [[0]*N for _ in range(N)]

for i in range(N):
    for j in range(N):
        if arr[i][j] ==1:
            DFS(arr,i,j)
            ans.append(cnt)
            cnt = 0
            dfs_cnt +=1

ans.sort()
# for k in range(N):
#     print(arr[k])

print(dfs_cnt)
for i in range(len(ans)):
    print(ans[i])