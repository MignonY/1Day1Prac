input()
ls_N = list(map(int, input().split()))
a = int(input())
count= 0
for num in ls_N:
    if num == a:
        count+=1
        
print(count)