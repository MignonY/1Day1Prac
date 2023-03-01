N, M = map(int,input().split())
arr = [list(input()) for _ in range(N)]
queue = [0 for _ in range(1000000)]

def up(Ri,Rj,Bi,Bj):
    nRi = Ri; nRj = Rj; nBi = Bi; nBj = Bj

    R_goal = False
    while True:
        if arr[nRi][Rj] == 'O':
            R_goal = True
            break
        if arr[nRi][Rj] == '#':
            nRi += 1
            break
        nRi -= 1

    B_goal = False
    while True:
        if arr[nBi][Bj] == 'O':
            B_goal = True
            break
        if arr[nBi][Bj] == '#':
            nBi += 1
            break
        nBi -= 1

    if nRi == nBi and Rj == Bj:
        if Ri > Bi:
            nRi += 1
        else:
            nBi += 1
    return (nRi, Rj, nBi, Bj, R_goal, B_goal)

def down(Ri,Rj,Bi,Bj):
    nRi = Ri; nRj = Rj; nBi = Bi; nBj = Bj

    R_goal = False
    while True:
        if arr[nRi][Rj] == 'O':
            R_goal = True
            break
        if arr[nRi][Rj] == '#':
            nRi -= 1
            break
        nRi += 1

    B_goal = False
    while True:
        if arr[nBi][Bj] == 'O':
            B_goal = True
            break
        if arr[nBi][Bj] == '#':
            nBi -= 1
            break
        nBi += 1

    if nRi == nBi and Rj == Bj:
        if Ri > Bi:
            nBi -= 1
        else:
            nRi -= 1
    return (nRi, Rj, nBi, Bj, R_goal, B_goal)

def left(Ri,Rj,Bi,Bj):
    nRi = Ri; nRj = Rj; nBi = Bi; nBj = Bj

    R_goal = False
    while True:
        if arr[Ri][nRj] == 'O':
            R_goal = True
            break
        if arr[Ri][nRj] == '#':
            nRj += 1
            break
        nRj -= 1

    B_goal = False
    while True:
        if arr[Bi][nBj] == 'O':
            B_goal = True
            break
        if arr[Bi][nBj] == '#':
            nBj += 1
            break
        nBj -= 1

    if nRj == nBj and Ri == Bi:
        if Rj > Bj:
            nRj += 1
        else:
            nBj += 1
    return (Ri, nRj, Bi, nBj, R_goal, B_goal)

def right(Ri,Rj,Bi,Bj):
    nRi = Ri; nRj = Rj; nBi = Bi; nBj = Bj

    R_goal = False
    while True:
        if arr[Ri][nRj] == 'O':
            R_goal = True
            break
        if arr[Ri][nRj] == '#':
            nRj -= 1
            break
        nRj += 1

    B_goal = False
    while True:
        if arr[Bi][nBj] == 'O':
            B_goal = True
            break
        if arr[Bi][nBj] == '#':
            nBj -= 1
            break
        nBj += 1

    if nRj == nBj and Ri == Bi:
        if Rj > Bj:
            nBj -= 1
        else:
            nRj -= 1
    return (Ri, nRj, Bi, nBj, R_goal, B_goal)


Ri = 0 ; Rj = 0; Bi = 0; Bj = 0
for i in range(N):
    for j in range(M):
        if arr[i][j] == 'R':
            Ri = i ; Rj = j
            arr[i][j] = '.'
        if arr[i][j] == 'B':
            Bi = i ; Bj = j
            arr[i][j] = '.'



rear = -1
front = 0
cnt = 0
rear += 1
u = 2
queue[rear] = (Ri, Rj, Bi, Bj, cnt, u)
R_goal = False ; B_goal = False
ans = -1
while rear +1 != front:
    Ri,Rj,Bi,Bj,cnt,u = queue[front]
    front += 1
    if cnt == 10:
        break

    if u != 1:
        #up
        nRi, nRj , nBi, nBj, R_goal, B_goal = up(Ri,Rj,Bi,Bj)
        if R_goal and not B_goal:
            ans = cnt + 1
            break

        elif not R_goal and not B_goal:
            rear +=1
            queue[rear] = (nRi,nRj,nBi,nBj,cnt+1,1)

        #down
        nRi, nRj, nBi, nBj, R_goal, B_goal = down(Ri, Rj, Bi, Bj)
        if R_goal and not B_goal:
            ans = cnt + 1
            break

        elif not R_goal and not B_goal:
            rear += 1
            queue[rear] = (nRi, nRj, nBi, nBj, cnt + 1, 1)


    if u != 0:
        #left
        nRi, nRj, nBi, nBj, R_goal, B_goal = left(Ri, Rj, Bi, Bj)
        if R_goal and not B_goal:
            ans = cnt + 1
            break

        elif not R_goal and not B_goal:
            rear += 1
            queue[rear] = (nRi, nRj, nBi, nBj, cnt + 1, 0)

        # right
        nRi, nRj, nBi, nBj, R_goal, B_goal = right(Ri, Rj, Bi, Bj)
        if R_goal and not B_goal:
            ans = cnt + 1
            break

        elif not R_goal and not B_goal:
            rear += 1
            queue[rear] = (nRi, nRj, nBi, nBj, cnt + 1, 0)

        # print(f'RiRj={nRi,nRj},BiBj={nBi,nBj},cnt={cnt},u={u}')

print(ans)
