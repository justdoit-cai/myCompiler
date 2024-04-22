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