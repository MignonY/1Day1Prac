N = int(input())
alpha = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
right = [0 for _ in range(26)]
left = [0 for _ in range(26)]
for i in range(N):
    a,b,c = input().split()
    if b != '.':
        left[alpha.index(a)] = b
    if c != '.':
        right[alpha.index(a)] = c
#
# print(left)
# print(right)

pod = []
def POD(n):
    pod.append(n)
    if left[alpha.index(n)]:
        POD(left[alpha.index(n)])
    if right[alpha.index(n)]:
        POD(right[alpha.index(n)])

iod = []
def IOD(n):
    if left[alpha.index(n)]:
        IOD(left[alpha.index(n)])
    iod.append(n)
    if right[alpha.index(n)]:
        IOD(right[alpha.index(n)])

psod = []
def PSOD(n):
    if left[alpha.index(n)]:
        PSOD(left[alpha.index(n)])
    if right[alpha.index(n)]:
        PSOD(right[alpha.index(n)])
    psod.append(n)

POD('A')
IOD('A')
PSOD('A')
print(''.join(pod))
print(''.join(iod))
print(''.join(psod))
