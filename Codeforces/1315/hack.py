for _ in range(int(input())):
    a, b, p = [int(i) for i in input().strip().split()]
    s = input()
    s = 'X' + s[:-1] + 'X'
    n = len(s)
    cost = [0] * n

    lastchar = 'X'

    for i in range(1, n):
        if s[i] != lastchar:
            if lastchar == 'A':
                cost[i] = a
            elif lastchar == 'B':
                cost[i] = b
            lastchar = s[i]

    exp = 0
    walkto = -1
    for i in range(n - 1, 0, -1):
        if exp + cost[i] > p:
            walkto = i
            break
        exp += cost[i]

    if i == 1:
        walkto = 1

    print(walkto)
