def check(coordinates):
    return coordinates[0] >= 0 and coordinates[0] < 8 and coordinates[1] >= 0 and coordinates[1] < 8


def solution(src, dest):
    # Your code here
    src_row = src // 8
    src_col = src % 8

    des_row = dest // 8
    des_col = dest % 8

    q = []
    q.append((src_row, src_col))

    visited = {}
    visited[(src_row, src_col)] = True

    distance = {}
    distance[(src_row, src_col)] = 0

    parent = {}
    parent[(src_row, src_col)] = (src_row, src_col)

    while q:
        front = q.pop(0)
        front_row = front[0]
        front_col = front[1]

        if front_row == des_row and front_col == des_col:
            return int(distance[front])

        vertices = []

        vertices.append((front_row - 2, front_col + 1))
        vertices.append((front_row - 1, front_col + 2))
        vertices.append((front_row + 1, front_col + 2))
        vertices.append((front_row + 2, front_col + 1))
        vertices.append((front_row + 2, front_col - 1))
        vertices.append((front_row + 1, front_col - 2))
        vertices.append((front_row - 1, front_col - 2))
        vertices.append((front_row - 2, front_col - 1))

        for vertex in vertices:
            if check(vertex):
                if vertex not in visited:
                    visited[vertex] = True
                    parent[vertex] = front
                    distance[vertex] = distance[front] + 1
                    q.append(vertex)

    return -1


# print(solution(0, 1))
# print(solution(19, 36))

# print(solution(0, 0))
print(solution(0, 63))
