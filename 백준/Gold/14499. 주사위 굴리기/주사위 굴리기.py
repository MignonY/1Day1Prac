N,M,y,x,k = map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(N)]
command = list(map(int,input().split()))

dice = [0,0,0,0,0,0] # 상하좌우앞뒤
dice_ori = [1,6,4,3,5,2]

def right_1(d):
    dc = list(d)
    d[0] = dc[2]
    d[1] = dc[3]
    d[2] = dc[1]
    d[3] = dc[0]

def left_2(d):
    #341652
    dc = list(d)
    d[0] = dc[3]
    d[1] = dc[2]
    d[2] = dc[0]
    d[3] = dc[1]

def up_3(d):
    #524361
    dc = list(d)
    d[0] = dc[4]
    d[1] = dc[5]
    d[4] = dc[1]
    d[5] = dc[0]

def down_4(d):
    #254316
    dc = list(d)
    d[0] = dc[5]
    d[1] = dc[4]
    d[4] = dc[0]
    d[5] = dc[1]
    return
# x y = 주사위좌표
# 주사위밑면 dice[1]

if arr[y][x] ==0:
    arr[y][x] = dice[1]
else:
    dice[1] = arr[y][x]
    arr[y][x] = 0



for com in command:
    Flag = True
    if com == 1 :
        if x+1>= M:
            Flag = False
            continue
        else:
            x += 1
            right_1(dice)
    elif com == 2:
        if x-1 < 0:
            Flag = False
            continue
        else:
            x -= 1
            left_2(dice)
    elif com == 3:
        if y-1 < 0:
            Flag = False
            continue
        else:
            y -= 1
            up_3(dice)
    elif com == 4:
        if y+1>=N:
            Flag = False
            continue
        else:
            y += 1
            down_4(dice)

    if arr[y][x] == 0:
        arr[y][x] = dice[1]
    else:
        dice[1] = arr[y][x]
        arr[y][x] = 0

    if Flag:
        # print(dice, y,x)
        print(dice[0])
    else:
        continue

