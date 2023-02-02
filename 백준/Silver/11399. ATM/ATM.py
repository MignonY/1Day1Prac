import sys

N = int(sys.stdin.readline())
P = list(map(int,sys.stdin.readline().split()))
sum = 0

for i in range(len(P)-1,0,-1):
    for j in range(i):
        if P[j] > P[j+1]:
            P[j], P[j+1] = P[j+1], P[j]
# print(P)

for a in range(len(P)-1):
    P[a+1]+=P[a]

for a in range(len(P)):
    sum += P[a]
    
# print(P)
print(sum)