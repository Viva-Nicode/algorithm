const matrixzSize = 5

const matrix = [
    ['R', 'R', 'R', 'B', 'B'],
    ['G', 'G', 'B', 'B', 'B'],
    ['B', 'B', 'B', 'R', 'R'],
    ['B', 'B', 'R', 'R', 'R'],
    ['R', 'R', 'R', 'R', 'R']]

const visited = Array.from(Array(matrixzSize), () => Array(matrixzSize).fill(0))

const solution = (x, y, color) => {

    visited[x][y] = 1



}

// 구해진 각 구역이 어떤 구역끼리 이어져있는지 정보를 동적계획법?

solution(0, 0, matrix[0][0])


