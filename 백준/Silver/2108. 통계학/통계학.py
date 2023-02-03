import sys
from collections import Counter

T = int(sys.stdin.readline())
ls = [int(sys.stdin.readline()) for _ in range(T)]

ls.sort()
temp_ls = Counter(ls).most_common(2)

# print(temp_ls)
if len(ls) > 1:
    if temp_ls[0][1] == temp_ls[1][1]:
        freq = temp_ls[1][0]
    else:
        freq = temp_ls[0][0]
else:
    freq = ls[0]


print(round(sum(ls)/T))
print(ls[len(ls)//2])
print(freq)
print(max(ls) - min(ls))
