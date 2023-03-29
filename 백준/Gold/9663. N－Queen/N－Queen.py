n = int(input())
ans = 0
row = [0] * n


def is_promising(x):
    for i in range(x):
        if row[x] == row[i] or abs(row[x] - row[i]) == abs(x - i):
            return False

    return True


def n_queens(x):
    global ans
    if x == n:
        ans += 1
        return

    else:
        for i in range(row[x - 1] - 1):
            row[x] = i
            if is_promising(x):
                n_queens(x + 1)

        for i in range(row[x - 1] + 1, n):
            row[x] = i
            if is_promising(x):
                n_queens(x + 1)


for i in range(n // 2):
    row[0] = i
    n_queens(1)
ans *= 2

if n % 2:  # odd case.
    row[0] = n // 2
    n_queens(1)


print(ans)
