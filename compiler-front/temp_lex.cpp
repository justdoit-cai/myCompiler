#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string input;
int idx = 0;
char getNextChar() {
    if (idx == input.length()) {
        return '\0';
    }
    return input[idx++];
}
void undoGetChar() {
    idx--;
}

void output(string tokenType, string tokenValue) {
    cout << tokenType << ":" << tokenValue << endl;
}
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
void solve() {
    int state = 0;
    string tokenValue;
    string tokenType;
    while (1) {
        char ch = getNextChar();
        switch (state) {
            case 0:
                if (ch == '\0') {
                    return;
                }
                else if (ch == ' ') {
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'i') {
                    state = 1;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 3;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 9;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 14;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 20;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 26;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 30;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '+') {
                    state = 35;
                    tokenValue += ch;
                    tokenType = "PLUS";
                }
                else if (ch == '-') {
                    state = 36;
                    tokenValue += ch;
                    tokenType = "MINUS";
                }
                else if (ch == '*') {
                    state = 37;
                    tokenValue += ch;
                    tokenType = "MUL";
                }
                else if (ch == '/') {
                    state = 38;
                    tokenValue += ch;
                    tokenType = "DIV";
                }
                else if (ch == '%') {
                    state = 39;
                    tokenValue += ch;
                    tokenType = "MOD";
                }
                else if (ch == '<') {
                    state = 40;
                    tokenValue += ch;
                    tokenType = "LT";
                }
                else if (ch == '>') {
                    state = 41;
                    tokenValue += ch;
                    tokenType = "GT";
                }
                else if (ch == '!') {
                    state = 44;
                    tokenValue += ch;
                    tokenType = "";
                }
                else if (ch == '=') {
                    state = 46;
                    tokenValue += ch;
                    tokenType = "ASSIGN";
                }
                else if (ch == ',') {
                    state = 48;
                    tokenValue += ch;
                    tokenType = "COMMA";
                }
                else if (ch == '(') {
                    state = 49;
                    tokenValue += ch;
                    tokenType = "LRP";
                }
                else if (ch == ')') {
                    state = 50;
                    tokenValue += ch;
                    tokenType = "RRP";
                }
                else if (ch == '[') {
                    state = 51;
                    tokenValue += ch;
                    tokenType = "LS";
                }
                else if (ch == ']') {
                    state = 52;
                    tokenValue += ch;
                    tokenType = "RS";
                }
                else if (ch == ';') {
                    state = 53;
                    tokenValue += ch;
                    tokenType = "SEM";
                }
                else if (ch == '{') {
                    state = 54;
                    tokenValue += ch;
                    tokenType = "LB";
                }
                else if (ch == '}') {
                    state = 55;
                    tokenValue += ch;
                    tokenType = "RB";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '1') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '2') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '3') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '4') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '5') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '6') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '7') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '8') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '9') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 1:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'f') {
                    state = 2;
                    tokenValue += ch;
                    tokenType = "IF";
                }
                else if (ch == 'n') {
                    state = 7;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 3:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'l') {
                    state = 4;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 9:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'l') {
                    state = 10;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 14:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'o') {
                    state = 15;
                    tokenValue += ch;
                    tokenType = "DO";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 20:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'e') {
                    state = 21;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 26:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'o') {
                    state = 27;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 30:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'h') {
                    state = 31;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 35:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "PLUS";
                undoGetChar();
                break;
            case 36:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "MINUS";
                undoGetChar();
                break;
            case 37:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "MUL";
                undoGetChar();
                break;
            case 38:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "DIV";
                undoGetChar();
                break;
            case 39:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "MOD";
                undoGetChar();
                break;
            case 40:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '=') {
                    state = 42;
                    tokenValue += ch;
                    tokenType = "LE";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 41:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '=') {
                    state = 43;
                    tokenValue += ch;
                    tokenType = "GE";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 44:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '=') {
                    state = 45;
                    tokenValue += ch;
                    tokenType = "NE";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 46:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '=') {
                    state = 47;
                    tokenValue += ch;
                    tokenType = "EQ";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 48:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "COMMA";
                undoGetChar();
                break;
            case 49:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "LRP";
                undoGetChar();
                break;
            case 50:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "RRP";
                undoGetChar();
                break;
            case 51:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "LS";
                undoGetChar();
                break;
            case 52:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "RS";
                undoGetChar();
                break;
            case 53:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "SEM";
                undoGetChar();
                break;
            case 54:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "LB";
                undoGetChar();
                break;
            case 55:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "RB";
                undoGetChar();
                break;
            case 56:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 57:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '0') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '1') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '2') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '3') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '4') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '5') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '6') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '7') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '8') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '9') {
                    state = 58;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '.') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 2:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 7:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 't') {
                    state = 8;
                    tokenValue += ch;
                    tokenType = "INT";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 4:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 's') {
                    state = 5;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 10:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'o') {
                    state = 11;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 15:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'u') {
                    state = 16;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 21:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 't') {
                    state = 22;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 27:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'i') {
                    state = 28;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 31:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'i') {
                    state = 32;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 42:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "LE";
                undoGetChar();
                break;
            case 43:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "GE";
                undoGetChar();
                break;
            case 45:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "NE";
                undoGetChar();
                break;
            case 47:
                output(tokenType, tokenValue);
                state = 0;
                tokenValue = "";
                tokenType = "EQ";
                undoGetChar();
                break;
            case 58:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '0') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '1') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '2') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '3') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '4') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '5') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '6') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '7') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '8') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '9') {
                    state = 58;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else if (ch == '.') {
                    state = 57;
                    tokenValue += ch;
                    tokenType = "NUM";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 8:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 5:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'e') {
                    state = 6;
                    tokenValue += ch;
                    tokenType = "ELSE";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 11:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'a') {
                    state = 12;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 16:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'b') {
                    state = 17;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 22:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'u') {
                    state = 23;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 28:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'd') {
                    state = 29;
                    tokenValue += ch;
                    tokenType = "VOID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 32:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'l') {
                    state = 33;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 6:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 12:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 't') {
                    state = 13;
                    tokenValue += ch;
                    tokenType = "FLOAT";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 17:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'l') {
                    state = 18;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 23:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'r') {
                    state = 24;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 29:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 33:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'e') {
                    state = 34;
                    tokenValue += ch;
                    tokenType = "WHILE";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 13:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 18:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'e') {
                    state = 19;
                    tokenValue += ch;
                    tokenType = "DOUBLE";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 24:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == 'n') {
                    state = 25;
                    tokenValue += ch;
                    tokenType = "RETURN";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 34:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 19:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            case 25:
                if (ch == '\0') {
                    output(tokenType, tokenValue);
                    return;
                }
                else if (ch == ' ') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\n') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '\t') {
                    output(tokenType, tokenValue);
                    state = 0;
                    tokenValue = "";
                }
                else if (ch == '_') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'a') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'b') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'c') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'd') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'e') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'f') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'g') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'h') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'i') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'j') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'k') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'l') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'm') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'n') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'o') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'p') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'r') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 's') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 't') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'u') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'v') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'w') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'x') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'A') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'B') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'C') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'D') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'E') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'F') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'G') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'H') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'I') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'J') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'K') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'L') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'M') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'N') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'O') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'P') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Q') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'R') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'S') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'T') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'U') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'V') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'W') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'X') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Y') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == 'Z') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '0') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '1') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '2') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '3') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '4') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '5') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '6') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '7') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '8') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else if (ch == '9') {
                    state = 56;
                    tokenValue += ch;
                    tokenType = "ID";
                }
                else {
                    output(tokenType, tokenValue);
                    tokenValue = "";
                    state = 0;
                    undoGetChar();
                }
                break;
            default:
                cout << "error" << endl;
                return;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        return 0;
    }    input = readFile(argv[1]);
    solve();
    return 0;
}