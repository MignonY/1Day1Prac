

N = int(input())
arr = [list(map(int,input().split())) for _ in range(N)]
visit = [[0]*N for _ in range(N)]
queue = [0 for _ in range(50000)]
fishcnt = 0
# for i in range(N):
# 	print(arr[i])

#상어위치 파악, 지우기
savei = 0
savej = 0
for i in range(N):
	for j in range(N):
		if arr[i][j] == 9:
			savei = i
			savej = j
			arr[i][j] = 0
for i in range(N):
	for j in range(N):
		if arr[i][j] != 0:
			fishcnt += 1

# print('fishcnt:',fishcnt)
#bfs 돌려서 이동가능한곳(수 자기자신 이하) 체크 후 큐에 삽입
# 뎁스별로 먹을 수 있는 고기 리스트에 담아 정리해서 lambda sort 후 먹는다
# 먹고나면 종료시키고 while문 돌아가서 다시 bfs 실행
# 먹을때마다 총 물고기수 -1
# 총 물고기 수 == 0 되면 / 또는 bfs 돌렸는데 먹은게 없으면 강제종료

def BFS(y,x,depth):
	global arr, fishcnt, big, eat, time
	rear = -1
	front = 0

	rear += 1
	queue[rear] = (y,x,depth)
	visit[y][x] = 1
	temp = []

	while rear+1 != front:
		(y,x,depth) = queue[front]
		front += 1
		# print(temp)
		if len(temp)>=1 and ( queue[front]== 0 or depth > temp[0][0]):
			# print(temp)
			# print()
			# temp.sort(key = lambda x: (x[0], x[1], x[2]))
			temp.sort()
			eat += 1
			fishcnt -= 1
			time += temp[0][0]
			newy = temp[0][1]
			newx = temp[0][2]
			arr[newy][newx] = 0
			return (newy, newx)

		for dy,dx in ((-1,0),(0,-1),(0,1),(1,0)):
			ny = y + dy
			nx = x + dx
			if 0<=ny<N and 0<=nx<N and visit[ny][nx] == 0 and arr[ny][nx]<=big:
				#먹을 수 있는 물고기 발견
				if arr[ny][nx]!= 0 and arr[ny][nx] < big:
					temp.append([depth+1, ny,nx])
				#전진
				rear += 1
				queue[rear]  = (ny,nx,depth+1)
				visit[ny][nx] = 1

	return (y,x)

time = 0
saveeat = 0
eat = 0
big = 2
while True:
	# for i in range(N):
	# 	print(arr[i], time,big,eat)
	saveeat = eat
	savei, savej = BFS(savei,savej,0)	#최종 상어 위치 반환
	if eat == big:
		eat = 0
		big += 1

	if (eat == saveeat) or (fishcnt == 0):
		break

	#init
	for i in range(N):
		for j in range(N):
			visit[i][j] = 0


print(time)
