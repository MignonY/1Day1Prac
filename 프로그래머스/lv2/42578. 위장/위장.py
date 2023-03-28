def solution(clothes):
    dic = {}
    for i in range(len(clothes)):
        if clothes[i][1] in dic:
            dic[clothes[i][1]].append(clothes[i][0])
        else:
            dic[clothes[i][1]] = []
            dic[clothes[i][1]].append(clothes[i][0])
    # print(dic)

    cnt = []
    for key, value in dic.items():
        if len(value) == 1:
            cnt.append(2)
        elif len(value) >= 2:
            cnt.append(len(value)+1)

    ans = 1
    for i in range(len(cnt)):
        ans *= cnt[i]

    answer = ans -1
    # print(answer)
    return answer


# solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]])
# solution([["crow_mask", "face"], ["blue_sunglasses", "face"], ["smoky_makeup", "face"]])