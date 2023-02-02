import sys
ls = [int(sys.stdin.readline()) for _ in range(5)]
max = 0
for i in range(len(ls)):
    if max < ls[i]:
        max = ls[i] 

cnt = [0] * (max+1)
arr = [0] * len(ls)

for i in range(len(ls)):
    cnt[ls[i]] += 1
    
for i in range(1,len(cnt)):
    cnt[i] += cnt[i-1]

for i in range(len(ls)-1,-1,-1):
    cnt[ls[i]] -=1
    arr[cnt[ls[i]]] = ls[i]
    
#총합구해서 평균
sum = 0
for i in range(len(arr)):
    sum += arr[i] 
    
print(sum//5)
print(arr[2])