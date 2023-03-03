def Bingo():
    global arr
    cnt = 0
    for i in range(N):
        for j in range(N):
            if arr[i][j] == 0:
                for dx,dy in ((0,1),(1,0),(1,1),(1,-1)):
                    kan = 0
                    for mul in range(1,5):
                        ny = i + dy*mul
                        nx = j + dx*mul
                        if 0<= ny < N and 0<= nx < N and arr[ny][nx] ==0:
                            kan +=1
                    if kan == 4:
                        cnt += 1

    return cnt



N = 5
arr = [list(map(int, input().split())) for _ in range(N)]
numls = [list(map(int, input().split())) for _ in range(N)]

ans = 0
for i in range(N):
    for j in range(N):
        if Bingo() >= 3:
            break
        for k in range(N):
            for l in range(N):
                if arr[k][l] == numls[i][j]:
                    arr[k][l] = 0
                    ans += 1

print(ans)