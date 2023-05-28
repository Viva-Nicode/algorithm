#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string readFile(const string filePath) {
    ifstream tfile(filePath);
    string origin = "";
    string line = "";
    while (getline(tfile, line))
        origin += line;
    tfile.close();

    return origin;
}

vector<pair<char, unsigned int>>* getPairVector(string origin) {
    map<char, unsigned int> m;

    for (const char c : origin)
        m[c] = m[c] + 1;

    vector<pair<char, unsigned int>>* vec = new vector<pair<char, unsigned int>>(m.begin(), m.end());

    sort(vec->begin(), vec->end(), [](const pair<char, unsigned int>& lhs, const pair<char, unsigned int>& rhs) -> bool {
        if (lhs.second == rhs.second) return lhs.first < rhs.first;
        return lhs.second > rhs.second;
    });

    return vec;
}

void huffman_compression(const string inputPath, const string outputPath) {
    string origin = readFile(inputPath);

    vector<pair<char, unsigned int>>* vec = getPairVector(origin);  // 0 = frequncy high

    ofstream tfile("/Users/nicode./MainSpace/algorithm/Huffman_Compression/table.txt");
    for (auto e : *vec)
        tfile << string(1, e.first) + " ";
    tfile.close();

    string binString("");
    for (const char c : origin) {
        string buf("0");
        for (auto e : *vec) {
            if (e.first == c)
                break;
            buf = '1' + buf;
        }
        binString += buf;
    }

    for (int i = 0; i < 8 - (binString.length() % 8); i++)
        binString += "0";  // zero padding

    ofstream compresedFile(outputPath, ios::binary);
    bitset<8> bits;
    for (size_t i = 0; i < binString.length(); i += 8) {
        string substring = binString.substr(i, 8);
        bits = bitset<8>(substring);
        unsigned char data = static_cast<unsigned char>(bits.to_ulong());
        compresedFile.write(reinterpret_cast<const char*>(&data), sizeof(data));
    }
    compresedFile.close();
}

void huffman_decompression(const string compresed_filepath, const string decompress_filepath, const string mappingTablePath) {
    ifstream file(compresed_filepath, ios::binary);
    ofstream repl(decompress_filepath);
    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();
    file.seekg(0, ios::beg);
    vector<char> buffer(fileSize);
    file.read(buffer.data(), fileSize);
    ostringstream oss;
    for (const char& c : buffer)
        oss << bitset<8>(static_cast<unsigned char>(c)).to_string();
    string compresed_string = oss.str();

    ifstream table(mappingTablePath);
    string tableString = "";
    getline(table, tableString);

    for (int i = compresed_string.length() - 1; i >= 0; i--) {
        if (compresed_string[i] == '0')
            compresed_string.pop_back();
        else
            break;
    }
    compresed_string += "0";
    unsigned int count = 0;
    for (const char c : compresed_string) {
        if (c == '0') {
            repl << tableString[count * 2];
            count = 0;
        } else
            count++;
    }
}

int main(int argc, char const* argv[]) {
    const string targetFilePath = "/Users/nicode./MainSpace/algorithm/Huffman_Compression/origin3.txt";
    const string outputFilePath = "/Users/nicode./MainSpace/algorithm/Huffman_Compression/output";
    const string mappingTablePath = "/Users/nicode./MainSpace/algorithm/Huffman_Compression/table.txt";
    const string decompresedFilePath = "/Users/nicode./MainSpace/algorithm/Huffman_Compression/repl.txt";

    huffman_compression(targetFilePath, outputFilePath);
    huffman_decompression(outputFilePath, decompresedFilePath, mappingTablePath);

    return 0;
}