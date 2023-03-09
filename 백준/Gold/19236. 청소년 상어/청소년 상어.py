fish = [[] for _ in range(4)]
D = [[] for _ in range(4)]
for i in range(4):
    a1,b1,a2,b2,a3,b3,a4,b4 = map(int,input().split())
    fish[i] = [a1,a2,a3,a4]
    D[i] = [b1,b2,b3,b4]

# for i in range(4):
#     print(fish[i])
# print()
visit = [[0]*4 for _ in range(4)]
savemap = [[0]*4 for _ in range(4)]
saveD = [[0]*4 for _ in range(4)]


Dic = {1:(-1,0), 2:(-1,-1), 3:(0,-1), 4:(1,-1), 5:(1,0), 6:(1,1), 7:(0,1), 8: (-1,1)}
# 1: 상 / 2: 좌상 / 3: 좌/ 4: 좌하 / 5: 하 / 6: 하우 / 7: 우 / 8: 상우
ans = fish[0][0]
shark = [0,0,D[0][0]]
fish[0][0] = -1
D[0][0] = 0

# for i in range(4):
#     print(fish[i])
# print()
# for i in range(4):
#     print(D[i])
# print()
#

def fmove():
    global fls,savedirr,savefls,D,fish
    fls = [[0,0,0] for _ in range(17)]
    # for i in range(4):
    #     print(fish[i],'fish')
    for i in range(4):
        for j in range(4):
            if fish[i][j] ==0 or fish[i][j]==-1:
                continue
            fls[fish[i][j]][0] = i
            fls[fish[i][j]][1] = j
            fls[fish[i][j]][2] = D[i][j]
    # print(fls,'fls')
    for i in range(1,len(fls)):
        y = fls[i][0]
        x = fls[i][1]
        dirr = fls[i][2]
        savedirr = dirr
        if ( dirr==0 or  dirr==-1):
            continue
        # print(i)
        while True:
            Flag = False
            # print(i,dirr)
            ny = y + Dic[dirr][0]
            nx = x + Dic[dirr][1]
            if 0<=ny<4 and 0<=nx<4 and fish[ny][nx] != -1:
                # print(i,dirr,"yes")
                # fish[ny][nx], fish[y][x] = fish[y][x], fish[ny][nx]
                # D[ny][nx], D[y][x] = D[y][x], D[ny][nx]
                # fls[fish[ny][nx]], fls[fish[y][x]] = fls[fish[y][x]], fls[fish[ny][nx]]
                if fish[ny][nx] == 0:
                    fls[fish[y][x]][0] = ny
                    fls[fish[y][x]][1] = nx
                    fls[i][2] = dirr
                else:
                    fls[fish[ny][nx]][0], fls[fish[y][x]][0] = fls[fish[y][x]][0], fls[fish[ny][nx]][0]
                    fls[fish[ny][nx]][1], fls[fish[y][x]][1] = fls[fish[y][x]][1], fls[fish[ny][nx]][1]
                    fls[i][2] = dirr
                fish[ny][nx], fish[y][x] = fish[y][x], fish[ny][nx]
                Flag = True

            else:
                # print(i, dirr, 'no')
                if (dirr+1)%8 == 0:
                    dirr = 8
                else:
                    dirr = (dirr+1) % 8
                Flag = False
                if dirr == savedirr:
                    dirr = savedirr
                    Flag = True
            if Flag:
                # print(fls)
                # for i in range(4):
                #     print(fish[i])
                # print()
                break

    for q in range(4):
        for w in range(4):
            D[q][w]=0

    # print(fls,'check')
    for q in range(1,len(fls)):
        if fls[q][0] == 0 and fls[q][1] == 0 and fls[q][2] ==0:
            continue
        D[fls[q][0]][fls[q][1]] = fls[q][2]
    # for i in range(4):
    #     print(fish[i],'check')
    # for i in range(4):
    #     print(D[i],'cd')



fmove()

# # print(fls)
# # print()
# for i in range(4):
#     print(fish[i],'fin')
# print()
# for i in range(4):
#     print(D[i],'dfin')
# print(0)
# # for i in range(4):
# #     print(D[i])

maxans = 0

# print(shark,'shark')
# savefish = 0
savefls = [[0, 0, 0] for _ in range(17)]
mapsave = [i for i in range(17)]
Dsave = [0 for _ in range(17)]
flssave = [0 for _ in range(17)]
anssave = [0 for _ in range(17)]
dirrsave = [0 for _ in range(17)]
depth = 0
def sangO(y,x):
    global shark,fls,ans,maxans,fish,savefish,savefls,D,saveD,depth,mapsave,Dsave,flssave,anssave,dirrsave
    sdir = shark[2]
    ny = y + Dic[sdir][0]
    nx = x + Dic[sdir][1]
    # print(f'fstart: yx:{(y,x)},dir:{shark[2]}')
    # for i in range(4):
    #     print(fish[i],'start')
    # for i in range(4):
    #     print(D[i],'d')


    while 0<=ny<4 and 0<=nx<4:
        # print(f'current:{(y,x)},dir:{sdir},ans:{ans},nynx:{ny,nx},fish:{fish[ny][nx]},depth:{depth}')
        # for i in range(4):
        #     print(fish[i])
        if fish[ny][nx] != 0:
            # print("eat",(ny,nx))
            # visit[ny][nx]=1
            anssave[depth] = ans
            dirrsave[depth] = sdir
            mapsave[depth] = list(map(list,fish))
            Dsave[depth] = list(map(list,D))
            flssave[depth] = list(map(list,fls))
            # print(f'save: depth:{depth},cur:{fish},map:{mapsave}')
            shark[2] = fls[fish[ny][nx]][2]
            ans += fish[ny][nx]
            savefish = fish[ny][nx]
            depth +=1
            fish[ny][nx] = -1
            fish[y][x] = 0
            D[ny][nx] = 0
            # for t in range(4):
            #     print(fish[t], 'bfmove')
            # for t in range(4):
            #     print(D[t], 'bfd')
            # print()
            # print('fish',depth)
            fmove()
            # for i in range(4):
            #     print(fish[i],'aftermove')
            # for i in range(4):
            #     print(D[i],'D')
            # print(fls,'aftermove')
            # print('shark', depth)
            sangO(ny,nx)
        #     print('exit', 'dir:',sdir, depth)
        # print('curr:',(y,x),(ny,nx))

        # for t in range(4):
        #     print(fish[t],'back')
        # for t in range(4):
        #     print(D[t],'back')
        ny += Dic[sdir][0]
        nx += Dic[sdir][1]
        # print("nofish",(nx,ny),"dir:",sdir)

    if ny<0 or ny >= 4 or nx <0 or nx >= 4:
        # print()
        # print(f'yx={y,x},nynx= {ny,nx},ans={ans}')
        maxans = max(maxans, ans)
        # visit[y][x] = 0
        # print(maxans,'max',ans)
        depth -=1
        # print(mapsave)
        # print(depth)
        if depth== -1:
            return
        ans = anssave[depth]
        shark[2] = dirrsave[depth]
        for i in range(4):
            for j in range(4):
                fish[i][j] = mapsave[depth][i][j]
        for i in range(4):
            for j in range(4):
                D[i][j] = Dsave[depth][i][j]
        for i in range(len(fls)):
            for j in range(len(fls[i])):
                fls[i][j] = flssave[depth][i][j]
        return


sangO(0,0)
print(maxans)