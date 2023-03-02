T = int(input())
for test_case in range(1,T+1):
    ls = list(map(int,input().split()))
    ls.pop(0)

    cnt = 0
    for i in range(len(ls)-1,0,-1):
        for j in range(i):
            if ls[j] > ls[j+1]:
                ls[j], ls[j+1] = ls[j+1], ls[j]
                cnt +=1


    print(f'{test_case}', cnt)