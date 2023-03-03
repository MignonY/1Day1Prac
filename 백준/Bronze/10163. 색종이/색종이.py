J = int(input()) # 색종이개수
arr = [[0]* 1000 for _ in range(1000)]
cnt = [0 for _ in range(J+1)]
tc = 0
for t in range(J):
    x,y,M,N = map(int, input().split())
    tc +=1

    for i in range(N):
        for j in range(M):
            arr[y+i][x+j] = tc


for i in range(1000):
    for j in range(1000):
        for k in range(1,J+1):
            if arr[i][j] ==k:
                cnt[k] +=1


for i in range(1,len(cnt)):
    print(cnt[i])
