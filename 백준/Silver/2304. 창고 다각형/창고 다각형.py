N = int(input())
maxL = 0
maxH = 0
maxidx = 0
ls = []
for i in range(N):
    L, H = map(int,input().split())
    maxL = max(maxL, L)
    if maxH <= H:
        maxH = H
        maxidx = L
    ls.append((L,H))

changgo = [0]* (maxL + 1)
for i in range(N):
    changgo[ls[i][0]] = ls[i][1]

sumv = 0
maxv = 0
for i in range(maxidx +1):
    if maxv < changgo[i]:
        maxv = changgo[i]
    sumv += maxv

sumv2 = 0
maxv = 0

for i in range(maxL, maxidx, -1):
    if maxv < changgo[i]:
        maxv = changgo[i]
    sumv2 += maxv

print(sumv+sumv2)