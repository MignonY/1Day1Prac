N_list = []
for i in range(9) :
    N_list.append(int(input()))  			

print(max(N_list))						
print(N_list.index(max(N_list))+1)