#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

#include "util.cpp"

using namespace std;

template <typename T, typename = enable_if<is_arithmetic<T>::value>>
int quickSelect(vector<T> &v, int k) {
    T pivot = v[v.size() - 1];  // 가장 마지막 요소를 피봇으로 선정

    vector<T> smallGroupV, largeGroupV;  // 각각 피봇보다 작은 벡터, 큰 벡터

    for (auto x : v) {
        if (x < pivot)  // 피봇 보다 작으면 작은 벡터에
            smallGroupV.push_back(x);
        else if (x > pivot)  // 크면 큰벡터에 삽입
            largeGroupV.push_back(x);
    }

    // 각 그룹의 길이를 비교해서 피봇이 속한 그룹으로 재귀 호출
    if (k <= smallGroupV.size())
        return quickSelect(smallGroupV, k);
    else if (k == smallGroupV.size() + 1)
        return pivot;
    else
        return quickSelect(largeGroupV, k - (smallGroupV.size() + 1));
}

int main(int argc, char const *argv[]) {
    
    if (argc <= 2) {
        cout << "required for execution args" << endl;
        return -1;
    }

    const string targetPath = argv[1];
    vector<int> result = split(readFromFile(argv[1]), ' ');
    int r = quickSelect(result, atoi(argv[2]));
    const string resultPath = targetPath.substr(0, targetPath.find_last_of("/") + 1) + "result.txt";
    writeToFile(vector<int>({r}), resultPath);

    return 0;
}
