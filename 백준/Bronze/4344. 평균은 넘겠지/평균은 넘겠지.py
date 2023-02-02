#일단 인풋받음 (테케개수)
#for문으로 인풋받고 테캐개수만큼 반복
#n=첫 수 = 분모
#s=나머지 수 다 합한거 = 분자
#s/n = 평균점수
#if list몇번째 > 평균점수 , 평균이상을 count 해서 
#  count / 첫숫자  == > round로 출력

import sys

TC = int(input())


for i in range(0,TC):
    count=0
    ls = list(map(int, sys.stdin.readline().split()))
    n = ls[0]
    s = sum(ls) - ls[0]
    AV = s/n 
    
    for j in range(0,len(ls)):
        if j>0 and ls[j]>AV:
            count+=1
      
    # print(AV)      
    # print(count)
    # print(n)
    answer = count/n*100
    print(f"{answer:.3f}%")