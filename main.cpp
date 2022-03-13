#include "encode.h"
#include "decode.h"
#include <string.h>
bool compareFiles(const std::string& p1, const std::string& p2) {
    std::ifstream f1(p1, std::ifstream::binary|std::ifstream::ate);
    std::ifstream f2(p2, std::ifstream::binary|std::ifstream::ate);

    if (f1.fail() || f2.fail()) {
        return false; //file problem
    }

    if (f1.tellg() != f2.tellg()) {
        return false; //size mismatch
    }

    //seek back to beginning and use std::equal to compare contents
    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);
    return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                      std::istreambuf_iterator<char>(),
                      std::istreambuf_iterator<char>(f2.rdbuf()));
}
int main(){
    std::string inputPath = R"(C:\Users\marsi\CLionProjects\ArithCoding\input)";
    std::string codedPath = R"(C:\Users\marsi\CLionProjects\ArithCoding\coded)";
    std::string decodedPath = R"(C:\Users\marsi\CLionProjects\ArithCoding\decoded)";
    char input[inputPath.length() + 1];
    char coded[codedPath.length() + 1];
    char decoded[decodedPath.length() + 1];
    strcpy(input, inputPath.c_str());
    strcpy(coded, codedPath.c_str());
    strcpy(decoded, decodedPath.c_str());

    Encode obj;
    obj.encode(input,coded);
    Decode obj1;
    obj1.decode(coded, decoded);
    std::cout << compareFiles(inputPath, decodedPath);

    return 0;
}
