class NODE():
    def __init__(self):
        self.data = 0
        self.prev = 0
        self.next = 0

N = int(input())
for tc in range(N):
    ch = input()

    head = NODE()
    head.next = head
    head.prev = head

    C = 0
    curs = head
    for i in range(len(ch)):
        # print(curs.data,'d')
        if curs == head and (ch[i] == '<' or ch[i]=='-'):
            # 커서가 맨앞인데 문자 아닌게 들어왔을때
            continue
        elif ch[i]!='<' and ch[i]!='>' and ch[i] != '-':
            new_node = NODE()
            new_node.data = ch[i]

            if curs.next == head:
                new_node.prev = head.prev
                new_node.next = head

                head.prev.next = new_node
                head.prev = new_node

                curs = new_node
            else:
                new_node.prev = curs
                new_node.next = curs.next

                curs.next = new_node
                new_node.next.prev = new_node

                curs = new_node
            # print(new_node.data,'check')
            C += 1

        elif ch[i] == '<': # <방향키가 나옴
            curs = curs.prev
        elif ch[i] == '>' and curs.next != head: # >방향키
            curs = curs.next
        elif ch[i] == '-' and curs.data!=0:
            # 백스페이스 나왔고 이전꺼 문자열일때
            curs.prev.next = curs.next # 문자 노드 삭제
            curs.next.prev = curs.prev
            curs = curs.prev
            C-=1
        # print(curs.data,'D')

    # print(C,'c')
    traverse = head.next # 순회
    while C:
        print(traverse.data,end='')
        traverse = traverse.next
        if traverse == head:
            traverse = traverse.next

        C -= 1
    print()

