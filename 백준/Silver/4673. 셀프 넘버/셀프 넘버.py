#함수 정의 
def d(n):
    init = n
    a = n%10  
    while n>0:
        n= n//10 
        a = a + n%10  
        
    # print(init,init+a)  
    return init + a



ls_d= []  #생성자가 있는 것들 무한생성 

for i in range(1,10000): 
    ls_d.append(d(i))
    i += 1

ls_d.sort()  #오름차순정렬 
ls_n = []    # 생성자가 있는 것들 중 특정 수 미만인것만 추출
#print(ls_d)

for num in ls_d[:]:
    if num < 10000:               # 100 -> 10000 변경필요  (100은 테스트용 )
        ls_n.append(num)
   
#print(ls_n)

# 1부터 특정숫자까지를 아까 추출한 리스트에 넣음 (10000) 넣을예정 

for j in range(1,10000):          # range(a,b)일때 a는 시작숫자, 마지막숫자는 b-1임 (b제외)
    ls_n.append(j)

ls_n.sort()     #중복 잘 확인하기 위해 정렬 (불필요할수도)
#print(ls_n)

# 이제 리스트를 돌면서 요소를 딕셔너리의 키값에 넣어줄거임 (중복제거가능)
# 그리고 밸류값은 중복된 만큼을 넣어줄거임

dic_fin = {}

for lnum in ls_n:
    try:
        dic_fin[lnum] += 1
    except:
        dic_fin[lnum] = 1

#print(dic_fin)

for key,value in dic_fin.items():
    if value == 1:
        print(key) 

