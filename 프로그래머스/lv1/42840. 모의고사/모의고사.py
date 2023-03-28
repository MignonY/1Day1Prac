def solution(answers):
    supo1 = [1,2,3,4,5]
    supo2 = [2,1,2,3,2,4,2,5]
    supo3 = [3,3,1,1,2,2,4,4,5,5]
    sup = [0 for _ in range(4)]
    answer = []

    for i in range(len(answers)):
        if answers[i] == supo1[i % len(supo1)]:
            sup[1] += 1
        if answers[i] == supo2[i % len(supo2)]:
            sup[2] += 1
        if answers[i] == supo3[i % len(supo3)]:
            sup[3] += 1
    maxv = max(sup)
    for i in range(1,len(sup)):
        if sup[i] == maxv:
            answer.append(i)
    # print(answer)
    return answer
