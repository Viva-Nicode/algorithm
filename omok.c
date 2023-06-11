#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_X 15
#define MAX_Y 15
#define BLACK 1
#define WHITE 2
#define EMPTY 0

const int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

int aix = 0, aiy = 0;

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

bool isindexoutofboundsexception(int x, int y) {
    if (x < 0 || x >= MAX_X || y < 0 || y >= MAX_Y)
        return true;
    else
        return false;
}

bool bbbwPattern(int board[MAX_Y][MAX_X], int evex, int evey) {
    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

    int stone = board[evey][evex];

    // 8방향검사
    for (int direction = 0; direction < 8; ++direction) {
        int count = 1;  // 흑돌 카운트

        // 한 방향으로 계속 진행하며 동일한 돌이 연속되는지 검사
        for (int i = 1; i <= 2; ++i) {
            int nx = evex + dx[direction] * i;
            int ny = evey + dy[direction] * i;

            // 배열 범위를 벗어나거나, 검사하는 돌과 다른 돌이라면 중단
            if (nx < 0 || nx >= MAX_X || ny < 0 || ny >= MAX_Y || board[ny][nx] != stone)
                break;
            count++;
        }

        // count가 3이고(흑독3개) 다른한쪽이 흰돌이면 트루
        if (count == 3 && (board[evey - dy[direction]][evex - dx[direction]] != stone))
            return true;
    }
    return false;
}

bool bbPattern(int board[MAX_Y][MAX_X], int evex, int evey) {
    int dx[] = {1, 1, 0, -1, 1, -1, 0, -1};  // 가로, 세로, 대각선 검사
    int dy[] = {0, 1, 1, 1, -1, -1, -1, 0};

    int stone = BLACK;  // 흑돌
    for (int d = 0; d < 8; ++d) {
        int count = 0;
        for (int i = 1; i <= 2; ++i) {
            int nx = evex + dx[d] * i;
            int ny = evey + dy[d] * i;
            if (nx < 0 || nx >= MAX_X || ny < 0 || ny >= MAX_Y)
                break;
            if (board[ny][nx] == stone) {
                ++count;
            } else {
                break;
            }
        }
        if (count == 2)
            return true;
    }
    return false;
}

bool bbbPattern(int board[MAX_Y][MAX_X], int evex, int evey) {
    int dx[] = {1, 1, 0, -1};  // 가로, 세로, 대각선 방향 검사
    int dy[] = {0, 1, 1, 1};

    int stone = BLACK;  // 흑돌
    for (int d = 0; d < 4; ++d) {
        int count = 0;
        for (int i = -3; i <= 3; ++i) {
            int nx = evex + dx[d] * i;
            int ny = evey + dy[d] * i;
            if (nx < 0 || nx >= MAX_X || ny < 0 || ny >= MAX_Y)
                continue;
            if (board[ny][nx] == stone) {
                ++count;
                if (count == 3)
                    return true;
            } else {
                count = 0;
            }
        }
    }
    return false;
}

bool bbbbPattern(int board[MAX_Y][MAX_X], int evex, int evey) {
    int dx[] = {1, 1, 0, -1};  // 가로, 세로, 대각선 방향 검사
    int dy[] = {0, 1, 1, 1};

    int stone = BLACK;  // 흑돌
    for (int d = 0; d < 4; ++d) {
        int count = 0;
        for (int i = -4; i <= 4; ++i) {
            int nx = evex + dx[d] * i;
            int ny = evey + dy[d] * i;
            if (nx < 0 || nx >= MAX_X || ny < 0 || ny >= MAX_Y)
                continue;
            if (board[ny][nx] == stone) {
                ++count;
                if (count == 4)
                    return true;
            } else {
                count = 0;
            }
        }
    }
    return false;
}

bool bbbbbPattern(int board[MAX_Y][MAX_X], int evex, int evey) {
    int dx[] = {1, 1, 0, -1};  // 가로, 세로, 대각선 방향 검사
    int dy[] = {0, 1, 1, 1};

    int stone = BLACK;  // 흑돌
    for (int d = 0; d < 4; ++d) {
        int count = 0;
        for (int i = -5; i <= 5; ++i) {
            int nx = evex + dx[d] * i;
            int ny = evey + dy[d] * i;
            if (nx < 0 || nx >= MAX_X || ny < 0 || ny >= MAX_Y)
                continue;
            if (board[ny][nx] == stone) {
                ++count;
                if (count == 5)
                    return true;
            } else {
                count = 0;
            }
        }
    }
    return false;
}

int getWeight(int board[MAX_Y][MAX_X], int x, int y) {
    int w = 0;

    if (bbbwPattern(board, x, y)) {
        w = 10;
    }
    if (bbbwPattern(board, x, y)) {
        w = 20;
    }
    if (bbbbPattern(board, x, y)) {
        w = 30;
    }
    if (bbbbbPattern(board, x, y)) {
        w = 300;
    }
    return w;
}

// 알파가 큰거 베타가 작은거
int turn(int board[MAX_Y][MAX_X], int depth, int evex, int evey) {
    if (depth == 3)
        return getWeight(board, evex, evey);

    int maxw = INT_MIN;
    int minw = INT_MAX;
    if (depth == 0 || depth == 2) {  // ai turn

        printf("AI\n");
        for (int x = 0; x < MAX_X; x++)  // for each child of node
        {
            for (int y = 0; y < MAX_Y; y++) {
                int curStone = board[x][y];
                bool flag = false;

                if (curStone == EMPTY) {
                    int deltax = 0, deltay = 0;
                    for (int k = 0; k < 8; k++) {
                        deltax = x + dx[k];
                        deltay = y + dy[k];
                        if (!isindexoutofboundsexception(deltax, deltay)) {
                            if (board[deltax][deltay] != EMPTY) {
                                flag = true;
                                break;
                            }
                        }
                    }
                    if (flag) {
                        board[x][y] = BLACK;
                        int ww = turn(board, depth + 1, x, y);
                        minw = min(minw, ww);
                        if (maxw < ww) {
                            maxw = ww;
                            aix = x;
                            aiy = y;
                        }
                        board[x][y] = EMPTY;
                    }
                }
            }
        }
    } else {  // player turn

        printf("P\n");
        for (int x = 0; x < MAX_X; x++)  // for each child of node
        {
            for (int y = 0; y < MAX_Y; y++) {
                int curStone = board[x][y];
                int flag = 0;

                if (curStone == EMPTY) {
                    int deltax = 0, deltay = 0;
                    for (int k = 0; k < 8; k++) {
                        deltax = x + dx[k];
                        deltay = y + dy[k];
                        if (!isindexoutofboundsexception(deltax, deltay)) {
                            if (board[deltax][deltay] != EMPTY) {
                                flag = 1;
                                break;
                            }
                        }
                    }
                    if (flag) {
                        board[x][y] = WHITE;
                        int ww = turn(board, depth + 1, x, y);
                        maxw = max(maxw, ww);
                        minw = min(minw, ww);
                        board[x][y] = EMPTY;
                    }
                }
            }
        }
        printf("w : %d\n", minw);
        return minw;
    }
}

int main(int argc, char const* argv[]) {
    int board[MAX_X][MAX_Y] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    turn(board, 0, 6, 7);
    printf("aix : %d aiy : %d", aix, aiy);
}