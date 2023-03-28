def solution(sizes):
    N = len(sizes)
    for i in range(N):
        sizes[i].sort(reverse=True)
    maxg = 0
    maxs = 0
    for i in range(N):
        if maxg < sizes[i][0]:
            maxg = sizes[i][0]
        if maxs < sizes[i][1]:
            maxs = sizes[i][1]
    # print(maxg,maxs)
    answer = maxg*maxs

    return answer


# solution([[60, 50], [30, 70], [60, 30], [80, 40]])