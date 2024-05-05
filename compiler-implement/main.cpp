#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "utils.cpp"
#include "runRE/runRE.cpp"
#include "runGrammar/runGrammar.cpp"
using namespace std;

json solveRE(string filename){
    map<string, json> ret;
    vector<string> content = readFileByLine(filename);
    vector<pair<string, string>> rePairList;
    for (string line : content) {
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == '=') {
                rePairList.emplace_back(make_pair(line.substr(0, i), line.substr(i+1)));
                break;
            }
        }
    }
    Lex lex = Lex(rePairList);
    ret.insert(make_pair("graph", lex.getGraph()));
    ret.insert(make_pair("code", lex.getCode()));
    return ret;
}
json transformJson(json j, map<char, string> m)
{
    json ret;
    for (const auto &item : j.items())
    {
        if (!item.key().empty() && j[item.key()].is_object())
        {
            ret[m.find(item.key()[0])->second] = transformJson(j[item.key()], m);
        }
        else if (!item.key().empty() && j[item.key()].is_array())
        {
            for (int i = 0; i < j[item.key()].size(); i++)
            {
                if (j[item.key()][i].is_object()) {
                    ret[m.find(item.key()[0])->second].emplace_back(transformJson(j[item.key()][i], m));
                } else {
                    ret[m.find(item.key()[0])->second].emplace_back(j[item.key()][i]);
                }
            }
        }
        else if (!item.key().empty())
        {
            return item;
        }
        else {
            return item;
        }
    }
    return ret;
}
json solveGrammar(string grammarPath, string lexPath) {
    map<string, json> ret;
    map<string, char> charMap;
    map<char, string> reverseCharMap; // charMap的反向kv存储，便于根据value反向搜索key
    vector<string> grammarInput = readFileByLine(grammarPath); // 输入的文法文件
    vector<string> tokenInput = readFileByLine(lexPath); // 输入的lex文件
    vector<pair<string, string>> grammarList; // 输入的文法文件转为pair存储
    vector<string> grammarList2;
    vector<Production> productionList;
    char terminatorChar = 65; // 终结符
    char nonTerminatorChar = 33; // 非终结符
    // 初始化非终结点，分配其对应的单个字符，因为文法处理程序只能识别一个符号为一个整体
    for (string grammar : grammarInput) {
        int idx = grammar.find("->");
        string leftPart = grammar.substr(0, idx);
        string rightPart = grammar.substr(idx + 2);
        charMap.insert(make_pair(leftPart, nonTerminatorChar));
        reverseCharMap.insert(make_pair(nonTerminatorChar, leftPart));
        cout << leftPart << " : " << nonTerminatorChar << endl;
        nonTerminatorChar++;
        if (nonTerminatorChar == '@' || nonTerminatorChar == EXT_START || nonTerminatorChar == '.') {
            nonTerminatorChar++;
        }
        grammarList.emplace_back(make_pair(leftPart, rightPart));
    }
    // 将右部转为单个字符
    for (auto grammar : grammarList) {
        string leftPart = grammar.first;
        string rightPart = grammar.second;
        vector<string> partList1 = split(rightPart, "|"); // 右部先用|分割
        for (string part1 : partList1) {
            vector<string> partList2 = split(part1, " "); // 再用空格分隔
            string str;
            for (string part2 : partList2) {
                part2 = replace(part2, " ", "");
                if (part2 == "") continue;
                if (part2 == "@") {
                    charMap.insert(make_pair("@", '@'));
                    reverseCharMap.insert(make_pair('@', "@"));
                    cout << "@ : @" << endl;
                    str = '@';
                    break;
                }
                if (charMap.count(part2)) {
                    str += charMap.find(part2)->second;
                } else {
                    if (charMap.count(part2)) {
                        str += charMap.find(part2)->second;
                    } else {
                        str += terminatorChar;
                        cout << part2 << " : " << terminatorChar << endl;
                        charMap.insert(make_pair(part2, terminatorChar));
                        reverseCharMap.insert(make_pair(terminatorChar, part2));
                        terminatorChar++;
                    }
                }
                str += " ";
            }
            str = replace(str, " ", ""); // 去除空格
            productionList.emplace_back(Production{charMap.find(leftPart)->second, str});
        }
    }
    // 开始分析文法
    Grammar grammar = Grammar(productionList, reverseCharMap);
    // 输出first和follow集
    for (char ch: grammar.nonTerminatorSet) {
        json j;
        j["char"] = reverseCharMap.find(ch)->second;
        for (char ch1: grammar.firstSetMap.find(ch)->second) {
            if (reverseCharMap.count(ch1)) {
                j["firstSet"].push_back(reverseCharMap.find(ch1)->second);
            } else {
                j["firstSet"].push_back(char2str(ch1));
            }
        }
        for (char ch2: grammar.followSetMap.find(ch)->second) {
            if (reverseCharMap.count(ch2)) {
                j["followSet"].push_back(reverseCharMap.find(ch2)->second);
            } else {
                j["followSet"].push_back(char2str(ch2));
            }
        }
        ret["firstAndFollowSet"].emplace_back(j);
    }
    // 输出LR(1)DFA图
    for (DfaNode node: grammar.dfaNodeList) {
        json j1;
        for (Project p: node.projectSet) {
            json j2;
            if (reverseCharMap.count(p.leftPart)) {
                j2["left"] = reverseCharMap.find(p.leftPart)->second;
            } else {
                j2["left"] = char2str(p.leftPart);
            }
            string str;
            for (char ch : p.rightPart) {
                if (reverseCharMap.count(ch)) {
                    str += reverseCharMap.find(ch)->second;
                } else {
                    str += ch;
                }
                str += " ";
            }
            j2["right"] = str;
            j1.push_back(j2);
        }
        ret["lr0"]["node"].push_back(j1);
    }
    for (DfaEdge edge: grammar.dfaEdgeList) {
        json j1;
        j1["from"] = edge.from;
        j1["to"] = edge.to;
        string str;
        if (reverseCharMap.count(edge.val)) {
            str += reverseCharMap.find(edge.val)->second;
        } else {
            str += edge.val;
        }
        j1["label"] = str;
        ret["lr0"]["edge"].push_back(j1);
    }
    ret["isSlr1"] = grammar.isSlr1;
    cout << grammar.errResult;
    for (map<char, string> m: grammar.slr1Table) {
        json j;
        for (auto i: m) {
            string str1;
            if (reverseCharMap.count(i.first)) {
                str1 = reverseCharMap.find(i.first)->second;
            } else {
                str1 = i.first;
            }
            string str2;
            if (i.second.substr(0,2) == "r(") {
                str2 += "r(";
                if (reverseCharMap.count(i.second[2])) {
                    str2 += reverseCharMap.find(i.second[2])->second;
                } else {
                    str2 += i.second[2];
                }
                str2 += "->";
                for (int k = 5; k < i.second.length() - 1; ++k) {
                    char t = i.second[k];
                    if (reverseCharMap.count(t)) {
                        str2 += reverseCharMap.find(t)->second;
                    } else {
                        str2 += t;
                    }
                    str2 += " ";
                }
                str2.erase(str2.length() - 1, 1);
                str2 += ')';
            } else {
                str2 = i.second;
            }
            j[str1] = str2;
        }
        ret["slr1"].push_back(j);
    }
//    ret["errResult"] = grammar.errResult;
    // 语法树生成
    vector<Token> tokenList;
    for (string s : tokenInput) {
        if (s.find(":") == string::npos) {
            continue;
        }
        int idx = s.find(":");
        tokenList.emplace_back(Token{charMap.find(s.substr(0, idx))->second, s.substr(idx + 1)});
    }
    json tree = grammar.outputGrammarTree(tokenList);
    ret["tree"] = transformJson(tree, reverseCharMap);
    return ret;
}

/**
 * 输入正则表达式，生成对应的NFA图，DFA图，最小化的DFA图，词法分析程序
 * main.exe <input re file>
 * 输入文法文件和lex文件，生成文法对应的first集，follow集，LR(0)DFA图，SLR(1)分析表和lex对应的语法树
 * main.exe <input grammar file> <input lex file>
 * @return
 */
int main(int argc, char* argv[]) {
    string help = " * 输入正则表达式，生成对应的NFA图，DFA图，最小化的DFA图，词法分析程序\n"
                  " * main.exe <input re file>\n"
                  " * 输入文法文件和lex文件，生成文法对应的first集，follow集，LR(0)DFA图，SLR(1)分析表和lex对应的语法树\n"
                  " * main.exe <input grammar file> <input lex file>";
    if (argc == 2) {
        writeFile("temp/temp_re.out", solveRE(argv[1]).dump(4));
    }
    else if (argc == 3) {
        writeFile("temp/temp_grammar.out", solveGrammar(argv[1], argv[2]).dump(4));
    } else {
        cout << help << endl;
    }
//    writeFile("out/tiny_re.out", solveRE("./test/re/tiny.re").dump(4));
//    writeFile("out/minic_re.out", solveRE("./test/re/minic.re").dump(4));
//    writeFile("out/tiny_grammar.out", solveGrammar("C:\\Users\\20688\\Desktop\\compiler-project\\compiler-implement\\test\\grammar\\minic.grammar", "C:\\Users\\20688\\Desktop\\compiler-project\\compiler-front\\1714937490746.txt").dump(4));
//    writeFile("out/tiny_grammar.out", solveGrammar("C:\\Users\\20688\\Desktop\\compiler-project\\test\\grammar\\tiny.grammar", "C:\\Users\\20688\\Desktop\\compiler-project\\compiler-front\\app\\start-win32-x64\\temp\\1714943683024.txt").dump(4));
    return 0;
}