
temp = []
final = []
def combi(depth):
    global ls,visit,temp,final
    # print(temp,depth)
    if depth == len(ls):
        # print(temp)
        visit = [0 for _ in range(len(temp))]
        if len(temp)==1:
            final.append(temp[0])
        elif len(temp)>1:
            perm(len(temp),0,temp,visit)
        # print(final,'d')
        return

    temp.append(ls[depth])
    combi(depth+1)
    temp.pop()
    combi(depth+1)

temp2 = []

def perm(depth,cnt,temp,visit):
    global final
    if cnt == depth:
        # print(temp2,'temp2')
        final.append("".join(temp2))
        return

    for i in range(len(temp)):
        if visit[i] == 0:
            visit[i] = 1
            temp2.append(temp[i])
            perm(depth,cnt+1,temp,visit)
            temp2.pop()
            visit[i] = 0


def solution(numbers):
    global ls
    ls = list(numbers)
    combi(0)
    answer = 0
    arr = list(map(int,final))
    arr = list(set(arr))
    arr.sort()
    print(arr)
    for i in range(len(arr)):
        if arr[i] == 1 or arr[i] == 0:
            continue
        else:
            if findsosu(arr[i]):
                # print(arr[i])
                answer += 1

    # print(answer)
    return answer

def findsosu(n):
    if n == 2:
        return True
    num = int(n ** (1/2)) + 1
    # print(n,num)
    Flag = True
    for i in range(2, num+1):
        if n % i == 0:
            Flag = False
            break

    return Flag

# solution("17")
# solution("011")
# solution("31")