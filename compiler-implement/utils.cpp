#ifndef _UTILS_H
#define _UTILS_H
#include <iostream>
#include <fstream>
#include <string>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

string readFile(string filename) {
    string result;
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "error reading file!" << endl;
        exit(0);
    }

    while (!in.eof()) {
        result += in.get();
    }
    in.close();

    return result.substr(0, result.length() - 1) + '\0';
}
string replace(string target, string oldStr, string newStr) {
    int idx = target.find(oldStr);
    while (idx != string::npos) {
        target = target.replace(idx, oldStr.length(), newStr);
        idx = target.find(oldStr);
    }
    return target;
}
vector<string> split(string str, string spacer) {
    vector<string> v;
    int pos1, pos2;
    int len = spacer.length();     //记录分隔符的长度
    pos1 = 0;
    pos2 = str.find(spacer);
    while (pos2 != string::npos) {
        v.push_back(str.substr(pos1, pos2 - pos1));
        pos1 = pos2 + len;
        pos2 = str.find(spacer, pos1);    // 从str的pos1位置开始搜寻spacer
    }
    if (pos1 != str.length()) //分割最后一个部分
        v.push_back(str.substr(pos1));
    return v;
}
string num2str(int num) {
    string s;
    s += (char) num;
    return s;
}

string char2str(char ch) {
    string s;
    s += ch;
    return s;
}
vector<string> readFileByLine(string filename) {
    vector<string> ret;
    ifstream in(filename);
    string line;
    while(getline(in, line)){
        ret.push_back(line);
    }
    return ret;
}

void writeFile(string filename, string content) {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "error writing file!" << endl;
        exit(0);
    }
    out << content;
    out.close();
}
#endif