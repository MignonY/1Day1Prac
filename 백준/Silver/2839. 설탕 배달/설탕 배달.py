N = int(input())



def sugar(N):
    a=N//5 +1
    if N % 5 == 0:
        print(N//5)
        
    
    elif N % 5 != 0:
        while a>=1:
            a -=1
            if (N - (5*a)) % 3 == 0:
                b = (N-(5*a))//3
                print(a+b)
                return
    
        if N % 3 == 0:
            print(N//3)
            
        else:
            print(-1)
       


        
sugar(N)