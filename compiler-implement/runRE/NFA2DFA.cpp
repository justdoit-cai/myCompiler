#ifndef _NFA2DFA_H
#define _NFA2DFA_H
#include "RE2NFA.cpp"
#include <set>
using namespace std;

class NFA2DFA {
public:
    int cnt = 0;
    bool visited[1000] = {0}; // 长度应为token.endState + 1
    int dfaNodeListIdx = 0; // 记录当前结尾状态集的下标，等价于dfaNodeList.length()-1，从而不用重复查询dfaNodeList的长度
    // 输入
    NFAToken nfaToken;
    map<int, vector<Edge>> nextNfaEdgeMap; // 记录某个节点有哪些后续节点
    // 输出
    vector<set<int>> dfaNodeList; // 记录某个状态集里面有哪些节点
    vector<Edge> dfaEdgeList; // 记录DFA的边信息
    NFA2DFA(NFAToken nfaToken) {
        this->nfaToken = nfaToken;
        innerRun(this->nfaToken);
    }

    /**
     * @param pNode 当前的节点下标
     * @param currentDfaNodeListIdx 当前节点属于dfaNodeList中的哪个状态集
     * @return
     */
    void dfs(int pNode, int currentDfaNodeListIdx) {
        if (!nextNfaEdgeMap.count(pNode)) { // 没有后续边
            return;
        }
        vector<Edge> nextEdgeList = nextNfaEdgeMap.find(pNode)->second; // 当前节点有哪些后续边

        for (int i = 0; i < nextEdgeList.size(); ++i) { // 遍历当前节点的后续边
            int to = nextEdgeList[i].to;
            char ch = nextEdgeList[i].ch;
            map<char, int> newStateMap; // 维护不同状态后继节点的集合，避免相同值的后继节点被分到不同状态
            if (ch == '#') { // 同一状态集
                this->dfaNodeList[currentDfaNodeListIdx].insert(to); // 下一节点加入当前状态集
                dfs(to, currentDfaNodeListIdx);
            } else { // 不同状态集，需要注意后继节点如果相同，算同一状态集，有多少个不同的后继节点，状态集就加多少，所以还需要知道后继节点的集合
                if (!visited[pNode]) {
                    visited[pNode] = true; // 避免无限递归，但是只有非空串后续节点需要记录，空串后续节点可以重复遍历
                    if (!newStateMap.count(ch)) { // 没有记录过这个字符的边，状态集就加一
                        dfaNodeListIdx++;
                        dfaEdgeList.emplace_back(Edge(currentDfaNodeListIdx, dfaNodeListIdx, ch));
                        newStateMap.insert(make_pair(ch, dfaNodeListIdx)); // 记录当前节点的哪些后续边的字符之前已经记录过了
                        // 注意新添加dfaNodeList元素的时候要初始化，所以要判断一下插入的那个位置初始化过没
                        if (this->dfaNodeList.size() > dfaNodeListIdx) { // 之前初始化过
                            this->dfaNodeList[dfaNodeListIdx].insert(to);
                        } else { // 没初始化过
                            set<int> s;
                            s.insert(to);
                            this->dfaNodeList.emplace_back(s);
                        }
                        dfs(to, dfaNodeListIdx);
                    } else { // 当前字符之前已经记录过，就直接在map中找下一个节点属于哪个状态集
                        int nextState = newStateMap.find(ch)->second;
                        this->dfaNodeList[nextState].insert(to);
                        dfs(to, nextState); // ch相同就相同状态集
                    }
                } else {
                    // 遍历过的非空边集不需要向后遍历，但是需要记录边,这里就要思考怎么知道后继节点是哪个状态的（非空边的后继节点一定只属于一个状态集，空边的后继节点可以属于多个状态集!）
                    // 找到非空边的后继节点属于哪个状态集（一定是找的到的，因为是遍历过了的）
                    for (int j = 0; j < this->dfaNodeList.size(); ++j) { // 遍历状态集数组
                        for (auto k: this->dfaNodeList[j]) { // 遍历状态集
                            if (k == to) {
                                dfaEdgeList.emplace_back(Edge(currentDfaNodeListIdx, j, ch));
                            }
                        }
                    }
                }
            }
        }
    }

    /**
     * NFA转DFA(使用子集构造法)
     * 在箭头的方向上，一路值为#的都可以看作为同一状态，直到遇到不为#的箭头，才算下一状态。这样状态数就可以减少
     * 1. 消除空串
     * 2. 消除多重转换
     * 要求：
     * 1. DFA初态只有一个
     * 2. DFA中存在的都是非空转换
     * 思路：
     * Q: 如何找到初态?
     * A: 没有箭头指向的节点就是起点（在上面求NFA的算法中可知，编号为1的节点就是起点），然后找到和这个起点同一状态的所有节点集就是初态。
     * Q: 如何找到同一状态的状态集?
     * A: 从某一节点出发，沿着箭头的边向后深度优先遍历，如果遇到非空串就return
     * 遍历某个的节点的时候，如果这个节点的后继节点是空串，就记录这个节点的编号，加入上个节点的状态集，我们需要维护一个变量，存放某个状态集和后续状态集和路径值，
     * 由于一个状态集会有多个后续状态集，因此整个的数据结构类似于树，因此后续状态集需要存放在一个数组里。
     * */
    void innerRun(NFAToken token) {
        vector<Edge> edgeList = token.nfaEdgeList;

        // 初始化nextNfaEdgeMap变量
        for (int i = 0; i < edgeList.size(); ++i) {
            int from = edgeList[i].from;
            if (nextNfaEdgeMap.count(from) == 0) { // 没有记录过
                vector<Edge> v;
                v.emplace_back(edgeList[i]);
                nextNfaEdgeMap.insert(make_pair(from, v));
            } else { // 记录过
                auto iter = nextNfaEdgeMap.find(from);
                iter->second.emplace_back(edgeList[i]);
            }
        }

        // 直接将起点放到状态集的开头，根据前面RE2NFA的算法，可以知道下标为1的节点为起点
        set<int> s;
        s.insert(1);
        dfaNodeList.emplace_back(s);

        // 从起点1开始dfs
        dfs(1, 0);
    }
};
#endif
