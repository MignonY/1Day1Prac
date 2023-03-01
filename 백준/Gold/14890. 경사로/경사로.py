N, L = map(int, input().split())
arr = [list(map(int,input().split())) for _ in range(N)]
visit = [[0]* N for _ in range(N)]
cnt = 0

for i in range(N):
    j = 0
    Flag = False
    while j < N-1:
        # print(i,j)
        if arr[i][j] == arr[i][j+1]:
            Flag = True
            j += 1
        else:
            #올라가는
            if arr[i][j+1] == arr[i][j] + 1 and j+1-L >= 0 :
                fl = True
                for k in range(L):
                    if arr[i][j-k] != arr[i][j] or visit[i][j-k] == 1:
                        fl = False
                        break
                if fl:
                    Flag = True
                    for k in range(L):
                        visit[i][j-k] = 1
                    j += 1
                else:
                    Flag = False
                    break

            # 내려가는
            elif arr[i][j+1] == arr[i][j] - 1 and j+L < N:
                fl = True
                for k in range(1,L+1):
                    if arr[i][j+k] != arr[i][j+1] or visit[i][j+k] == 1:
                        # print(i,j+k,'d')
                        fl = False
                        break
                if fl:
                    Flag = True
                    for k in range(1,L + 1):
                        visit[i][j + k] = 1
                    j += L
                else:
                    Flag = False
                    break
            else:
                Flag = False
                break

    if Flag:
        # print(i,'good')
        cnt += 1

# print(cnt)


# 행렬 돌려서 체크

arr2 = [[0]*N for _ in range(N)]
for i in range(N):
    for j in range(N):
        visit[i][j] = 0

for i in range(N):
    for j in range(N):
        arr2[i][j] = arr[N-1-j][i]

# for i in range(N):
#     print(arr2[i])
cnt2 = 0
for i in range(N):
    j = 0
    Flag = False
    while j < N-1:
        # print(i,j)
        if arr2[i][j] == arr2[i][j+1]:
            Flag = True
            j += 1
        else:
            #올라가는
            if arr2[i][j+1] == arr2[i][j] + 1 and j+1-L >= 0 :
                fl = True
                for k in range(L):
                    if arr2[i][j-k] != arr2[i][j] or visit[i][j-k] == 1:
                        fl = False
                        break
                if fl:
                    Flag = True
                    for k in range(L):
                        visit[i][j-k] = 1
                    j += 1
                else:
                    Flag = False
                    break

            # 내려가는
            elif arr2[i][j+1] == arr2[i][j] - 1 and j+L < N:
                fl = True
                for k in range(1,L+1):
                    if arr2[i][j+k] != arr2[i][j+1] or visit[i][j+k] == 1:
                        # print(i,j+1,j+k,'d')
                        # print(visit[i][j+k],'d')
                        # for i in range(N):
                        #     print(visit[i])
                        fl = False
                        break
                if fl:
                    Flag = True
                    for k in range(1, L + 1):
                        visit[i][j + k] = 1
                    j += L
                else:
                    Flag = False
                    break
            else:
                Flag = False
                break

    if Flag:
        # print(i,'good')
        cnt2 += 1

# print(cnt,cnt2)
print(cnt + cnt2)