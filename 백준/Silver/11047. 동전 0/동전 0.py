import sys

N,K = list(map(int,sys.stdin.readline().split()))
money = [int(sys.stdin.readline()) for _ in range(N)]
money.reverse()

# print(money)

cnt = 0
for i in range(len(money)):
        cnt += K//money[i]
        K -= K//money[i] * money[i]

print(cnt)

        