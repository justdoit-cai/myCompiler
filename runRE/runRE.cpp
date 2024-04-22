//#include <string>
//#include <map>
//#include <vector>
//#include <set>
//#include <algorithm>
//#include <queue>
//#include <stack>
//#include <fstream>
//#include "../nlohmann/json.hpp"
//
//using namespace std;
//using json = nlohmann::json;
//
//class Lex {
//public:
//    // 预声明（前向声明的类或者结构体只能用来定义指针或者引用）
//    class RE2NFA;
//
//    class NFA2DFA;
//
//    class SimplifyDFA;
//
//    class DFA2Code;
//
//    struct Edge {
//        int from;
//        int to;
//        char ch;
//
//        Edge(int from, int to, char ch) : from(from), to(to), ch(ch) {};
//    };
//
//
//
//
//    // 成员变量
//    string data; // 输入的RE字符串
//    NFAToken nfaToken; // 存储NFA的边信息和终止节点
//    map<int, vector<Edge>> nextNfaEdgeMap; // 记录某个节点有哪些后续节点
//    vector<set<int>> dfaNodeList; // 记录某个状态集里面有哪些节点
//    vector<Edge> dfaEdgeList; // 记录DFA的边信息
//    vector<set<int>> simplifiedDfaNodeList; // 记录某个状态集里面有哪些节点
//    vector<Edge> simplifiedDfaEdgeList; // 记录简化后DFA的边信息
//    int simplifiedDfaStartState; // DFA的初始状态属于哪个状态集，根据算法可知，DFA终结状态的状态集下标一定为1
//    string outputCode; // 最终返回的词法分析程序代码
//
//
//    // 内部类
//    RE2NFA *inner1;
//    NFA2DFA *inner2;
//    SimplifyDFA *inner3;
//    DFA2Code *inner4;
//
//    // 内部类定义
//
//
//    class NFA2DFA {
//    public:
//        Lex *outer;
//
//        bool visited[1000] = {0}; // 长度应为token.endState + 1
//        int dfaNodeListIdx = 0; // 记录当前结尾状态集的下标，等价于dfaNodeList.length()-1，从而不用重复查询dfaNodeList的长度
//
//        NFA2DFA(Lex *outer) {
//            this->outer = outer;
//        }
//
//        /**
//         * @param pNode 当前的节点下标
//         * @param currentDfaNodeListIdx 当前节点属于dfaNodeList中的哪个状态集
//         * @return
//         */
//        void dfs(int pNode, int currentDfaNodeListIdx) {
//            if (!outer->nextNfaEdgeMap.count(pNode)) { // 没有后续边
//                return;
//            }
//            vector<Edge> nextEdgeList = outer->nextNfaEdgeMap.find(pNode)->second; // 当前节点有哪些后续边
//
//            for (int i = 0; i < nextEdgeList.size(); ++i) { // 遍历当前节点的后续边
//                int to = nextEdgeList[i].to;
//                char ch = nextEdgeList[i].ch;
//                map<char, int> newStateMap; // 维护不同状态后继节点的集合，避免相同值的后继节点被分到不同状态
//                if (ch == '#') { // 同一状态集
//                    this->outer->dfaNodeList[currentDfaNodeListIdx].insert(to); // 下一节点加入当前状态集
//                    dfs(to, currentDfaNodeListIdx);
//                } else { // 不同状态集，需要注意后继节点如果相同，算同一状态集，有多少个不同的后继节点，状态集就加多少，所以还需要知道后继节点的集合
//                    if (!visited[pNode]) {
//                        visited[pNode] = true; // 避免无限递归，但是只有非空串后续节点需要记录，空串后续节点可以重复遍历
//                        if (!newStateMap.count(ch)) { // 没有记录过这个字符的边，状态集就加一
//                            dfaNodeListIdx++;
//                            outer->dfaEdgeList.emplace_back(Edge(currentDfaNodeListIdx, dfaNodeListIdx, ch));
//                            newStateMap.insert(make_pair(ch, dfaNodeListIdx)); // 记录当前节点的哪些后续边的字符之前已经记录过了
//                            // 注意新添加dfaNodeList元素的时候要初始化，所以要判断一下插入的那个位置初始化过没
//                            if (this->outer->dfaNodeList.size() > dfaNodeListIdx) { // 之前初始化过
//                                this->outer->dfaNodeList[dfaNodeListIdx].insert(to);
//                            } else { // 没初始化过
//                                set<int> s;
//                                s.insert(to);
//                                this->outer->dfaNodeList.emplace_back(s);
//                            }
//                            dfs(to, dfaNodeListIdx);
//                        } else { // 当前字符之前已经记录过，就直接在map中找下一个节点属于哪个状态集
//                            this->outer->dfaNodeList[newStateMap.find(ch)->second].insert(to);
//                            dfs(to, newStateMap.find(ch)->second); // ch相同就相同状态集
//                        }
//                    } else {
//                        // 遍历过的非空边集不需要向后遍历，但是需要记录边,这里就要思考怎么知道后继节点是哪个状态的（非空边的后继节点一定只属于一个状态集，空边的后继节点可以属于多个状态集）
//                        // 找到非空边的后继节点属于哪个状态集（一定是找的到的，因为是遍历过了的）
//                        for (int j = 0; j < this->outer->dfaNodeList.size(); ++j) { // 遍历状态集数组
//                            for (auto k: this->outer->dfaNodeList[j]) { // 遍历状态集
//                                if (k == to) {
//                                    outer->dfaEdgeList.emplace_back(Edge(currentDfaNodeListIdx, j, ch));
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//        /**
//         * NFA转DFA(使用子集构造法)
//         * 在箭头的方向上，一路值为#的都可以看作为同一状态，直到遇到不为#的箭头，才算下一状态。这样状态数就可以减少
//         * 1. 消除空串
//         * 2. 消除多重转换
//         * 要求：
//         * 1. DFA初态只有一个
//         * 2. DFA中存在的都是非空转换
//         * 思路：
//         * Q: 如何找到初态?
//         * A: 没有箭头指向的节点就是起点（在上面求NFA的算法中可知，编号为1的节点就是起点），然后找到和这个起点同一状态的所有节点集就是初态。
//         * Q: 如何找到同一状态的状态集?
//         * A: 从某一节点出发，沿着箭头的边向后深度优先遍历，如果遇到非空串就return
//         * 遍历某个的节点的时候，如果这个节点的后继节点是空串，就记录这个节点的编号，加入上个节点的状态集，我们需要维护一个变量，存放某个状态集和后续状态集和路径值，
//         * 由于一个状态集会有多个后续状态集，因此整个的数据结构类似于树，因此后续状态集需要存放在一个数组里。
//         * */
//        void innerRun(NFAToken token) {
//            vector<Edge> edgeList = token.nfaEdgeList;
//
//            // 初始化outer->nextNfaEdgeMap变量
//            for (int i = 0; i < edgeList.size(); ++i) {
//                int from = edgeList[i].from;
//                if (outer->nextNfaEdgeMap.count(from) == 0) { // 没有记录过
//                    vector<Edge> v;
//                    v.emplace_back(edgeList[i]);
//                    outer->nextNfaEdgeMap.insert(make_pair(from, v));
//                } else { // 记录过
//                    auto iter = outer->nextNfaEdgeMap.find(from);
//                    iter->second.emplace_back(edgeList[i]);
//                }
//            }
//
//            // 直接将起点放到状态集的开头，根据前面RE2NFA的算法，可以知道下标为1的节点为起点
//            set<int> s;
//            s.insert(1);
//            outer->dfaNodeList.emplace_back(s);
//
//            // 从起点1开始dfs
//            dfs(1, 0);
//        }
//
//        void run() {
//            innerRun(this->outer->nfaToken);
//        }
//
//        json toJson() {
//            json ret;
//            ret["start"] = 0;
//            vector<int> end;
//            for (int i = 0; i < this->outer->dfaNodeList.size(); ++i) { // 包括了NFA终态节点的DFA状态就是DFA的非接受终态
//                for (int j: this->outer->dfaNodeList[i]) {
//                    if (this->outer->nfaToken.endState == j) {
//                        end.emplace_back(i);
//                        break;
//                    }
//                }
//            }
//            ret["end"] = end;
//            for (int i = 0; i < this->outer->dfaEdgeList.size(); ++i) {
//                Edge edge = this->outer->dfaEdgeList[i];
//                string ch = {edge.ch}; // 直接将char放到json会转为数字
//                json tmp;
//                tmp["from"] = edge.from;
//                tmp["to"] = edge.to;
//                tmp["label"] = ch;
//                ret["data"]["edgeList"].emplace_back(tmp);
//            }
//            for (int i = 0; i < this->outer->dfaNodeList.size(); ++i) {
//                json tmp;
//                for (int j : this->outer->dfaNodeList[i]) {
//                    tmp.emplace_back(j);
//                }
//                ret["data"]["nodeList"].emplace_back(tmp);
//            }
//            return ret;
//        }
//    };
//
//    class SimplifyDFA {
//    public:
//        Lex *outer;
//
//        SimplifyDFA(Lex *outer) {
//            this->outer = outer;
//        }
//
//        /**
//         * https://www.tr0y.wang/2021/04/01/%E7%BC%96%E8%AF%91%E5%8E%9F%E7%90%86%EF%BC%88%E4%B8%80%EF%BC%89%EF%BC%9A%E8%AF%8D%E6%B3%95%E5%88%86%E6%9E%90/#nfa-dfa
//         * https://zhuanlan.zhihu.com/p/31166841
//         * DFA的初态是包含了NFA初态的那个DFA状态；
//         * DFA的终态是所有包含了NFA终态的DFA的状态。
//         * DFA的非接受状态等于DFA的终态
//         * 状态数最少，即意味者把多余的，等价的状态进行合并,这里关键的就是如何划分等价的状态。
//         * Hopcroft 算法步骤：
//         * 1. 首先把整个状态划分为接收状态和非接受状态，方法是：包含了NFA终态节点的状态集就一定是DFA的非接收状态
//         * 2. 遍历某个状态集中存在的字符，看当前状态集的每个节点接收到这个字符跳转到的下一个状态是否相同，如果相同就继续判断下一个字符，直到所有字符都判断成功就可以成功插入到结果。
//         * 如果存在不同，就把当前状态集的节点根据当前字符到的目标状态来划分，划分后的结果重新入栈处理。
//         * 要注意等价状态，如果两个状态s，t，对于所有输入符号，状态s和状态t都转换到等价的状态里，那么这两个状态就是等价的
//         * 可区分：对于任何两个状态t和s，若从一状态出发接受输入字符串ω，而从另一状态出发不接受ω，或者从t出发和从s出发到达不同的接受状态，则称ω对状态t和s是可区分的。
//         * 不可区分：设想任何输入序列ω对s和t均是不可区分的，则说明从s出发和从t出发，分析任何输入序列ω均得到相同结果。因此，s和t可以合并成一个状态
//         */
//        void simplifyDFA() {
//            map<int, int> belongStateMap; // 记录某个节点属于哪个状态集
//            set<int> isAcceptedStateSet;  // 接收状态
//            set<int> notAcceptedStateSet; // 非接收状态
//            int length = 2; // 至少可以划分为接受状态和非接受状态
//
//
//            // 划分接收状态和非接受状态
//            for (int i = 0; i < this->outer->dfaNodeList.size(); ++i) { // 包括了NFA终态节点的DFA状态就是DFA的非接受终态
//                bool isAccepted = true;
//                for (int j: this->outer->dfaNodeList[i]) {
//                    if (this->outer->nfaToken.endState == j) {
//                        isAccepted = false;
//                        notAcceptedStateSet.insert(i);
//                        belongStateMap.insert(make_pair(i, 1));
//                        break;
//                    }
//                }
//                if (isAccepted) {
//                    isAcceptedStateSet.insert(i);
//                    belongStateMap.insert(make_pair(i, 0));
//                }
//            }
//
//            map<int, vector<Edge>> nextEdgeMap; // key为起点的边
//            // 初始化nextEdgeMap
//            for (int i = 0; i < this->outer->dfaEdgeList.size(); ++i) {
//                int from = this->outer->dfaEdgeList[i].from;
//                if (nextEdgeMap.count(from) == 0) {
//                    vector<Edge> v;
//                    v.emplace_back(this->outer->dfaEdgeList[i]);
//                    nextEdgeMap.insert(make_pair(from, v));
//                } else {
//                    auto iter = nextEdgeMap.find(from);
//                    iter->second.emplace_back(this->outer->dfaEdgeList[i]);
//                }
//            }
//
//            stack<set<int>> workStack;
//
//            workStack.push(isAcceptedStateSet);
//            workStack.push(notAcceptedStateSet);
//
//            while (!workStack.empty()) {
//                set<int> currentPartition = workStack.top();
//                workStack.pop();
//
//                if (currentPartition.empty()) {
//                    continue;
//                }
//
//                if (currentPartition.size() == 1) { // 节点数为一肯定无法划分
//                    this->outer->simplifiedDfaNodeList.emplace_back(currentPartition);
//                    continue;
//                }
//                // 注意：每个点的后续边的字符权值肯定只会在每个边只会出现一次，不然肯定会在NFA转DFA的时候合并到一个状态集，因此我们不用担心一个字符权值出现多次的情况
//                map<int, map<char, int>> charStateMapMap; // 记录每个点后续边的ch和toState的关系map
//                // 初始化charStateMapMap
//                for (int i: currentPartition) {
//                    //在map.find的时候一定要先判断map中有没有这个元素，不然可能有时候会报错有时候不会，导致很难debug
//                    if (!nextEdgeMap.count(i)) {
//                        map<char, int> m;
//                        charStateMapMap.insert(make_pair(i, m));
//                        continue;
//                    }
//                    // 没有上面的判断下面会报错，因为这里在nextEdgeMap找不到i，但是编译器却往后走了（看编译器），导致后面的->second为野指针。
//                    // terminate called after throwing an instance of 'std::bad_array_new_length'
//                    //  what():  std::bad_array_new_length
//                    vector<Edge> edgeList = nextEdgeMap.find(i)->second;
//                    map<char, int> charStateMap; // map内部会对key进行排序，有利于比较
//                    for (Edge edge: edgeList) {
//                        charStateMap.insert(make_pair(edge.ch, belongStateMap.find(edge.to)->second));
//                    }
//                    charStateMapMap.insert(make_pair(i, charStateMap));
//                }
//                map<char, int> charStateMap = charStateMapMap.find(*currentPartition.begin())->second;
//                for (char ch = ' '; ch <= '~'; ++ch) { // 可显示字符：开头为空格，对于的ASCII码为32，结尾为~，对应的ascii码是126
//                    map<int, set<int>> partitionMap;
//
//                    if (!charStateMap.count(ch)) { // 不存在某个字符的边就当toState=-1
//                        set<int> s;
//                        s.insert(*currentPartition.begin());
//                        partitionMap.insert(make_pair(-1, s));
//                    } else {
//                        set<int> s;
//                        s.insert(*currentPartition.begin());
//                        partitionMap.insert(make_pair(charStateMap.find(ch)->second, s));
//                    }
//
//                    for (int i: currentPartition) {
//                        if (i == *currentPartition.begin()) {
//                            continue;
//                        }
//                        map<char, int> _charStateMap = charStateMapMap.find(i)->second;
//                        int _toState = _charStateMap.find(ch)->second;
//                        if (!_charStateMap.count(ch)) { // 不存在ch
//                            if (partitionMap.count(-1)) {
//                                partitionMap.find(-1)->second.insert(i);
//                            } else {
//                                set<int> s;
//                                s.insert(i);
//                                partitionMap.insert(make_pair(-1, s));
//                            }
//                        } else {
//                            if (partitionMap.count(_toState)) {
//                                partitionMap.find(_toState)->second.insert(i);
//                            } else {
//                                set<int> s;
//                                s.insert(i);
//                                partitionMap.insert(make_pair(_toState, s));
//                            }
//                        }
//                    }
//
//                    // 看看是不是可分割的，如果是就将初步分割后的结果再次入栈
//                    if (partitionMap.size() != 1) {
//                        for (auto i: partitionMap) {
//                            length++;
//                            workStack.push(i.second);
//                            for (int j: i.second) { // 修改节点所属于的状态集
//                                belongStateMap.find(j)->second = length;
//                            }
//                        }
//                        goto last;
//                    }
//                }
//
//                this->outer->simplifiedDfaNodeList.emplace_back(currentPartition);
//
//                last:;
//            }
//            // 计算连边，记得去重
//            for (int i = 0; i < this->outer->dfaEdgeList.size(); ++i) {
//                Edge edge = this->outer->dfaEdgeList[i];
//                int from = edge.from;
//                int to = edge.to;
//                char ch = edge.ch;
//                int fromState = belongStateMap.find(from)->second;
//                int toState = belongStateMap.find(to)->second;
//                bool isExisted = false;
//                for (int j = 0; j < this->outer->simplifiedDfaEdgeList.size(); ++j) {
//                    if (fromState == this->outer->simplifiedDfaEdgeList[j].from &&
//                        toState == this->outer->simplifiedDfaEdgeList[j].to &&
//                        ch == this->outer->simplifiedDfaEdgeList[j].ch) {
//                        isExisted = true;
//                    }
//                }
//                if (!isExisted) {
//                    this->outer->simplifiedDfaEdgeList.emplace_back(Edge(fromState, toState, ch));
//                }
//
//                // 找到起点的状态集下标
//                this->outer->simplifiedDfaStartState = belongStateMap.find(0)->second;
//            }
//        }
//
//        void run() {
//            simplifyDFA();
//        }
//
//        json toJson() {
//            json ret;
//            ret["start"] = this->outer->simplifiedDfaStartState;
//            ret["end"] = 1;
//            for (int i = 0; i < this->outer->simplifiedDfaEdgeList.size(); ++i) {
//                Edge edge = this->outer->simplifiedDfaEdgeList[i];
//                string ch = {edge.ch}; // 直接将char放到json会转为数字
//                json tmp;
//                tmp["from"] = edge.from;
//                tmp["to"] = edge.to;
//                tmp["label"] = ch;
//                ret["data"].emplace_back(tmp);
//            }
//            return ret;
//        }
//    };
//
//    class DFA2Code {
//    public:
//        Lex *outer;
//
//        DFA2Code(Lex *outer) {
//            this->outer = outer;
//        }
//
//        string innerRun(int startState, int endState) {
//            map<int, vector<Edge>> nextEdgeMap; // 某个节点有哪些边
//            for (auto i: this->outer->simplifiedDfaEdgeList) {
//                int from = i.from;
//                int to = i.to;
//                char ch = i.ch;
//                if (nextEdgeMap.count(from)) { // 存在
//                    nextEdgeMap.find(from)->second.emplace_back(i);
//                } else {
//                    vector<Edge> v;
//                    v.emplace_back(i);
//                    nextEdgeMap.insert(make_pair(from, v));
//                }
//            }
//
//            string ret;
//            ret += "#include <iostream>\n"
//                   "#include <string>\n"
//                   "using namespace std;\n"
//                   "\n"
//                   "bool isAccepted(string str) {\n";
//
//            ret += "    int currentState = " + to_string(startState) + ";\n";
//            ret += "    int endState = " + to_string(endState) + ";\n";
//            ret += "    for (int i = 0; i < str.size(); ++i) {\n"
//                   "        switch (currentState) {\n";
//
//            for (auto i: nextEdgeMap) {
//                for (int j = 0; j < i.second.size(); ++j) {
//                    int from = i.second[j].from;
//                    int to = i.second[j].to;
//                    string ch = {i.second[j].ch};
//
//                    if (j == 0) {
//                        ret += "            case " + to_string(from) + ":\n";
//                        ret += "                if (str[i] == '" + ch + "') {\n";
//                        ret += "                    currentState = " + to_string(to) + ";\n";
//                        ret += "                }\n";
//                    } else {
//                        ret += "                else if (str[i] == '" + ch + "') {\n";
//                        ret += "                    currentState = " + to_string(to) + ";\n";
//                        ret += "                }\n";
//                    }
//                }
//                ret += "                else {\n"
//                       "                    return false;\n"
//                       "                }\n"
//                       "                break;\n";
//            }
//            ret += "            default:\n"
//                   "                return false;\n"
//                   "        }\n"
//                   "    }\n"
//                   "    if (currentState == endState) {\n"
//                   "        return true;\n"
//                   "    }\n"
//                   "    return false;\n"
//                   "}\n"
//                   "\n"
//                   "int main() {\n"
//                   "    string str;\n"
//                   "    cin >> str;\n"
//                   "    if (isAccepted(str)) {\n"
//                   "        cout << \"accepted\" << endl;\n"
//                   "    }\n"
//                   "    else {\n"
//                   "        cout << \"can not accepted\" << endl;\n"
//                   "    }\n"
//                   "    return 0;\n"
//                   "}";
//
//            return ret;
//        }
//
//        void run() {
//            this->outer->outputCode = innerRun(this->outer->simplifiedDfaStartState, 1);
//        }
//    };
//
//    json toJson() {
//        json ret;
//        ret["inner1"] = inner1->toJson();
//        ret["inner2"] = inner2->toJson();
//        ret["inner3"] = inner3->toJson();
//        ret["outputCode"] = outputCode;
//
//        return ret;
//    }
//
//    Lex() {};
//
//    Lex(string data) {
//        this->data = data;
//        // 让内部类可以访问外部类
//        this->inner1 = new RE2NFA(this);
//        this->inner2 = new NFA2DFA(this);
//        this->inner3 = new SimplifyDFA(this);
//        this->inner4 = new DFA2Code(this);
//        inner1->run();
//        inner2->run();
//        inner3->run();
//        inner4->run();
//    }
//};