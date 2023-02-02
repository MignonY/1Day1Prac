H ,M = map(int, input().split())
if M >= 45:
    M -= 45    
elif M < 45 and H >= 1:
    H -= 1
    M += 15
elif M < 45 and H == 0:
    H = 23
    M += 15

print(H , M)