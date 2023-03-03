L = int(input())  # 롤케이크길이
P = int(input())  # 방청객 수

cake = [0 for _ in range(L+1)]
eat = [0 for _ in range(P+1)]
maxv = 0
savep = 0
max_real = 0
for pnum in range(1,P+1):
    S, G = map(int, input().split())  # 각 방청객이 적어낸 롤케이크 범위
    if maxv< G-S:
        maxv = G-S
        savep = pnum

    for i in range(S,G+1):
        if not cake[i]:
            cake[i] = pnum


for i in range(1,len(cake)):
    if cake[i]:
        eat[cake[i]] +=1

maxvv = max(eat[1:])
for i in range(len(eat)):
    if eat[i] == maxvv:
        max_real = i
        break
# 
# print(cake)
# print(eat)
print(savep)
print(max_real)