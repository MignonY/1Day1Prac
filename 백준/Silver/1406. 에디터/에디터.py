ch = input()
N = len(ch)
tc = int(input())
class NODE():
    def __init__(self):
        self.data = 0
        self.prev = 0
        self.next = 0

head = NODE()
head.prev = head
head.next = head

for i in range(N):
    new_node = NODE()
    new_node.data = ch[i]
    new_node.prev = head.prev
    new_node.next = head

    head.prev.next = new_node
    head.prev = new_node

# C = len(ch)
# traverse = head.next
#
# while C:
#     print(traverse.data)
#     traverse = traverse.next
#     C -= 1
C = len(ch)

curs = head.prev
for t in range(tc):
    cmls = list(input())
    # print(cmls)
    # print(curs.data,'check')
    if cmls[0] == 'L':
        if curs != head:
            curs = curs.prev
    elif cmls[0] == 'D':
        if curs.next != head:
            curs = curs.next
    elif cmls[0] == 'P':
        new_node = NODE()
        new_node.data = cmls[2]
        new_node.next = curs.next
        new_node.prev = curs

        curs.next.prev = new_node
        curs.next = new_node
        curs = new_node
        C += 1
    elif cmls[0] == 'B':
        if curs != head:
            curs.prev.next = curs.next
            curs.next.prev = curs.prev
            curs = curs.prev
            C -= 1


traverse = head.next
# print(C)
while C:
    print(traverse.data,end='')
    traverse = traverse.next
    C -= 1

