#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include "../utils.cpp"
#include <queue>

using namespace std;
using nlohmann::json;
#define EXT_START '~'

struct Production {
    char leftPart;
    string rightPart;
    bool operator==(const Production &p) const { //����constһ����������
        return leftPart == p.leftPart && rightPart == p.rightPart;
    }

    bool operator<(const Production &p) const { //����constһ����������
        if (leftPart != p.leftPart)
            return leftPart < p.leftPart;
        else
            return rightPart < p.rightPart;
    }
};

struct Project {
    char leftPart;
    string rightPart;

    bool operator==(const Project &project) const { //����constһ����������
        return leftPart == project.leftPart && rightPart == project.rightPart;
    }

    bool operator<(const Project &project) const { //����constһ����������
        if (leftPart != project.leftPart)
            return leftPart < project.leftPart;
        else
            return rightPart < project.rightPart;
    }
};

struct DfaNode {
    set<Project> projectSet; // ��ͬ״̬����Ŀ�б�
    bool operator==(const DfaNode &dfaNode) const { //����constһ����������
        if (projectSet.size() != dfaNode.projectSet.size())
            return false;
        for (auto i1 = projectSet.begin(), i2 = dfaNode.projectSet.begin(); i1 != projectSet.end(); i1++, i2++) {
            if (i1->leftPart != i2->leftPart || i1->rightPart != i2->rightPart) {
                return false;
            }
        }
        return true;
    }
};

struct DfaEdge {
    int from, to;
    char val;;
};

struct Token {
    char tokenType;
    string tokenValue;
};
class Grammar {
public:
    vector<Production> productions; // �ķ�����ʽ�Ĵ洢
    set<char> nonTerminatorSet; // ���ս���Ĵ洢
    set<char> charSet = {'@'}; // ���з��ŵĴ洢������@
    map<char, set<char>> firstSetMap;
    map<char, set<char>> followSetMap;
    vector<DfaNode> dfaNodeList;
    vector<DfaEdge> dfaEdgeList;
    bool isSlr1 = true;
    map<char, set<Production>> productionMap; // ��¼�ȼ۵�production
    string errResult;
    vector<map<char, string>> slr1Table; // SLR1�㷨������Ĵ洢
    queue<int> workQueue;
    map<char, string> charMap;
    Grammar(vector<Production> pList, map<char, string> charMap) {
        this->charMap = charMap;
        this->productions = pList;
        for (Production p: pList) {
            nonTerminatorSet.insert(p.leftPart);
            charSet.insert(p.leftPart);
            for (char ch : p.rightPart) {
                charSet.insert(ch);
            }
        }
        stack<char> unhandleCharStack;
        for (char nt : nonTerminatorSet) {
            unhandleCharStack.push(nt);
        }
        while (!unhandleCharStack.empty()) {
            char nt = unhandleCharStack.top();
            unhandleCharStack.pop();
            if (this->productionMap.count(nt)) {
                continue;
            }
            set<Production> s;
            bool flag = false;
            for (Production p: pList) {
                if (p.leftPart == nt) {
                    s.insert(p);
                    char firstRightChar = p.rightPart[0];
                    if (isNonTerminator(firstRightChar)) {
                        if (this->productionMap.count(firstRightChar)) { // ���firstRightChar�ĵȼ�ProductionSet�Ѿ���ǰ�洦�����
                            set<Production> addSet = this->productionMap.find(firstRightChar)->second;
                            set_union(s.begin(), s.end(), addSet.begin(), addSet.end(), inserter(s, s.begin()));
                        } else { // �ݹ鴦��firstRightPart
                            unhandleCharStack.push(nt);
                            unhandleCharStack.push(firstRightChar);
                            if (firstRightChar != p.leftPart) {
                                flag = true; // δ�����
                            }
                        }
                    }
                }
            }
            if (!flag) {
                this->productionMap.insert(make_pair(nt, s));
            }
        }
        getFirstSet();
        getFollowSet();
        getLr0Dfa();
        checkSlr1();
        getSlr1Table();
    }

    bool isNonTerminator(char ch) {
        return 32 <= ch && ch < 65 && ch != '@';
    }

    void getFirstSet() {
        map<char, set<char>> ret;
        int firstSetSize = nonTerminatorSet.size();
        set<char> solvedSet;

        // ��ʼ��
        for (char it: nonTerminatorSet) {
            ret.insert(make_pair(it, set<char>()));
        }
        // �����Է�
        for (Production p1: productions) {
            // ע��E->E+T����������Ͳ����ˣ������������E->@����Ҫ����һ����ȥ
            if (p1.leftPart != p1.rightPart[0]) {
                ret.find(p1.leftPart)->second.insert(p1.rightPart[0]);
            }
            for (Production p2 : productions) {
                if (p2.leftPart == p1.rightPart[0] && p2.rightPart == "@") {
                    ret.find(p1.leftPart)->second.insert(p1.rightPart[1]);
                }
            }
        }

        // ע��A->BC,B->@���������ʱ�ȼ���A->C,��˻����C����A��firstSet
        // ������A->BC,B->D,D->@����ʱҲ�ǵȼ���A->C
        // A->BC,B->DE,D->@,E->@,Ҳ���ǵȼ���A->C
        // ����ĺ����߼��������Ѿ�����˵��ַ���firstSetȥ������û�д���õ��ַ�
        // ��¼��Щ���ս���Ѿ��������firstSet
        while (solvedSet.size() < firstSetSize) {
            for (auto it1: ret) {
                bool selfSolved = true;
                char nowCh = it1.first;
                set<char> nowFirstSet = it1.second;
                // �Ż�����ǰ�жϹ��Ͳ����ж���
                if (solvedSet.count(nowCh) > 0) {
                    selfSolved = true;
                } else {
                    for (char ch: nowFirstSet) {
                        // �϶���û���
                        if (isNonTerminator(ch)) {
                            selfSolved = false;
                            break;
                        }
                    }
                }
                // ���nowCh�Ѿ�����ˣ�����������ŵ�firstSetȥ���������ķ��š�
                // ��Ҫע����ǣ�����������ch��firstSet�к��п��ַ�@����ô�������ch���ŵ�firstSet�����������ŵ�ʱ����Ҫ��������Ǹ����ŵ�leftPart�е�ǰch���ŵ���һ������
                if (selfSolved) {
                    solvedSet.insert(nowCh);
                    for (auto &it2: ret) {
                        if (it2.first == nowCh || !it2.second.count(nowCh)) {
                            continue;
                        }
                        if (nowFirstSet.count('@') > 0) { // ����A->@�����
                            nowFirstSet.erase('@'); // �����Ƴ����ַ��ǲ�Ӱ��ԭfirstSet��
                            for (Production production: productions) {
                                if (production.leftPart == it2.first) {
                                    for (int i = 0; i < production.rightPart.length(); i++) {
                                        char ch = production.rightPart[i];
                                        // �����ǰ�ַ��е�first��������@���Ͱ���һ���Ž���
                                        if (ret.find(ch)->second.count('@') > 0) {
                                            if (i < production.rightPart.length() - 1) {
                                                it2.second.insert(production.rightPart[i + 1]);
                                            } else {
                                                // ���������ĩβ���ͼ�����ַ�����
                                                it2.second.insert('@');
                                            }
                                        } else {
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        // ɾ�����滻ԭԪ��
                        it2.second.erase(nowCh);
                        it2.second.insert(nowFirstSet.begin(), nowFirstSet.end());
                    }
                }
            }
        }
        firstSetMap = ret;
    }

    void getFollowSet() {
        map<char, set<char>> ret;
        int followSetSize = nonTerminatorSet.size();
        set<char> solvedSet;

        // ��ʼ��
        for (char it: nonTerminatorSet) {
            ret.insert(make_pair(it, set<char>()));
        }
        // ��ʼ���ŵ�followSet��һ����@
        ret.find(productions[0].leftPart)->second.insert('@');
        // �������п��ܵ������ַ�
        for (Production production: productions) {
            for (int i = 0; i < production.rightPart.length(); ++i) {
                char ch = production.rightPart[i];
                // ���Ƿ��ս������������Ϊ����ֻ��Ҫ����ս����follow��
                if (isNonTerminator(ch)) {
                    // �����ǰ���ս���������һ��Ԫ��
                    if (i < production.rightPart.length() - 1) {
                        // ��ȡ��ǰ�ս������һ��Ԫ��
                        char nextCh = production.rightPart[i + 1];
                        // �����һ�����ڵ��ַ����ս����ֱ�Ӽ���
                        if (!isNonTerminator(nextCh)) {
                            ret.find(ch)->second.insert(nextCh);
                        }
                            // �����һ�����ڵ��ַ��Ƿ��ս���ͽ�First(nextCh)���룬
                            // �������@��First(nextCh)�У�����Ҫ�ݹ�ļ��벢�ж���һ��nextCh��nextCh��First����ֱ����ĩβ�����ǰ�ַ���First���д���@���Ͱ�Follow(leftPart)����
                        else {
                            // ��ȡ��һ��Ԫ�ص�first��
                            set<char> s = firstSetMap.find(nextCh)->second;
                            // �������Ϊ������Ҫ�����жϺ�����ַ�����ΪҪע��A->BCD������C��first���к���@�����B��follow������Ҫ����D��first��
                            if (s.count('@') > 0) {
                                // ��ǰ�Ѿ������һ��Ԫ���ˣ��������@������Ҫ������ߵ�follow��
                                if (i + 2 == production.rightPart.length()) {
                                    ret.find(ch)->second.insert(production.leftPart);
                                }
                                // ����������һ��Ԫ��
                                for (int j = i + 2; j < production.rightPart.length(); ++j) {
                                    // һֱ��ȡ�������¸��ַ���first��������ע��Ҫȥ��@������Ҫ���ж���û��@
                                    set<char> tmpChFirstSet = firstSetMap.find(production.rightPart[j])->second;
                                    if (tmpChFirstSet.count('@') > 0) {
                                        tmpChFirstSet.erase('@');
                                        // ��������һ��Ԫ�أ������ֱ�ӽ���ߵķ��ŵ�follow�����뵽��ǰretԪ�ص�follow����
                                        if (j == production.rightPart.length() - 1) {
                                            ret.find(ch)->second.insert(production.leftPart);
                                        }
                                    }
                                    ret.find(ch)->second.insert(tmpChFirstSet.begin(), tmpChFirstSet.end());
                                }
                            }
                            // �����ʱ����Ҫע��ȥ��@���ַ�
                            s.erase('@');
                            ret.find(ch)->second.insert(s.begin(), s.end());
                        }
                    }
                        // �����ǰ�ķ��ս�������һ��Ԫ�ؾ���Ҫֱ�Ӱ�����ʽ��ߵ��ս����follow����@���뵱ǰ�ս����follow��
                    else {
                        ret.find(ch)->second.insert(production.leftPart);
                        ret.find(ch)->second.insert('@');
                    }
                }
            }
        }
        // ȥ�����Լ���followSet�����Լ���
        for (auto &it: ret) {
            it.second.erase(it.first);
        }
        while (solvedSet.size() < followSetSize) {
            // �����Щ�Ѿ��ַ���FollowSet�Ѿ�������ˣ����������˾�������ַ���FollowSetȥ������˵�
            for (auto &it1: ret) {
                bool solved = true;
                if (solvedSet.count(it1.first) > 0) {
                    solved = true;
                } else {
                    // ��鵱ǰ�ַ��Ƿ��Ѿ��������
                    here:;
                    for (char ch: it1.second) {
                        if (isNonTerminator(ch)) {
                            // ���ch��followSet��Ҳ��it1->first��û����
                            set<char> tmp = ret.find(ch)->second;
                            if (tmp.count(it1.first) > 0) {
                                // �����ַ���followSet����ȥ���Է�
                                tmp.erase(it1.first);
                                it1.second.erase(ch);
                                // ����һ���ַ���followSet���뵱ǰ�ַ���followSet
                                it1.second.insert(tmp.begin(), tmp.end());
                                // �������ַ���followSetһ��
                                ret.find(ch)->second = it1.second;
                                goto here;
                            }
                            solved = false;
                        }
                    }
                }
                if (solved) {
                    solvedSet.insert(it1.first);
                    // ������ַ�ȥ������
                    for (auto &it2: ret) {
                        if (it2.second.count(it1.first) > 0) {
                            it2.second.erase(it1.first);
                            it2.second.insert(it1.second.begin(), it1.second.end());
                        }
                    }
                }
                // �޸�bug������
                // ����A->xxxB,B->xxxA���������ʱ��ȻA��B��follow�����ƶ�û�д���ã�������ʵA��B��follow������һ����
            }
        }
        followSetMap = ret;
    }

    void getLr0Dfa(){
        DfaNode firstNode;
        firstNode.projectSet.insert(Project{EXT_START, "." + char2str(productions[0].leftPart)});
        // �޸�bug������
        // ��Ҫ�ж���ʼ״̬����S��ͷ�Ĳ���ʽ���Ҳ��ǲ����Է��ս����ͷ������ǻ���Ҫ�����Ǹ����ս���Ĳ���ʽ�������Ҹ�������ʼ״̬�����������
        // ���磺S->A,A->B����ʱ���ܺ���A��ͷ�Ĳ���ʽ
        // �޸���Ĵ���
        set<char> notAddBakSet; // ֱ���ڱ���set��ʱ�����Ӻ�ɾ��set�е�Ԫ�ػ�����⣬����������Ҫ��һ�����ݵ�set
        set<char> notAddSet;
        set<char> isAddSet;
        notAddSet.insert(productions[0].leftPart);
        notAddBakSet.insert(productions[0].leftPart);
        while (!notAddSet.empty()) {
            for (char ch: notAddSet) {
                isAddSet.insert(ch);
                notAddBakSet.erase(ch);
                for (Production production: productions) {
                    if (production.leftPart == ch) {
                        // ע�������S->@������ת��ΪS->.������S->.@
                        if (production.rightPart == "@") {
                            firstNode.projectSet.insert(Project{production.leftPart, "."});
                        } else {
                            firstNode.projectSet.insert(Project{production.leftPart, "." + production.rightPart});
                            if (isNonTerminator(production.rightPart[0])) {
                                // �����˾Ͳ����ٴ�����
                                if (isAddSet.count(production.rightPart[0]) > 0) {
                                    continue;
                                }
                                notAddBakSet.insert(production.rightPart[0]);
                            }
                        }
                    }
                }
            }

            notAddSet = notAddBakSet;
            notAddBakSet.clear();
        }

        dfaNodeList.push_back(firstNode);
        // ����ʼ״̬����������״̬
        workQueue.push(0);
        while (!workQueue.empty()) {
            int pNodeIdx = workQueue.front();
            workQueue.pop();
            DfaNode pNode = dfaNodeList[pNodeIdx];
            // ��¼��ǰ״̬�����յ�ĳ���ַ��ᵽ�ĸ�״̬�����⵱ǰ״̬��ǰ���ж�����Խ�����ͬ�ַ������
            // ���磺A->.ab, A->.ac
            map<char, int> stateMap;
            // �ݴ���
            vector<DfaNode> tmpDfaNodeList;
            // ��¼����tmpDfaNodeList��ĳ��Node���������ĸ�char�ַ�
            map<int, char> edgeMap;
            for (Project project: pNode.projectSet) {
                DfaNode node;
                string rightPart = project.rightPart;
                int dotIdx = rightPart.find('.');
                if (dotIdx == rightPart.length() - 1) {
                    continue;
                }
                // ��ź������ڵ��ַ�
                char dotNextChar = rightPart[dotIdx + 1];
                // ��ź���һλ
                rightPart.erase(dotIdx, 1);
                rightPart.insert(dotIdx + 1, ".");

                node.projectSet.insert(Project{project.leftPart, rightPart});
                if (dotIdx == rightPart.length() - 2) { // .�����ƽ��������һλ
                    // �����ǰ��¼������ַ����ƽ�
                    if (stateMap.count(dotNextChar) > 0) {
                        tmpDfaNodeList[stateMap.find(dotNextChar)->second].projectSet.insert(node.projectSet.begin(), node.projectSet.end());
                    } else {
                        tmpDfaNodeList.push_back(node);
                        stateMap.insert(make_pair(dotNextChar, tmpDfaNodeList.size() - 1));
                        // ��¼��
                        edgeMap.insert(make_pair(tmpDfaNodeList.size() - 1, dotNextChar));
                    }
                    continue;
                }
                char dotNextNextChar = rightPart[dotIdx + 2];
                // ���dotNextChar������ַ��Ƿ��ս��������Ҫ����������ս���Ĳ���ʽ������������ʽ�Ŀ�ͷ�ַ������Ƿ��ս������������Ҫ���еݹ�Ĵ���
                if (isNonTerminator(dotNextNextChar)) {
                    set<Production> tmp = this->productionMap.find(dotNextNextChar)->second;
                    for (Production production: tmp) {
                        if (production.rightPart == "@") {
                            node.projectSet.insert(Project{production.leftPart, "."});
                        } else {
                            node.projectSet.insert(Project{production.leftPart, "." + production.rightPart});
                        }
                    }
                }

                // �����ǰ��¼������ַ����ƽ�
                if (stateMap.count(dotNextChar) > 0) {
                    tmpDfaNodeList[stateMap.find(dotNextChar)->second].projectSet.insert(node.projectSet.begin(),
                                                                                         node.projectSet.end());
                } else {
                    tmpDfaNodeList.push_back(node);
                    stateMap.insert(make_pair(dotNextChar, tmpDfaNodeList.size() - 1));
                    // ��¼��
                    edgeMap.insert(make_pair(tmpDfaNodeList.size() - 1, dotNextChar));
                }
            }
            // ȫ����������ٽ��ݴ����е�Node����ȫ�ֱ���dfaNodeList�С�
            // ����Ҫע����������²�����node���ԭ�����ظ���������Ҫ�ж�һ����û�к�ԭ�����ظ�������ظ����ǾͲ���Ҫ���룬�������߾���ԭ���ľͿ�����
            // ��������ظ��ˣ�˵��ԭ����node�϶��Ѿ��������ˣ��������ǾͲ���Ҫ�ڰ����node��queue�ˣ���Ȼ���ǻ���ѭ����
            for (int i = 0; i < tmpDfaNodeList.size(); ++i) {
                DfaNode node1 = tmpDfaNodeList[i];
                bool isNew = true;
                for (int j = 0; j < dfaNodeList.size(); ++j) {
                    DfaNode node2 = dfaNodeList[j];
                    if (node1 == node2) {
                        isNew = false;
                        // ����node1�����߾�Ҫָ��node2
                        dfaEdgeList.push_back(DfaEdge{pNodeIdx, j, edgeMap.find(i)->second});
                        break;
                    }
                }
                if (isNew) {
                    dfaNodeList.push_back(node1);
                    int newIdx = dfaNodeList.size() - 1;
                    dfaEdgeList.push_back(DfaEdge{pNodeIdx, newIdx, edgeMap.find(i)->second});
                    workQueue.push(newIdx);
                }
            }
        }
    }

/**
 * SLR(1)�ķ����жϷ�ʽ:
 * �����κ�״̬s�����㣺
 * 1. ������s�е��κ���ĿA->a.Xb,��X��һ���ս��,��X��Follow(B)��ʱ��s��û����������ĿB->y.
 * ���ڵ�һ����÷�֤��
 * ���s�д���A->y.����s����������B->a.Xb��X��һ���ս������Ŀ��Follow(A)�е��ַ������ܴ���X
 * 2. ������s�е��κ�����������ĿA->a.��B->b.��Follow(A)��Follow(B)�Ľ���Ϊ��
 */
    void checkSlr1() {
        for (int i = 0; i < dfaNodeList.size(); ++i) {
            DfaNode node = dfaNodeList[i];
            for (Project project1: node.projectSet) {
                char leftPart1 = project1.leftPart;
                if (leftPart1 == EXT_START) {
                    continue;
                }
                set<char> followSet1 = followSetMap.find(leftPart1)->second;
                string rightPart1 = project1.rightPart;
                int dotIdx1 = rightPart1.find('.');
                // A->a.����ʽ
                if (dotIdx1 == rightPart1.length() - 1) {
                    for (Project project2: node.projectSet) {
                        if (project1 == project2) {
                            continue;
                        }
                        char leftPart2 = project2.leftPart;
                        if (leftPart2 == EXT_START) {
                            continue;
                        }
                        set<char> followSet2 = followSetMap.find(leftPart2)->second;
                        string rightPart2 = project2.rightPart;
                        int dotIdx2 = rightPart2.find('.');
                        // �жϵڶ���
                        if (dotIdx2 == rightPart2.length() - 1) {
                            set<char> intersection;
                            set_intersection(followSet1.begin(), followSet1.end(),
                                             followSet2.begin(), followSet2.end(),
                                             inserter(intersection, intersection.begin()));
                            if (intersection.size() != 0) {
                                isSlr1 = false;
                                errResult = "״̬" + to_string(i) + "�е���Ŀ" + project1.leftPart + "->" +
                                            project1.rightPart + "����Ŀ"
                                            + project2.leftPart + "->" + project2.rightPart + "�����˳�ͻ! Follow(" +
                                            project1.leftPart + ")��Follow(" + project2.leftPart + ")�Ľ�����Ϊ��!";
                            }
                        }
                            // �жϵ�һ��
                        else {
                            char dotNextChar2 = rightPart2[dotIdx2 + 1];
                            if (!isNonTerminator(dotNextChar2)) {
                                if (followSet1.count(dotNextChar2) > 0) {
                                    isSlr1 = false;
                                    errResult = "״̬" + to_string(i) + "�е���Ŀ" + project1.leftPart + "->" +
                                                project1.rightPart + "����Ŀ"
                                                + project2.leftPart + "->" + project2.rightPart + "�����˳�ͻ! " +
                                                dotNextChar2 + "��һ���ս������������Follow(" + project1.leftPart +
                                                ")��!";
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    void getSlr1Table() {
        vector<map<char, string>> ret;
        for (int i = 0; i < dfaNodeList.size(); ++i) {
            DfaNode node = dfaNodeList[i];
            map<char, string> row;
            // ͨ����Ѱ���ƽ�
            for (DfaEdge edge: dfaEdgeList) {
                if (edge.from == i) {
                    if (isNonTerminator(edge.val)) {
                        row.insert(make_pair(edge.val, to_string(edge.to)));
                    } else {
                        row.insert(make_pair(edge.val, "s" + to_string(edge.to)));
                    }
                }
            }
            // ͨ��״̬�����ĿѰ�ҹ�Լ
            for (Project p: node.projectSet) {
                if (p.rightPart.find('.') == p.rightPart.length() - 1) { // .�����һλ
                    if (p.leftPart == EXT_START) {
                        row.insert(make_pair('@', "acc"));
                        continue;
                    }
                    set<char> followSet = followSetMap.find(p.leftPart)->second;
                    for (char ch: followSet) {
                        // ȥ��ĩβ��.���������ֻ��һ�����תΪ@
                        if (p.rightPart == ".") {
                            row.insert(make_pair(ch, "r(" + char2str(p.leftPart) + "->@)"));
                        } else {
                            row.insert(make_pair(ch, "r(" + char2str(p.leftPart) + "->" +
                                                     p.rightPart.substr(0, p.rightPart.length() - 1) + ")"));
                        }
                    }
                }
            }
            for (char ch: charSet) {
                // û�м�¼����Ҳ�����޷��ƽ��ģ�Ҳ�޷���Լ�ģ�����error��־
                if (row.count(ch) == 0) {
                    row.insert(make_pair(ch, ""));
                }
            }
            ret.push_back(row);
        }
        slr1Table = ret;
    }

    void outputStack(stack<pair<char, int>> stepStack) {
        cout << "0 " ;
        stack<pair<char, int>> reverseStack;
        while (!stepStack.empty()) {
            reverseStack.push(stepStack.top());
            stepStack.pop();
        }
        while (!reverseStack.empty()) {
            pair<char,int> top = reverseStack.top();
            reverseStack.pop();
            cout << charMap.find(top.first)->second << " " << top.second << " ";
        }
        cout << endl;
    }
    json outputGrammarTree(vector<Token> tokenList) {
        json ret;
        int state = 0;
        map<char, string> row;
        stack<pair<char, int>> stepStack;
        stack<json> valueStack;
        for (int i = 0; i < tokenList.size(); i++) {
            Token token = tokenList[i];
            row = slr1Table[state];
            string action = row.find(token.tokenType)->second;
            if (action.empty()) {
                cout << "warning" << endl;
//                bool flag = false;
//                action = row.find('@')->second;
//                if (action != "") {
//                    json j;
//                    vector<string> content = split(action.substr(2, action.length() - 3), "->");
//                    int len = content[1].length();
//                    while (len--) {
//                        stepStack.pop();
//                        j[content[0]].emplace_back(valueStack.top());
//                        valueStack.pop();
//                    }
//                    row = slr1Table[stepStack.top().second];
//                    char tokenType = content[0][0];
//                    string action = row.find(tokenType)->second;
//                    state = atoi(action.c_str());
//                    stepStack.push(make_pair(tokenType, state));
//                    valueStack.push("@");
//                    outputStack(stepStack);
//                    i--;
//                    flag = true;
//                    goto here;
//                }
//                for (auto it : row) { //
//                    if (std::count(it.second.begin(), it.second.end(),'@')) {
//                        char tokenType = split(it.second.substr(2, it.second.length() - 3), "->")[0][0];
//                        string action = row.find(tokenType)->second;
//                        state = atoi(action.c_str());
//                        stepStack.push(make_pair(tokenType, state));
//                        valueStack.push("@");
//                        outputStack(stepStack);
//                        i--;
//                        flag = true;
//                        break;
//                    }
//                }
//                here:;
//                if (!flag) {
//                    cout << "err" << endl;
//                }
            } else if (action[0] == 's') {
                state = atoi(action.substr(1).c_str());
                stepStack.push(make_pair(token.tokenType, state));
                valueStack.push(token.tokenValue);
                outputStack(stepStack);
            } else if (action[0] == 'r') {
                action = action.substr(2, action.length() - 3);
                vector<string> content = split(action, "->");
                if (content[1] == "@") {
                    string action = row.find(content[0][0])->second;
                    state = atoi(action.c_str());
                    stepStack.push(make_pair(content[0][0], state));
                    valueStack.push("@");
                    outputStack(stepStack);
                    i--;
                } else {
                    int len = content[1].length();
                    json j;
                    while (len--) {
                        stepStack.pop();
                        j[content[0]].emplace_back(valueStack.top());
                        valueStack.pop();
                    }
                    if (stepStack.empty()) {
                        row = slr1Table[0];
                    } else {
                        row = slr1Table[stepStack.top().second];
                    }
                    state = atoi(row.find(content[0][0])->second.c_str());
                    stepStack.push(make_pair(content[0][0], state));
                    valueStack.push(j);
                    outputStack(stepStack);
                    i--;
                }
            } else if (action == "acc") {
            } else {
            }
        }
        // �����@��Լ
        while (1) {
            json j;
            row = slr1Table[stepStack.top().second];
            string action = row.find('@')->second;
            if (action == "acc") {
                cout << "success" << endl;
                return valueStack.top();
            }
            if (action.empty() || action[0] != 'r') {
                cout << "error" << endl;
                break;
            }
            action = action.substr(2, action.length() - 3);
            vector<string> content = split(action, "->");
            int len = content[1].length();
            while (len--) {
                stepStack.pop();
                j[content[0]].emplace_back(valueStack.top());
                valueStack.pop();
            }
            if (stepStack.empty()) {
                row = slr1Table[0];
            } else {
                row = slr1Table[stepStack.top().second];
            }
            state = atoi(row.find(content[0][0])->second.c_str());
            stepStack.push(make_pair(content[0][0], state));
            valueStack.push(j);
            outputStack(stepStack);
        }
        return ret;
    }
};