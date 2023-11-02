class NODE():
    def __init__(self):
        self.data = 0
        self.next = 0
        self.prev = 0


def mv_200(m_src, m_dst):
    # src의 노드줄기 떼다가 dst의 헤드와 첫노드 사이로 이식
    if scnt[m_src] > 0 :
        C[m_src].next.prev = C[m_dst]
        C[m_src].prev.next = C[m_dst].next

        C[m_dst].next.prev = C[m_src].prev
        C[m_dst].next = C[m_src].next

        C[m_src].prev = C[m_src]
        C[m_src].next = C[m_src]

        #노드개수갱신
        scnt[m_dst] += scnt[m_src]
        scnt[m_src] = 0

def mv_300(m_src, m_dst):
    # m_src 첫번째꺼랑 m_dst 첫번째꺼 교환
    # 둘중 하나가 비어있으면 그냥 받음

    #노드개수 조건 
    if scnt[m_src] > 0 and scnt[m_dst] > 0:
        #데이터만 쏙 교환
        C[m_src].next.data, C[m_dst].next.data = C[m_dst].next.data, C[m_src].next.data
        prls[C[m_src].next.data], prls[C[m_dst].next.data] = prls[C[m_dst].next.data], prls[C[m_src].next.data]
 
    elif scnt[m_src] == 0 and scnt[m_dst] > 0:
        # m_dst에서 앞에꺼 하나만 끊어다가 m_src 헤드에 붙임
        # src 헤드에서 앞뒤연결
        C[m_src].prev = C[m_dst].next
        C[m_src].next = C[m_dst].next
        # print(C[m_dst].next.data, C[m_dst].next.next.data, 'check')

        # dst 두번째노드의 prev 헤드에 연결
        C[m_dst].next.next.prev = C[m_dst]

        # dst 헤드에서 두번째노드 연결 (첫번째노드갱신)
        C[m_dst].next = C[m_dst].next.next

        # 옮겨진 노드의 next prev 갱신
        C[m_src].next.next = C[m_src]
        C[m_src].next.prev = C[m_src]

        # print(C[m_dst].data, C[m_dst].next.data, C[m_dst].next.next.data, 'check')
        scnt[m_src] += 1
        scnt[m_dst] -= 1

    elif scnt[m_dst] == 0 and scnt[m_src] > 0:
        C[m_dst].prev = C[m_src].next
        C[m_dst].next = C[m_src].next

        # src 두번째노드의 prev 헤드에 연결
        C[m_src].next.next.prev = C[m_src]

        # src 헤드에서 두번째노드 연결 (첫번째노드갱신)
        C[m_src].next = C[m_src].next.next

        # 옮겨진 노드의 next prev 갱신
        C[m_dst].next.next = C[m_dst]
        C[m_dst].next.prev = C[m_dst]

        scnt[m_dst] += 1
        scnt[m_src] -= 1

def mv_400(m_src, m_dst):
    # src의 n//2번째까지 떼서 dst의 헤드와 첫노드 사이로 이식
    if scnt[m_src] > 1:
        tcnt = scnt[m_src]//2
        # 끊어야하는 해당 위치까지 일단 순회
        current = C[m_src]
        while tcnt > 0:
            # print(current.data,'cur')
            current = current.next
            tcnt -= 1

        #m_src에서 빠져나간 자리 메꾸기
        current.next.prev = C[m_src]
        svnode= current.next

        # current 까지 끊어서 m_dst 앞에다 이식
        current.next = C[m_dst].next
        C[m_src].next.prev = C[m_dst]

        #m_dst에서 받아주기
        C[m_dst].next.prev = current
        C[m_dst].next = C[m_src].next

        # print(C[m_dst].prev.data, C[m_dst].next.data)
        # print(current.prev.data, current.next.data)
        #m_src에서 빠져나간 자리 메꾸기 2
        C[m_src].next = svnode

        #노드개수갱신
        scnt[m_dst] += scnt[m_src]//2
        scnt[m_src] -= scnt[m_src]//2



q = int(input())
for t in range(q):
    cmls = list(map(int,input().split()))
    # print(cmls)
    # 1번 공장만들기
    if cmls[0] == 100:
        n = cmls[1]
        m = cmls[2]
        C = [NODE() for _ in range(n+1)]
        scnt = [0 for _ in range(n+1)]
        prls = [0 for _ in range(m+1)]
        for i in range(1,n+1):
            head = C[i]
            head.prev = head
            head.next = head
        for i in range(3,len(cmls)):
            new_node = NODE()
            new_node.data = i-2
            scnt[cmls[i]] += 1
            new_node.prev = C[cmls[i]].prev
            new_node.next = C[cmls[i]]

            C[cmls[i]].prev.next = new_node
            C[cmls[i]].prev = new_node

            prls[i-2] = new_node

        # print(scnt)
        # 순회체크코드
        # for i in range(1,n+1):
        #     cnt = scnt[i]
        #     traverse = C[i].next
        #     while cnt:
        #         print(f'C:{i}, data:{traverse.data}')
        #         traverse = traverse.next
        #         cnt -= 1

    # 2번 교환코드 // C[num] = 해당 컨테이너 노드줄기의 헤드
    elif cmls[0] == 200:
        m_src = cmls[1] # ex - 2
        m_dst = cmls[2] # ex - 4
        mv_200(m_src, m_dst)

        # print(scnt,'scnt')
        # # 순회체크코드
        # for i in range(1, n + 1):
        #     cnt = scnt[i]
        #     traverse = C[i].next
        #     while cnt:
        #         print(f'C:{i}, data:{traverse.data}')
        #         traverse = traverse.next
        #         cnt -= 1

        print(scnt[m_dst])

    elif cmls[0] == 300:
        m_src = cmls[1]  # ex - 2
        m_dst = cmls[2]  # ex - 4
        mv_300(m_src, m_dst)

        # print(scnt, 'scnt')
        # # 순회체크코드
        # for i in range(1, n + 1):
        #     cnt = scnt[i]
        #     traverse = C[i].next
        #     while cnt:
        #         print(f'C:{i}, data:{traverse.data}')
        #         traverse = traverse.next
        #         cnt -= 1

        print(scnt[m_dst])

    elif cmls[0] == 400:
        m_src = cmls[1]  # ex - 4
        m_dst = cmls[2]  # ex - 2
        mv_400(m_src, m_dst)
        # print(scnt, 'scnt')
        # # 순회체크코드
        # for i in range(1, n + 1):
        #     cnt = scnt[i]
        #     traverse = C[i].next
        #     while cnt:
        #         print(f'C:{i}, data:{traverse.data}')
        #         traverse = traverse.next
        #         cnt -= 1

        print(scnt[m_dst])

    elif cmls[0] == 500:
        p_num = cmls[1]
        # print(scnt, 'scnt')
        ans5 = 0
        # 정답 도출 코드
        traverse = prls[p_num]
        tpd = traverse.prev.data
        tnd = traverse.next.data
        if tpd == 0:
            tpd = -1
        if tnd == 0:
            tnd = -1
        ans5 = tpd + (2 * tnd)
        print(ans5)

    elif cmls[0] == 600:
        b_num = cmls[1]
        # print(scnt, 'scnt','600')

        # 정답 도출코드
        cnt = scnt[b_num]

        a = C[b_num].next.data
        b = C[b_num].prev.data
        c = cnt

        if a == 0:
            a = -1
        if b == 0:
            b = -1

        ans6 = a + (2*b) + (3*c)
        # while cnt:
        #     print(f'C:{b_num}, data:{traverse.data}')
        #     traverse = traverse.next
        #     cnt -= 1

        print(ans6)
