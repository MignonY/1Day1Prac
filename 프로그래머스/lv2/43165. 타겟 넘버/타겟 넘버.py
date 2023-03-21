def solution(numbers, target):
    global inputls, fin_ans,cnt,cls
    inputls = numbers
    fin_ans = target
    Combi(0,len(numbers))

    answer = cnt
    # print(cnt)
    return answer


ls = [-1,1]
temp = []
cnt = 0

def Combi(depth,num):
    global temp, inputls, cnt, fin_ans,cls
    if depth == num:
        cls = list(inputls)
        # print(temp)
        for i in range(num):
            cls[i] *= temp[i]
        # print(cls, sum(cls))
        if sum(cls) == fin_ans:
            cnt += 1
        return

    for idx in range(len(ls)):
        temp.append(ls[idx])
        Combi(depth+1,num)
        temp.pop()


