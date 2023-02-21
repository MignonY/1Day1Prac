import sys
input = sys.stdin.readline

# N>K 또는 N = K 또는 N<K
# K = 0 / 1 / 2일때 체크
# 큐범위 출력용으로 건드렸으면 다시 숫자 돌려주기
# 2 갔다가 다시 2로 돌아올 경우는..?

N, K = map(int,input().split())

if N==K:
    print(0)
elif N>K:
    print(N-K)

else:
    graph = [[] for _ in range(200000)]
    visit = [0 for _ in range(K*2)]
    queue = [0 for _ in range(K*2)]

    graph[0].append(1)
    graph[0].append(0)
    for i in range(1,len(graph)):
        graph[i].append(i+1)
        graph[i].append(i-1)
        graph[i].append(i*2)

    def BFS(start_v):
        rear = -1
        front = 0

        rear += 1
        queue[rear] = start_v
        visit[start_v] = 1

        while rear +1 != front:
            current = queue[front]
            # print(queue)
            front +=1
            for i in graph[current]:
                if i> K+1:
                    continue
                if visit[i] == 0:
                    rear +=1
                    queue[rear] = i
                    # print(visit)
                    visit[i] = 1+ visit[current]
                    if i == K:
                        return

    # print(graph)



    BFS(N)
    # print(visit)
    print(visit[K] - 1)