N, M = map(int,input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
arr_ori = list(map(list,arr))
# print(arr_ori)
def c1(y,x,Dir):
    sy = y; sx= x
    if Dir == 0:
        while x+1 < M:
            if arr[y][x + 1] == 6:
                break
            if arr[y][x+1] == 0:
                arr[y][x+1] = '#'
            x += 1
        x = sx; y = sy
    if Dir == 1:
        while y+1 < N:
            if arr[y+1][x]== 6:
                break
            if arr[y+1][x] == 0:
                arr[y+1][x] = '#'
            y += 1
        x = sx; y = sy
    if Dir == 2:
        while 0 <= x-1:
            if arr[y][x-1] == 6:
                break
            if arr[y][x-1] == 0:
                arr[y][x-1] = '#'
            x -= 1
        x = sx; y = sy
    if Dir == 3:
        while 0 <= y-1:
            if arr[y-1][x] == 6:
                break
            if arr[y-1][x] == 0:
                arr[y-1][x] = '#'
            y -= 1
        x = sx; y = sy

def c2(y,x,Dir):
    sy = y; sx = x
    if Dir % 2 == 0:
        while x+1 < M:
            if arr[y][x+1] == 6:
                break
            if arr[y][x+1] == 0:
                arr[y][x+1] = '#'
            x += 1
        x = sx; y = sy
        while 0 <= x-1:
            if arr[y][x-1] == 6:
                break
            if arr[y][x-1] == 0:
                arr[y][x-1] = '#'
            x -= 1
    if Dir % 2 == 1:
        while y+1 < N:
            if arr[y+1][x] == 6:
                break
            if arr[y+1][x] == 0:
                arr[y+1][x] = '#'
            y += 1
        x = sx; y = sy
        while 0 <= y-1:
            if arr[y-1][x] == 6:
                break
            if arr[y-1][x] == 0:
                arr[y-1][x] = '#'
            y -= 1
        x = sx; y = sy
        # print(y,x,'check')

def c3(y,x,Dir):
    sy = y; sx = x
    if Dir == 0:
        while x + 1 < M:
            if arr[y][x + 1] == 6:
                break
            if arr[y][x + 1] ==0:
                arr[y][x + 1] = '#'
            x += 1
        x = sx; y = sy
        while 0 <= y - 1:
            if arr[y - 1][x] == 6:
                break
            if arr[y - 1][x] ==0:
                arr[y - 1][x] = '#'
            y -= 1
        x = sx; y = sy
    if Dir == 1:
        while x + 1 < M:
            if arr[y][x + 1] == 6:
                break
            if arr[y][x + 1] == 0:
                arr[y][x + 1] = '#'
            x += 1
        x = sx; y = sy
        while y + 1 < N:
            if arr[y + 1][x] == 6:
                break
            if arr[y + 1][x] == 0:
                arr[y + 1][x] = '#'
            y += 1
        x = sx; y = sy
    if Dir == 2:
        while 0 <= x - 1:
            if arr[y][x - 1] == 6:
                break
            if arr[y][x - 1] == 0:
                arr[y][x - 1] = '#'
            x -= 1
        x = sx; y = sy
        while y + 1 < N:
            if arr[y + 1][x] == 6:
                break
            if arr[y + 1][x] == 0:
                arr[y + 1][x] = '#'
            y += 1
        x = sx; y = sy
    if Dir == 3:
        while 0 <= x - 1:
            if arr[y][x - 1] == 6:
                break
            if arr[y][x - 1] == 0:
                arr[y][x - 1] = '#'
            x -= 1
        x = sx; y = sy
        while 0 <= y - 1:
            if arr[y - 1][x] == 6:
                break
            if arr[y - 1][x] == 0:
                arr[y - 1][x] = '#'
            y -= 1
        x = sx; y = sy

def c4(y,x,Dir):
    sy = y; sx = x;
    if Dir == 0:
        while x+1 < M:
            if arr[y][x+1] == 6:
                break
            if arr[y][x+1] == 0:
                arr[y][x+1] = '#'
            x += 1
        x = sx; y = sy
        while 0 <= x-1:
            if arr[y][x-1] == 6:
                break
            if arr[y][x-1] == 0:
                arr[y][x-1] = '#'
            x -= 1
        x = sx; y = sy
        while 0 <= y-1:
            if arr[y-1][x] == 6:
                break
            if arr[y-1][x] == 0:
                arr[y-1][x] = '#'
            y -= 1
        x = sx; y = sy
    if Dir == 1:
        while x+1 < M:
            if arr[y][x+1] == 6:
                break
            if arr[y][x+1] == 0:
                arr[y][x+1] = '#'
            x += 1
        x = sx; y = sy
        while y+1 < N:
            if arr[y+1][x] == 6:
                break
            if arr[y+1][x] == 0:
                arr[y+1][x] = '#'
            y += 1
        x = sx; y = sy
        while 0 <= y-1:
            if arr[y-1][x] == 6:
                break
            if arr[y-1][x] == 0:
                arr[y-1][x] = '#'
            y -= 1
        x = sx; y = sy
    if Dir == 2:
        while 0 <= x-1:
            if arr[y][x-1] == 6:
                break
            if arr[y][x-1] == 0:
                arr[y][x-1] = '#'
            x -= 1
        x = sx; y = sy
        while x+1 < M:
            if arr[y][x+1] == 6:
                break
            if arr[y][x+1] == 0:
                arr[y][x+1] = '#'
            x += 1
        x = sx; y = sy
        while y+1 < N:
            if arr[y+1][x] == 6:
                break
            if arr[y+1][x] == 0:
                arr[y+1][x] = '#'
            y += 1
        x = sx; y = sy
    if Dir == 3:
        while 0 <= y-1:
            if arr[y-1][x] == 6:
                break
            if arr[y-1][x] == 0:
                arr[y-1][x] = '#'
            y -= 1
        x = sx; y = sy
        while 0 <= x-1:
            if arr[y][x-1] == 6:
                break
            if arr[y][x-1] == 0:
                arr[y][x-1] = '#'
            x -= 1
        x = sx; y = sy
        while y+1 < N:
            if arr[y+1][x] == 6:
                break
            if arr[y+1][x] == 0:
                arr[y+1][x] = '#'
            y += 1
        x = sx; y = sy

def c5(y,x,Dir):
    sy = y ; sx = x
    if Dir == 0 or Dir == 1 or Dir == 2 or Dir == 3:
        while x+1 < M:
            if arr[y][x+1] == 6:
                break
            if arr[y][x+1] == 0:
                arr[y][x+1] = '#'
            x += 1
        x = sx; y = sy
        while 0 <= x-1:
            if arr[y][x-1] == 6:
                break
            if arr[y][x-1] == 0:
                arr[y][x-1] = '#'
            x -= 1
        x = sx; y = sy
        while 0 <= y-1:
            if arr[y-1][x] == 6:
                break
            if arr[y-1][x] == 0:
                arr[y-1][x] = '#'
            y -= 1
        x = sx; y = sy
        while y+1 < N:
            if arr[y+1][x] == 6:
                break
            if arr[y+1][x] == 0:
                arr[y+1][x] = '#'
            y += 1
        x = sx; y = sy

def callc(y,x,n,tempn):
    if n == 1:
        c1(y,x,tempn)
    if n == 2:
        c2(y,x,tempn)
    if n == 3:
        c3(y,x,tempn)
    if n == 4:
        c4(y,x,tempn)
    if n == 5:
        c5(y,x,tempn)


# for i in range(N):
#     print(arr[i])


ccnt = 0
ccls = []
for i in range(N):
    for j in range(M):
        if arr[i][j] != 6 and arr[i][j] !=0:
            ccnt += 1
            ccls.append((i,j,arr[i][j]))

# callc(1,1,4,3)
# print(ccnt)
ls = [0,1,2,3]
temp = []
# print(ccls)
#상하좌우 4 중복조합
minsafe = 10000
def comb(cnt,depth,begin):
    global minsafe, arr
    if cnt == depth:
        # print(temp,'s') # 조합
        for q in range(N):
            for w in range(M):
                arr[q][w] = arr_ori[q][w]
                arr[q][w] = arr_ori[q][w]
        for i in range(len(temp)): # cctv별로 돌리는거 시뮬
            # print(arr)
            # print(ccls[i][0],ccls[i][1],ccls[i][2],temp[i])
            callc(ccls[i][0],ccls[i][1],ccls[i][2],temp[i])

            # for j in range(N):
            #     print(arr[j])
            # print()

            safe = 0
            for q in range(N):
                for w in range(M):
                    if arr[q][w] ==0 :
                        safe += 1
            minsafe = min(safe, minsafe)

        return

    for idx in range(len(ls)):
        temp.append(ls[idx])
        comb(cnt+1, depth, idx)
        temp.pop()


comb(0,ccnt,0)

# for i in range(N):
#     print(arr[i])
# #
#
if minsafe == 10000:
    zeroc = 0
    for i in range(N):
        for j in range(M):
            if arr[i][j]==0:
                zeroc += 1
    print(zeroc)
else:
    print(minsafe)