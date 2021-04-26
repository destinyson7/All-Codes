import itertools

T = int(input())

for t in range(1, T + 1):
    v = list(map(int, input().strip().split()))
    v = sorted(v)

    # print(list(itertools.permutations(v)))

    for a in list(itertools.permutations(v)):
        x = 51833
        y = 303071227

        seconds = int(60 * 60 * int(1e9) * 12)

        cnt = (60 - 1) * 12

        cur = (a[1] - a[0]) * x * y
        cur %= seconds
        cur += seconds
        cur %= seconds

        # print("cur: ", cur)

        if ((cnt * cur + a[1] - a[2]) % seconds + seconds) % seconds == 0:
            nano = cur % int(1e9)
            sec = int((cur / int(1e9))) % 60
            mi = int(int(cur / int(1e9)) / 60) % 60
            hours = int(int(int(cur / int(1e9)) / 60) / 60)

            ans = [hours, mi, sec, nano]
            break

    print("Case #" + str(t) + ": " + str(ans[0]) + " " +
          str(ans[1]) + " " + str(ans[2]) + " " + str(ans[3]))
