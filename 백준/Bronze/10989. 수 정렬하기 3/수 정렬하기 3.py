import sys

N = int(sys.stdin.readline().strip())
temp = [0] * 10001



for _ in range(N):
    temp[int(sys.stdin.readline().strip())] += 1


for i in range(10001):
    if temp[i] != 0:
        for j in range(temp[i]):
            print(i)