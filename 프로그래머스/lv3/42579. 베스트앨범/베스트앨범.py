def solution(genres, plays):
    dic = {}
    info_ls = []
    for i in range(len(genres)):
        if genres[i] in dic:
            dic[genres[i]] += plays[i]
        else:
            dic[genres[i]] = 0
            dic[genres[i]] += plays[i]

    # print(dic)

    for i in range(len(genres)):
        info_ls.append([i,genres[i],plays[i]])

    # print(info_ls)


    info_ls.sort(key = lambda x: (dic[x[1]], x[2]), reverse=True)

    # print(info_ls)

    answer = []
    dic_best = {}
    for i in range(len(info_ls)):
        if info_ls[i][1] in dic_best:
            dic_best[info_ls[i][1]] += 1
        else:
            dic_best[info_ls[i][1]] = 0
            dic_best[info_ls[i][1]] += 1

        if dic_best[info_ls[i][1]] <=2:
            answer.append(info_ls[i][0])
        else:
            continue

    # print(dic_best)
    # print(answer)

    return answer



# solution(["classic", "pop", "classic", "classic", "pop"],[500, 600, 150, 800, 2500])