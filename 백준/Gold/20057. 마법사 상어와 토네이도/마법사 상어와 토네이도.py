# r행 c열 // A[r][c] 모래양
# 한칸 이동할때마다 모래 날림
# 1,1까지 토네이도 실행
# 격자밖으로 나간 모래 총량 구하기 // 소수점 버림 // a == 남은모래양
# ㅅㅂ

# N(홀수) 크기 최대 500 // 모래 최대 1000 // 가운데칸 모래양 0으로 시작

# 필요
# 1. 중앙부터 토네이도 도는 함수
# 2. (델타겠지) 모래 양 계산해서 흩날리는 함수

# if 밖으로?
# ans += 밖으로 나가는 모래양 , continue



N = int(input())
arr = [list(map(int,input().split())) for _ in range(N)]
midy = N//2
midx = N//2
ans = 0
# print(arr)


dy = [0, 1, 0, -1] # 좌 하 우 상
dx = [-1, 0, 1, 0]



forgo = 1   # 방향 바꾸기 전까지 이동 칸수_  초기값

def Tornado(y,x,D):
    global arr, dy, dx, forgo, ans
    cnt = 0
    while True:
        inbound = True
        for i in range(forgo):
            if x + dx[D] < 0:
                inbound = False
                break

            y += dy[D]
            x += dx[D]
            # print(y,x, 'curr')
            munji(y,x,D)
            # arr[y][x] = 1

        if not inbound:
            # print(y,x, 'current')
            break

        D = (D+1) % 4
        cnt += 1

        if cnt == 2:
            forgo += 1
            cnt = 0





def munji(y,x,D):
    global ans, arr, N
    # 먼지 방향대로 날리는 로직
    amount = arr[y][x]
    if D == 0 or D==2: # 좌 우
            # 나중에 틀리면 여기봐야함 -- 칸에다 적은만큼 빼는게 나머지인지 아님 밖에 날리는것도 빼는건지
        if 0 <= y+ dy[D]*2 < N and 0 <= x+ dx[D]*2 < N:
            arr[y+ dy[D]*2][x+ dx[D]*2] += int(arr[y][x] * 0.05)
            amount -= int(arr[y][x] * 0.05)
        else:
            ans += int(arr[y][x] * 0.05)
            amount -= int(arr[y][x] * 0.05)

        if 0 <= y+ dy[(D+1)%4] < N and 0 <= x+ dx[(D+1)%4] < N:
            arr[y+ dy[(D+1)%4]][x+ dx[(D+1)%4]] += int(arr[y][x] * 0.07)
            amount -= int(arr[y][x] * 0.07)
        else:
            ans += int(arr[y][x] * 0.07)
            amount -= int(arr[y][x] * 0.07)

        if 0<= y + dy[(D + 3) % 4] < N and 0<= x + dx[(D + 3) % 4] < N:
            arr[y + dy[(D + 3) % 4]][x + dx[(D + 3) % 4]] += int(arr[y][x] * 0.07)
            amount -= int(arr[y][x] * 0.07)
        else:
            ans += int(arr[y][x] * 0.07)
            amount -= int(arr[y][x] * 0.07)

        if 0<= y+ dy[(D+1)%4]*2 <N and 0<= x+ dx[(D+1)%4]*2 <N:
            arr[y + dy[(D + 1) % 4] * 2][x + dx[(D + 1) % 4] * 2] += int(arr[y][x] * 0.02)
            amount -= int(arr[y][x] * 0.02)
        else:
            ans += int(arr[y][x] * 0.02)
            amount -= int(arr[y][x] * 0.02)

        if 0 <= y + dy[(D + 3) % 4] * 2 < N and 0 <= x + dx[(D + 3) % 4] * 2 < N:
            arr[y+ dy[(D+3)%4]*2][x+ dx[(D+3)%4]*2] += int(arr[y][x] * 0.02)
            amount -= int(arr[y][x] * 0.02)
        else:
            ans += int(arr[y][x] * 0.02)
            amount -= int(arr[y][x] * 0.02)

        if 0<= y+ dy[3] < N and 0<= x+ dx[(D+2)%4] < N:
            arr[y+ dy[3]][x+ dx[(D+2)%4]] += int(arr[y][x] * 0.01)
            amount -= int(arr[y][x] * 0.01)
        else:
            ans += int(arr[y][x] * 0.01)
            amount -= int(arr[y][x] * 0.01)

        if 0<= y+ dy[1] <N and 0<= x+ dx[(D+2)%4] <N:
            arr[y+ dy[1]][x+ dx[(D+2)%4]] += int(arr[y][x] * 0.01)
            amount -= int(arr[y][x] * 0.01)
        else:
            ans += int(arr[y][x] * 0.01)
            amount -= int(arr[y][x] * 0.01)

        if 0<= y+dy[3] < N and 0<= x+dx[D] <N:
            arr[y + dy[3]][x +dx[D]] += int(arr[y][x] * 0.1)
            amount -= int(arr[y][x] * 0.1)
        else:
            ans += int(arr[y][x] * 0.1)
            amount -= int(arr[y][x] * 0.1)

        if 0<= y+dy[1] < N and 0<= x+dx[D] <N:
            arr[y + dy[1]][x +dx[D]] += int(arr[y][x] * 0.1)
            amount -= int(arr[y][x] * 0.1)
        else:
            ans += int(arr[y][x] * 0.1)
            amount -= int(arr[y][x] * 0.1)

        # 차이 == amount
        if 0 <= y + dy[D] < N and 0 <= x + dx[D] < N:
            arr[y + dy[D]][x + dx[D]] += amount
        else:
            ans += amount

        arr[y][x] = 0


    if D == 1 or D == 3:  # 상 하
        # if 0<= y+ dy[D] <N and 0<= x+ dx[D] <N:
        #     arr[y+ dy[D]][x+ dx[D]] = int(arr[y][x] * 0.55)
        # else:
        #     ans += int(arr[y][x] * 0.55)

        if 0 <= y+ dy[D]*2 < N and 0 <= x+ dx[D]*2 < N:
            arr[y+ dy[D]*2][x+ dx[D]*2] += int(arr[y][x] * 0.05)
            amount -= int(arr[y][x] * 0.05)
        else:
            ans += int(arr[y][x] * 0.05)
            amount -= int(arr[y][x] * 0.05)

        if 0 <= y+ dy[(D+1)%4] < N and 0 <= x+ dx[(D+1)%4] < N:
            arr[y+ dy[(D+1)%4]][x+ dx[(D+1)%4]] += int(arr[y][x] * 0.07)
            amount -= int(arr[y][x] * 0.07)
        else:
            ans += int(arr[y][x] * 0.07)
            amount -= int(arr[y][x] * 0.07)

        if 0<= y + dy[(D + 3) % 4] < N and 0<= x + dx[(D + 3) % 4] < N:
            arr[y + dy[(D + 3) % 4]][x + dx[(D + 3) % 4]] += int(arr[y][x] * 0.07)
            amount -= int(arr[y][x] * 0.07)
        else:
            ans += int(arr[y][x] * 0.07)
            amount -= int(arr[y][x] * 0.07)

        if 0<= y+ dy[(D+1)%4]*2 <N and 0<= x+ dx[(D+1)%4]*2 <N:
            arr[y + dy[(D + 1) % 4] * 2][x + dx[(D + 1) % 4] * 2] += int(arr[y][x] * 0.02)
            amount -= int(arr[y][x] * 0.02)
        else:
            ans += int(arr[y][x] * 0.02)
            amount -= int(arr[y][x] * 0.02)

        if 0 <= y + dy[(D + 3) % 4] * 2 < N and 0 <= x + dx[(D + 3) % 4] * 2 < N:
            arr[y+ dy[(D+3)%4]*2][x+ dx[(D+3)%4]*2] += int(arr[y][x] * 0.02)
            amount -= int(arr[y][x] * 0.02)
        else:
            ans += int(arr[y][x] * 0.02)
            amount -= int(arr[y][x] * 0.02)
        ######
        #

        if 0 <= y + dy[(D + 2) % 4] < N and 0 <= x + dx[0] < N:
            arr[y + dy[(D + 2) % 4]][x + dx[0]] += int(arr[y][x] * 0.01)
            amount -= int(arr[y][x] * 0.01)
        else:
            ans += int(arr[y][x] * 0.01)
            amount -= int(arr[y][x] * 0.01)

        if 0 <= y + dy[(D + 2) % 4] < N and 0 <= x + dx[2] < N:
            arr[y + dy[(D + 2) % 4]][x + dx[2]] += int(arr[y][x] * 0.01)
            amount -= int(arr[y][x] * 0.01)
        else:
            ans += int(arr[y][x] * 0.01)
            amount -= int(arr[y][x] * 0.01)

        if 0 <= y + dy[D] < N and 0 <= x + dx[0] < N:
            arr[y + dy[D]][x + dx[0]] += int(arr[y][x] * 0.1)
            amount -= int(arr[y][x] * 0.1)
        else:
            ans += int(arr[y][x] * 0.1)
            amount -= int(arr[y][x] * 0.1)

        if 0 <= y + dy[D] < N and 0 <= x + dx[2] < N:
            arr[y + dy[D]][x + dx[2]] += int(arr[y][x] * 0.1)
            amount -= int(arr[y][x] * 0.1)
        else:
            ans += int(arr[y][x] * 0.1)
            amount -= int(arr[y][x] * 0.1)

        # 차이 == amount
        if 0 <= y + dy[D] < N and 0 <= x + dx[D] < N:
            arr[y + dy[D]][x + dx[D]] += amount
        else:
            ans += amount
        arr[y][x] = 0

    # for i in range(N):
    #     print(arr[i], (y,x))
    # print(ans)
    # print()


            # 나중에 틀리면 여기봐야함 -- 칸에다 적은만큼 빼는게 나머지인지 아님 밖에 날리는것도 빼는건지
            # arr[y + dy[D]][x + dx[D]] = int(arr[y][x] * 0.55)
            # arr[y + dy[D] * 2][x + dx[D] * 2] += int(arr[y][x] * 0.05)
            # arr[y + dy[(D + 1) % 4]][x + dx[(D + 1) % 4]] += int(arr[y][x] * 0.07)
            # arr[y + dy[(D + 3) % 4]][x + dx[(D + 3) % 4]] += int(arr[y][x] * 0.07)
            # arr[y + dy[(D + 1) % 4] * 2][x + dx[(D + 1) % 4] * 2] += int(arr[y][x] * 0.02)
            # arr[y + dy[(D + 3) % 4] * 2][x + dx[(D + 3) % 4] * 2] += int(arr[y][x] * 0.02)
            #
            #
            # arr[y + dy[(D + 2) % 4]][x + dx[0]] += int(arr[y][x] * 0.01)
            # arr[y + dy[(D + 2) % 4]][x + dx[2]] += int(arr[y][x] * 0.01)
            # arr[y + dy[D]][x + dx[0]] += int(arr[y][x] * 0.1)
            # arr[y + dy[D]][x + dx[2]] += int(arr[y][x] * 0.1)
            # arr[y][x] = 0



    # dy = [0, 1, 0, -1]  # 좌 하 우 상
    # dx = [-1, 0, 1, 0]
# 좌 기준으로 상우 하우일때
# 상 기준으로는 하좌 하우임
# 하 기준으로는 상좌 상우
# 우 기준으로는 상좌 하좌임

# munji(5,3,1)
Tornado(midy, midx, 0)
# print(midy,midx)
# for i in range(N):
#     print(arr[i])
print(ans)
