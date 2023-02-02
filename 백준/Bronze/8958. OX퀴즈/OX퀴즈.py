a = int(input())
for i in range(a):
    word = input()
    sum = 0
    count = 0
    for w in word:
        if w == 'O':
            count += 1
        else:
            count = 0
        sum += count
        
    print(sum)
