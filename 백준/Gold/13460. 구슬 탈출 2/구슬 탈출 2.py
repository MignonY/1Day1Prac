def up(red_y, red_x, blue_y, blue_x):
    new_red_y = red_y
    new_blue_y = blue_y

    red_goal = False
    while True:
        if arr[new_red_y][red_x] == 'O':
            red_goal = True
            break
        elif arr[new_red_y][red_x] == '#':
            new_red_y += 1
            break
        new_red_y -= 1

    blue_goal = False
    while True:
        if arr[new_blue_y][blue_x] == 'O':
            blue_goal = True
            break
        if arr[new_blue_y][blue_x] == '#':
            new_blue_y += 1
            break
        new_blue_y -= 1

    if new_red_y == new_blue_y and red_x == blue_x:
        if red_y < blue_y:
            new_blue_y += 1
        else:
            new_red_y += 1

    return (new_red_y, red_x, new_blue_y, blue_x, red_goal, blue_goal)


def down(red_y, red_x, blue_y, blue_x):
    new_red_y = red_y
    new_blue_y = blue_y

    red_goal = False
    while True:
        if arr[new_red_y][red_x] == 'O':
            red_goal = True
            break
        elif arr[new_red_y][red_x] == '#':
            new_red_y -= 1
            break
        new_red_y += 1

    blue_goal = False
    while True:
        if arr[new_blue_y][blue_x] == 'O':
            blue_goal = True
            break
        if arr[new_blue_y][blue_x] == '#':
            new_blue_y -= 1
            break
        new_blue_y += 1

    if new_red_y == new_blue_y and red_x == blue_x:
        if red_y > blue_y:
            new_blue_y -= 1
        else:
            new_red_y -= 1

    return (new_red_y, red_x, new_blue_y, blue_x, red_goal, blue_goal)


def left(red_y, red_x, blue_y, blue_x):
    new_red_x = red_x
    new_blue_x = blue_x

    red_goal = False
    while True:
        if arr[red_y][new_red_x] == 'O':
            red_goal = True
            break
        elif arr[red_y][new_red_x] == '#':
            new_red_x += 1
            break
        new_red_x -= 1

    blue_goal = False
    while True:
        if arr[blue_y][new_blue_x] == 'O':
            blue_goal = True
            break
        if arr[blue_y][new_blue_x] == '#':
            new_blue_x += 1
            break
        new_blue_x -= 1

    if new_red_x == new_blue_x and red_y == blue_y:
        if red_x < blue_x:
            new_blue_x += 1
        else:
            new_red_x += 1

    return (red_y, new_red_x, blue_y, new_blue_x, red_goal, blue_goal)


def right(red_y, red_x, blue_y, blue_x):
    new_red_x = red_x
    new_blue_x = blue_x

    red_goal = False
    while True:
        if arr[red_y][new_red_x] == 'O':
            red_goal = True
            break
        elif arr[red_y][new_red_x] == '#':
            new_red_x -= 1
            break
        new_red_x += 1

    blue_goal = False
    while True:
        if arr[blue_y][new_blue_x] == 'O':
            blue_goal = True
            break
        if arr[blue_y][new_blue_x] == '#':
            new_blue_x -= 1
            break
        new_blue_x += 1

    if new_red_x == new_blue_x and red_y == blue_y:
        if red_x > blue_x:
            new_blue_x -= 1
        else:
            new_red_x -= 1

    return (red_y, new_red_x, blue_y, new_blue_x, red_goal, blue_goal)


dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
N, M = map(int, input().split())

arr = [list(input()) for i in range(N)]
queue = [0 for _ in range(2050000)]

red_x = 0
red_y = 0
blue_x = 0
blue_y = 0
hole_x = 0
hole_y = 0

for i in range(N):
    for j in range(M):
        if arr[i][j] == 'B':
            blue_x = j
            blue_y = i
            arr[i][j] = '.'
        elif arr[i][j] == 'R':
            red_x = j
            red_y = i
            arr[i][j] = '.'
        elif arr[i][j] == 'O':
            hole_x = j
            hole_y = i

front = 0
rear = -1

rear += 1
queue[rear] = (red_y, red_x, blue_y, blue_x, 0)

answer = -1
while rear + 1 != front:
    (red_y, red_x, blue_y, blue_x, count) = queue[front]
    front += 1

    if count == 10:
        break

    # up
    (next_red_y, next_red_x, next_blue_y, next_blue_x, red_goal, blue_goal) = up(red_y, red_x, blue_y, blue_x)
    if red_goal and not blue_goal:
        answer = count + 1
        rear = -1
        front = 0
        break

    elif not blue_goal:
        rear += 1
        queue[rear] = (next_red_y, next_red_x, next_blue_y, next_blue_x, count + 1)

    # down
    (next_red_y, next_red_x, next_blue_y, next_blue_x, red_goal, blue_goal) = down(red_y, red_x, blue_y, blue_x)
    if red_goal and not blue_goal:
        answer = count + 1
        rear = -1
        front = 0
        break

    elif not blue_goal:
        rear += 1
        queue[rear] = (next_red_y, next_red_x, next_blue_y, next_blue_x, count + 1)

    #left
    (next_red_y, next_red_x, next_blue_y, next_blue_x, red_goal, blue_goal) = left(red_y, red_x, blue_y, blue_x)
    if red_goal and not blue_goal:
        answer = count + 1
        rear = -1
        front = 0
        break

    elif not blue_goal:
        rear += 1
        queue[rear] = (next_red_y, next_red_x, next_blue_y, next_blue_x, count + 1)

    #right
    (next_red_y, next_red_x, next_blue_y, next_blue_x, red_goal, blue_goal) = right(red_y, red_x, blue_y, blue_x)
    if red_goal and not blue_goal:
        answer = count + 1
        rear = -1
        front = 0
        break

    elif not blue_goal:
        rear += 1
        queue[rear] = (next_red_y, next_red_x, next_blue_y, next_blue_x, count + 1)

print(answer)