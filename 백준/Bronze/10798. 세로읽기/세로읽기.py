# T = int(input())
# for test_case in range(1,T+1):
ls = []
for i in range(5):
    ls.append(input())

maxlen = -100
for i in range(len(ls)):
    if maxlen < len(ls[i]):
        maxlen = len(ls[i])

ls_fin = [['*']*maxlen for _ in range(len(ls))]

for i in range(len(ls)):
    for j in range(len(ls[i])):
        ls_fin[i][j] = ls[i][j]

# print(ls_fin)
# print(ls)

# print(f'#{test_case}',end= " ")

for i in range(maxlen):
    for j in range(len(ls)):
        if ls_fin[j][i] == '*':
            pass
        else:
            print(ls_fin[j][i], end="")