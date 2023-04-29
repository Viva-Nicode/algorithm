#include <vector>
#include <iostream>
#include <cstdlib>
#include "util.cpp"

using namespace std;

template <typename T, typename = std::enable_if<std::is_arithmetic<T>::value>>
int quickSelect(vector<T> v, int k)
{
    T pivot = v[v.size() - 1];

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

    // 1번째부터 실제 전달한 인자
    if (argc <= 1)
    {
        cout << "실행하는데 필요한 매개변수 수가 부족합니다." << endl;
        return -1;
    }

    const string targetPath = argv[1];
    vector<int> result = split(readFromFile(argv[1]), ' ');
    int r = quickSelect(result, stoi(argv[2])); // 정렬 실행
    const string resultPath = targetPath.substr(0, targetPath.find_last_of("/") + 1) + "result.txt";
    writeToFile(vector<int>({r}), resultPath);

    return 0;
}
