nA, nB = list(map(int, input().split()))

A = [list(map(int,input().split())) for _ in range(nA)]
B = [list(map(int,input().split())) for _ in range(nA)]
C = [ [0 for _ in range (nB)] for _ in range (nA)]

for i in range(nA):
    for j in range(nB):
        C[i][j] = A[i][j]+B[i][j]
        print(C[i][j], end =' ')
    print()