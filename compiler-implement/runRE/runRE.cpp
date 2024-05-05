#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <fstream>
#include "RE2NFA.cpp"
#include "NFA2DFA.cpp"
#include "simplifyDFA.cpp"
#include "DFA2Code.cpp"
#include "../nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;

class Lex {
public:
    // 输入
    vector<pair<string, string>> rePairList;
    // 中间变量
    vector<pair<string ,vector<Edge>>> simplifiedDfaEdgeListList;
    vector<int> simplifiedDfaStartStateList;
    Lex() {};

    Lex(vector<pair<string, string>> rePairList) {
        this->rePairList = rePairList;
    }
    /**
     * 合并起点和终点相同的边，为了加速前端渲染
     * @param edgeList
     * @param p
     * @return
     */
    vector<Edge2> simplifyGraph(vector<Edge> edgeList, int p){
        map<int, vector<Edge>> nextEdgeMap;
        for (Edge edge : edgeList) {
            if (nextEdgeMap.count(edge.from)) {
                nextEdgeMap.find(edge.from)->second.emplace_back(edge);
            } else {
                vector<Edge> tmp;
                tmp.emplace_back(edge);
                nextEdgeMap.insert(make_pair(edge.from, tmp));
            }
        }
        vector<Edge2> ret;
        queue<int> workQueue;
        workQueue.push(p);
        bool visit[1000];
        for (int i = 0; i < 1000;++i) {
            visit[i] = false;
        }
        while (!workQueue.empty()) {
            int pNode = workQueue.front();
            workQueue.pop();
            if (!nextEdgeMap.count(pNode)) {
                continue;
            }
            vector<Edge> nextEdgeList = nextEdgeMap.find(pNode)->second;
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
    json getGraph() {
        map<string, json> ret;
        for (auto item : rePairList) {
            json j;
            RE2NFA re2Nfa = RE2NFA(item.second);
            NFAToken nfaToken = re2Nfa.outputToken;
            NFA2DFA nfa2Dfa = NFA2DFA(nfaToken);
            SimplifyDFA simplifyDfa = SimplifyDFA(nfa2Dfa.dfaNodeList, nfa2Dfa.dfaEdgeList, nfaToken.endState);
            pair<vector<set<int>>, vector<Edge>> simplifiedDfaPair = simplifyDfa.run();
            this->simplifiedDfaEdgeListList.emplace_back(item.first, simplifiedDfaPair.second);
            this->simplifiedDfaStartStateList.emplace_back(simplifyDfa.simplifiedDfaStartState);
            // =====re2nfa=====
            j["re2nfa"]["start"] = 1;
            j["re2nfa"]["end"] = nfaToken.endState;
            for (int i = 0; i < nfaToken.nfaEdgeList.size(); ++i) {
                Edge edge = nfaToken.nfaEdgeList[i];
                string ch = {edge.ch}; // 直接将char放到json会转为数字，因此这里需要转为string
                json tmp;
                tmp["from"] = edge.from;
                tmp["to"] = edge.to;
                tmp["label"] = ch;
                j["re2nfa"]["edgeList"].emplace_back(tmp);
            }
            // ====nfa2dfa=====
            vector<set<int>> dfaNodeList = nfa2Dfa.dfaNodeList;
            vector<Edge2> dfaEdgeList = simplifyGraph(nfa2Dfa.dfaEdgeList, 0);
            j["nfa2dfa"]["start"] = 0;
            vector<int> end;
            for (int i = 0; i < dfaNodeList.size(); ++i) { // 包括了NFA终态节点的DFA状态就是DFA的非接受终态
                for (int j: dfaNodeList[i]) {
                    if (nfaToken.endState == j) {
                        end.emplace_back(i);
                        break;
                    }
                }
            }
            j["nfa2dfa"]["end"] = end;
            for (int i = 0; i < dfaEdgeList.size(); ++i) {
                Edge2 edge = dfaEdgeList[i];
                string s;
                for (char ch : edge.chSet) {
                    s += ch;
                    s += ",";
                }
                json tmp;
                tmp["from"] = edge.from;
                tmp["to"] = edge.to;
                tmp["label"] = s;
                j["nfa2dfa"]["edgeList"].emplace_back(tmp);
            }
            for (int i = 0; i < dfaNodeList.size(); ++i) {
                json tmp;
                for (int j: dfaNodeList[i]) {
                    tmp.emplace_back(j);
                }
                j["nfa2dfa"]["nodeList"].emplace_back(tmp);
            }
            // =====simplify dfa=====
            vector<set<int>> simplifiedDfaNodeList = simplifiedDfaPair.first;
            vector<Edge> simplifiedDfaEdgeList = simplifiedDfaPair.second;
            j["simplifiedDfa"]["start"] = simplifyDfa.simplifiedDfaStartState;
            j["simplifiedDfa"]["end"] = 1;
            for (int i = 0; i < simplifiedDfaEdgeList.size(); ++i) {
                Edge edge = simplifiedDfaEdgeList[i];
                string ch = {edge.ch}; // 直接将char放到json会转为数字
                json tmp;
                tmp["from"] = edge.from;
                tmp["to"] = edge.to;
                tmp["label"] = ch;
                j["simplifiedDfa"]["edgeList"].emplace_back(tmp);
            }
            ret.insert(make_pair(item.first, j));
        }
        return ret;
    }
    json getCode() {
        json ret;
        DFA2Code dfa2Code = DFA2Code(this->simplifiedDfaEdgeListList, this->simplifiedDfaStartStateList);
        dfa2Code.combineAllDfa();
        vector<Edge2> edgeList = dfa2Code.simplifyGraph(dfa2Code.combinedDfaEdgeList);
        for (int i = 0; i <  edgeList.size(); ++i) {
            Edge2 edge =  edgeList[i];
            string s;
            for (char ch : edge.chSet) {
                s += ch;
                s += ",";
            }
            json tmp;
            tmp["from"] = edge.from;
            tmp["to"] = edge.to;
            tmp["label"] = s;
            ret["edgeList"].emplace_back(tmp);
        }
        dfa2Code.getCode();
        ret["code"] = dfa2Code.code;
        return ret;
    }
};