N,L = map(int,input().split()) #신호등개수 / 도로의길이 , 1초1미터
# ls= [[0,0] for _ in range(12)]
time = 0
current = 0
for i in range(N):
    D,R,G = map(int,input().split())  # D 신호등위치 RG 빨초
    # ls[D] = [R,G]
    if current == 0:
        if D>=R:
            current = D
            time = D
        else:
            current = D
            time =D +(R-D)
    else:
        time += D - current
        current = D
        R = R - (time % (R+G))
        if R > 0:
            time += R

time += L-current

print(time)

