# import numpy as np
from fractions import Fraction


def gcd(a, b):
    if b == 0:
        return a

    return gcd(b, a % b)


def transpose(A):
    # print(A)
    B = [[0 for i in range(len(A[0]))] for j in range(len(A))]
    # print(B)
    for i in range(len(A)):
        for j in range(len(A[0])):
            B[i][j] = A[j][i]

    return B


def dot(X, Y):

    result = [[0 for i in range(len(Y[0]))] for j in range(len(X))]
    # print(result)

    for i in range(len(X)):
        for j in range(len(Y[0])):
            for k in range(len(Y)):
                result[i][j] += X[i][k] * Y[k][j]

    return result


def next_state(matrix, probs):
    # matrix = np.matrix(matrix)
    matrix = transpose(matrix)
    # print(matrix)
    new_probs = dot(matrix, probs)
    matrix = transpose(matrix)
    return matrix, new_probs


def solution(m):

    # print(m)

    prob_matrix = []

    for i in m:
        row_sum = sum(i)

        if row_sum != 0:
            prob_matrix.append([float(j) / float(row_sum) for j in i])

        else:
            prob_matrix.append(i)

    # print(prob_matrix)

    which = []

    for i in range(len(prob_matrix)):
        if all(v == 0 for v in prob_matrix[i]):
            which.append(1)
            prob_matrix[i][i] = 1.0

        else:
            which.append(0)

    transposed_probs = [[i] for i in prob_matrix[0]]
    probs = transposed_probs

    for i in range(5000):
        # print(prob_matrix)
        prob_matrix, probs = next_state(prob_matrix, probs)

    # print(probs)

    final = []

    for i in range(len(m)):
        # print("wow")
        # print(probs.item(i))
        final.append(probs[i][0])

    # print(final)

    num = []
    den = []

    lcm = 1
    index = 0

    for i in final:
        # print(i)
        num.append(Fraction(str(i)).limit_denominator().numerator)
        den.append(Fraction(str(i)).limit_denominator().denominator)

        lcm = (lcm * den[index]) / gcd(lcm, den[index])
        index += 1

    ans = []

    for i in range(len(num)):
        if which[i] == 1:
            ans.append((num[i] * lcm) // den[i])

    ans.append(lcm)

    return list(map(int, ans))
    # return 0


print(solution([[0, 2, 1, 0, 0], [0, 0, 0, 3, 4], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]))
print(solution([[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]))
