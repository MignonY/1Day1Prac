A,B,C = map(int, input().split())
if A==B==C:
    print(10000+A*1000)
elif A==B!=C:
    print(1000+A*100)
elif A==C!=B:
    print(1000+A*100)
elif B==C!=A:
    print(1000+B*100)
elif A>B>C:
    print(A*100)
elif A>C>B:
    print(A*100)
elif B>A>C:
    print(B*100)
elif B>C>A:
    print(B*100)
else:
    print(C*100)
