alpha = input() #aaabbc
alpha = alpha.upper()
ls_a = list(set(alpha)) #abc
cnt = []            #321

for i in ls_a:
    count = alpha.count(i) 
    cnt.append(count)
    
if cnt.count(max(cnt))>=2:
    print("?")
else:
    print(ls_a[cnt.index(max(cnt))])
