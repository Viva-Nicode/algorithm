#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

// 배열을 분할하는 함수
template <typename T, typename = enable_if<is_arithmetic<T>::value>>
int partition(vector<T> &arr, int li, int ri)
{
    // 가장 마지막값을 피봇으로 선정
    T pivot = arr[ri];

    // pivot 기준으로 작은 값을 pivot 왼쪽, 큰 값을 pivot 오른쪽에 위치시킴
    int i(li - 1); // 피봇보다 작은 값을 가장 좌측으로 이동시키고 1 증가시켜서 피봇이 삽입될 위치 추적
    for (int j = li; j < ri; j++)
    {
        if (arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[ri]); // pivot가장 오른쪽에 피봇과 i + 1값 스왑

    return i + 1; // pivot 위치 반환
}

// Quick Sort 함수
int quickSort(vector<int> &arr, int li, int ri, int k)
{
    if (li < ri)
    {
        int pi = partition(arr, li, ri); // 피봇기준 정렬
        if (pi - 1 >= k)
            quickSort(arr, li, pi - 1, k); // small group quick sort
        else if (pi - 1 <= k)
            quickSort(arr, pi + 1, ri, k - (pi + 1)); // large group quick sort
        else if(pi == k)
            return arr[pi];
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr{5, 4, 6, 2, 1, 7, 3, 91};

    cout << quickSort(arr, 0, arr.size() - 1, 4);

    return 0;
}
