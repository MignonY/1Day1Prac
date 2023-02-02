n=int(input())
count =0
        
for i in range(n):          #단어 하나씩 받기
    word = input()
    dic = {}
        
    for i in range(len(word)):          #철자 하나씩 확인               
        if word[i] in dic:    #딕쇼노리에 키가 이미 존재할 때 
            if word[i] == word[i-1]:
                True
                dic[word[i]]=1
            else:
                False
                count+=1
                break
                
        else:               #딕쇼노리에 키 없닷
            dic[word[i]]=1   #키 넣고 다시 반복이닷{}
                          
                    

                 
print(n-count)