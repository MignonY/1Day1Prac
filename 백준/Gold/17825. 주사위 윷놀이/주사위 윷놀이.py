#인접리스트?

command = list(map(int, input().split()))
node_num = [0 for _ in range(33)]

class NODE():
    def __init__(self):
        self.data = 0 # 노드에적힌숫자
        self.mal = 0
        self.next = 0
        self.prior = 0
        self.nodenum =0
        self.ifprior = 0

head = NODE()
node_num[0] = NODE()
tail = head
for i in range(2,55,2):
    # print(i,' ',end='')
    new_node = NODE()
    node_num[i//2] = new_node
    new_node.data = i
    new_node.nodenum = i//2
    if i == 10 or i == 20 or i == 30:
        new_node.ifprior = 1
    tail.next = new_node
    tail = new_node
# print()

new_node = NODE()
node_num[21] = new_node
new_node.data = 13
new_node.nodenum = 21
new_node.ifprior = 1
node_num[5].prior = new_node
tail = new_node     # tail 13

for i in range(16,20,3): # 16 19
    # print(i,' ',end='')
    new_node = NODE()
    node_num[tail.nodenum+1] = new_node
    new_node.data = i
    new_node.nodenum = tail.nodenum +1
    new_node.ifprior = 1
    tail.prior = new_node
    tail = new_node
    # print(tail.nodenum,'check')

new_node = NODE()   #25 => nodenum 24
node_num[tail.nodenum+1] = new_node
new_node.data = 25
new_node.nodenum = tail.nodenum +1
new_node.ifprior = 1
tail.prior = new_node
tail = new_node

# 20 - 22
new_node = NODE()
node_num[tail.nodenum+1] = new_node #현재 TAIL 25임
new_node.data = 22
new_node.nodenum = tail.nodenum + 1
new_node.ifprior = 1
node_num[10].prior = new_node
tail = new_node     # tail 22, nodenum 25

# 22 - 24
new_node = NODE()
node_num[tail.nodenum+1] = new_node
new_node.data = 24
new_node.nodenum = tail.nodenum + 1
new_node.ifprior = 1
tail.prior = new_node
tail = new_node     # tail 24, nodenum 26

tail.prior = node_num[24] # 24 - 25

# 30 - 28
new_node = NODE()
node_num[tail.nodenum+1] = new_node
new_node.data = 28
new_node.nodenum = tail.nodenum + 1
new_node.ifprior = 1
node_num[15].prior = new_node
tail = new_node     # tail 28, nodenum 27

# 27 26
for i in range(27,25,-1): # 27, 26 > nodenum 28 29 // tail = 26
    # print(i,' ',end='')
    new_node = NODE()
    node_num[tail.nodenum+1] = new_node
    new_node.data = i
    new_node.nodenum = tail.nodenum +1
    new_node.ifprior = 1
    tail.prior = new_node
    tail = new_node
    # print(tail.nodenum,'check')

tail.prior = node_num[24] # 26> 25 // 현재 TAIL 26임

# 25 > 30
new_node = NODE()
node_num[30] = new_node
new_node.data = 30
new_node.nodenum = 30
new_node.ifprior = 1
node_num[24].prior = new_node
tail = new_node     # tail 30 nodenum 30
# 30 > 35
new_node = NODE()
node_num[31] = new_node
new_node.data = 35
new_node.nodenum = 31
new_node.ifprior = 1
tail.prior = new_node
tail = new_node     # tail 35 nodenum 31

# 35 > 40

tail.prior = node_num[20]
tail = node_num[20] # tail 40 nodenum 20

# 끝에 더미노드 여분으로 놓기
new_node = NODE()
node_num[32] = new_node
new_node.data = 0
new_node.nodenum = 32
new_node.ifprior = 1
tail.prior = new_node
tail.next = new_node
tail = new_node

###############################################################
###############################################################


ls = [0,1,2,3]
temp = []
saveyx = [head,head,head,head] # 말0123 현재 위치한 노드

# for i in range(21,33):
#     print(f'node_num = {i}, node_data = {node_num[i].data}, next = {node_num[i].prior.data}')
#  command = 주사위숫자
#  temp = 몇번째말 움직일건지 순열
# ttemp[i] = 현재말번호 // command[i] 현재 주사위숫자

# for i in range(len(node_num)):
#     print(node_num[i].nodenum, node_num[i].data, 'node')

maxv = 0
def perm(cnt):
    global maxv,saveyx
    if cnt == 10:
        hap = 0
        savenum = -1
        for q in range(4):
            saveyx[q].mal = 0
        saveyx = [head, head, head, head]
        # print(temp)
        for i in range(10): #커맨드랑 순열 동시에 돌기
            if temp[i] == savenum:
                break
            if saveyx[temp[i]].ifprior == 0:  # 현재 밟은게 빨강이다?
                traverse = saveyx[temp[i]]  # 일단 현재노드에서
                # print(traverse.data,'current',command[i])
                Flag = False  # (도착지 넘어가는거 체크 플래그)
                for cnt in range(command[i]):
                    traverse = traverse.next  # 숫자만큼 앞으로 감 (prior이동)
                    if traverse.data == 0:  # 가고있는데 도착점 넘어섬
                        saveyx[temp[i]].mal = 0
                        Flag = True  # 멈초
                        break
                if Flag:  # 다음 커맨드로 넘어가면 됨.. 어 근데 또 똑같은말 나오면 어카지
                    savenum = temp[i]
                    continue  # 아마 틀리면 여기 고쳐야함 save값 두고 또나오면 걍 break쳐버림
                if traverse.mal == 0:  # 노드에 말이 없으면
                    hap += traverse.data  # 번호값 더함
                    saveyx[temp[i]].mal = 0  # 원래 있던곳 값 비워주고
                    traverse.mal = 1  # 말 이동 :visit체크
                    saveyx[temp[i]] = traverse  # 현재 말 위치 기록(노드주소,정보)

                else:
                    break  # 아닐시 말 겹치므로 종료

            elif saveyx[temp[i]].ifprior == 1:  #현재 밟은게 파랑이다?
                traverse = saveyx[temp[i]]  #일단 현재노드에서
                # print(traverse.data,'current',command[i])
                Flag = False                #(도착지 넘어가는거 체크 플래그)
                for cnt in range(command[i]):
                    traverse = traverse.prior   #숫자만큼 앞으로 감 (prior이동)
                    if traverse.data == 0:      # 가고있는데 도착점 넘어섬
                        saveyx[temp[i]].mal = 0
                        Flag = True             # 멈초
                        break
                if Flag:                        #다음 커맨드로 넘어가면 됨.. 어 근데 또 똑같은말 나오면 어카지
                    savenum = temp[i]
                    continue                    #아마 틀리면 여기 고쳐야함 save값 두고 또나오면 걍 break쳐버림
                if traverse.mal == 0:           #노드에 말이 없으면
                    hap += traverse.data        #번호값 더함
                    saveyx[temp[i]].mal = 0  # 원래 있던곳 값 비워주고
                    traverse.mal = 1  # 말 이동 :visit체크
                    saveyx[temp[i]] = traverse  # 현재 말 위치 기록(노드주소,정보)

                else:
                    break   # 아닐시 말 겹치므로 종료

            # print(hap,i)
        maxv = max(hap,maxv)
        return

    for idx in range(4):
        temp.append(ls[idx])
        perm(cnt+1)
        temp.pop()


perm(0)

print(maxv)
