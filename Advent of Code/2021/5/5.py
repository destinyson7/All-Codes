grid = [[0 for i in range(5000)] for j in range(5000)]

with open("in.txt", "r") as f:
    for line in f:
        a = line.split("->")
        b = a[0].split(",")

        x1 = int(b[0].strip())
        y1 = int(b[1].strip())

        c = a[1].split(",")
        x2 = int(c[0].strip())
        y2 = int(c[1].strip())

        # print(x1, y1, x2, y2)

        if x1 == x2:
            if y1 > y2:
                y1, y2 = y2, y1

            for y in range(y1, y2 + 1):
                grid[x1][y] += 1

        elif y1 == y2:
            if x1 > x2:
                x1, x2 = x2, x1

            for x in range(x1, x2 + 1):
                grid[x][y1] += 1

        elif abs(x1 - x2) == abs(y1 - y2):

            if (x1 - x2) == (y1 - y2):
                if x1 > x2:
                    x1, x2 = x2, x1
                    y1, y2 = y2, y1

                for i in range(x2 - x1 + 1):
                    grid[x1 + i][y1 + i] += 1

            else:
                if x1 > x2:
                    x1, x2 = x2, x1
                    y1, y2 = y2, y1

                for i in range(x2 - x1 + 1):
                    grid[x1 + i][y1 - i] += 1


cnt = 0

for i in range(5000):
    for j in range(5000):
        if grid[i][j] > 1:
            # print(i, j)
            cnt += 1

print(cnt)
