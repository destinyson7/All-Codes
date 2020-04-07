def solution(s):
    ans = 1
    n = len(s)

    for i in range(1, n + 1):
        if n % i == 0:
            # print(i)
            cur = ""

            for j in range(i):
                cur += s[j]

            # print(cur)

            possible = True

            temp = ""
            for j in range(1, n + 1):

                temp += s[j - 1]

                if j % i == 0:
                    # print(i, j, temp, cur)
                    if cur != temp:
                        possible = False
                        break

                    else:
                        temp = ""

            if possible:
                ans = max(ans, n / i)

    return ans


print(int(solution("abcabcabcabc")))
print(int(solution("abccbaabccba")))
print(int(solution("aaa")))
