def distV(a,b):
	res = (abs(a[0]-b[0]) **2 + abs(a[1]-b[1]) **2) ** (1/2)
	return res


def findP(a):
	if parent[a] == a:
		return a
	else:
		b = findP(parent[a])
		return b


def merge(a,b):
	a = findP(a)
	b = findP(b)

	if a== b:
		return
	if a<b:
		parent[a] = b
	else:
		parent[b] = a


def KRUSKAL():
	global arr, resv
	arr.sort()

	for i in range(len(arr)):
		cost = arr[i][0]
		current = arr[i][1][0]
		next = arr[i][1][1]

		if findP(current) != findP(next):
			# print(ls[current],ls[next])
			resv += cost
			merge(current,next)


n = int(input())
ls = []
for i in range(n):
	a, b = map(float,input().split())
	ls.append([a,b])

arr = []
for i in range(n):
	for j in range(n):
		if i == j:
			continue
		arr.append([distV(ls[i],ls[j]),[i,j]])

#
# print(ls)
# print(arr)
parent = [i for i in range(n)]
resv = 0

KRUSKAL()

print(round(resv,2))