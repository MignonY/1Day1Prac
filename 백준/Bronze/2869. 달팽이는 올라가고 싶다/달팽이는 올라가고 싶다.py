import math 
A,B,V = list(map(int,input().split()))

# A*cnt -B*(cnt-1)=V
# A*cnt - B*cnt + B = V
# (A-B)*cnt = V-B
cnt = (V-B)/(A-B)

print(math.ceil(cnt))