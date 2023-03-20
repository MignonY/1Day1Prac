N = int(input())
ls = []
arr = [[0]*N for _ in range(N)]
varr = [[0]*N for _ in range(N)]
for i in range(N*N):
	ls.append(list(map(int,input().split())))

# print(ls)


# arr[1][1] = ls[0][0]


manjok = 0
for q in range(0,len(ls)):
	savey = 0
	savex = 0
	maxFcnt = 0
	# maxVcnt = 0
	for i in range(N):
		for j in range(N):
			Fcnt = 0
			Vcnt = 0
			for dy, dx in ((-1,0),(1,0),(0,-1),(0,1)):
				ny = i + dy
				nx = j + dx
				if arr[i][j]==0 and 0<=ny<N and 0<=nx<N:
					for k in range(1,5):
						if arr[ny][nx] == ls[q][k]:
							Fcnt += 1
					if arr[ny][nx] == 0:
						Vcnt += 1
			varr[i][j] = Vcnt
			if maxFcnt < Fcnt:
				maxFcnt = Fcnt
				savey = i
				savex = j
			elif maxFcnt == Fcnt:
				if varr[savey][savex] < varr[i][j]:
					savey = i
					savex = j
				elif varr[savey][savex] == varr[i][j]:
					if savey == i:
						savex = min(savex, j)
					else:
						if i < savey:
							savey = i
							savex = j
			if arr[savey][savex] != 0:
				savey = i
				savex = j
	arr[savey][savex] = ls[q][0]

	# for p in range(N):
	# 	print(arr[p])
	# print()


ls.sort(key = lambda x: x[0])
# print(ls)
for i in range(N):
	for j in range(N):
		cnt = 0
		for dy, dx in ((-1,0),(1,0),(0,-1),(0,1)):
			ny = i + dy
			nx = j + dx
			if 0<=ny<N and 0<=nx<N:
				for k in range(1, 5):
					if arr[ny][nx] == ls[arr[i][j]-1][k]:
						cnt += 1

		if cnt == 0:
			manjok += 0
		elif cnt == 1:
			manjok += 1
		elif cnt == 2:
			manjok += 10
		elif cnt == 3:
			manjok += 100
		elif cnt == 4:
			manjok += 1000

# for p in range(N):
# 	print(arr[p])
# print()

print(manjok)