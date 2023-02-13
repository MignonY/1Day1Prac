import sys
input = sys.stdin.readline
stack = []

def push(a):
    stack.append(a)

def pop():
    if stack:
        print(stack[-1])
        stack.pop()
    else:
        print(-1)

def top():
    if stack:
        print(stack[-1])
    else:
        print(-1)

def size():
    print(len(stack))

def empty():
    if stack:
        print(0)
    else:
        print(1)

N = int(input())
for i in range(N):
    command = input().split()
    if command[0] == 'push':
        push(command[1])
    elif command[0] == 'top':
        top()
    elif command[0] == 'size':
        size()
    elif command[0] == 'pop':
        pop()
    elif command[0] == 'empty':
        empty()