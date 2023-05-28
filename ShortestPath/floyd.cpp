#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void printVector(vector<vector<unsigned int>> &v) {
    for (vector<unsigned int> v1 : v) {
        for (const unsigned int w : v1) {
            if (w == UINT_MAX)
                cout << "- ";
            else
                cout << w << " ";
        }
        cout << endl;
    }
}
void floyd(vector<vector<unsigned int>> &v) {
    int k, j, i, l = v.size();

    for (k = 0; k < l; k++) {
        for (i = 0; i < l; i++)
            for (j = 0; j < l; j++)
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
        printVector(v);
        cout << "=======================================" << endl;
    }
}

int main(int argc, char const *argv[]) {
    vector<vector<unsigned int>> v({{0, 3, 1, 2, UINT_MAX},
                                    {UINT_MAX, 0, 1, UINT_MAX, 1},
                                    {UINT_MAX, 1, 0, 2, 5},
                                    {3, UINT_MAX, UINT_MAX, 0, 6},
                                    {UINT_MAX, 1, 5, 5, 0}});
    printVector(v);
    cout << "=======================================" << endl;
    floyd(v);

    return 0;
}
