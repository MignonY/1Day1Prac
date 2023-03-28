def solution(participant, completion):
    dic = {}
    for i in range(len(participant)):
        if participant[i] in dic:
            dic[participant[i]] += 1
        else:
            dic[participant[i]] = 0
            dic[participant[i]] += 1

    # print(dic)

    for i in range(len(completion)):
        if completion[i] in dic:
            dic[completion[i]] -= 1

    answer = ""
    # print(dic)
    for key,value in dic.items():
        if value != 0:
            answer = key
    # print(answer)
    return answer


# solution(["mislav", "stanko", "mislav", "ana"],["stanko", "ana", "mislav"])