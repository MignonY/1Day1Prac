import sys

T = int(sys.stdin.readline())

for i in range (T):
    A,B= map(int, sys.stdin.readline().split())
    i+=1
    print(f"Case #{i}: {A+B}")
    
