import sys
input = sys.stdin.readline

def cal(a1, a2, op):
    if op == '+':
        return a1 + a2
    elif op == '-':
        return a1 - a2
    elif op == '*':
        return a1 * a2
    elif op == '//':
        if a1 < 0 :
            return 0 - (abs(a1) // a2)
        else:
            return a1//a2

def perm(arr,ans,n):
    if n == len(arr):
        fin_op.append(list(ans))
        return
    for i in range(len(arr)):
        if visit[i] == 0:
            visit[i] = 1
            ans.append(arr[i])
            perm(arr,ans,n+1)
            ans.pop()
            visit[i] = 0



N = int(input())
dic = {0:'+', 1:'-', 2:'*', 3:'//'}
num_ls = list(map(int,input().split()))
num_copy = list(num_ls)
op_num = list(map(int,input().split()))
op = []
fin_op = []
stack =[]
for i in range(len(op_num)):
    for j in range(op_num[i]):
        op.append(dic[i])
visit= [0 for _ in range(len(op))]


perm(op,[],0)
# print(fin_op)

minv = 1000000000
maxv = -1000000000

for i in range(len(fin_op)):
    for k in range(len(num_ls)):
        num_ls[k] = num_copy[k]
    # print("i")
    # print(num_ls)
    for j in range(len(num_ls)-1):
        res = cal(num_ls[j], num_ls[j+1], fin_op[i][j])
        num_ls[j+1] = res
        # print(num_ls)
        # print(num_ls[j],num_ls[j+1])
    fin_res = num_ls[-1]
    # print(fin_res)
    if minv > fin_res:
        minv = fin_res
    if maxv <= fin_res:
        maxv = fin_res
print(maxv)
print(minv)