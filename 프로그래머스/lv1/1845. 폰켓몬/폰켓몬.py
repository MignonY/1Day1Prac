def solution(nums):
    dic = {}
    N = len(nums)
    print(nums)
    for i in range(N):
        if nums[i] in dic:
            dic[nums[i]].append(i)
        else:
            dic[nums[i]] = []
            dic[nums[i]].append(i)

    print(dic)
    if len(dic) >= N//2:
        answer = N//2
    else:
        answer = len(dic)
    # print(answer)
    return answer

# solution([3,1,2,3])
# solution([3,3,3,2,2,4])