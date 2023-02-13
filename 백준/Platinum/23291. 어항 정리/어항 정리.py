# import sys
# input = sys.stdin.readline

N, K = map(int, input().split())
fish = list(map(int,input().split()))


def org(arr):
    N = len(arr)
    minv = 100000    # step1 = 최소어항에 하나씩
    idxmin = []
    for i in range(N):
        if minv > arr[i]:
            minv = arr[i]
    for i in range(N):
        if arr[i] == minv:
            idxmin.append(i)
    # print(idxmin)
    for idx in idxmin:
        arr[idx] +=1
    # print(arr)

    lsls = []    # step2 = 2개 쌓아서 새 리스트에 넣기
    lsls.insert(0,[])
    for i in range(2):
        lsls[0].insert(0, arr[0])
        arr.remove(arr[0])
    lsls.append([])
    for i in range(2):
        lsls[1].append(arr[i])
    for i in range(2):
        arr.remove(arr[0])
    # print(lsls,"f")
    # print(arr,"fa")

    while len(lsls) <= len(arr):    #step3: 돌려쌓기 (temp = 돌린행렬)
        temp = [[0]*(len(lsls)) for _ in range(len(lsls[0]))]
        for i in range(len(lsls[0])):
            for j in range(len(lsls)):
                temp[i][j] = lsls[len(lsls)-1-j][i]
        lsls = []  # 템프 크기와 같은 빈리스트 만들기
        for i in range(len(temp)):
            lsls.append([])
        for i in range(len(temp)):
            for j in range(len(temp[i])):
                lsls[i].append(temp[i][j])
        lsls.append([]) # 돌리기위해 아래에 arr 넣어줄거임
        for i in range(len(lsls[0])):
            lsls[-1].append(arr[i])

        # print(temp,'t')
        # print(lsls,'l')
        # print(arr,'a')

        for i in range(len(lsls[0])):
            arr.remove(arr[0])

    #     print(arr, 'rem')
    #
    #
    #
    # print(lsls,'fin')
    # print(arr,'fin')
    #


    # step4. 물고기 수 조절, 조절용 대빵어항 하나 다시 만들기 = bigfish
    bigfish = []
    for i in range(len(lsls)):
        bigfish.append(lsls[i])
    for i in range(len(arr)):
        bigfish[-1].append(arr[i])
    # print(bigfish,"bf")
    newbf = [] # 조절한 어항 또 만들어줘야함
    for i in range(len(bigfish)):
        newbf.append([])
    for i in range(len(bigfish)):
        for j in range(len(bigfish[i])):
           newbf[i].append(bigfish[i][j])
    # print(newbf, "newbf")

    for i in range(len(bigfish)):
        for j in range(len(bigfish[i])):
            for dy, dx in ((-1,0),(1,0),(0,-1),(0,1)):
                ny = i + dy
                nx = j + dx
                try:
                    if 0 <= nx < len(bigfish[i]):
                        if abs(bigfish[i][j] - bigfish[i][nx]) >= 5:
                            if bigfish[i][j] > bigfish[i][nx]:
                                newbf[i][nx] += (bigfish[i][j] - bigfish[i][nx]) // 5
                                newbf[i][j] -= (bigfish[i][j] - bigfish[i][nx]) // 5


                    if 0 <= ny < len(bigfish):
                        if abs(bigfish[i][j] - bigfish[ny][j]) >= 5:
                            if bigfish[i][j] > bigfish[ny][j]:
                                newbf[ny][j] += (bigfish[i][j] - bigfish[ny][j]) // 5
                                newbf[i][j] -= (bigfish[i][j] - bigfish[ny][j]) // 5
                except:
                    if 0 <= nx < len(bigfish[i]):
                        if abs(bigfish[i][j] - bigfish[i][nx]) >= 5:
                            if bigfish[i][j] > bigfish[i][nx]:
                                newbf[i][nx] += (bigfish[i][j] - bigfish[i][nx]) // 5
                                newbf[i][j] -= (bigfish[i][j] - bigfish[i][nx]) // 5

    # for i in range(len(newbf)):
    #     print(newbf[i])


    #다시 바닥에 일렬로 놓기
    bottom = []
    for i in range(len(newbf[-1])):
       for j in range(len(newbf)):
           try:
               bottom.append(newbf[len(newbf)-1-j][i])
           except:
               pass
    # print(bottom) #  바닥에 다 내려논거

    new_ls = [[],[]]
    for i in range(len(bottom)//2-1,-1,-1):
        new_ls[0].append(bottom[i])
    for i in range(len(bottom)//2, len(bottom)):
        new_ls[1].append(bottom[i])
    # print(new_ls) # 180도 돌려쌓기 한번실행
    new_ls.insert(0,[])
    new_ls.insert(2,[])
    # print(new_ls) # 일단 쪼개넣기 위해서 공간 만들어줌


    for i in range(len(new_ls[3])//2):
        new_ls[0].append(new_ls[3][len(new_ls[3])//2-1-i])
    for i in range(len(new_ls[3])//2):
        new_ls[3].remove(new_ls[3][0])
    for i in range(len(new_ls[1])//2, len(new_ls[1])):
        new_ls[2].append(new_ls[1][i])
    new_ls.insert(1,[])
    for i in range(len(new_ls[2])//2-1,-1,-1):
        new_ls[1].append(new_ls[2][i])
    new_ls.remove(new_ls[2])

    # print(new_ls) # 180도 두번 시행함


    # 또 조절하장

    newbff = []  # 조절한 어항 또 만들어줘야함
    for i in range(len(new_ls)):
        newbff.append([])
    for i in range(len(new_ls)):
        for j in range(len(new_ls[i])):
            newbff[i].append(new_ls[i][j])
    # print(newbff,"newbff")
    # print(new_ls,"new_ls")
    for i in range(len(new_ls)):
        for j in range(len(new_ls[i])):
            for dy, dx in ((-1,0),(1,0),(0,-1),(0,1)):
                ny = i + dy
                nx = j + dx
                if 0 <= nx < len(new_ls[i]):
                    if abs(new_ls[i][j] - new_ls[i][nx]) >= 5:
                        if new_ls[i][j] > new_ls[i][nx]:
                            newbff[i][nx] += (new_ls[i][j] - new_ls[i][nx]) // 5
                            newbff[i][j] -= (new_ls[i][j] - new_ls[i][nx]) // 5
                if 0 <= ny < len(new_ls):
                    if abs(new_ls[i][j] - new_ls[ny][j]) >= 5:
                        if new_ls[i][j] > new_ls[ny][j]:
                            newbff[ny][j] += (new_ls[i][j] - new_ls[ny][j]) // 5
                            newbff[i][j] -= (new_ls[i][j] - new_ls[ny][j]) // 5



    #
    # for i in range(len(newbff)):
    #     print(newbff[i])



    # 마지막 내려놓기
    fin_ls = []
    for i in range(len(newbff[0])):
        for j in range(len(newbff)):
            fin_ls.append(newbff[len(newbff)-1-j][i])

    return fin_ls

# print(org(fish))

cnt = 0
while max(fish) - min(fish) > K:
    cnt +=1
    fish = org(fish)
    # print(fish,"final")
print(cnt)

