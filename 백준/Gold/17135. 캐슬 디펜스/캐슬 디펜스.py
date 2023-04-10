N, M, D= map(int,input().split())
arr = [list(map(int,input().split())) for _ in range(N)]
arr_ori = list(map(list,arr))
ls = [i for i in range(M)]
enemy_ls = []

# for i in range(N):
# 	print(arr[i])

# 궁수 공격
# 궁수 좌표 (N,x)
# 가장 y좌표 큰거부터(우선), 그 다음은 x좌표 작은 순으로
def archer(x):
	tmp = []
	global D
	for i in range(N-1, N-D-1, -1):
		for j in range(x-(D-1), x+D):
			if 0<=i<N and 0<=j<M:
				dis = abs(N - i) + abs(x - j)
				if dis <=D:
					if arr[i][j] == 1:
						tmp.append([dis, i,j])
	# print(tmp)
	tmp.sort(key = lambda x: (x[0],x[2]))
	# print(tmp)
	if len(tmp)>=1:
		enemy_ls.append(tmp[0])


# 한칸씩 내려오는 적
def down():
	for j in range(M):
		i = N-1
		while i > 0:
			arr[i][j] = arr[i-1][j]
			i -= 1
		arr[i][j] = 0


# 궁수 조합
temp = []
maxv = -9999
def nCr(cnt, depth, begin):
	global enemy_ls, enemy_num, maxv
	if cnt == depth:
		for i in range(N):
			for j in range(M):
				arr[i][j] = arr_ori[i][j]
		enemy_num = 0
		# print(f'temp:{temp}')
		while True:
			enemy_ls = []
			archer(temp[0])
			archer(temp[1])
			archer(temp[2])
			# print(enemy_ls)

			if len(enemy_ls) >=1:
				for i in range(len(enemy_ls)):
					if arr[enemy_ls[i][1]][enemy_ls[i][2]] ==1:
						arr[enemy_ls[i][1]][enemy_ls[i][2]] = 0
						enemy_num += 1
			down()
			# for i in range(N):
			# 	print(arr[i], enemy_num)
			# print()

			Flag = True
			for i in range(N):
				for j in range(M):
					if arr[i][j] == 1:
						Flag = False
						break
			if Flag:
				break

		if maxv < enemy_num:
			maxv = enemy_num
		return

	for idx in range(begin, len(ls)):
		temp.append(ls[idx])
		nCr(cnt+1, depth, idx+1)
		temp.pop()

nCr(0,3,0)
print(maxv)