N=int(input())
sc_ls= list(map(int, input().split()))

sc_ls.sort()
for i in range(len(sc_ls)):
    sc_ls[i]= sc_ls[i]/sc_ls[-1]*100

print(sum(sc_ls)/N)