
S = [list(map(int,input().split())) for _ in range(9)]

max_v = 0
max_y = 1
max_x = 1

for i in range(9):
    for j in range(9):
        if max_v < S[i][j]:
            max_v = S[i][j]
            max_y = i
            max_x = j
        
        if max_v == S[i][j]:
            pass
        
print(max_v)
print(max_y+1, max_x+1) 