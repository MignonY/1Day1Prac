import sys
input = sys.stdin.readline
N,M = map(int,input().split())
ls = [0 for _ in range(1,N+1)]
for i in range(M):
     I,J,K = map(int,input().split())
     I -= 1 ; J -=1

     for i in range(I,J+1):
         ls[i] = K


print(*ls)