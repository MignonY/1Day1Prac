class NODE():
    def __init__(self):
        self.data = 0
        self.next = 0
        self.prev = 0

q = int(input())
for t in range(q):
    cmls = list(map(int,input().split()))
    print(cmls)
    if cmls[0] == 100:
        n = cmls[1]
        m = cmls[2]
        C = [NODE() for _ in range(n+1)]
        scnt = [0 for _ in range(n+1)]
        for i in range(1,n+1):
            head = C[i]
            head.prev = head
            head.next = head
        for i in range(3,len(cmls)):
            new_node = NODE()
            new_node.data = i-2
            print(i-2,'d')
            scnt[cmls[i]] += 1
            new_node.prev = C[cmls[i]].prev
            new_node.next = C[cmls[i]]

            C[cmls[i]].prev.next = new_node
            C[cmls[i]].prev = new_node

        print(scnt)
        for i in range(1,n+1):
            cnt = scnt[i]
            traverse = C[i].next
            while cnt:
                print(f'C:{i}, data:{traverse.data}')
                traverse = traverse.next
                cnt -= 1


    #
    #     print(C)
    # if cmls[0] == 200:
    #