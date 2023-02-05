import sys
N = int(sys.stdin.readline())
stu = [list((map(int, sys.stdin.readline().split()))) for _ in range(N)]

# print(stu)



for i in range(len(stu)):
    cnt = 1
    for j in range(len(stu)):
        if stu[i][0] < stu[j][0] and stu[i][1] < stu[j][1]:
            cnt += 1
    print(cnt)