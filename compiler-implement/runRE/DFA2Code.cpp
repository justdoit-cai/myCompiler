#ifndef _DFA2CODE_H
#define _DFA2CODE_H
#include "NFA2DFA.cpp"
#include <queue>
using namespace std;

struct Edge2{
    int from, to;
    set<char> chSet;
};

class DFA2Code {
public:
    // 需要的输入
    vector<pair<string ,vector<Edge>>> dfaEdgeListList;
    vector<int> dfaStartStateList;
    // 输出，起点从0开始，按照顺序递增
    vector<Edge> combinedDfaEdgeList;
    vector<Edge2> simplifiedEdgeList;
    vector<string> newNodeList;
    int currentNodeIdx = 0;
    string code;
    map<int, vector<Edge>> nextEdgeMapAll; // 记录合并后的图某个节点有哪些后继边
    DFA2Code(vector<pair<string ,vector<Edge>>> dfaEdgeListList, vector<int> dfaStartStateList) {
        this->dfaEdgeListList = dfaEdgeListList;
        this->dfaStartStateList = dfaStartStateList;
    }
    // 让所有dfa图合并为起点一致的图
    void combineAllDfa() {
        newNodeList.emplace_back("");
        for (int i = 0; i < dfaEdgeListList.size(); ++i) {
            pair<string, vector<Edge>> item = dfaEdgeListList[i]; // 某个dfa图
            string name = item.first; // 当前dfa图对应的是哪个token
            vector<Edge> dfaEdgeList = item.second; // 当前dfa图的边
            int startState = dfaStartStateList[i]; // 当前dfa图起始点的序号
            int endState = 1; // 当前dfa图终点的序号
            map<int, set<int>> nodeMapping; // 原图的节点序号:合并后图的节点序号,注意这里原图中的一个节点可能对应新图中的多个节点
            set<int> s1;
            s1.insert(0);
            nodeMapping.insert(make_pair(startState, s1)); // 把起点都映射到新图的0节点
            map<int, vector<Edge>> nextEdgeMap;
            // 记录当前dfa图的某个节点有哪些后继边
            for (int j = 0; j < dfaEdgeList.size(); ++j) { // 遍历当前dfa图边
                int from = dfaEdgeList[j].from;
                if (nextEdgeMap.count(from)) { // 记录过就修改
                    nextEdgeMap.find(from)->second.push_back(dfaEdgeList[j]);
                } else { // 反之插入
                    vector<Edge> tmp;
                    tmp.push_back(dfaEdgeList[j]);
                    nextEdgeMap.insert(make_pair(from,tmp));
                }
            }
            // 从当前dfa图的起点开始bfs遍历，把起点都设为0
            queue<int> workQueue;
            workQueue.push(startState);
            bool visit[1000];
            for (int k = 0; k < 1000; ++k) {
                visit[k] = false;
            }
            while (!workQueue.empty()) {
                int pNode = workQueue.front();
                workQueue.pop();
                if (!nextEdgeMap.count(pNode)) {
                    continue;
                }
                vector<Edge> nextEdgeList = nextEdgeMap.find(pNode)->second;
                visit[pNode] = true;
                if (nodeMapping.find(pNode)->second.size() > 1) { // 处理多个from是等价的情况
                    set<int> fromSet = nodeMapping.find(pNode)->second;
                    for (int l = 0; l < nextEdgeList.size(); ++l) {
                        Edge edge = nextEdgeList[l];
                        for (int from: fromSet) {
                            for (Edge edgeAll : combinedDfaEdgeList) {
                                if (edgeAll.from == from && edgeAll.ch == edge.ch) {
                                    if (!nodeMapping.find(pNode)->second.count(edgeAll.to)) {
                                        nodeMapping.find(pNode)->second.insert(edgeAll.to);
                                        fromSet.insert(edgeAll.to);
                                        l = -1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                for (int l = 0; l < nextEdgeList.size(); ++l) { // 遍历当前节点的后续边
                    bool isEnd = false;
                    Edge edge = nextEdgeList[l];
                    if (endState == edge.to) {
                        isEnd = true;
                    }
                    if (!visit[edge.to]) {
                        workQueue.push(edge.to);
                        visit[edge.to] = true;
                    }
                    int from, to;
                    if (!nodeMapping.count(edge.from)) { // 没有映射过，也就是新点
                        currentNodeIdx++;
                        from = currentNodeIdx;
                        set<int> s2;
                        s2.insert(from);
                        nodeMapping.insert(make_pair(edge.from, s2));
                        newNodeList.emplace_back("");
                        if (!nodeMapping.count(edge.to)) { // 没有映射过
                            currentNodeIdx++;
                            to = currentNodeIdx;
                            set<int> s3;
                            s3.insert(to);
                            nodeMapping.insert(make_pair(edge.to, s3));
                            if (isEnd) {
                                newNodeList.emplace_back(name);
                            } else {
                                newNodeList.emplace_back("");
                            }
                        } else { // 在简化了的dfa图中不可能出现from没有映射过，但是to映射过了这种情况，肯定一个to点只能对应一个from点，但是可能一个from点对应多个to点
                            // error
                            cout << "ERROR";
                        }
                        combinedDfaEdgeList.emplace_back(from, to, edge.ch);
                        if (nextEdgeMapAll.count(from)) {
                            nextEdgeMapAll.find(from)->second.emplace_back(from, to, edge.ch);
                        } else {
                            vector<Edge> tmp;
                            tmp.emplace_back(from, to, edge.ch);
                            nextEdgeMapAll.insert(make_pair(from, tmp));
                        }
                    } else { // from映射过的话要注意看有没有相同的后继边，有的话就不用先建后继点和后继边了
                        set<int> s4 = nodeMapping.find(edge.from)->second;
                        for (int f : s4) {
                            bool isFound = false; // 是否有相同的后继边
                            if (nextEdgeMapAll.count(f)) { // 有后继边
                                vector<Edge> nextEdgeListAll = nextEdgeMapAll.find(f)->second;
                                for (Edge edgeAll: nextEdgeListAll) {
                                    if (edgeAll.ch == edge.ch) { // 找到了相同的后继边
                                        // 找到了就不用新建,需要注意一个from可以经过多个ch到不同的to这种情况，此时就不能修改nodeMapping，而是应该一个原图中的点对应多个合并图的点
                                        // 注意在新映射
                                        isFound = true;
                                        if (nodeMapping.count(edge.to)) {
                                            nodeMapping.find(edge.to)->second.insert(edgeAll.to);
                                        } else {
                                            set<int> s5;
                                            s5.insert(edgeAll.to);
                                            nodeMapping.insert(make_pair(edge.to, s5));
                                        }
                                        if (isEnd && newNodeList[edgeAll.to].empty()) {
                                            newNodeList[edgeAll.to] = name;
                                        }
                                        break;
                                    }
                                }
                            }
                            if (!isFound) {
                                if (!nodeMapping.count(edge.to)) { // to没有映射过
                                    currentNodeIdx++;
                                    to = currentNodeIdx;
                                    set<int> s6;
                                    s6.insert(to);
                                    nodeMapping.insert(make_pair(edge.to, s6));
                                    if (isEnd) {
                                        newNodeList.emplace_back(name);
                                    } else {
                                        newNodeList.emplace_back("");
                                    }
                                    combinedDfaEdgeList.emplace_back(f, to, edge.ch);
                                    if (nextEdgeMapAll.count(f)) {
                                        nextEdgeMapAll.find(f)->second.emplace_back(f, to, edge.ch);
                                    } else {
                                        vector<Edge> tmp;
                                        tmp.emplace_back(f, to, edge.ch);
                                        nextEdgeMapAll.insert(make_pair(f, tmp));
                                    }
                                } else {
                                    // to有多个只用选一个(肯定是选大的，最大的最后)就行了，不然会有很多无用边
                                    int t = *nodeMapping.find(edge.to)->second.rbegin();
                                    combinedDfaEdgeList.emplace_back(f, t, edge.ch);
                                    if (nextEdgeMapAll.count(f)) {
                                        nextEdgeMapAll.find(f)->second.emplace_back(f, t, edge.ch);
                                    } else {
                                        vector<Edge> tmp;
                                        tmp.emplace_back(f, t, edge.ch);
                                        nextEdgeMapAll.insert(make_pair(f, tmp));
                                    }
                                }

                            }
                        }
                    }
                }
            }
        }
    }
    // 下班从0开始
    vector<Edge2> simplifyGraph(vector<Edge> edgeList){
        vector<Edge2> ret;
        queue<int> workQueue;
        workQueue.push(0);
        bool visit[1000];
        for (int i = 0; i < 1000;++i) {
            visit[i] = false;
        }
        while (!workQueue.empty()) {
            int pNode = workQueue.front();
            workQueue.pop();
            if (!nextEdgeMapAll.count(pNode)) {
                continue;
            }
            vector<Edge> nextEdgeList = nextEdgeMapAll.find(pNode)->second;
            map<int, set<char>> nextNodeMap;
            for (int i = 0; i < nextEdgeList.size(); ++i) {
                Edge edge = nextEdgeList[i];
                if (!nextNodeMap.count(edge.to)) {
                    set<char> s;
                    s.insert(edge.ch);
                    nextNodeMap.insert(make_pair(edge.to, s));
                } else {
                    nextNodeMap.find(edge.to)->second.insert(edge.ch);
                }
            }
            for (auto it : nextNodeMap) {
                if (!visit[it.first]) {
                    workQueue.push(it.first);
                    visit[it.first] = true;
                }
                ret.emplace_back(Edge2{pNode, it.first, it.second});
            }
        }
        return ret;
    }
    string getTemplate(char ch, int to) {
        string ret = "                else if (ch == \'";
        ret += ch;
        ret += "\') {\n";
        ret +=       "                    state = " + to_string(to) + ";\n"
                     "                    tokenValue += ch;\n"
                     "                    tokenType = \"" + newNodeList[to] + "\";\n"
                     "                }\n";
        return ret;
    }
    // 下标从0开始
    void getCode() {
        code += "#include <iostream>\n"
                "#include <fstream>\n"
                "#include <string>\n"
                "using namespace std;\n"
                "\n"
                "string input;\n"
                "int idx = 0;\n"
                "char getNextChar() {\n"
                "    if (idx == input.length()) {\n"
                "        return '\\0';\n"
                "    }\n"
                "    return input[idx++];\n"
                "}\n"
                "void undoGetChar() {\n"
                "    idx--;\n"
                "}\n"
                "\n"
                "void output(string tokenType, string tokenValue) {\n"
                "    cout << tokenType << \":\" << tokenValue << endl;\n"
                "}\n"
                "string readFile(string filename) {\n"
                "    string result;\n"
                "    ifstream in(filename);\n"
                "    if (!in.is_open()) {\n"
                "        cout << \"error reading file!\" << endl;\n"
                "        exit(0);\n"
                "    }\n"
                "\n"
                "    while (!in.eof()) {\n"
                "        result += in.get();\n"
                "    }\n"
                "    in.close();\n"
                "\n"
                "    return result.substr(0, result.length() - 1) + '\\0';\n"
                "}\n"
                "void solve() {\n"
                "    int state = 0;\n"
                "    string tokenValue;\n"
                "    string tokenType;\n"
                "    while (1) {\n"
                "        char ch = getNextChar();\n"
                "        switch (state) {\n";
        string str0 = "                if (ch == '\\0') {\n"
                      "                    return;\n"
                      "                }\n"
                      "                else if (ch == ' ') {\n"
                      "                    state = 0;\n"
                      "                    tokenValue = \"\";\n"
                      "                }\n"
                      "                else if (ch == '\\n') {\n"
                      "                    state = 0;\n"
                      "                    tokenValue = \"\";\n"
                      "                }\n"
                      "                else if (ch == '\\t') {\n"
                      "                    state = 0;\n"
                      "                    tokenValue = \"\";\n"
                      "                }\n";
        string str1 = "                if (ch == '\\0') {\n"
                      "                    output(tokenType, tokenValue);\n"
                      "                    return;\n"
                     "                }\n"
                     "                else if (ch == ' ') {\n"
                     "                    output(tokenType, tokenValue);\n"
                     "                    state = 0;\n"
                     "                    tokenValue = \"\";\n"
                     "                }\n"
                     "                else if (ch == '\\n') {\n"
                     "                    output(tokenType, tokenValue);\n"
                     "                    state = 0;\n"
                     "                    tokenValue = \"\";\n"
                     "                }\n"
                     "                else if (ch == '\\t') {\n"
                     "                    output(tokenType, tokenValue);\n"
                     "                    state = 0;\n"
                     "                    tokenValue = \"\";\n"
                     "                }\n";
        bool visit[1000];
        for (int i = 0; i < 1000; ++i) {
            visit[i] = false;
        }
        queue<int> workQueue;
        workQueue.push(0);
        while (!workQueue.empty()) {
            int pNode = workQueue.front();
            workQueue.pop();
            if (!nextEdgeMapAll.count(pNode)) {
                code += "            case " + to_string(pNode) + ":\n"
                        "                output(tokenType, tokenValue);\n"
                        "                state = 0;\n"
                        "                tokenValue = \"\";\n"
                        "                tokenType = \"" + newNodeList[pNode] + "\";\n"
                        "                undoGetChar();\n"
                        "                break;\n";
                continue;
            }
            vector<Edge> nextEdgeList = nextEdgeMapAll.find(pNode)->second;
            code += "            case " + to_string(pNode) + ":\n";
            if (pNode == 0) {
                code += str0;
            } else {
                code += str1;
            }
            for (int i = 0; i < nextEdgeList.size(); ++i) {
                Edge edge = nextEdgeList[i];
                if (!visit[edge.to]) {
                    workQueue.push(edge.to);
                    visit[edge.to] = true;
                }
                code += getTemplate(edge.ch, edge.to);
            }
            code += "                else {\n"
                    "                    output(tokenType, tokenValue);\n"
                    "                    tokenValue = \"\";\n"
                    "                    state = 0;\n"
                    "                    undoGetChar();\n"
                    "                }\n"
                    "                break;\n";
        }
        code += "            default:\n"
                "                cout << \"error\" << endl;\n"
                "                return;\n"
                "        }\n"
                "    }\n"
                "}\n"
                "\n"
                "int main(int argc, char* argv[]) {\n"
                "    if (argc != 2) {\n"
                "        return 0;\n"
                "    }\n"
                "    input = readFile(argv[1]);\n"
                "    solve();\n"
                "    return 0;\n"
                "}";
    }
};
#endif