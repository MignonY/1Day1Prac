n=int(input())
temp = n
count = 0

while True:
    a = n // 10     #2   
    b = n % 10     #6     
    c = (a + b) % 10    #8
    n = (b*10) + c  #68

    count = count +1
    if(n == temp):
        break
    
print(count)
