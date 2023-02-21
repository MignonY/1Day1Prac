import sys
input = sys.stdin.readline
N,M = map(int,input().split())
ls = [i for i in range(1,N+1)]
for i in range(M):
    I,J = map(int,input().split())
    I -= 1 ; J -= 1
    ls[I], ls[J] = ls[J], ls[I]

print(*ls)