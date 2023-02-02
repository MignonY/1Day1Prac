n = int(input())

paper = [[0 for _ in range(100)] for _ in range(100)]
count = 0

for p in range(n):
    x, y = map(int,input().split())
    for i in range(y,y+10):
        for j in range(x,x+10):
            paper[i][j] = 1
        
for a in range(len(paper)):
    for b in range(len(paper[a])):
        if paper[a][b] ==1:
            count+=1

print(count)