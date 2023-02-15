# 100 99 1 98
# 100 50 50 0 50

#
# 100 49 51 2 49
# 100 51 49 2 47

# 100 75 25 50
# 100 25 75

# 100 70 30 40
# 100 30 70
#
# 100 64
# 100 65 35 30 5 25

# 150 101 49 52
#150 100 50 50 0
# 150 99 51 48 3 45

# 2/3 -1 부터 시작
# 대충 반쯤은 최대값 절대아님> 끝점
N = int(input())
# ls = [N]
def recur(N,A):
    if N-A < 0:
        # print(ls)
        return ls
    ls.append(N-A)
    return recur(A,N-A)
#
# for A in range(round(N/2),round(N/3)*2):
#     ls = [N]
#     print(recur(N,A))
max_len = 0
save_A = []

if N <= 10:
    for A in range(N+1):
        ls = [N, A]
        # print(recur(N,A))
        recur(N, A)
        if max_len < len(ls):
            max_len = len(ls)
            save_A = ls
else:
    for A in range(round(N/2)+1,round(N/3)*2):
        ls = [N,A]
        # print(recur(N,A))
        recur(N,A)
        if max_len < len(ls):
            max_len = len(ls)
            save_A = ls

print(max_len)
print(*save_A)


#
# print(recur(100,62))
