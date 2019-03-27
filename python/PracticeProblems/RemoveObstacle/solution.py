from collections import defaultdict

from collections import deque


def is_valid(i, j, m, n, matrix, visited):
    if i >= 0 and j >= 0 \
            and i < m and j < n \
            and visited[i][j] is False \
            and matrix[i][j] in (1, 9):
        return True

    return False


def remove_obstacle(matrix, m, n):
    queue = deque()
    i = 0
    j = 0
    queue.append((i, j, 0))

    visited = [[False for _ in range(n)] for _ in range(m)]
    distance_matrix = [[100 for _ in range(n)] for _ in range(m)]

    visited[i][j] = True

    while queue:
        i, j, distance = queue.popleft()
        distance_matrix[i][j] = distance

        visited[i][j] = True

        if matrix[i][j] == 9:
            return distance
        new_distance = distance + 1
        if is_valid(i + 1, j, m, n, matrix, visited):
            queue.append((i + 1, j, new_distance))

        if is_valid(i - 1, j, m, n, matrix, visited):
            queue.append((i - 1, j, new_distance))

        if is_valid(i, j + 1, m, n, matrix, visited):
            queue.append((i, j + 1, new_distance))

        if is_valid(i, j - 1, m, n, matrix, visited):
            queue.append((i, j - 1, new_distance))

    return -1


if __name__ == '__main__':
    m = 5
    n = 4
    l = [
        [1, 1, 1, 1],
        [0, 1, 1, 1],
        [0, 1, 0, 1],
        [1, 1, 9, 1],
        [0, 0, 1, 1]
    ]

    bfs = remove_obstacle(l, m, n)
    assert bfs == 5

    m = 3
    n = 3
    l = [
        [1, 0, 0],
        [1, 0, 0],
        [1, 9, 1]
    ]

    bfs = remove_obstacle(l, m, n)
    assert bfs == 3
