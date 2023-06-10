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

int getWeight() {
    return 1;
}

int turn(enum STONE board[LENGTH][LENGTH], int depth, int *a, int *b) {
    static int aix, aiy;
    if (depth == 3)
        return getWeight();

    if (depth % 2 == 0) {  // ai turn
        int v = INT_MIN;
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
                        int w = turn(board, depth + 1, a, b);
                        if (v < w) {
                            v = w;
                            if (depth == 0) {
                                aix = x;
                                aiy = y;
                            }
                        }
                        *a = max(*a, v);
                    }
                }
            }
        }
    } else {  // player turn
        return getWeight();
    }
}