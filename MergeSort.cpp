#include <vector>
#include <iostream>

using namespace std;

template <typename T, typename = std::enable_if<std::is_arithmetic<T>::value>>
vector<T> MergeSort(vector<T> v){

}