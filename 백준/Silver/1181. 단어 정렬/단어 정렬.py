N= int(input())
ls = [input() for _ in range (N)]
ls = list(set(ls))



ls.sort(key = lambda str: (str[0],str[1:]))
ls.sort(key= len)


for i in ls:
    print(i)