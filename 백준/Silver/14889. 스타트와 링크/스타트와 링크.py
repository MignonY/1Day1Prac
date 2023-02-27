N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
ls = [i for i in range(N)]
visit = [False for _ in range(N)]
perm = [0 for _ in range(2)]
# for i in range(N):
#     print(arr[i])
val = 0

def plus(ls,n): # 팀 능력치 구하는 함수
    global val
    if n == 2:
        # print(perm,'*')
        # print(arr[perm[0]][perm[1]])
        val += arr[perm[0]][perm[1]]
        return
    for i in range(len(ls)):
        if visit[i] == 0:
            visit[i] = 1
            perm[n] = ls[i]
            plus(ls, n+1)
            visit[i] = 0

    return val


minv = 100000
def DFS(n,ans):
    global minv
    global val
    if n == len(ls):
        if len(ans) == len(ls)//2:
            start = ans
            link = []
            for i in range(len(ls)):
                if i not in start:
                    link.append(i)

            val = 0
            start_v = plus(start, 0)
            val = 0
            link_v = plus(link,0)

            if minv > abs(start_v - link_v):
                minv = abs(start_v - link_v)
        return

    ans.append(ls[n])
    DFS(n+1,ans)
    ans.pop()
    DFS(n+1,ans)
    return


DFS(0,[])
print(minv)