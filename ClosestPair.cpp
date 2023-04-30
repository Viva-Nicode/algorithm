#include <cstdlib>
#include <cmath>

using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    int getX() { return x; }
    double getLength(Point other)
    {
        return sqrt(pow(abs(this->x - other.x), 2) + pow(abs(this->y - other.y), 2));
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
