#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

int quickSelect(vector<int> v, int k)
{
    int pivot = v[0]; // 임의의 element를 pivot으로 설정

    vector<int> A1, A2;

    for (auto x : v)
    {
        // pivot을 기준으로 element partitioning
        if (x < pivot)
            A1.push_back(x);
        else if (x > pivot)
            A2.push_back(x);
    }

    if (k <= A1.size()) // 찾고자 하는 answer가 A1에 있을 경우 subproblem 호출
        return quickSelect(A1, k);
    else if (k == A1.size() + 1) // 현재 problem의 answer가 pivot일 경우 반환
        return pivot;
    else // 찾고자 하는 answer가 A2에 있을 경우 subproblem 호출
        return quickSelect(A2, k - (A1.size() + 1));
}

int main(int argc, char const *argv[])
{
    vector<int> arr{5, 4, 6, 1, 7, 3, 91, 14, 5};
    cout << quickSelect(arr, 4);
    return 0;
}
