n= int(input())

def fiv(a):
    if a<1:
        return 0
    if a==1:
        return 1

    
    return fiv(a-1) + fiv(a-2)

print(fiv(n))