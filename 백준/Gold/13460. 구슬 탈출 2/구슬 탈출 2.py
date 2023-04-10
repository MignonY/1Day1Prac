N, M = map(int, input().split())
arr = [list(input()) for _ in range(N)]
queue = [0 for _ in range(50000)]

# for i in range(len(arr)):
# 	print(arr[i])

Bi = 0;
Bj = 0;
Ri = 0;
Rj = 0;
Oi = 0;
Oj = 0;
for i in range(N):
	for j in range(M):
		if arr[i][j] == 'B':
			Bi = i
			Bj = j
			arr[i][j] = '.'
		if arr[i][j] == 'R':
			Ri = i
			Rj = j
			arr[i][j] = '.'
		if arr[i][j] == 'O':
			Oi = i
			Oj = j


def UP(Ri, Rj, Bi, Bj, B_GOAL, R_GOAL):
	Ry = Ri;
	Rx = Rj
	By = Bi;
	Bx = Bj
	R_GOAL = False
	B_GOAL = False
	while True:
		# print('red')
		if arr[Ry - 1][Rx] != '#':
			Ry -= 1
			if arr[Ry][Rx] == 'O':
				R_GOAL = True
		elif arr[Ry - 1][Rx] == '#':
			break

	while True:
		# print("blue")
		if arr[By - 1][Bx] != '#':
			By -= 1
			if arr[By][Bx] == 'O':
				B_GOAL = True
		elif arr[By - 1][Bx] == '#':
			break
	if Rx == Bx and Ry == By:
		if Ri > Bi:
			Ry += 1
		else:
			By += 1

	return (Ry, Rx, By, Bx, B_GOAL, R_GOAL)


def DOWN(Ri, Rj, Bi, Bj, B_GOAL, R_GOAL):
	Ry = Ri;
	Rx = Rj
	By = Bi;
	Bx = Bj
	R_GOAL = False
	B_GOAL = False
	while True:
		# print('red')
		if arr[Ry + 1][Rx] != '#':
			Ry += 1
			if arr[Ry][Rx] == 'O':
				R_GOAL = True
		elif arr[Ry + 1][Rx] == '#':
			break

	while True:
		# print("blue")
		if arr[By + 1][Bx] != '#':
			By += 1
			if arr[By][Bx] == 'O':
				B_GOAL = True
		elif arr[By + 1][Bx] == '#':
			break
	if Rx == Bx and Ry == By:
		if Ri > Bi:
			By -= 1
		else:
			Ry -= 1
	return (Ry, Rx, By, Bx, B_GOAL, R_GOAL)


def RIGHT(Ri, Rj, Bi, Bj, B_GOAL, R_GOAL):
	Ry = Ri;
	Rx = Rj
	By = Bi;
	Bx = Bj
	R_GOAL = False
	B_GOAL = False
	while True:
		# print('red')
		if arr[Ry][Rx + 1] != '#':
			Rx += 1
			if arr[Ry][Rx] == 'O':
				R_GOAL = True
		elif arr[Ry][Rx + 1] == '#':
			break

	while True:
		# print("blue")
		if arr[By][Bx + 1] != '#':
			Bx += 1
			if arr[By][Bx] == 'O':
				B_GOAL = True
		elif arr[By][Bx + 1] == '#':
			break
	if Rx == Bx and Ry == By:
		if Rj > Bj:
			Bx -= 1
		else:
			Rx -= 1
	return (Ry, Rx, By, Bx, B_GOAL, R_GOAL)


def LEFT(Ri, Rj, Bi, Bj, B_GOAL, R_GOAL):
	Ry = Ri;
	Rx = Rj
	By = Bi;
	Bx = Bj
	R_GOAL = False
	B_GOAL = False
	while True:
		# print('red')
		if arr[Ry][Rx - 1] != '#':
			Rx -= 1
			if arr[Ry][Rx] == 'O':
				R_GOAL = True
		elif arr[Ry][Rx - 1] == '#':
			break

	while True:
		# print("blue")
		if arr[By][Bx - 1] != '#':
			Bx -= 1
			if arr[By][Bx] == 'O':
				B_GOAL = True
		elif arr[By][Bx - 1] == '#':
			break
	if Rx == Bx and Ry == By:
		if Rj > Bj:
			Rx += 1
		else:
			Bx += 1
	return (Ry, Rx, By, Bx, B_GOAL, R_GOAL)


def BFS(Ri, Rj, Bi, Bj, depth):
	global answer
	rear = -1
	front = 0

	VUD = 2

	rear += 1
	queue[rear] = (Ri, Rj, Bi, Bj, depth, VUD)

	B_GOAL = False
	R_GOAL = False

	while rear + 1 != front:
		Ri, Rj, Bi, Bj, depth, VUD = queue[front]
		# print(f'RiRj={Ri, Rj},BiBj={Bi, Bj},cnt={depth},VUD={VUD}')
		front += 1

		if depth == 10:
			answer = -1
			break

		# UP
		if VUD != 1:
			(nRi, nRj, nBi, nBj, B_GOAL, R_GOAL) = UP(Ri, Rj, Bi, Bj, B_GOAL, R_GOAL)
			if R_GOAL == True and B_GOAL == False:
				answer = depth + 1
				break
			if not B_GOAL:
				rear += 1
				queue[rear] = (nRi, nRj, nBi, nBj, depth + 1, 1)

			# DOWN

			(nRi, nRj, nBi, nBj, B_GOAL, R_GOAL) = DOWN(Ri, Rj, Bi, Bj, B_GOAL, R_GOAL)
			if R_GOAL == True and B_GOAL == False:
				answer = depth + 1
				break
			if not B_GOAL:
				rear += 1
				queue[rear] = (nRi, nRj, nBi, nBj, depth + 1, 1)

		# LEFT
		if VUD != 0:
			(nRi, nRj, nBi, nBj, B_GOAL, R_GOAL) = LEFT(Ri, Rj, Bi, Bj, B_GOAL, R_GOAL)
			if R_GOAL == True and B_GOAL == False:
				answer = depth + 1
				break
			if not B_GOAL:
				rear += 1
				queue[rear] = (nRi, nRj, nBi, nBj, depth + 1, 0)

			# RIGHT
			nRi, nRj, nBi, nBj, B_GOAL, R_GOAL = RIGHT(Ri, Rj, Bi, Bj, B_GOAL, R_GOAL)
			if R_GOAL == True and B_GOAL == False:
				answer = depth + 1
				break
			if not B_GOAL:
				rear += 1
				queue[rear] = (nRi, nRj, nBi, nBj, depth + 1, 0)


BFS(Ri, Rj, Bi, Bj, 0)
print(answer)