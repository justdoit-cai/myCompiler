#ifndef _SIMPLIFYDFA_H
#define _SIMPLIFYDFA_H
#include "NFA2DFA.cpp"
using namespace std;
class SimplifyDFA {
public:
    vector<set<int>> dfaNodeList;
    vector<Edge> dfaEdgeList;
    int nfaEndState;
    vector<set<int>> simplifiedDfaNodeList; // 记录某个状态集里面有哪些节点
    vector<Edge> simplifiedDfaEdgeList; // 记录简化后DFA的边信息
    int simplifiedDfaStartState; // DFA的初始状态属于哪个状态集，根据算法可知，DFA终结状态的状态集下标一定为1

    SimplifyDFA(vector<set<int>> dfaNodeList, vector<Edge> dfaEdgeList, int nfaEndState) {
        this->dfaNodeList = dfaNodeList; 
        this->dfaEdgeList = dfaEdgeList; 
        this->nfaEndState = nfaEndState;
    }

    /**
     * https://www.tr0y.wang/2021/04/01/%E7%BC%96%E8%AF%91%E5%8E%9F%E7%90%86%EF%BC%88%E4%B8%80%EF%BC%89%EF%BC%9A%E8%AF%8D%E6%B3%95%E5%88%86%E6%9E%90/#nfa-dfa
     * https://zhuanlan.zhihu.com/p/31166841
     * DFA的初态是包含了NFA初态的那个DFA状态；
     * DFA的终态是所有包含了NFA终态的DFA的状态。
     * DFA的非接受状态等于DFA的终态
     * 状态数最少，即意味者把多余的，等价的状态进行合并,这里关键的就是如何划分等价的状态。
     * Hopcroft 算法步骤：
     * 1. 首先把整个状态划分为接收状态和非接受状态，方法是：包含了NFA终态节点的状态集就一定是DFA的非接收状态
     * 2. 遍历某个状态集中存在的字符，看当前状态集的每个节点接收到这个字符跳转到的下一个状态是否相同，如果相同就继续判断下一个字符，直到所有字符都判断成功就可以成功插入到结果。
     * 如果存在不同，就把当前状态集的节点根据当前字符到的目标状态来划分，划分后的结果重新入栈处理。
     * 要注意等价状态，如果两个状态s，t，对于所有输入符号，状态s和状态t都转换到等价的状态里，那么这两个状态就是等价的
     * 可区分：对于任何两个状态t和s，若从一状态出发接受输入字符串ω，而从另一状态出发不接受ω，或者从t出发和从s出发到达不同的接受状态，则称ω对状态t和s是可区分的。
     * 不可区分：设想任何输入序列ω对s和t均是不可区分的，则说明从s出发和从t出发，分析任何输入序列ω均得到相同结果。因此，s和t可以合并成一个状态
     */
    void simplifyDFA() {
        map<int, int> belongStateMap; // 记录某个节点属于哪个状态集
        set<int> isAcceptedStateSet;  // 接收状态
        set<int> notAcceptedStateSet; // 非接收状态
        int length = 2; // 至少可以划分为接受状态和非接受状态


        // 划分接收状态和非接受状态
        for (int i = 0; i < this->dfaNodeList.size(); ++i) { // 包括了NFA终态节点的DFA状态就是DFA的非接受终态
            bool isAccepted = true;
            for (int j: this->dfaNodeList[i]) {
                if (this->nfaEndState == j) {
                    isAccepted = false;
                    notAcceptedStateSet.insert(i);
                    belongStateMap.insert(make_pair(i, 1));
                    break;
                }
            }
            if (isAccepted) {
                isAcceptedStateSet.insert(i);
                belongStateMap.insert(make_pair(i, 0));
            }
        }

        map<int, vector<Edge>> nextEdgeMap; // key为起点的边
        // 初始化nextEdgeMap
        for (int i = 0; i < this->dfaEdgeList.size(); ++i) {
            int from = this->dfaEdgeList[i].from;
            if (nextEdgeMap.count(from) == 0) {
                vector<Edge> v;
                v.emplace_back(this->dfaEdgeList[i]);
                nextEdgeMap.insert(make_pair(from, v));
            } else {
                auto iter = nextEdgeMap.find(from);
                iter->second.emplace_back(this->dfaEdgeList[i]);
            }
        }

        stack<set<int>> workStack;

        workStack.push(isAcceptedStateSet);
        workStack.push(notAcceptedStateSet);

        while (!workStack.empty()) {
            set<int> currentPartition = workStack.top();
            workStack.pop();

            if (currentPartition.empty()) {
                continue;
            }

            if (currentPartition.size() == 1) { // 节点数为一肯定无法划分
                this->simplifiedDfaNodeList.emplace_back(currentPartition);
                continue;
            }
            // 注意：每个点的后续边的字符权值肯定只会在每个边只会出现一次，不然肯定会在NFA转DFA的时候合并到一个状态集，因此我们不用担心一个字符权值出现多次的情况
            map<int, map<char, int>> charStateMapMap; // 记录每个点后续边的ch和toState的关系map
            // 初始化charStateMapMap
            for (int i: currentPartition) {
                //在map.find的时候一定要先判断map中有没有这个元素，不然可能有时候会报错有时候不会，导致很难debug
                if (!nextEdgeMap.count(i)) {
                    map<char, int> m;
                    charStateMapMap.insert(make_pair(i, m));
                    continue;
                }
                // 没有上面的判断下面会报错，因为这里在nextEdgeMap找不到i，但是编译器却往后走了（看编译器），导致后面的->second为野指针。
                // terminate called after throwing an instance of 'std::bad_array_new_length'
                //  what():  std::bad_array_new_length
                vector<Edge> edgeList = nextEdgeMap.find(i)->second;
                map<char, int> charStateMap; // map内部会对key进行排序，有利于比较
                for (Edge edge: edgeList) {
                    charStateMap.insert(make_pair(edge.ch, belongStateMap.find(edge.to)->second));
                }
                charStateMapMap.insert(make_pair(i, charStateMap));
            }
            map<char, int> charStateMap = charStateMapMap.find(*currentPartition.begin())->second;
            for (char ch = ' '; ch <= '~'; ++ch) { // 可显示字符：开头为空格，对于的ASCII码为32，结尾为~，对应的ascii码是126
                map<int, set<int>> partitionMap;

                if (!charStateMap.count(ch)) { // 不存在某个字符的边就当toState=-1
                    set<int> s;
                    s.insert(*currentPartition.begin());
                    partitionMap.insert(make_pair(-1, s));
                } else {
                    set<int> s;
                    s.insert(*currentPartition.begin());
                    partitionMap.insert(make_pair(charStateMap.find(ch)->second, s));
                }

                for (int i: currentPartition) {
                    if (i == *currentPartition.begin()) {
                        continue;
                    }
                    map<char, int> _charStateMap = charStateMapMap.find(i)->second;
                    int _toState = _charStateMap.find(ch)->second;
                    if (!_charStateMap.count(ch)) { // 不存在ch
                        if (partitionMap.count(-1)) {
                            partitionMap.find(-1)->second.insert(i);
                        } else {
                            set<int> s;
                            s.insert(i);
                            partitionMap.insert(make_pair(-1, s));
                        }
                    } else {
                        if (partitionMap.count(_toState)) {
                            partitionMap.find(_toState)->second.insert(i);
                        } else {
                            set<int> s;
                            s.insert(i);
                            partitionMap.insert(make_pair(_toState, s));
                        }
                    }
                }

                // 看看是不是可分割的，如果是就将初步分割后的结果再次入栈
                if (partitionMap.size() != 1) {
                    for (auto i: partitionMap) {
                        length++;
                        workStack.push(i.second);
                        for (int j: i.second) { // 修改节点所属于的状态集
                            belongStateMap.find(j)->second = length;
                        }
                    }
                    goto last;
                }
            }

            this->simplifiedDfaNodeList.emplace_back(currentPartition);

            last:;
        }
        // 计算连边，记得去重
        for (int i = 0; i < this->dfaEdgeList.size(); ++i) {
            Edge edge = this->dfaEdgeList[i];
            int from = edge.from;
            int to = edge.to;
            char ch = edge.ch;
            int fromState = belongStateMap.find(from)->second;
            int toState = belongStateMap.find(to)->second;
            bool isExisted = false;
            for (int j = 0; j < this->simplifiedDfaEdgeList.size(); ++j) {
                if (fromState == this->simplifiedDfaEdgeList[j].from &&
                    toState == this->simplifiedDfaEdgeList[j].to &&
                    ch == this->simplifiedDfaEdgeList[j].ch) {
                    isExisted = true;
                }
            }
            if (!isExisted) {
                this->simplifiedDfaEdgeList.emplace_back(Edge(fromState, toState, ch));
            }

            // 找到起点的状态集下标
            this->simplifiedDfaStartState = belongStateMap.find(0)->second;
        }
    }

    pair<vector<set<int>>, vector<Edge>> run() {
        simplifyDFA();
        return make_pair(this->simplifiedDfaNodeList, this->simplifiedDfaEdgeList);
    }

};
#endif