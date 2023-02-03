import sys
N, K = map(int, sys.stdin.readline().split())
ls = list(map(int, sys.stdin.readline().split()))

init_sum = sum(ls[0:K])
prefix_sum = [init_sum]

for i in range(0, len(ls)-K):
    init_sum = init_sum-ls[i]+ls[K+i]
    prefix_sum.append(init_sum)

print(max(prefix_sum))