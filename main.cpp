#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "utils.cpp"
#include "runRe/DFA2Code.cpp"
#include "runRE/NFA2DFA.cpp"
#include "runRE/simplifyDFA.cpp"
#include "runRE/RE2NFA.cpp"
using namespace std;

json solveRE(string filename){
    map<string, json> ret;
    vector<string> content = readFileByLine(filename);
    for (string line : content) {
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == '=') {
                ret.insert(make_pair(line.substr(0, i), RE2NFA(line.substr(i+1)).run()));
                break;
            }
        }
    }
    return ret;
}
/**
 * main.exe -re <input re file>
 * @return
 */
int main() {
    cout << solveRE("./test/re/minic.re").dump(4);
//    cout << RE2NFA("\\*").run().dump(4);
    return 0;
}