X, Y = map(int,input().split())
N = int(input())
garo = [0,X] ; sero =[0,Y]
for i in range(N):
    A,B = map(int,input().split())
    if A == 0:
        sero.append(B)
    elif A == 1:
        garo.append(B)

garo.sort()
sero.sort()

gmax = 0
for i in range(len(garo)-1):
    gmax = max(garo[i+1]-garo[i], gmax)

smax = 0
for i in range(len(sero)-1):
    smax = max(sero[i+1]-sero[i], smax)

print(gmax*smax)
