def cal(num, case):
	if case == 2:
		return num + 1
	elif case == 1:
		return num - 1
	elif case == 0:
		return num * 2


def BFS(n, depth):
	rear = -1
	front = 0
	rear += 1
	queue[rear] = (n, depth)
	visit[n] = 1

	while (rear + 1) % queue_size != front:
		current = queue[front][0]
		depth = queue[front][1]
		if current == K:
			# print(front)
			return depth

		front = (front + 1) % queue_size

		for i in range(3):
			ret = cal(current, i)
			# print(ret,current)
			if 0 <= ret <= 200005 and visit[ret] != 1:
				rear = (rear + 1) % queue_size
				visit[ret] = 1
				if i != 0:
					queue[rear] = (ret, depth + 1)
				else:
					queue[rear] = (ret, depth)


queue_size = 3000000
queue = [0 for _ in range(queue_size)]


N, K = map(int, input().split())
visit = [0 for _ in range(1000001)]

if N > K:
	ans = N-K
else:
	ans = BFS(N, 0)
print(ans)
