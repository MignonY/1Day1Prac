N = int(input())
ls = [[' ' for _ in range(N)] for _ in range (N)]


# (y,x) 좌표에서 N만큼의 크기의 별찍기를 하는 함수.
def star(y,x,N):

    if N ==1:
        ls[y][x] = '*'
        return 
       
    N=N//3
    for i in range(3):
        for j in range(3):
            if i==1 and j==1:
                continue

            star(y+ i*N, x+ j*N, N)

                                

star(0,0,N) 


for a in (ls):
    for b in a:
        print(b, end='')
    print()    



