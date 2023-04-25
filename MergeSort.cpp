#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename = enable_if<is_arithmetic<T>::value>>
void merge(vector<T> &arr, int left, int middle, int right)
{
    cout << left << " " << middle << " " << right << endl;
    vector<T> temp(right - left + 1); // 임시 배열 생성

    int i = left;
    int j = middle + 1;

    // 정렬 병합된 요소의 총 갯수 k
    int k = 0;

    // 작은 순서대로 배열에 삽입
    // 한쪽이 먼저 전부 temp에 복사되면 다른 한쪽이 정렬되어야 하는 배열이 남음
    while (i <= middle && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // 남은 데이터도 삽입
    while (i <= middle)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    // 임시 배열의 데이터를 원래 배열으로 복사
    for (int x = 0; x < k; x++)
        arr[left + x] = temp[x];
}

template <typename T, typename = enable_if<is_arithmetic<T>::value>>
void mergeSort(vector<T> &arr, int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;

        // Divide and Conquer
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main()
{
    vector<int> arr = {5, 2, 8, 6, 1, 9, 3};

    // Merge Sort 수행
    mergeSort(arr, 0, arr.size() - 1);

    // 정렬 결과 출력
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
