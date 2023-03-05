P = list(map(list,input().split()))
dic = {'A':0, 'B':1, "C":2, "D":3, "E":4, "F":5, "G":6, "H":7}

for i in range(2):
    for j in range(2):
        if P[i][j].isnumeric():
            P[i][j] = int(P[i][j])
        else:
            P[i][j] = dic[P[i][j]]
P[2][0] = int("".join(P[2]))

ky = P[0][1] ; kx = P[0][0]
dy = P[1][1] ; dx = P[1][0]

d_mv = {'R':(0,1),'L':(0,-1),'B':(-1,0),'T':(1,0),'RT':(1,1),'LT':(1,-1),'RB':(-1,1),'LB':(-1,-1)}
# print(P)
# print(P[2][0])
for t in range(P[2][0]):
    V = input()
    # print(ky,kx,'sky')
    # print(dy,dx,'sdy')
    # print(V)
    nky = ky + d_mv[V][0]
    nkx = kx + d_mv[V][1]
    ndy = dy + d_mv[V][0]
    ndx = dx + d_mv[V][1]
    if 1<=nky<9 and 0<=nkx<8:
        if nky == dy and nkx == dx:
            if 1<= ndy <9 and 0<= ndx <8:
                ky = nky; kx = nkx
                dy = ndy; dx = ndx
        else:
            ky = nky; kx = nkx

#
# print((ky,kx),(dy,dx))
dic = {v:k for k,v in dic.items()}

kx = dic[kx] ; dx = dic[dx]
ky = str(ky) ; dy = str(dy)
kl = [kx,ky]
dl = [dx,dy]
print(''.join(kl))
print(''.join(dl))