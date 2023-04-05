import numpy as np

matrixzSize = 5

matrix = np.array(
    [
        ["R", "R", "R", "B", "B"],
        ["G", "G", "B", "B", "B"],
        ["B", "B", "B", "R", "R"],
        ["B", "B", "R", "R", "B"],
        ["R", "R", "R", "R", "R"],
    ]
)

visited = np.array([[0 for j in range(matrixzSize)] for i in range(matrixzSize)])


dx = [0, 1, -1, 0]
dy = [1, 0, 0, -1]
# 우 하 좌 상


def searchArea(x, y, color):
    visited[x][y] = 1
    for i in range(4):
        X = x + dx[i]
        Y = y + dy[i]
        if 0 <= X < matrixzSize and 0 <= Y < matrixzSize and visited[X][Y] == 0 and matrix[X][Y] == color:
            searchArea(X, Y, matrix[X][Y])


def solution():
    result = 0
    while not np.all(visited == 1):
        result += 1
        x, y = np.where(visited == 0)
        searchArea(x[0], y[0], matrix[x[0]][y[0]])
    return result


# print(solution())

def e(x):
    return np.exp(-x)

print(e(-3))
