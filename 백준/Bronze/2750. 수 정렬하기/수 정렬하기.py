import sys
N = int(sys.stdin.readline())

ls = [int(sys.stdin.readline()) for _ in range(N)]

for i in range(len(ls)-1,0,-1):
    for j in range(0,i):
        if ls[j]> ls[j+1]:
            ls[j],ls[j+1] = ls[j+1],ls[j]

for i in range(N):   
    print(ls[i])