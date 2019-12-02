s = input()

l = len(s)

num = 0
cur = 0

for i in range(l - 1, -1, -1):
    if s[i] == '1':
        num = num + 2**cur

    cur = cur + 1

ans = 0


while True:
    if 4**ans >= num:
        print(ans - 1)
        break

    ans = ans + 1
