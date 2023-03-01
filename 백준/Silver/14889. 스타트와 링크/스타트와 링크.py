N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
start = []
link = []
stN = N//2
liN = N//2

def Cal(ls):
    res = 0
    for i in range(N//2):
        for j in range(N//2):
            res += arr[ls[i]][ls[j]]
    return res

minv = 1000000
def Combi(n):
    global stN, liN,minv
    if n == N:
        # print(start, link)
        temp = abs(Cal(start) - Cal(link))
        if minv > temp:
            minv = temp
        return

    if stN:
        start.append(n)
        stN -= 1
        Combi(n+1)
        start.pop()
        stN += 1


    if liN:
        link.append(n)
        liN -= 1
        Combi(n+1)
        link.pop()
        liN += 1


Combi(0)

print(minv)