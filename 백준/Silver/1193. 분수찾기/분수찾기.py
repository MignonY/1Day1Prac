a=int(input())


start=1
i = 0
while a>=start:  
    start += i
    i+=1


fnum = start-i+1
sum_bunsu = i

bunsu_a = 1+ (a-fnum)
bunsu_b = i - bunsu_a

if i%2 ==1:
    print(f'{bunsu_a}/{bunsu_b}')
if i%2 ==0:    
    print(f'{bunsu_b}/{bunsu_a}')