def solution(tickets):
    global visit, arr, N, graph, visited, dic, dic_swap,answer,depth,grcnt
    arr = tickets
    dic = {}
    answer = []
    N = len(arr)
    visit = [0 for _ in range(N)]
    num = -1
    for i in range(N):
        for j in range(2):
            if arr[i][j] in dic:
                continue
            else:
                num +=1
                dic[arr[i][j]] = num

    graph = [[] for _ in range(len(dic))]
    grcnt = 0
    for i in range(len(arr)):
        graph[dic[arr[i][0]]].append(dic[arr[i][1]])
        grcnt += 1
    # print(arr)
    # print(graph)
    # for i in range(len(graph)):
    #     graph[i].sort()
    # print(graph)
    dic_swap = {v:k for k,v in dic.items()}


    for i in range(len(graph[dic['ICN']])):
        visit = list(map(list,graph))
        for j in range(len(visit)):
            for k in range(len(visit[j])):
                visit[j][k] = 0
        visited = [dic_swap[dic['ICN']],dic_swap[graph[dic['ICN']][i]]]
        visit[dic['ICN']][i] = -1
        DFS(graph[dic['ICN']][i],1)
        visit[dic['ICN']][i] = 0
    # print(f'ans={ans}')
    return ans



def DFS(n,depth):
    global grcnt,answer,ans
    # print(dic)
    # print(n,'n')
    # print(graph)
    # print()
    if depth == len(arr):
        iford = True
        # print(f'depth:{depth}, {visited}')
        # print(visited,'######', answer)
        if len(answer) == 0:
            answer = list(visited)
            # print('dd')
        else:
            for j in range(len(answer)):
                # print(j)
                if visited[j] != answer[j]:
                    if ord(visited[j][0]) > ord(answer[j][0]):
                        iford = False
                        break
                    elif ord(visited[j][0]) == ord(answer[j][0]):
                        if ord(visited[j][1]) > ord(answer[j][1]):
                            iford = False
                            break
                        elif ord(visited[j][1]) == ord(answer[j][1]):
                            if ord(visited[j][2]) > ord(answer[j][2]):
                                iford = False
                                break
                    break
            # print(iford)
            if iford:
                answer = list(visited)
        # print(answer,'ans')
        ans = list(answer)
        for i in range(len(visit[dic[visited[-2]]])):
            if graph[dic[visited[-2]]][i] == dic[visited[-1]]:
                visit[dic[visited[-2]]][i] = 0
                break
        visited.pop()
        return ans


    for i in range(len(graph[n])):
        if visit[n][i] != -1:
            visited.append(dic_swap[graph[n][i]])
            # print((n,i), 'depth=',depth)
            visit[n][i] = -1
            DFS(graph[n][i],depth+1)
            visit[n][i] = 0
            # print(n,'now?')

    # print()
    # print(visited, depth)
    # print(visit,n)
    # print(graph)
    # print()
    # for i in range(len(visit[dic[visited[-2]]])):
    #     if graph[dic[visited[-2]]][i] == dic[visited[-1]]:
    #         visit[dic[visited[-2]]][i] = 0
    #         break
    # print(depth, dic[visited[depth]],dic[visited[depth-1]])
    visited.pop()
    # print(visit, depth,'back',n)
    # print(visited)



