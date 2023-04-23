#include <vector>
#include <iostream>

// 배열을 분할하는 함수
template <typename T>
int partition(std::vector<T> &arr, int li, int ri)
{
    // 가장 마지막값을 피봇으로 선정
    T pivot = arr[ri];

    // pivot 기준으로 작은 값을 pivot 왼쪽, 큰 값을 pivot 오른쪽에 위치시킴
    int i(li - 1); // 피봇보다 작은 값을 가장 좌측으로 이동시키고 1 증가시켜서 피봇이 삽입될 위치 추적
    for (int j = li; j < ri; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[ri]); // pivot가장 오른쪽에 피봇과 i + 1값 스왑

    return i + 1; // pivot 위치 반환
}

// Quick Sort 함수
template <typename T>
void quickSort(std::vector<T> &arr, int li, int ri)
{
    if (li < ri)
    {
        int pi = partition(arr, li, ri); // 피봇기준 정렬
        quickSort(arr, li, pi - 1);      // small group quick sort
        quickSort(arr, pi + 1, ri);      // large group quick sort
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> arr{5, 4, 6, 2, 1, 7, 3, 91};

    quickSort(arr, 0, arr.size() - 1);

    return 0;
}
