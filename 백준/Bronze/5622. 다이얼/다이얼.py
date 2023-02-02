dial = {2:['A','B','C'], 3:['D','E','F'],
        4:['G','H','I'], 5:['J','K','L'],
        6:['M','N','O'], 7:['P','Q','R','S'],
        8:['T','U','V'], 9:['W','X','Y','Z']}

word = input()
cnt = 0

for w in word:   
    for key,value in dial.items():
        if w in value:
            cnt += key+1


print(cnt)