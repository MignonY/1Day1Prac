import sys
N = int(sys.stdin.readline())

numls = [i for i in range(1, 1000001)]

def BHH(n):
    ls = list(str(n)) + [n]
    ls = list(map(int, ls))
    return ls

finls = list(map(BHH, numls))
ssjls = []
for i in range(len(finls)):
    if sum(finls[i]) == N:
        ssjls.append(finls[i][-1])


min = 100000001
for i in range(len(ssjls)):
    if min > ssjls[i]:
        min = ssjls[i]

if len(ssjls) == 0:
    print(0)
else:
    print(min)