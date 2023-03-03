dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]
vtxls = []

def dragoncurve(n,g,D):
    vtx = [D]
    while n < g:
        rvtx = list(reversed(vtx))
        rvtx= list(map(lambda x: (x + 1) % 4, rvtx))
        vtx = vtx + rvtx
        n+=1
    return vtx

num = int(input())
for i in range(num):
    x,y,d,g = map(int,input().split())
    ret =dragoncurve(0,g,d)
    vtxls.append((x,y))
    for i in range(len(ret)):
        x += dx[ret[i]]
        y += dy[ret[i]]
        vtxls.append((x, y))

    vtx_ls = list(set(vtxls))
    # print((x,y), ret)
# print(vtxls)
# print(vtx_ls)


VL = len(vtx_ls)
cnt = 0
for q in range(VL):
    i,j = vtx_ls[q]
    Flag = True
    for di, dj in ((1,0),(0,1),(1,1)):
        ni = i + di ; nj = j + dj
        if (ni,nj) not in vtx_ls:
            Flag = False
            continue
    if Flag:
        # print(i,j)
        cnt += 1

print(cnt)