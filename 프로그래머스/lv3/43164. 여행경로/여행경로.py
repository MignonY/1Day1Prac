visited = ['ICN']
def solution(tickets):
    global graph,tnum
    for i in range(len(tickets)):
        for j in range(len(tickets[i])):
            tickets[i][j] = (ord(tickets[i][j][0])-65)*26*26 + (ord(tickets[i][j][1])-65)*26 + ord(tickets[i][j][2])-65

    tnum = len(tickets)
    # print(tickets)
    graph = [[] for _ in range(20000)]
    gr_ls = []
    for i in range(len(tickets)):
        graph[tickets[i][0]].append(tickets[i][1])
        if len(graph[tickets[i][0]]) > 1:
            gr_ls.append(tickets[i][0])

    for i in range(len(gr_ls)):
            graph[gr_ls[i]].sort()

    ICN = (ord("I")-65)*26*26 + (ord("C")-65)*26 + (ord("N")-65)
    DFS(ICN, 0)
    answer = visited
    return answer

def trans(num):
    temp = []
    t_char = ''
    a = 3
    while a >0:
        na = chr(num % 26 + 65)
        num //= 26
        temp.append(na)
        a-=1
    for i in range(len(temp)-1,-1,-1):
        t_char += temp[i]

    return t_char


def DFS(n,depth):
    global graph
    if depth == tnum:
        # print(visited)
        return True

    for i in range(len(graph[n])):
        if graph[n][i] != -1:
            next_go = graph[n][i]
            visited.append(trans(next_go))
            graph[n][i] = -1
            if DFS(next_go, depth+1) == True:
                return True
            visited.pop()
            graph[n][i] = next_go

    return False





# solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]])
# print(ord('A')-65)
# print(graph[5473])