W = input()
i=0
w_list=[]
cr_list ={"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="}

while i<len(W):
    
    if W[i:i+3] in cr_list:
        w_list.append(W[i:i+3])
        i+=2
    elif W[i:i+2] in cr_list:
        w_list.append(W[i:i+2])
        i+=1
    else:
        w_list.append(W[i])
    
    i+=1
    
print(len(w_list))

