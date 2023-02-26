# 연산자 순서  + - * //

N = int(input())
num_ls = list(map(int,input().split()))
op_type = list(map(int,input().split()))
# len(op list) == N-1
op_list = [0 for _ in range(N-1)]

def cal():
    val = num_ls[0]
    for i in range(N-1):
        if op_list[i] == 0:
            val += num_ls[i+1]
        elif op_list[i] == 1:
            val -= num_ls[i+1]
        elif op_list[i] == 2:
            val *= num_ls[i+1]
        elif op_list[i] == 3:
            if val < 0:
                val = 0 - (abs(val)//num_ls[i+1])
            else:
                val //= num_ls[i+1]
    return val

max_value = -1000000005
min_value = 1000000005
def combi(depth):
    global max_value
    global min_value
    if depth == N-1:
        # print(op_list)
        # print(cal())
        val = cal()
        if val < min_value:
            min_value = val
        if val > max_value:
            max_value = val
        return

    for i in range(4):
        if op_type[i] != 0:
            op_list[depth] = i
            op_type[i] -= 1
            combi(depth+1)
            op_type[i] += 1

combi(0)
print(max_value)
print(min_value)