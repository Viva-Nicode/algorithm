#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T, typename = std::enable_if<std::is_arithmetic<T>::value>>
int quickSelect(vector<T> v, int k)
{
    T pivot = v[0];

    vector<T> smallGroupV, largeGroupV;

    for (auto x : v)
    {
        if (x < pivot)
            smallGroupV.push_back(x);
        else if (x > pivot)
            largeGroupV.push_back(x);
    }

    if (k <= smallGroupV.size())
        return quickSelect(smallGroupV, k);
    else if (k == smallGroupV.size() + 1)
        return pivot;
    else
        return quickSelect(largeGroupV, k - (smallGroupV.size() + 1));
}

int main(int argc, char const *argv[])
{
    vector<int> arr{5, 4, 6, 1, 7, 3, 91, 14, 5};
    cout << quickSelect(arr, 4);
    return 0;
}
