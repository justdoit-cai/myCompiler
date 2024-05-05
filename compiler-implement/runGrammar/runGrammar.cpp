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
    bool operator==(const Production &p) const { //两个const一个都不能少
        return leftPart == p.leftPart && rightPart == p.rightPart;
    }

    bool operator<(const Production &p) const { //两个const一个都不能少
        if (leftPart != p.leftPart)
            return leftPart < p.leftPart;
        else
            return rightPart < p.rightPart;
    }
};

struct Project {
    char leftPart;
    string rightPart;

    bool operator==(const Project &project) const { //两个const一个都不能少
        return leftPart == project.leftPart && rightPart == project.rightPart;
    }

    bool operator<(const Project &project) const { //两个const一个都不能少
        if (leftPart != project.leftPart)
            return leftPart < project.leftPart;
        else
            return rightPart < project.rightPart;
    }
};

struct DfaNode {
    set<Project> projectSet; // 相同状态的项目列表
    bool operator==(const DfaNode &dfaNode) const { //两个const一个都不能少
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
    vector<Production> productions; // 文法产生式的存储
    set<char> nonTerminatorSet; // 非终结符的存储
    set<char> charSet = {'@'}; // 所有符号的存储，包括@
    map<char, set<char>> firstSetMap;
    map<char, set<char>> followSetMap;
    vector<DfaNode> dfaNodeList;
    vector<DfaEdge> dfaEdgeList;
    bool isSlr1 = true;
    map<char, set<Production>> productionMap; // 记录等价的production
    string errResult;
    vector<map<char, string>> slr1Table; // SLR1算法分析表的存储
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
                        if (this->productionMap.count(firstRightChar)) { // 如果firstRightChar的等价ProductionSet已经在前面处理好了
                            set<Production> addSet = this->productionMap.find(firstRightChar)->second;
                            set_union(s.begin(), s.end(), addSet.begin(), addSet.end(), inserter(s, s.begin()));
                        } else { // 递归处理firstRightPart
                            unhandleCharStack.push(nt);
                            unhandleCharStack.push(firstRightChar);
                            if (firstRightChar != p.leftPart) {
                                flag = true; // 未处理好
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

        // 初始化
        for (char it: nonTerminatorSet) {
            ret.insert(make_pair(it, set<char>()));
        }
        // 先无脑放
        for (Production p1: productions) {
            // 注意E->E+T的特殊情况就不放了，但是如果存在E->@，就要放下一个进去
            if (p1.leftPart != p1.rightPart[0]) {
                ret.find(p1.leftPart)->second.insert(p1.rightPart[0]);
            }
            for (Production p2 : productions) {
                if (p2.leftPart == p1.rightPart[0] && p2.rightPart == "@") {
                    ret.find(p1.leftPart)->second.insert(p1.rightPart[1]);
                }
            }
        }

        // 注意A->BC,B->@的情况，此时等价于A->C,因此还需把C放入A的firstSet
        // 还可能A->BC,B->D,D->@，此时也是等价于A->C
        // A->BC,B->DE,D->@,E->@,也就是等价于A->C
        // 下面的核心逻辑就是拿已经解决了的字符的firstSet去化简别的没有处理好的字符
        // 记录哪些非终结符已经处理好了firstSet
        while (solvedSet.size() < firstSetSize) {
            for (auto it1: ret) {
                bool selfSolved = true;
                char nowCh = it1.first;
                set<char> nowFirstSet = it1.second;
                // 优化：以前判断过就不用判断了
                if (solvedSet.count(nowCh) > 0) {
                    selfSolved = true;
                } else {
                    for (char ch: nowFirstSet) {
                        // 肯定还没完成
                        if (isNonTerminator(ch)) {
                            selfSolved = false;
                            break;
                        }
                    }
                }
                // 如果nowCh已经解决了，就拿这个符号的firstSet去化简其它的符号。
                // 需要注意的是，如果这个符号ch的firstSet中含有空字符@，那么在用这个ch符号的firstSet化简其它符号的时候还需要引入对于那个符号的leftPart中当前ch符号的下一个符号
                if (selfSolved) {
                    solvedSet.insert(nowCh);
                    for (auto &it2: ret) {
                        if (it2.first == nowCh || !it2.second.count(nowCh)) {
                            continue;
                        }
                        if (nowFirstSet.count('@') > 0) { // 存在A->@的情况
                            nowFirstSet.erase('@'); // 这里移除空字符是不影响原firstSet的
                            for (Production production: productions) {
                                if (production.leftPart == it2.first) {
                                    for (int i = 0; i < production.rightPart.length(); i++) {
                                        char ch = production.rightPart[i];
                                        // 如果当前字符中的first集包含了@，就把下一个放进来
                                        if (ret.find(ch)->second.count('@') > 0) {
                                            if (i < production.rightPart.length() - 1) {
                                                it2.second.insert(production.rightPart[i + 1]);
                                            } else {
                                                // 如果到了最末尾，就加入空字符进来
                                                it2.second.insert('@');
                                            }
                                        } else {
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        // 删除并替换原元素
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

        // 初始化
        for (char it: nonTerminatorSet) {
            ret.insert(make_pair(it, set<char>()));
        }
        // 起始符号的followSet中一定有@
        ret.find(productions[0].leftPart)->second.insert('@');
        // 遍历所有可能的相邻字符
        for (Production production: productions) {
            for (int i = 0; i < production.rightPart.length(); ++i) {
                char ch = production.rightPart[i];
                // 不是非终结符就跳过，因为我们只需要求非终结符的follow集
                if (isNonTerminator(ch)) {
                    // 如果当前的终结符不是最后一个元素
                    if (i < production.rightPart.length() - 1) {
                        // 获取当前终结符的下一个元素
                        char nextCh = production.rightPart[i + 1];
                        // 如果下一个相邻的字符是终结符就直接加入
                        if (!isNonTerminator(nextCh)) {
                            ret.find(ch)->second.insert(nextCh);
                        }
                            // 如果下一个相邻的字符是非终结符就将First(nextCh)加入，
                            // 并且如果@在First(nextCh)中，则还需要递归的加入并判断下一个nextCh的nextCh的First集，直到到末尾如果当前字符的First集中存在@，就把Follow(leftPart)加入
                        else {
                            // 获取下一个元素的first集
                            set<char> s = firstSetMap.find(nextCh)->second;
                            // 如果可能为空则还需要继续判断后面的字符，因为要注意A->BCD，其中C的first集中含有@，因此B的follow集还需要加上D的first集
                            if (s.count('@') > 0) {
                                // 当前已经是最后一个元素了，如果存在@，就需要加上左边的follow集
                                if (i + 2 == production.rightPart.length()) {
                                    ret.find(ch)->second.insert(production.leftPart);
                                }
                                // 如果不是最后一个元素
                                for (int j = i + 2; j < production.rightPart.length(); ++j) {
                                    // 一直获取并加入下个字符的first集，还是注意要去掉@，不过要先判断有没有@
                                    set<char> tmpChFirstSet = firstSetMap.find(production.rightPart[j])->second;
                                    if (tmpChFirstSet.count('@') > 0) {
                                        tmpChFirstSet.erase('@');
                                        // 如果是最后一个元素，则可以直接将左边的符号的follow集加入到当前ret元素的follow集了
                                        if (j == production.rightPart.length() - 1) {
                                            ret.find(ch)->second.insert(production.leftPart);
                                        }
                                    }
                                    ret.find(ch)->second.insert(tmpChFirstSet.begin(), tmpChFirstSet.end());
                                }
                            }
                            // 加入的时候需要注意去掉@空字符
                            s.erase('@');
                            ret.find(ch)->second.insert(s.begin(), s.end());
                        }
                    }
                        // 如果当前的非终结符是最后一个元素就需要直接把生成式左边的终结符的follow集和@加入当前终结符的follow集
                    else {
                        ret.find(ch)->second.insert(production.leftPart);
                        ret.find(ch)->second.insert('@');
                    }
                }
            }
        }
        // 去除掉自己的followSet包含自己的
        for (auto &it: ret) {
            it.second.erase(it.first);
        }
        while (solvedSet.size() < followSetSize) {
            // 检查哪些已经字符的FollowSet已经处理好了，如果处理好了就用这个字符的FollowSet去化简别人的
            for (auto &it1: ret) {
                bool solved = true;
                if (solvedSet.count(it1.first) > 0) {
                    solved = true;
                } else {
                    // 检查当前字符是否已经处理好了
                    here:;
                    for (char ch: it1.second) {
                        if (isNonTerminator(ch)) {
                            // 如果ch的followSet中也有it1->first就没问题
                            set<char> tmp = ret.find(ch)->second;
                            if (tmp.count(it1.first) > 0) {
                                // 两个字符的followSet各自去掉对方
                                tmp.erase(it1.first);
                                it1.second.erase(ch);
                                // 让另一个字符的followSet加入当前字符的followSet
                                it1.second.insert(tmp.begin(), tmp.end());
                                // 让两个字符的followSet一致
                                ret.find(ch)->second = it1.second;
                                goto here;
                            }
                            solved = false;
                        }
                    }
                }
                if (solved) {
                    solvedSet.insert(it1.first);
                    // 拿这个字符去化简别的
                    for (auto &it2: ret) {
                        if (it2.second.count(it1.first) > 0) {
                            it2.second.erase(it1.first);
                            it2.second.insert(it1.second.begin(), it1.second.end());
                        }
                    }
                }
                // 修复bug！！！
                // 处理A->xxxB,B->xxxA的情况，此时虽然A和B的follow集看似都没有处理好，但是其实A和B的follow集就是一样的
            }
        }
        followSetMap = ret;
    }

    void getLr0Dfa(){
        DfaNode firstNode;
        firstNode.projectSet.insert(Project{EXT_START, "." + char2str(productions[0].leftPart)});
        // 修复bug！！！
        // 需要判断起始状态中以S开头的产生式的右部是不是以非终结符开头，如果是还需要加上那个非终结符的产生式，这里我搞忘了起始状态的这种情况。
        // 例如：S->A,A->B。此时不能忽略A开头的产生式
        // 修复后的代码
        set<char> notAddBakSet; // 直接在遍历set的时候增加和删除set中的元素会出问题，所以这里需要搞一个备份的set
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
                        // 注意如果有S->@，则是转换为S->.，而非S->.@
                        if (production.rightPart == "@") {
                            firstNode.projectSet.insert(Project{production.leftPart, "."});
                        } else {
                            firstNode.projectSet.insert(Project{production.leftPart, "." + production.rightPart});
                            if (isNonTerminator(production.rightPart[0])) {
                                // 处理了就不用再处理了
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
        // 由起始状态延申至其它状态
        workQueue.push(0);
        while (!workQueue.empty()) {
            int pNodeIdx = workQueue.front();
            workQueue.pop();
            DfaNode pNode = dfaNodeList[pNodeIdx];
            // 记录当前状态集接收到某个字符会到哪个状态，避免当前状态集前后有多个可以接收相同字符的情况
            // 例如：A->.ab, A->.ac
            map<char, int> stateMap;
            // 暂存区
            vector<DfaNode> tmpDfaNodeList;
            // 记录到达tmpDfaNodeList中某个Node经历的是哪个char字符
            map<int, char> edgeMap;
            for (Project project: pNode.projectSet) {
                DfaNode node;
                string rightPart = project.rightPart;
                int dotIdx = rightPart.find('.');
                if (dotIdx == rightPart.length() - 1) {
                    continue;
                }
                // 点号后面相邻的字符
                char dotNextChar = rightPart[dotIdx + 1];
                // 点号后移一位
                rightPart.erase(dotIdx, 1);
                rightPart.insert(dotIdx + 1, ".");

                node.projectSet.insert(Project{project.leftPart, rightPart});
                if (dotIdx == rightPart.length() - 2) { // .经过移进后到了最后一位
                    // 如果以前记录了这个字符的移进
                    if (stateMap.count(dotNextChar) > 0) {
                        tmpDfaNodeList[stateMap.find(dotNextChar)->second].projectSet.insert(node.projectSet.begin(), node.projectSet.end());
                    } else {
                        tmpDfaNodeList.push_back(node);
                        stateMap.insert(make_pair(dotNextChar, tmpDfaNodeList.size() - 1));
                        // 记录边
                        edgeMap.insert(make_pair(tmpDfaNodeList.size() - 1, dotNextChar));
                    }
                    continue;
                }
                char dotNextNextChar = rightPart[dotIdx + 2];
                // 如果dotNextChar后面的字符是非终结符，还需要加上这个非终结符的产生式，如果这个产生式的开头字符依旧是非终结符，就依旧需要进行递归的处理
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

                // 如果以前记录了这个字符的移进
                if (stateMap.count(dotNextChar) > 0) {
                    tmpDfaNodeList[stateMap.find(dotNextChar)->second].projectSet.insert(node.projectSet.begin(),
                                                                                         node.projectSet.end());
                } else {
                    tmpDfaNodeList.push_back(node);
                    stateMap.insert(make_pair(dotNextChar, tmpDfaNodeList.size() - 1));
                    // 记录边
                    edgeMap.insert(make_pair(tmpDfaNodeList.size() - 1, dotNextChar));
                }
            }
            // 全部计算完后再将暂存区中的Node放入全局变量dfaNodeList中。
            // 还需要注意这里可能新产生的node会和原来的重复，我们需要判断一下有没有和原来的重复，如过重复我们就不需要插入，而且连边就连原来的就可以了
            // 而且如果重复了，说明原来的node肯定已经遍历过了，这样我们就不需要在把这个node入queue了，不然还是会死循环。
            for (int i = 0; i < tmpDfaNodeList.size(); ++i) {
                DfaNode node1 = tmpDfaNodeList[i];
                bool isNew = true;
                for (int j = 0; j < dfaNodeList.size(); ++j) {
                    DfaNode node2 = dfaNodeList[j];
                    if (node1 == node2) {
                        isNew = false;
                        // 关于node1的连边就要指向node2
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
 * SLR(1)文法的判断方式:
 * 对于任何状态s，满足：
 * 1. 对于在s中的任何项目A->a.Xb,当X是一个终结符,且X在Follow(B)中时，s中没有完整的项目B->y.
 * 对于第一点最好反证：
 * 如果s中存在A->y.，则s中其它形如B->a.Xb，X是一个终结符的项目，Follow(A)中的字符不可能存在X
 * 2. 对于在s中的任何两个完整项目A->a.和B->b.，Follow(A)和Follow(B)的交集为空
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
                // A->a.的形式
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
                        // 判断第二点
                        if (dotIdx2 == rightPart2.length() - 1) {
                            set<char> intersection;
                            set_intersection(followSet1.begin(), followSet1.end(),
                                             followSet2.begin(), followSet2.end(),
                                             inserter(intersection, intersection.begin()));
                            if (intersection.size() != 0) {
                                isSlr1 = false;
                                errResult = "状态" + to_string(i) + "中的项目" + project1.leftPart + "->" +
                                            project1.rightPart + "和项目"
                                            + project2.leftPart + "->" + project2.rightPart + "发生了冲突! Follow(" +
                                            project1.leftPart + ")和Follow(" + project2.leftPart + ")的交集不为空!";
                            }
                        }
                            // 判断第一点
                        else {
                            char dotNextChar2 = rightPart2[dotIdx2 + 1];
                            if (!isNonTerminator(dotNextChar2)) {
                                if (followSet1.count(dotNextChar2) > 0) {
                                    isSlr1 = false;
                                    errResult = "状态" + to_string(i) + "中的项目" + project1.leftPart + "->" +
                                                project1.rightPart + "和项目"
                                                + project2.leftPart + "->" + project2.rightPart + "发生了冲突! " +
                                                dotNextChar2 + "是一个终结符，并且其在Follow(" + project1.leftPart +
                                                ")中!";
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
            // 通过边寻找移进
            for (DfaEdge edge: dfaEdgeList) {
                if (edge.from == i) {
                    if (isNonTerminator(edge.val)) {
                        row.insert(make_pair(edge.val, to_string(edge.to)));
                    } else {
                        row.insert(make_pair(edge.val, "s" + to_string(edge.to)));
                    }
                }
            }
            // 通过状态里的项目寻找归约
            for (Project p: node.projectSet) {
                if (p.rightPart.find('.') == p.rightPart.length() - 1) { // .在最后一位
                    if (p.leftPart == EXT_START) {
                        row.insert(make_pair('@', "acc"));
                        continue;
                    }
                    set<char> followSet = followSetMap.find(p.leftPart)->second;
                    for (char ch: followSet) {
                        // 去掉末尾的.，但是如果只有一个点就转为@
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
                // 没有记录过，也就是无法移进的，也无法归约的，填入error标志
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
        // 最后用@归约
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