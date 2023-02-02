# 1. H x W 이차원배열 만들기
# 2. 층수채우기?
# 3. 숫자로 방 지목하는 방법 구현

T = int(input())

for _ in range(T):
    H, W, N = list(map(int, input().split()))
    hotel = [[' ' for _ in range(W)] for _ in range(H)]

    for i in range(len(hotel)):
        for j in range(len(hotel[i])):
            if len(str(j+1))==1:
                hotel[i][j] = str(i+1)+ str(0)+ str(j+1)
            else:
                hotel[i][j] = str(i+1)+ str(j+1)

    div = N //H
    mod = N % H


    # print(hotel)
    # print(div, mod)
    if mod == 0:
        print(hotel[H-1][div-1])
    else:
        print(hotel[mod-1][div])
