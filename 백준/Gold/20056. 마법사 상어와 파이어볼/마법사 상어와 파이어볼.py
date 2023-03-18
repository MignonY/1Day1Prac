N, M, K = map(int, input().split())  # N 맵크기 / M 파이어볼개수 / K 함수실행횟수

ball = []
for i in range(M):
	ball.append(list(map(int, input().split())))  # y,x =위치/ m = 질량 / s= 속력 / d = 방향
	ball[i].append(True)
	for j in range(2):
		ball[i][j] -= 1

dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, 1, 1, 1, 0, -1, -1, -1]


def fire():
	global M, dy, dx, ball, arr
	# print(ball,'start')
	arr = [[[] for _ in range(N)] for _ in range(N)]
	M = len(ball)
	newls = []

	for i in range(M):
		y = ball[i][0]
		x = ball[i][1]
		m = ball[i][2]
		s = ball[i][3]
		d = ball[i][4]
		ny = y + dy[d] * s
		nx = x + dx[d] * s
		ny = ny % N
		nx = nx % N

		arr[ny][nx].append(i)
		ball[i][0] = ny
		ball[i][1] = nx
		ball[i][5] = False

	for i in range(N):
		for j in range(N):
			if len(arr[i][j]) == 1:
				ball.append([i, j, ball[arr[i][j][0]][2], ball[arr[i][j][0]][3], ball[arr[i][j][0]][4], True])
			elif len(arr[i][j]) >= 2:
				newm = 0
				news = 0
				for k in range(len(arr[i][j])):
					newm += ball[arr[i][j][k]][2]
					news += ball[arr[i][j][k]][3]
				if newm // 5 < 1:
					for k in range(len(arr[i][j])):
						ball[arr[i][j][k]][5] = False
					arr[i][j] = []
				else:
					newm //= 5
					news //= len(arr[i][j])
					hol = 0
					zzak = 0
					for k in range(len(arr[i][j])):
						if ball[arr[i][j][k]][4] % 2 == 0:
							zzak += 1
						elif ball[arr[i][j][k]][4] % 2 == 1:
							hol += 1
					if hol == len(arr[i][j]) or zzak == len(arr[i][j]):
						ball.append([i, j, newm, news, 0, True])
						ball.append([i, j, newm, news, 2, True])
						ball.append([i, j, newm, news, 4, True])
						ball.append([i, j, newm, news, 6, True])
					else:
						ball.append([i, j, newm, news, 1, True])
						ball.append([i, j, newm, news, 3, True])
						ball.append([i, j, newm, news, 5, True])
						ball.append([i, j, newm, news, 7, True])

	for i in range(len(ball)):
		if ball[i][5]:
			newls.append(ball[i])

	ball = newls


ans = 0
for i in range(K):
	fire()
# print(ball,i)

for i in range(len(ball)):
	# print(ball,'end')
	ans += ball[i][2]

print(ans)
