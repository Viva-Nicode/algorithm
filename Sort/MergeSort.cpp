#include <iostream>
#include <vector>

#include "util.cpp"

using namespace std;

template <typename T, typename = enable_if<is_arithmetic<T>::value>>
void merge(vector<T> &arr, int left, int middle, int right) {
    vector<T> temp(right - left + 1);  // 임시 배열 생성

    int i = left;
    int j = middle + 1;

    // 정렬 병합된 요소의 총 갯수 k
    int k = 0;

    // 작은 순서대로 배열에 삽입
    // 한쪽이 먼저 전부 temp에 복사되면 다른 한쪽이 정렬되어야 하는 배열이 남아버림
    while (i <= middle && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // 그래서 남은 데이터도 삽입
    while (i <= middle) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // 임시 배열의 데이터를 원래 배열으로 복사
    for (int x = 0; x < k; x++) arr[left + x] = temp[x];
}

// T 타입을 산술 연산이 가능한 타입으로 제한
template <typename T, typename = enable_if<is_arithmetic<T>::value>>
// 매개변수 벡터를 수정해야 하므로 백터 참조자
void mergeSort(vector<T> &arr, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;

        // 분할
        mergeSort(arr, left, middle);       // 왼쪽 그룹
        mergeSort(arr, middle + 1, right);  // 오른쪽 그룹

        // 병합
        merge(arr, left, middle, right);
    }
}

int main(int argc, char const *argv[]) {
    // 1번째부터 실제 전달한 인자
    if (argc <= 1) {
        cout << "실행하는데 필요한 매개변수 수가 부족합니다." << endl;
        return -1;
    }

    const string targetPath = argv[1];
    vector<int> result = split(readFromFile(argv[1]), ' ');
    mergeSort(result, 0, result.size() - 1);  // 정렬 실행
    const string resultPath = targetPath.substr(0, targetPath.find_last_of("/") + 1) + "result.txt";
    writeToFile(result, resultPath);

    return 0;
}
