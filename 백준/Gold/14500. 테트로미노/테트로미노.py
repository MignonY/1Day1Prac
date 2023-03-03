N, M = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(N)]
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
dl = len(dy)
#[0 1 2 3]> 중복 허용해서 for문으로 조합

def hap(y,x,i,j,k):
    hap = 0
    if 0<=y+dy[i]< N and 0<=x+dx[i]<M:
        hap = arr[y][x]
        y, x = y+dy[i], x+dx[i]
        hap += arr[y][x]
        if 0 <= y + dy[j] < N and 0 <= x + dx[j] < M:
            y, x = y + dy[j], x + dx[j]
            hap += arr[y][x]
            if 0 <= y + dy[k] < N and 0 <= x + dx[k] < M:
                y, x = y + dy[k], x + dx[k]
                hap += arr[y][x]
    return hap

def exc(y,x):
    h1 = 0
    maxh = 0
    for i in range(dl):
        for j in range(i+1,dl):
            for k in range(j+1,dl):
                # print(i,j,k)
                if 0 <= y + dy[i] < N and 0 <= x + dx[i] < M:
                    if 0 <= y + dy[j] < N and 0 <= x + dx[j] < M:
                        if 0 <= y + dy[k] < N and 0 <= x + dx[k] < M:
                            h1 = arr[y][x]
                            h1 += arr[y+dy[i]][x+dx[i]]
                            h1 += arr[y+dy[j]][x+dx[j]]
                            h1 += arr[y+dy[k]][x+dx[k]]
                            maxh = max(h1, maxh)

    return maxh


sumv = 0
for i in range(dl):
    for j in range(dl):
        for k in range(dl):
            if abs(i-j) == 1 and (i+j == 1 or i+j == 5):
                continue
            if abs(j-k) == 1 and (j+k == 1 or j+k == 5):
                continue
            # print(i,j,k)
            for r in range(N):
                for c in range(M):
                    sumv = max(hap(r,c,i,j,k),exc(r,c), sumv)
                    # if sumv == 6:
                    #     print(r,c,'*')
                    #     print(i,j,k,'*')

print(sumv)

