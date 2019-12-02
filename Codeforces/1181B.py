l = int(input())

s = input()

n = int(s)

if l % 2 == 0:
    div = (int)(l / 2)
    if s[div] != '0':
        s1 = (int)(s[:div])
        s2 = (int)(s[div:])

        print(s1 + s2)

    else:
        right = l
        for i in range(int(l / 2), l):
            if s[i] != '0':
                right = i
                break

        for i in range(int(l / 2) - 1, -1, -1):
            # print(i)
            if s[i] != '0':
                left = i
                break

        # print(left, right)

        if right != l:
            s1 = (int)(s[:right])
            s2 = (int)(s[right:])

        else:
            s1 = n
            s2 = n

        if left != 0:
            s3 = (int)(s[:left])
            s4 = (int)(s[left:])

        else:
            s3 = n
            s4 = n

        print(min(s1 + s2, s3 + s4))

else:
    check1 = int(l / 2)

    s1 = n
    s2 = n
    s3 = n
    s4 = n

    if s[check1 + 1] != '0':
        s1 = int(s[:check1 + 1])
        s2 = int(s[check1 + 1:])

    if s[check1] != '0':
        s3 = int(s[:check1])
        s4 = int(s[check1:])

    # print(s1, s2, s3, s4)

    if s[check1] == '0' and s[check1 + 1] == '0':
        right = l
        for i in range(int(l / 2), l):
            if s[i] != '0':
                right = i
                break

        for i in range(int(l / 2), -1, -1):
            # print(i)
            if s[i] != '0':
                left = i
                break

        # print(left, right)

        if right != l:
            s5 = (int)(s[:right])
            s6 = (int)(s[right:])

        else:
            s5 = n
            s6 = n

        if left != 0:
            s7 = (int)(s[:left])
            s8 = (int)(s[left:])

        else:
            s7 = n
            s8 = n

        print(min(s5 + s6, s7 + s8))

    else:
        print(min(s1 + s2, s3 + s4))
