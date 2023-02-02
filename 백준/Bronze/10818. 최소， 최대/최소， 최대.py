N = int(input())
ls_N = list(map(int, input().split()))
ls_N.sort()


print(ls_N[0],ls_N[N-1])