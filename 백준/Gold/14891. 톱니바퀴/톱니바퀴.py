#N극 = 0 S극 = 1
#맞닿는부분 2(1)-6(2) /2(2)-6(3)/ 2(4) 끼리
#만약 1이면 1>2>3>4/ 만약 2면 2>1, 2>3>4 // 만약 3이면 3>4, 3>2>1 // 4면 4>3>2>1
#def 시계방향회전(1)
#def 반시계회전(-1)

def Rotate(ls):
    new_ls= [0,0,0,0,0,0,0,0]
    for i in range(8):
        new_ls[i] = ls[i-1]
    return new_ls

def Rotate_Rev(ls):
    new_ls = [0,0,0,0,0,0,0,0]
    for i in range(8):
        new_ls[i] = ls[(i+1)%8]
    return new_ls

arr = [list(map(int,input())) for _ in range(4)]
K = int(input())
graph = [[1],[0,2],[1,3],[2]]

for i in range(K):
    visit = [0, 0, 0, 0]
    visited = []
    num, dir = map(int,input().split())
    save_dir = 2
    if dir == 1:
        save_dir = 1

    else:
        save_dir = -1
    sup_save_dir = save_dir
    def DFS(start_v):
        global save_dir, sup_save_dir
        current = start_v
        visit[start_v] = save_dir
        visited.append(current)
        for i in graph[current]:
            if visit[i] == 0:
                if current > i:
                    if arr[current][6] != arr[i][2]: #톱니 다를때
                        if save_dir == 2:
                            visit[i] = 2
                            save_dir = 2
                        elif save_dir == 1:
                            visit[i] = -1
                            save_dir = -1
                        elif save_dir == -1:
                            visit[i] = 1
                            save_dir = 1

                    else:                           #톱니 같을때
                        visit[i] = 2
                        save_dir = 2

                if current < i:
                    if current == num-1:
                        save_dir = sup_save_dir
                    if arr[current][2] != arr[i][6]:  # 톱니 다를때
                        if save_dir == 2:
                            visit[i] = 2
                            save_dir = 2
                        elif save_dir == 1:
                            visit[i] = -1
                            save_dir = -1
                        elif save_dir == -1:
                            visit[i] = 1
                            save_dir = 1

                    else:  # 톱니 같을때
                        visit[i] = 2
                        save_dir = 2
                DFS(i)

    DFS(num-1)

    for i in range(4):
        if visit[i] == 1:
            arr[i] = Rotate(arr[i])

        elif visit[i] == -1:
            arr[i] = Rotate_Rev(arr[i])
    # #
    # print(visited)
    # print(visit)
    #
    # for i in range(4):
    #     print(arr[i])


#1248
ans = 0
for i in range(4):
    if arr[i][0] == 1:
        ans += 2 ** i


print(ans)