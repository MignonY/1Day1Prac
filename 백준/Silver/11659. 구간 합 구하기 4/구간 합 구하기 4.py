import sys

N, M = map(int, sys.stdin.readline().split())
num = list(map(int, sys.stdin.readline().split()))
init_sum = 0
prefix_sum = [0]

for dat in num:
    init_sum += dat
    prefix_sum.append(init_sum)

for test_case in range(M):
    A, B = map(int, sys.stdin.readline().split())
    result = prefix_sum[B] - prefix_sum[A-1]
    print(result)
