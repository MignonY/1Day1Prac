# 색종이 1 2 3 4 5 , 각각 5개씩 갖고있음
# 색종이 들어있는 칸에 0이 들어있으면 안된다..
#1 나오면 모양체크해서 큰거부터 들어갈수 있는거 전부 따져서 백트래킹하기?

arr = [list(map(int,input().split())) for _ in range(10)]
remain = {1:5, 2:5, 3:5, 4:5, 5:5}
papercnt = 0
# for i in range(10):
# 	print(arr[i])

onecnt = 0
for i in range(10):
	for j in range(10):
		if arr[i][j] ==1:
			onecnt += 1

def check_num(num,y,x):
	global arr
	checkif = True
	for i in range(num):
		for j in range(num):
			if not (0<=y+num<= 10 and 0<=x+num<=10):
				checkif = False
				break
			else:
				if arr[y+i][x+j] == 0:
					checkif = False
					break

	if remain[num] == 0:
		checkif = False

	return checkif

maxcnt = onecnt
minv= 1000
def dfs(depth):
	global onecnt, papercnt,minv , maxcnt
	# for i in range(10):
	# 	print(arr[i],onecnt)
	# print()

	if papercnt >= minv:
		return

	if onecnt == 0:
		# print(f'{remain}, papercnt:{papercnt}, depth:{depth}')
		if minv> papercnt:
			minv = papercnt
		return


	for i in range(10):
		for j in range(10):
			if arr[i][j] == 1:
				for p in range(5,0,-1):
					ret = check_num(p,i,j)	# 색종이 몇개 남았는지 보고 실행해야함(함수단계)
					if ret == True:
						remain[p] -= 1
						papercnt += 1

						for k in range(p):
							for l in range(p):
								arr[i+k][j+l] = 0
								onecnt -= 1

						dfs(depth+1)

						remain[p] += 1
						papercnt -= 1
						for k in range(p):
							for l in range(p):
								arr[i+k][j+l] = 1
								onecnt += 1
				# print(i,j,remain)
				return

dfs(0)
if minv == 1000:
	print(-1)
else:
	print(minv)