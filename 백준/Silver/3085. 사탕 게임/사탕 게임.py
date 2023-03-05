N = int(input())
arr = [list(input()) for _ in range(N)]

maxc = 0
for i in range(N):
    for j in range(N):
        for dy, dx in ((-1,0),(1,0),(0,-1),(0,1)):
            ny = i + dy
            nx = j + dx
            if 0 <= ny <N and 0 <= nx < N and arr[i][j] != arr[ny][nx]:
                arr[i][j], arr[ny][nx] = arr[ny][nx], arr[i][j]
                for k in range(N):
                    savea = 'A'
                    cnt = 0
                    for l in range(N):
                        if arr[k][l] != savea:
                            savea = arr[k][l]
                            maxc = max(cnt, maxc)
                            cnt = 1
                        elif arr[k][l] == savea:
                            cnt += 1
                        maxc = max(cnt, maxc)

                for k in range(N):
                    savea = 'A'
                    cnt = 0
                    for l in range(N):
                        if arr[l][k] != savea:
                            savea = arr[l][k]
                            maxc = max(cnt, maxc)
                            cnt = 1
                        elif arr[l][k] == savea:
                            cnt += 1
                        maxc = max(cnt, maxc)

                arr[i][j], arr[ny][nx] = arr[ny][nx], arr[i][j]

print(maxc)