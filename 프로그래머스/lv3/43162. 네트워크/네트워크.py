def solution(n, computers):
    global visit,arr
    arr = computers
    visit = [0 for _ in range(n)]

    answer = 0
    start = 0

    for i in range(n):
        if visit[i] == 1:
            continue
        else:
            start = i
            answer += 1
            DFS(start)
        # print(i,visit)
        # print(i,answer)
    return answer


def DFS(n):
    global visit,arr
    visit[n] = 1

    for i in range(len(arr[n])):
        if visit[i] != 1 and arr[n][i] == 1:
            DFS(i)