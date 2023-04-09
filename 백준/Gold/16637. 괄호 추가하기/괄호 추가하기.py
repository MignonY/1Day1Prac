def CAL(temp):
	for i in range(len(ls_op)):
		if temp[i] == 1:
			if ls_op[i] == "+":
				res = ls_num[i] + ls_num[i+1]
			elif ls_op[i] == "-":
				res = ls_num[i] - ls_num[i+1]
			elif ls_op[i] == "*":
				res = ls_num[i] * ls_num[i+1]

			ls_all[i*2+1] = res
			ls_all[i*2] = res
			ls_all[i*2+2] = res

	cal_res = ls_all[0]
	for i in range(len(ls_all)):
		if ls_all[i] == '+':
			cal_res += ls_all[i+1]
		elif ls_all[i] == '-':
			cal_res -= ls_all[i+1]
		elif ls_all[i] == '*':
			cal_res *= ls_all[i+1]

	return cal_res

tmpls = [0,1]
temp = []
maxv = -999999999
def gwalho(depth):
	global maxv
	if depth == len(ls_op):
		for i in range(len(ls_all)):
			ls_all[i] = ls_ori[i]
		ret = CAL(temp)
		maxv = max(ret, maxv)
		return
	for i in range(len(tmpls)):
		if len(temp)==0 and tmpls[i] != 1:
			temp.append(tmpls[i])
		elif len(temp) >= 1 and not (tmpls[i] == 1 and temp[-1] == 1):
			temp.append(tmpls[i])
		else:
			continue
		gwalho(depth+1)
		temp.pop()


N = int(input())
ls_all = list(input())
for i in range(len(ls_all)):
	if ls_all[i].isdigit():
		ls_all[i] = int(ls_all[i])
ls_ori = list(ls_all)
ls_num = []
ls_op = []
for i in range(len(ls_all)):
	if i % 2:
		ls_op.append(ls_all[i])
	else:
		ls_num.append(int(ls_all[i]))

gwalho(0)
print(maxv)