def solution(phone_book):
    answer = True
    # print(phone_book)
    phone_book.sort(key=lambda x: (len(x), x[0]))
    dic = {}
    Flag = False
    for i in range(len(phone_book)):
        for j in range(len(phone_book[i])):
            # print(phone_book[i][0:j+1])
            if phone_book[i][0:j+1] in dic:
                Flag = True
                break
        if Flag:
            break
        else:
            dic[phone_book[i]] = 1

    if Flag:
        answer = False

    # print(answer)
    return answer





# solution(["2342", "12", "97674223", "1195524421", "45388","499"])
# solution(["119", "97674223", "1195524421"])
# solution(["123","456","789"])