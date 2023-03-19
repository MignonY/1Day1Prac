T = int(input())
comm = []
N = 10

arr = [[0] * 10 for _ in range(10)]
score = 0


def Rclear(x):
	for i in range(4):
		for j in range(x, 3, -1):
			arr[i][j] = arr[i][j - 1]


def Dclear(y):
	for i in range(4):
		for j in range(y, 3, -1):
			arr[j][i] = arr[j - 1][i]


def Rmove(t, y, x):
	global score, N
	if t == 1:
		while 0 <= y < N - 1 and 0 <= x < N - 1:
			if arr[y][x + 1] == 1:
				arr[y][x] = 1
				break
			x += 1
			if x == 9 and arr[y][x] == 0:
				arr[y][x] = 1

	elif t == 2:
		x = x + 1
		while 0 <= y < N - 1 and 0 <= x < N - 1:
			if arr[y][x + 1] == 1:
				arr[y][x] = 1
				arr[y][x - 1] = 1
				break
			x += 1
			if x == 9 and arr[y][x] == 0:
				arr[y][x] = 1
				arr[y][x - 1] = 1

	elif t == 3:
		while 0 <= y < N - 1 and 0 <= x < N - 1:
			if arr[y][x + 1] == 1 or arr[y + 1][x + 1] == 1:
				arr[y][x] = 1
				arr[y + 1][x] = 1
				break
			x += 1
			if x == 9 and arr[y][x] == 0:
				arr[y][x] = 1
				arr[y + 1][x] = 1

	for i in range(9, 5, -1):
		lcnt = 0
		for j in range(4):
			if arr[j][i] == 1:
				lcnt += 1
		if lcnt == 4:
			score += 1
			Rclear(i)
			a = 6
			while a > 0:
				nlcnt = 0
				for k in range(4):
					if arr[k][i] == 1:
						nlcnt += 1
				if nlcnt == 4:
					score += 1
					Rclear(i)
				else:
					break
				a = a - 1

	check4 = False
	check5 = False
	for j in range(4):
		if arr[j][4] == 1:
			check4 = True
			break
	for j in range(4):
		if arr[j][5] == 1:
			check5 = True
			break
	if check4 and check5:
		Rclear(9)
		Rclear(9)
	elif check4 or check5:
		Rclear(9)

def Dmove(t, y, x):
	global score, N
	if t == 1:
		while 0 <= y < N - 1 and 0 <= x < N - 1:
			if arr[y + 1][x] == 1:
				arr[y][x] = 1
				break
			y += 1
			if y == 9 and arr[y][x] == 0:
				arr[y][x] = 1

	elif t == 3:
		y = y + 1
		while 0 <= y < N - 1 and 0 <= x < N - 1:
			if arr[y + 1][x] == 1:
				arr[y][x] = 1
				arr[y - 1][x] = 1
				break

			y += 1
			if y == 9 and arr[y][x] == 0:
				arr[y][x] = 1
				arr[y - 1][x] = 1



	if t == 2:
		while 0 <= y < N - 1 and 0 <= x < N - 1:
			if arr[y + 1][x] == 1 or arr[y + 1][x + 1] == 1:
				arr[y][x] = 1
				arr[y][x + 1] = 1
				break

			y += 1
			if y == 9 and arr[y][x] == 0:
				arr[y][x] = 1
				arr[y][x + 1] = 1

	for i in range(9,5,-1):
		lcnt = 0
		for j in range(4):
			if arr[i][j] == 1:
				lcnt += 1
			else:
				break
		if lcnt == 4:
			score += 1
			Dclear(i)
			a = 6
			while a > 0:
				nlcnt = 0
				for k in range(4):
					if arr[i][k] == 1:
						nlcnt += 1
				if nlcnt == 4:
					score += 1
					Dclear(i)
				else:
					break
				a = a - 1

	check4 = False
	check5 = False
	for j in range(4):
		if arr[4][j] == 1:
			check4 = True
			break
	for j in range(4):
		if arr[5][j] == 1:
			check5 = True
			break
	if check4 and check5:
		Dclear(9)
		Dclear(9)
	elif check4 or check5:
		Dclear(9)



for i in range(T):
	t, y, x = map(int, input().split())
	Rmove(t, y, x)
	Dmove(t, y, x)

	# for j in range(N):
	# 	print(arr[j], i+1)
	# print()

bgcnt = 0
for i in range(6, 10):
	for j in range(4):
		if arr[i][j] == 1:
			bgcnt += 1
		if arr[j][i] == 1:
			bgcnt += 1

print(score)
print(bgcnt)


