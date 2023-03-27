
def solution(begin, target, words):
    global begin_,target_,words_,visit,queue
    begin_= begin
    target_= target
    words_= words
    visit = [0 for _ in range(len(words_))]
    queue = [0 for _ in range(10000)]

    answer = BFS(begin,0)
    print(answer)
    # answer = 0
    return answer


def BFS(word, depth):
    global visit
    rear = -1
    front = 0
    rear += 1
    depth = 0
    queue[rear] = (word, depth, visit)

    while rear +1 != front:
        current = queue[front][0]
        depth = queue[front][1]
        visit = list(queue[front][2])
        front += 1
        # print(f'current:{current}')
        if current == target_:
            return depth

        for i in range(len(words_)):
            cnt = 0
            # print(i,words_[i])
            for j in range(len(words_[i])):
                if visit[i] != 1 and (words_[i][j] == current[j]):
                    cnt += 1
            if cnt == len(words_[i])-1:
                # print(words_[i])
                rear += 1
                visit[i] = 1
                # print(visit,'visit')
                queue[rear] = (words_[i], depth+1, list(visit))
                visit[i] = 0


        if rear +1 == front:
            if current != target_:
                return 0

