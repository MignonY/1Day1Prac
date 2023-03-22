def solution(begin, target, words):
	global start, final, wordls, answer, visit, savest
	start = begin
	savest = begin
	final = target
	wordls = words
	visit = [0 for _ in range(len(wordls))]
	answer = 100000
	if final not in wordls:
		answer = 0
	else:
		DFS(0,0)
	print(answer)
	return answer

temp = []
def DFS(depth,bg):
	global start, savest, answer
	# print(temp, depth,start)
	if depth == len(wordls):
		# print(temp,'final',depth)
		return

	for i in range(len(wordls)):
		if visit[i] == 0:
			# if temp and i < temp[-1]:
			# 	continue
			cnt = 0
			for j in range(len(start)):
				if start[j] == wordls[i][j]:
					cnt += 1
			if cnt == len(start)-1:
				if wordls[i] == final:
					print(temp)
					if answer > depth+1:
						answer = depth+1
						continue
				temp.append(i)
				start = wordls[i]
				visit[i] = 1
				DFS(depth+1, i+1)
				if temp:
					visit[temp[-1]] = 0
					temp.pop()
				if temp:
					start = wordls[temp[-1]]
				else:
					start = savest

# solution('hit','cog',["hot","dot","dog","lot","log","cog"])