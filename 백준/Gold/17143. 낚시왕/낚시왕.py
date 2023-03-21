# 순서
# 1. 낚시왕 오른쪽 1칸이동 (초기세팅: 맵밖)
# 2. 해당 y축에서 y값 가장 작은 상어 잡음(삭제)
# 3. 상어 이동
    # 3-1. 상어는 초당 s칸 (주어진 속도) 이동
        #  이동하려는 칸이 맵밖이면 방향을 바꿔서 s칸 이동
            # 이거 속도만큼 벽으로 이동하고 남은거리 다시 반대로 이동하는거임 !!! 이동후 커브
            # 나머지연산으로 구현 될듯....? 아마도..?

    # 3-2. 상어 이동 후
        # 만약 한 자리 2이상 상어면 크기가 가장 큰 상어만 남음
            # 크기 같은 상어 없음


# 델타 : 1위 2아래 3오른쪽 4왼쪽 (입력)
# 행 y-1 열 x-1 속력s 방향d 크기z


### 설계
## 일단 잡은 상어 리스트 (최종) 만들기 -- 크기만 기록해도 되나?
## 지도에 상어 표시하고 갈지? -- 맵 최대크기가 100임
## 아니면 파이어볼처럼 상어 리스트(번호, 정보) 만들고 유효상어 리스트 갱신할지
    ## ++ 맵에는 그냥 상어 번호만 표시함
    ## 후자가 나을듯


## 필요함수
# 낚시왕 상어삭제 함수
# 상어 이동함수

## 준비물
# 낚시왕 위치(x값)
# 갱신형 상어 리스트(최종)
# Temp 상어 리스트

Y, X, M = map(int,input().split())
Sls = []
catch = 0
arr = [[[] for _ in range(X)] for _ in range(Y)]
for snum in range(M):
    y,x,s,d,z = map(int,input().split())
    Sls.append([y-1, x-1, s, d-1, z, True])

dy = [-1, 1, 0, 0]  #상 하 우 좌
dx = [0, 0, 1, -1]

# 1턴 위한 초기세팅 : arr에 상어번호 표시 (이동후기준)
for q in range(len(Sls)):
    # print(Sls[q][0],Sls[q][1])
    arr[Sls[q][0]][Sls[q][1]].append(q)

# print(Sls)
# for i in range(Y):
#     print(arr[i])

def turn(d):
    if d == 0:
        d = 1
    elif d == 1:
        d = 0
    elif d == 2:
        d = 3
    elif d == 3:
        d = 2
    return d

def FishKing():
    global catch, Sls, kx
    kx += 1
    ky = 0
    temp = []
    while 0 <= ky < Y:
        if len(arr[ky][kx])>0 :  # 배열안에 상어가 있으면
            catch += Sls[arr[ky][kx][0]][4] # 상어크기 더해주고
            # print(arr[ky][kx], Sls, 'd')
            Sls[arr[ky][kx][0]][5] = False   # 상어 잡았으니까 무효상어로 바꿔줌
            arr[ky][kx] = []   # 있던 자리 초기화
            break   # 하나 잡고 종료
        ky += 1  # 상어 나올때까지 전진탐색

    # True인거만 새 (임시)리스트에 담기
    ifFals = False
    for i in range(len(Sls)):
        if Sls[i][5] == True:
            temp.append(Sls[i])
        else:
            ifFals = True

    # Sls 다시 새리스트로 갱신
    Sls = temp
    if ifFals:
        for i in range(len(Sls)):
            arr[Sls[i][0]][Sls[i][1]] = [i]

def Smove():
    global Sls, Y, X
    temp = []
    for i in range(Y):
        for j in range(X):
            arr[i][j] = []

    for q in range(len(Sls)):
        y = Sls[q][0]
        x = Sls[q][1]
        s = Sls[q][2]
        d = Sls[q][3]
        z = Sls[q][4]

        # arr[y][x] = []  # 있던곳 비워주고
        ts = s              #이동해서 x y d갱신
        while ts > 0:
            if y+dy[d]<0 or y+dy[d]>=Y or x+dx[d]<0 or x+dx[d]>=X:
                d = turn(d)
            y += dy[d]
            x += dx[d]
            ts -= 1

        Sls[q][0] = y
        Sls[q][1] = x
        Sls[q][2] = s
        Sls[q][3] = d
        Sls[q][4] = z
        arr[y][x].append(q)  # 배열에 번호등록


    #이동 끝
    #2마리이상 들어간 구역 체크할거임
    # 물고기 가장 큰거 한마리로 갱신

    for i in range(Y):
        for j in range(X):
            if len(arr[i][j]) > 1:
                # for o in range(Y):
                #     print(arr[o])
                # print(arr[i][j])
                # arr[i][j].sort(key=lambda a: a[4], reverse=True)
                maxz = 0
                maxn = 0
                for k in range(len(arr[i][j])):
                    # print(Sls)
                    # print(arr[i][j],'sls')
                    if maxz < Sls[arr[i][j][k]][4]:
                        maxz = Sls[arr[i][j][k]][4]
                        maxn = arr[i][j][k]
                for k in range(len(arr[i][j])):
                    if arr[i][j][k] == maxn:
                        continue
                    Sls[arr[i][j][k]][5] = False     # 먹히는 물고기 다 false처리
                bigfish = maxn
                arr[i][j] = [bigfish]

    # 갱신끝



    # True인거만 새 (임시)리스트에 담기
    ifFals = False
    for i in range(len(Sls)):
        if Sls[i][5] == True:
            temp.append(Sls[i])
        else:
            ifFals = True

    # print('temp',temp)

    # Sls 다시 새리스트로 갱신
    Sls = temp
    if ifFals:
        for i in range(len(Sls)):
            arr[Sls[i][0]][Sls[i][1]] = [i]



kx = -1
# FishKing(kx)
# Smove()
for i in range(X):
    # print('before', Sls)
    FishKing()
    # print('kx:',kx)
    # print('catch', Sls)
    # for j in range(Y):
    #     print(arr[j], 'catch', i)
    # print()
    Smove()
    # for j in range(Y):
    #     print(arr[j], 'after', i)
    # print(catch,i)
    # print('after',Sls)
    # print()


print(catch)