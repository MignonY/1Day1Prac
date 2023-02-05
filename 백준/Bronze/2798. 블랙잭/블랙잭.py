import sys
N, M = map(int, sys.stdin.readline().split())
ls = list(map(int, sys.stdin.readline().split()))
hap = []
for i in range(N):
    for j in range(i+1, N):
        for k in range(j+1, N):
            if ls[i] + ls[j] + ls[k] <= M:
                hap.append(ls[i]+ls[j]+ls[k])

maxv = 0
for i in range(len(hap)):
    if maxv < hap[i]:
        maxv = hap[i]


print(maxv)