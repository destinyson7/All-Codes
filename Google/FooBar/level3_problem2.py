def solution(n):

    num = int(n)
    ans = 0

    while num != 1:
        if num % 2 == 0:
            num //= 2
            ans += 1

        elif num % 4 == 1:
            num -= 1
            ans += 1

        elif num != 3:
            num += 1
            ans += 1

        else:
            num -= 1
            ans += 1

    return int(ans)


print(solution(4))
print(solution(15))
print(solution(9))
print(solution(1))
print(solution(2))
print(solution(10))
print(solution(3))
