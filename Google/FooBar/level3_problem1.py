def pref_xor(l):
    if l <= 0:
        return 0

    rem = l % 4

    if rem == 0:
        return l

    elif rem == 1:
        return 1

    elif rem == 2:
        return l + 1

    else:
        return 0


def xor(l, r):
    return (pref_xor(r) ^ pref_xor(l - 1))


def solution(start, length):
    ans = 0
    skip = 0

    for i in range(length):
        ans ^= xor(start, start + length - 1 - skip)
        skip += 1
        start += length

    return int(ans)


print(solution(0, 3))
print(solution(17, 4))
