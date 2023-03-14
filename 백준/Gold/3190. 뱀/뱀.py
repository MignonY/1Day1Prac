N = int(input())
K = int(input())
arr = [[0]*N for _ in range(N)]
for i in range(K):
    p,o = map(int,input().split())
    # print(p-1,o-1)
    arr[p-1][o-1] = 3               # 지도에사과표시
L = int(input())
cmls = []
for i in range(L):
    Y,C = input().split()
    cmls.append((int(Y), C))
# print(cmls)




#시작: 오른쪽


dy = [-1,0,1,0] #상우하좌
dx = [0,1,0,-1]

class NODE():
    def __init__(self):
        self.yx = 0
        self.dirr = 0
        self.next = 0
        self.prev = 0

nodecnt = 0

head = NODE()
head.next = head  # 더미설정
head.prev = head
head.dirr = 1

new_node = NODE() #첫좌표(뱀머리)설정
new_node.yx = (0,0)
new_node.next = head
new_node.prev = head.prev
head.prev.next = new_node
head.prev = new_node
nodecnt += 1
arr[0][0] = 1


time = 0
while True:
    # print(new_node.yx, 'before')
    ny = head.prev.yx[0] + dy[head.dirr]
    nx = head.prev.yx[1] + dx[head.dirr]

    # 1.가려는곳이 맵 밖이면 종료
    if ny >= N or ny < 0 or nx >= N or nx < 0:
        # print("break,out")
        break

    # 2.노드순회하면서 몸통 좌표인지 확인 (가려는곳이 몸통이면 종료)
    if arr[ny][nx] == 1:
        # print("break,body")
        break

    # 아니면 노드에 그대로 추가 (머리의 이동)
    new_node = NODE()
    new_node.yx = (ny, nx)
    new_node.next = head
    new_node.prev = head.prev
    head.prev.next = new_node
    head.prev = new_node
    nodecnt += 1
    time +=1
    # print(new_node.yx, 'after')
    # print(time,'time')

    # print(nodecnt,'nodecnt')

    #사과체크
    if arr[ny][nx] == 3:
        arr[ny][nx] = 1
    else:
        arr[ny][nx] = 1
        arr[head.next.yx[0]][head.next.yx[1]] = 0
        head.next.next.prev = head
        head.next = head.next.next
        nodecnt -= 1


    # print(nodecnt,'nodecnt')

    # 노드순회하면서 좌표목록확인
    tnc = nodecnt
    traverse = head.next
    while tnc > 0:
        # print(traverse.yx,'check')
        traverse = traverse.next
        tnc -= 1

    # for i in range(N):
    #     print(arr[i])

    for i in range(L):
        if time == cmls[i][0]:
            if cmls[i][1] == 'D':
                # print('D', time,'************')
                head.dirr = (head.dirr + 1) % 4
            elif cmls[i][1] == 'L':
                # print('L',time,'*************')
                head.dirr = (head.dirr + 3) % 4



print(time+1)
