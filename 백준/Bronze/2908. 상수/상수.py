ls = list(map(str, input().split()))

fn= list(map(str,ls[0]))
sn= list(map(str,ls[1]))
fn.reverse()
sn.reverse()
jn = ["".join(fn),"".join(sn)]
fin= list(map(int, jn))
fin.sort(reverse=True)

# print(fn)        
# print(sn)
# print(jn)
# print(fin)
print(fin[0])