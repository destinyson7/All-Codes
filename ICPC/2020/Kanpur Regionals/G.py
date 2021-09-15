T = int(input())

while T:
    T -= 1
    k, d = map(int, input().split())

    mod = 1000000000

    ans = (k * k) // 2
    ans %= mod

    ans2 = (k ** (d - 1) - 1)
    ans2 = ans2 // (k - 1)
    ans2 %= mod

    ans = (ans * ans2) % mod

    ans += k
    ans %= mod

    print(int(ans))
