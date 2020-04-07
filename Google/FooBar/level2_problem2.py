def solution(n):
    mini = 0

    cnt = 0
    mul = 1

    while cnt < n:
        if cnt + mul > n:
            break

        cnt += mul
        mul *= 2
        mini += 1

    maxi = 0

    if n == 1:
        maxi = 1

    elif n < 4:
        maxi = 2

    else:
        maxi = 2
        prev1 = 1
        prev = 1

        cur = 2
        cnt = 2

        while cnt < n:
            if cnt + cur > n:
                break

            cnt += cur
            maxi += 1

            prev1 = prev
            prev = cur
            cur = prev + prev1

    return int(maxi - mini)


# print(solution(143))
# print(solution(10))

print(7, solution(7))
print(6, solution(6))
print(5, solution(5))
print(4, solution(4))
print(3, solution(3))
print(2, solution(2))
print(1, solution(1))
