#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define LENGTH 18

enum STONE {
    NONE = 0,
    WHITE = 1,
    BLACK = 2,
};

const int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

bool isindexoutofboundsexception(int x, int y) {
    if (x < 0 || x > LENGTH || y < 0 || y > LENGTH)
        return true;
    else
        return false;
}

int getWeight(enum STONE board[LENGTH][LENGTH], int evex, int evey) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
        }
    }

    return 1;
}

bool getWeight(enum STONE board[LENGTH][LENGTH], int evex, int evey) {
    int dx[] = {1, 1, 0, -1, 1, -1, 0, -1};  // 가로, 세로, 대각선 검사
    int dy[] = {0, 1, 1, 1, -1, -1, -1, 0};

    enum STONE stone = BLACK;  // 흑돌
    for (int d = 0; d < 8; ++d) {
        int count = 0;
        for (int i = 1; i <= 3; ++i) {
            int nx = evex + dx[d] * i;
            int ny = evey + dy[d] * i;
            if (nx < 0 || nx >= LENGTH || ny < 0 || ny >= LENGTH)
                break;
            if (board[nx][ny] == stone) {
                if (i == 2 && (nx == evex || ny == evey))
                    break;  // 직전 돌의 위치인 경우 패턴 미완성
                ++count;
            } else {
                break;
            }
        }
        if (count == 3)
            return true;
    }
    return false;
}

// 알파가 큰거 베타가 작은거
int turn(enum STONE board[LENGTH][LENGTH], int depth, int *a, int *b, int evex, int evey) {
    static int aix, aiy;
    if (depth == 3)
        return getWeight(board, evex, evey);

    if (depth % 2 == 0) {  // ai turn

        for (int x = 0; x < LENGTH; x++)  // for each child of node
        {
            for (int y = 0; y < LENGTH; y++) {
                enum STONE curStone = board[x][y];
                bool flag = false;

                if (curStone == NONE) {
                    int deltax = 0, deltay = 0;
                    for (int k = 0; k < 8; k++) {
                        deltax = x + dx[k];
                        deltay = y + dy[k];
                        if (!isindexoutofboundsexception(deltax, deltay)) continue;
                        if (board[deltax][deltay] != NONE) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        board[x][y] = BLACK;
                        int w = turn(board, depth + 1, a, b, x, y);
                        if (*a < w) {
                            *a = w;
                            if (depth == 0) {
                                aix = x;
                                aiy = y;
                            }
                        }
                    }
                }
            }
        }
    } else {                              // player turn
        for (int x = 0; x < LENGTH; x++)  // for each child of node
        {
            for (int y = 0; y < LENGTH; y++) {
            }
        }
    }
}