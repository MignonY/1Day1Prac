from string import ascii_lowercase

word = list(input())
alpha = list(ascii_lowercase)

for i in range(len(alpha)):
    if alpha[i] in word:
        alpha[i]=word.index(alpha[i])
    else:
        alpha[i] = -1

answer = list(map(str, alpha))        
final= " ".join(answer)
        

print(final)