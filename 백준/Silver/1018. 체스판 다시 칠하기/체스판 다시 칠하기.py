import sys
input = sys.stdin.readline
Y,X = map(int, input().split())
arr = [input().strip() for _ in range(Y)]


bwls = ['' for i in range(8)]
for i in range(8):
    if i % 2 == 0:
        bwls[i] = 'BWBWBWBW'
    else:
        bwls[i] = 'WBWBWBWB'

wbls = ['' for i in range(8)]
for i in range(8):
    if i % 2 == 0:
        wbls[i] = 'WBWBWBWB'
    else:
        wbls[i] = 'BWBWBWBW'

temp = []
minv = 1000
for i in range(Y-8+1):
    for j in range(X-8+1):
        cntBW = 0
        cntWB = 0
        for k in range(8):
            for l in range(8):
                if arr[i+k][j+l] != bwls[k][l]:
                    cntBW += 1
                elif arr[i+k][j+l] != wbls[k][l]:
                    cntWB += 1
        # print(cntBW,cntWB)

        if minv > cntBW:
            minv = cntBW
        if minv > cntWB:
            minv = cntWB

print(minv)
