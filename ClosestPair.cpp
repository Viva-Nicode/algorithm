#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

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
    int32_t s = pv.size();

    for (int i = 0; i < s; i++) {
        for (int j = i + 1; j < s; j++) {
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
    vector<Point> v;

    v.push_back(Point(10, 15));
    v.push_back(Point(5, 15));
    v.push_back(Point(20, 3));
    v.push_back(Point(6, 1));
    v.push_back(Point(9, 7));
    v.push_back(Point(15, 9));
    v.push_back(Point(8, 15));
    v.push_back(Point(20, 14));
    v.push_back(Point(17, 13));
    v.push_back(Point(16, 11));
    v.push_back(Point(7, 12));
    v.push_back(Point(10, 10));
    v.push_back(Point(1, 19));
    v.push_back(Point(8, 8));
    v.push_back(Point(30, 9));
    v.push_back(Point(22, 4));

    sort(v.begin(), v.end(), [](const Point& lhs, const Point& rhs) -> bool {
        if (lhs.getX() != rhs.getX())
            return lhs.getX() < rhs.getX();
        else
            return lhs.getY() < rhs.getY();
    });

    cout << "result : " << closest_pair(v) << endl;

    return 0;
}