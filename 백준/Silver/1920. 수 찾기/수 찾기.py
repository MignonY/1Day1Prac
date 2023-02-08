import sys
N = int(sys.stdin.readline())
Nls = list(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline())
Mls = list(map(int, sys.stdin.readline().split()))

Nls.sort()

def Bi_S(arr, N, key):
    start = 0
    end = N-1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == key:
            return 1
        elif arr[mid] < key:
            start = mid + 1
        else:
            end = mid - 1
    return 0


for i in range(M):
    if len(Nls) == 1:
        if Mls[i] == Nls[0]:
            print(1)
        else:
            print(0)
    else:
        print(Bi_S(Nls, N, Mls[i]))

