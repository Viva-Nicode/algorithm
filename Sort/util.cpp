#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// 그냥 split
vector<int> split(string str, char Delimiter)
{
    istringstream iss(str); // istringstream에 str을 담는다.
    string buffer;          // 구분자를 기준으로 분할된 문자열이 담겨지는 버퍼
    vector<int> result;     // 결과 벡터

    while (getline(iss, buffer, Delimiter))
        result.push_back(atoi(buffer.c_str())); // 분할된 문자열을 vector에 저장

    return result;
}

// 정렬할 파일을 읽어들임
string readFromFile(string path)
{
    std::ifstream tfile(path);
    std::string textNumbers = "";

    if (tfile.is_open()) // 파일 제대로 열렸는지 확인
    {
        std::string line = "";
        while (getline(tfile, line))
            textNumbers += line;
        tfile.close();
    }
    else
    {
        std::cout << "파일을 여는데 실패하였습니다." << std::endl;
    }
    return textNumbers;
}

// 정렬된 결과를 파일에 출력
int writeToFile(vector<int> v, string path)
{
    std::ofstream rfile(path);

    if (rfile.is_open())
    {
        string rs = "";
        for (int e : v)
            rs += to_string(e) + " ";
        rfile << rs;
        rfile.close();
    }
    else
    {
        std::cout << "파일을 여는데 실패하였습니다." << std::endl;
        return 1;
    }
    return 0;
}