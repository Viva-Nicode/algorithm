#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Point {
   private:
    int x, y;

   public:
    Point(int x, int y) : x(x), y(y) {}
    int getX() const { return x; }
    int getY() const { return y; }

    double_t getLength(Point other) const {
        return sqrt(pow(abs(this->x - other.x), 2) + pow(abs(this->y - other.y), 2));
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& point) {
        cout << "( " << point.x << " , " << point.y << " )";
        return out;
    }
};

double_t closest_pair(const vector<Point>& pv) {
    if (pv.size() <= 3)
        return brute_force(pv);
}

double_t brute_force(const vector<Point>& pv) {
    
}

int main(int argc, char const* argv[]) {
    vector<Point> v;

    v.push_back(Point(2, 2));
    v.push_back(Point(5, 5));
    v.push_back(Point(2, 4));
    v.push_back(Point(7, 1));
    v.push_back(Point(9, 3));
    v.push_back(Point(5, 6));
    v.push_back(Point(7, 4));

    sort(v.begin(), v.end(), [](const Point& p1, const Point& p2) -> bool {
        if (p1.getX() != p2.getX())
            return p1.getX() < p2.getX();
        else
            return p1.getY() < p2.getY();
    });

    for (Point p : v)
        cout << p << endl;

    return 0;
}
