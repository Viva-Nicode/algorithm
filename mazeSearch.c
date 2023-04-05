#include <stdio.h>

#define ROWS 7
#define COLS 7

// 미로 배열
int maze[ROWS][COLS] = {
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}};

// 경로를 표시할 방문 배열
int visited[ROWS][COLS] = {0};

// 도착하고 나서 스택을 빨리 풀기위해
int isReturn = 0;

void escape_maze(int row, int col)
{
    // 도착했다면 방문 배열 출력하고 종료
    if (isReturn == 1)
        return;

    // 도착 조건 만족시 visited출력
    if (row == ROWS - 1 && col == COLS - 1)
    {
        visited[row][col] = 1;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
                printf("%d ", visited[i][j]);
            printf("\n");
        }
        isReturn = 1;
        return;
    }

    // 방문 표시
    visited[row][col] = 1;

    //  현재 위치가 배열을 넘어서지 않고, 다음위치가 벽이 아닌 길이며, 재방문이 아닌경우
    if (col < COLS - 1 && maze[row][col + 1] == 0 && visited[row][col + 1] == 0)
        escape_maze(row, col + 1); // 우측 이동

    if (row < ROWS - 1 && maze[row + 1][col] == 0 && visited[row + 1][col] == 0)
        escape_maze(row + 1, col); // 하단 이동

    if (col > 0 && maze[row][col - 1] == 0 && visited[row][col - 1] == 0)
        escape_maze(row, col - 1); // 좌측 이동

    if (row > 0 && maze[row - 1][col] == 0 && visited[row - 1][col] == 0)
        escape_maze(row - 1, col); // 상단 이동

    // 방문 해제 표시
    visited[row][col] = 0;
}

int main(int argc, char const *argv[])
{
    escape_maze(0, 0);
    return 0;
}