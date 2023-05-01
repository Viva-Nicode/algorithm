#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "util.cpp"

using namespace std;

// 배열을 분할하는 함수
template <typename T, typename = std::enable_if<std::is_arithmetic<T>::value>>
int partition(std::vector<T> &arr, int li, int ri) {
    // 가장 마지막값을 피봇으로 선정
    T pivot = arr[ri];

    // pivot 기준으로 작은 값을 pivot 왼쪽, 큰 값을 pivot 오른쪽에 위치시킴
    int i(li - 1);  // 피봇보다 작은 값을 가장 좌측으로 이동시키고 1 증가시켜서 피봇이 삽입될 위치 추적
    for (int j = li; j < ri; j++) {
        if (arr[j] <= pivot)
            std::swap(arr[++i], arr[j]);
    }
    std::swap(arr[i + 1], arr[ri]);  // pivot가장 오른쪽에 피봇과 i + 1값 스왑

    return i + 1;  // pivot 위치 반환
}

// Quick Sort 함수
template <typename T, typename = std::enable_if<std::is_arithmetic<T>::value>>
void quickSort(std::vector<T> &arr, int li, int ri) {
    if (li < ri) {
        int pi = partition(arr, li, ri);  // 피봇기준 정렬
        quickSort(arr, li, pi - 1);       // small group quick sort
        quickSort(arr, pi + 1, ri);       // large group quick sort
    }
}

int main(int argc, char const *argv[]) {
    // 1번째부터 실제 전달한 인자
    if (argc <= 1) {
        std::cout << "실행하는데 필요한 매개변수 수가 부족합니다." << std::endl;
        return -1;
    }

    const string targetPath = argv[1];
    vector<int> result = split(readFromFile(argv[1]), ' ');
    quickSort(result, 0, result.size() - 1);  // 정렬 실행
    const string resultPath = targetPath.substr(0, targetPath.find_last_of("/") + 1) + "result.txt";
    writeToFile(result, resultPath);

    return 0;
}
