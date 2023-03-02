N = int(input())
ls = [i for i in range(1,N+1)]
temp = [0 for _ in range(N)]
num = list(map(int,input().split()))
for i in range(N):
    if temp[i-num[i]] == 0:
        temp[i-num[i]] = ls[i]
    else:
        for j in range(N-2,i-num[i]-1,-1):
            temp[j+1] = temp[j]
        temp[i - num[i]] = ls[i]


print(*temp)