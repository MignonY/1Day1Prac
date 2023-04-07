r,c,k = map(int,input().split())
r -= 1; c -= 1;
arr = [list(map(int,input().split())) for _ in range(3)]
bigarr = [[0]* 100 for _ in range(100)]# 100바꿔야함
# 헹별 길이 기록
# lenls = [0 for _ in range(100)] # 100으로바꿔야함
maxlen = len(arr[0])
maxh = len(arr)

# for i in range(3):
# 	print(arr[i])
# print()

def R_CAL():
	global maxlen, maxh
	dic = {}
	maxlen = 0
	maxh = len(arr)
	for i in range(len(arr)):
		temp = []
		for j in range(len(arr[i])):
			if arr[i][j] ==0:
				continue
			if arr[i][j] not in dic:
				dic[arr[i][j]] = 0
				dic[arr[i][j]] += 1
			else:
				dic[arr[i][j]] += 1
		# print(i, dic)
		if maxlen < len(dic)*2:
			maxlen = len(dic)*2
			if maxlen>100:
				maxlen = 100
		for k in dic.keys():
			temp.append([k, dic[k]])
		temp.sort(key = lambda x: (x[1], x[0]))
		# print(temp)
		bigidx = 0
		for l in range(len(temp)):
			for p in range(len(temp[l])):
				bigarr[i][bigidx] = temp[l][p]
				bigidx += 1
		dic = {}
	# for i in range(len(bigarr)):
	# 	print(bigarr[i])

def C_CAL():
	global maxlen, maxh
	dic = {}
	maxlen = len(arr[0])
	maxh = 0
	for i in range(maxlen):
		temp = []
		for j in range(len(arr)):
			if arr[j][i] ==0:
				continue
			if arr[j][i] not in dic:
				dic[arr[j][i]] = 0
				dic[arr[j][i]] += 1
			else:
				dic[arr[j][i]] += 1
		# print(i,dic)
		if maxh < len(dic)*2:
			maxh = len(dic)*2
			if maxh > 100:
				maxh = 100
		for k in dic.keys():
			temp.append([k, dic[k]])
		temp.sort(key = lambda x: (x[1], x[0]))
		# print(temp)
		bigidx = 0
		for l in range(len(temp)):
			for p in range(len(temp[l])):
				bigarr[bigidx][i] = temp[l][p]
				bigidx += 1
		dic = {}
	# for i in range(len(bigarr)):
	# 	print(bigarr[i])

time =0
while True:
	if len(arr)-1>= r and len(arr[0])-1 >=c and arr[r][c] == k:
		print(time)
		break

	time += 1

	if maxh>= maxlen:
		R_CAL()

	else:
		C_CAL()

	arr = [[0] * maxlen for _ in range(maxh)]
	for i in range(maxh):
		for j in range(maxlen):
			arr[i][j] = bigarr[i][j]
	# print()
	# print(maxh,maxlen)
	# for i in range(maxh):
	# 	print(time, arr[i])
	# print()

	for i in range(maxh):
		for j in range(maxlen):
			bigarr[i][j] = 0

	if time >= 101:
		print(-1)
		break
