#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

#include "util.cpp"

using namespace std;

class Point {
   private:
    int x, y;

   public:
    Point(int x, int y) : x(x), y(y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    double_t getLength(const Point& other) const {
        return sqrt(pow(abs(this->x - other.x), 2) + pow(abs(this->y - other.y), 2));
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& point) {
        cout << "( " << point.x << " , " << point.y << " )";
        return out;
    }
};

double_t brute_force(const vector<Point>& pv) {
    double_t least = numeric_limits<double>::max();

    for (int i = 0; i < pv.size(); i++) {
        for (int j = i + 1; j < pv.size(); j++) {
            if (double l = pv.at(i).getLength(pv.at(j)); l < least)
                least = l;
        }
    }
    return least;
}

double_t closest_pair(const vector<Point>& pv) {
        if (pv.size() <= 3)
        return brute_force(pv);

    double_t divided_l = closest_pair(vector<Point>(pv.begin(), pv.begin() + pv.size() / 2));
    double_t divided_r = closest_pair(vector<Point>(pv.begin() + pv.size() / 2, pv.end()));
    double_t least = min(divided_l, divided_r);

    vector<Point> strip_v = vector<Point>();

    for (const Point& p : pv) {
        if ((double)abs(pv.at(pv.size() / 2).getX() - p.getX()) <= least)
            strip_v.push_back(p);
    }

    return min(least, brute_force(strip_v));
}

int main(int argc, char const* argv[]) {
    if (argc <= 1)
        return -1;

    vector<Point> v;
    ifstream tfile(argv[1]);

    if (tfile.is_open()) {
        string line = "";
        while (getline(tfile, line)) {
            vector<int> iv = split(line, ' ');
            v.push_back(Point(iv[0], iv[1]));
        }
        tfile.close();
    } else
        cout << "파일을 여는데 실패하였습니다." << endl;

    sort(v.begin(), v.end(), [](const Point& lhs, const Point& rhs) -> bool {
        if (lhs.getX() != rhs.getX())
            return lhs.getX() < rhs.getX();
        else
            return lhs.getY() < rhs.getY();
    });

    cout << "result : " << closest_pair(v) << endl;

    return 0;
}