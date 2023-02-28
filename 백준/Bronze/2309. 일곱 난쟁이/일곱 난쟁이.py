ls= []
for i in range(9):
    ls.append(int(input()))

# print(ls)
temp = []
def Combi(n,ls,ans,temp):
    if n == len(ls):
        if len(ans) == 7:
            if sum(ans) == 100:
                temp.append(list(ans))
                temp[0].sort()
        return

    ans.append(ls[n])
    Combi(n+1,ls,ans,temp)
    ans.pop()
    Combi(n+1,ls,ans,temp)

Combi(0,ls,[],temp)

for i in range(7):
    print(temp[0][i])