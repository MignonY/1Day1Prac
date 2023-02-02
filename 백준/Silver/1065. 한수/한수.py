# 자리수 하나씩 출력해서 리스트에 넣기
def divm(n): 
    init = n % 10 #4
    DM= []
    DM.append(init)
    while n>9:
        n= n//10  #123 
        a= n%10 #3
        DM.append(a)
    
    return DM
#divm 테스트

def HAN(X):
    lsdm =divm(X)
    # han = []
    if X<=100:
        pass
    elif lsdm[0]+lsdm[2] == lsdm[1] *2:
        return True
 
    


N=int(input())
fin=[]


for i in range(1,N+1):
    if HAN(i)==True:
        fin.append(N)  
    else:
        pass

if N<100:
    print(N)
elif N== 1000:    
    print(99+len(fin)-1)
else:
     print(99+len(fin)) 