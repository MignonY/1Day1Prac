T = int(input())

for i in range(T):
    a = int(input())
    b = int(input())
    
    # TC =[int(input()) for _ in range(T)]
    # TC2=[int(input()) for _ in range(T+1,T+3)]

    # print(TC) #1,3  = 0,1 + 0,2 + 0,3
    # print(TC2) #2,3 = 1,1 + 1,2 + 1,3


    def apart(a,b):
        ap = [[int(0) for _ in range (b+1)] for _ in range(a+2) ] 
        for i in range(0,a+1): # 0 1 2
            for j in range(0,b+1): # 1 2 3
                ap[0][j] = j
                ap[i+1][j] = sum(ap[i][:j+1])
        # print(ap)        
        return ap[a][b]

    print(apart(a,b))

