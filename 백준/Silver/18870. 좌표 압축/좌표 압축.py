import sys
N = int(sys.stdin.readline())
ls = list(map(int, sys.stdin.readline().split()))
dic = {}
st_ls = sorted(list(set(ls)))

for i in range(len(st_ls)):
    dic[st_ls[i]] = i


for i in range(len(ls)):
    ls[i] = dic[ls[i]]
    print(ls[i], end=" ")