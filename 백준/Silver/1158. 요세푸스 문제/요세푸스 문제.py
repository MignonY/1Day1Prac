class NODE:
    def __init__(self):
        self.data = 0
        self.prev = 0
        self.next = 0

N, K = map(int,input().split())
arr = [NODE() for _ in range(N+1)]
# 0~6
for i in range(N):
    A = NODE()
    arr[i+1].prev = ((i + (N-1)) % N) + 1
    arr[i+1].next = ((i + 1) % N) + 1
    arr[i+1].data = i+1
print('<', end='')


n = K
while N:
    if N>=2:
        print(f'{arr[n].data}, ',end='')
    else:
        print(f'{arr[n].data}>',end='')
    # print(arr[n].prev, arr[n].next, 'd')
    arr[arr[n].prev].next = arr[n].next
    arr[arr[n].next].prev = arr[n].prev
    for i in range(K):
        n = arr[n].next
    # print(n)
    N -= 1



