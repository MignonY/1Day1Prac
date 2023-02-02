now = map(int, input().split())
N = list(now)
time =map(int,input().split())
T = list(time)

if N[1] + T[0] >= 60:
    N[0] += (N[1] + T[0])//60
    N[0] %= 24 
    N[1] = (N[1] + T[0]) % 60

elif N[1] + T[0] < 60:
    N[1] += T[0]


print(N[0], N[1])
