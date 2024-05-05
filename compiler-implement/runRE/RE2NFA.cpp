#ifndef _RE2NFA_H
#define _RE2NFA_H
#include <iostream>
#include <vector>
using namespace std;
/**
 * 正则表达式只识别()*|这几个运算符，需要注意正则中的符号()*|会和词法中的冲突，因此词法中在使用这几个符号的时候要使用转义符号
 */
struct Edge {
    int from;
    int to;
    char ch;

    Edge(int from, int to, char ch) : from(from), to(to), ch(ch) {};
};
struct NFAToken {
    vector<Edge> nfaEdgeList;
    int endState;
};
class RE2NFA {
public:
    // 输入
    string re;
    // 输出
    NFAToken outputToken;
    RE2NFA(string re) {
        this->re = re;
        this->outputToken = innerRun(this->re, 1);
    }
    /**
     * 获取字符串不在括号内的所有|的下标列表
     * @param token
     * @return
     */
    vector<int> getOuterVerticalLinePosition(string token) {
        vector<int> v;
        int length = token.length();
        for (int i = 0; i < length; ++i) {
            if (token[i] == '|') {
                string beforeStr = token.substr(0, i);
                // 前面字符串的(和)数量匹配就说明当前的|在括号外面,这里默认()不会在开头，不然j-1就数组越界了
                int num1 = 0, num2 = 0;
                for (int j = 0; j < beforeStr.length(); ++j) {
                    if (beforeStr[j] == '(' && beforeStr[j - 1] != '\\'){
                        num1++;
                    }
                    if (beforeStr[j] == ')' && beforeStr[j - 1] != '\\'){
                        num2++;
                    }
                }
                if (num1 == num2) {
                    v.emplace_back(i);
                }
            }
        }
        return v;
    }

    /**
     * 分割没有圆括号和|的字符串，将分割后的字符串存到vector里
     * 例如将xxxy*分割为xxx和y*; xxxy*zzz分割为xxx,y*,zzz;
     * @param token
     * @return
     */
    vector<string> splitTokenWithoutRoundBracketAndVerticalLine(string token) {
        vector<string> v;
        int start = 0;
        // 默认*不会开头
        for (int i = 0; i < token.length(); ++i) {
            if (token[i] == '*' && token[i - 1] != '\\') {
                if (token.length() != 2) {
                    v.emplace_back(token.substr(start, (i - 2) - start + 1));
                }
                v.emplace_back(token.substr(i - 1, 2));
                start = i + 1;
            }
                // 处理*后结尾的部分
            else if (i == token.length() - 1) {
                v.emplace_back(token.substr(start, i - start + 1));
                return v;
            }
        }
        return v;
    }

    /**
     * 将字符串分割为形如a*，(aaa)*，aaa的样子
     * 注意：有外部的|先处理外部的|，即对于(aaa)*bbb|ccc，先要将其划分为(aaa)*bbb和ccc，再分别递归划分
     * @param token
     * @return
     */
    vector<string> splitToken(string token) {
//        cout << "splitToken():  token -> " << token << endl;
        vector<string> v;
        int length = token.length();

        // 去除两边的括号(注意(xxx)(yyy)类似的token就不用去掉)
        if (token[0] == '(' && token[length - 1] == ')') {
            // 判断是不是上面的特例，通过查找字符串开头的(是不是和字符串最后的)匹配，方法是看(的数量和)的数量是否相等
            int tot = 1;
            for (int i = 1; i < token.length(); ++i) {
                if (token[i] == '(' && token[i - 1] != '\\') {
                    tot++;
                } else if (token[i] == ')' && token[i - 1] != '\\' && --tot == 0) {
                    if (i == token.length() - 1) {
                        return splitToken(token.substr(1, length - 2));
                    } else {
                        break;
                    }
                }
            }
        }

        vector<int> outerVerticalLinePosition = getOuterVerticalLinePosition(token);
        int outerVerticalLinePositionSize = outerVerticalLinePosition.size();
        if (outerVerticalLinePositionSize) { // 有外部的|
            for (int i = 0; i < outerVerticalLinePositionSize; ++i) {
                if (i == 0) {
                    v.emplace_back(token.substr(0, outerVerticalLinePosition[i]));
                } else {
                    v.emplace_back(token.substr(outerVerticalLinePosition[i - 1] + 1,
                                                outerVerticalLinePosition[i] - outerVerticalLinePosition[i - 1] -
                                                1));
                }
                v.emplace_back("|");
                if (i == outerVerticalLinePositionSize - 1) {
                    v.emplace_back(
                            token.substr(outerVerticalLinePosition[i] + 1, length - outerVerticalLinePosition[i]));
                }
            }
        } else { // 不存在|,就用()和*分割
            int start = -1, end = -1; // 记录token前后界的位置
            for (int i = 0; i < length; ++i) {
                if (token[i] == '(' && (!i || token[i - 1] != '\\')) {
                    if (i != end + 1) { // 不是(xxx)(xxx)的形式
                        vector<string> v1 = splitTokenWithoutRoundBracketAndVerticalLine(
                                token.substr(end + 1, (i - 1) - (end + 1) + 1));
                        v.insert(v.end(), v1.begin(), v1.end());
                    }
                    start = i;
                    int tot = 1;
                    for (int j = i + 1; j < length; ++j) {
                        if (token[j] == '(' && token[j - 1] != '\\') {
                            tot++;
                        }
                        if (token[j] == ')' && token[j - 1] != '\\' && --tot == 0) {
                            if (j + 1 < length && token[j + 1] == '*') { // 括号后面如果有*也需要带上
                                end = j + 1;
                            } else {
                                end = j;
                            }
                            v.emplace_back(token.substr(start, end - start + 1));
                            i = end;
                            break;
                        }
                    }
                } else if (i == length - 1) {
                    vector<string> v1 = splitTokenWithoutRoundBracketAndVerticalLine(
                            token.substr(end + 1, i - (end + 1) + 1));
                    v.insert(v.end(), v1.begin(), v1.end());
                }
            }
        }
        return v;
    }

    /**
     * RE转NFA（使用Thompson构造法）
     * https://blog.csdn.net/weixin_44691608/article/details/110195743
     * Thompson构造法的第一步就是先构建所有基本单元
     * 主运行逻辑程序：通过递归处理子Token处理。
     * 递归的终点:
     * 1. 纯连接的Token（也就是不存在|和*），形如aaabbb, (aaa)(bbb)，(aaa)bbb...这些都等价于aaabbb。
     * 2. 形如x*的单个字符+'*'
     * 递归的转换:
     * @param input
     * @param state
     * @return
     */
    NFAToken innerRun(string input, int state) {
        // 纯连接(不存在|和*)的Token可以直接解决，但是要注意\*代表乘号是可以的
        bool flag1 = true; // 标识是否是纯连接
        for (int i = 0; i < input.length() ; ++i) {
            // 注意这里是默认|和*不会出现在第一位，不然i-1就数组越界了
            if ((input[i] == '|' || input[i] == '*') && (input[i - 1] != '\\')) {
                flag1 = false;
                break;
            }

        }
        if (flag1) {
            // 去掉正则运算符的括号,注意在遍历删除时的细节
            int length = input.length();
            for (int j = 0; j < length; ++j) {
                if (j != 0 && (input[j] == '(' || input[j] == ')') && input[j - 1] != '\\') {
                    input.erase(j, 1);
                    length--;
                    j--;
                }
            }
            input.erase(remove(input.begin(), input.end(), '\\'), input.end());
            vector<Edge> nfaEdgeList;
            for (int i = 0; i < input.length(); ++i) {
                nfaEdgeList.emplace_back(state, state + 1, input[i]);
                // 到了结尾就不用再给后面添加#边了
                if (i != input.length() - 1) {
                    nfaEdgeList.emplace_back(state + 1, state + 2, '#');
                    state = state + 2;
                } else {
                    state++;
                }
            }

            NFAToken token;
            token.endState = state;
            token.nfaEdgeList = nfaEdgeList;
            return token;
        }

        // x*可以直接解决
        int length = input.length();
        if ((length == 2 && input[1] == '*' && input[0] != '\\') || (length == 3 && input[2] == '*' && input[0] == '\\')) {
            vector<Edge> nfaEdgeList;
            nfaEdgeList.emplace_back(state, state + 1, '#');
            nfaEdgeList.emplace_back(state + 1, state + 2, input[length - 2]);
            nfaEdgeList.emplace_back(state + 2, state + 1, '#');
            nfaEdgeList.emplace_back(state + 2, state + 3, '#');
            nfaEdgeList.emplace_back(state, state + 3, '#');

            NFAToken token;
            token.endState = state + 3;
            token.nfaEdgeList = nfaEdgeList;
            return token;
        }
        // 无法用最简单基本可处理的状态处理就分割为单元表达式，然后依次递归处理，这里的单元表达式可能存在单个字符"|"
        vector<string> tokenValueList = splitToken(input);

        // 存在|就全部并联
        if (count(tokenValueList.begin(), tokenValueList.end(), "|")) {
            vector<Edge> nfaEdgeList;
            vector<int> tailNfaEdgeList; // 记录当前
            int startState = state;
            state++;
            for (int i = 0; i < tokenValueList.size(); ++i) {
                if (tokenValueList[i] != "|") {
                    nfaEdgeList.emplace_back(startState, state, '#');
                    NFAToken subToken = innerRun(tokenValueList[i], state); // 递归处理
                    state = subToken.endState + 1; // 处理完的一个token的endState+加1后作为下一个待处理的token的startState
                    tailNfaEdgeList.emplace_back(subToken.endState);

                    nfaEdgeList.insert(nfaEdgeList.end(), subToken.nfaEdgeList.begin(), subToken.nfaEdgeList.end());
                }
            }
            for (int i = 0; i < tailNfaEdgeList.size(); ++i) {
                nfaEdgeList.emplace_back(tailNfaEdgeList[i], state, '#');
            }

            NFAToken token;
            token.nfaEdgeList = nfaEdgeList;
            token.endState = state;
            return token;
        }
        // 不存在|就连接，但是要注意(xxx)*
        else {
            vector<Edge> nfaEdgeList;
            int endState; // 记录整个链的endState
            for (int i = 0; i < tokenValueList.size(); ++i) {
                string item = tokenValueList[i];

                if (item[item.length() - 1] == '*') { // (xxx)*要递归处理(xxx)
                    nfaEdgeList.emplace_back(state, state + 1, '#');
                    NFAToken token = innerRun(item.substr(0, item.length() - 1), state + 1);
                    nfaEdgeList.emplace_back(token.endState, state + 1, '#');
                    nfaEdgeList.emplace_back(token.endState, token.endState + 1, '#');
                    nfaEdgeList.emplace_back(state, token.endState + 1, '#');

                    if (i != tokenValueList.size() - 1) {
                        nfaEdgeList.emplace_back(token.endState + 1, token.endState + 2, '#');
                        endState = token.endState + 1;
                        state = endState;
                    } else {
                        endState = token.endState + 1;
                        state = endState;
                    }

                    nfaEdgeList.insert(nfaEdgeList.end(), token.nfaEdgeList.begin(), token.nfaEdgeList.end());
                } else {
                    NFAToken token = innerRun(item, state);
                    nfaEdgeList.insert(nfaEdgeList.end(), token.nfaEdgeList.begin(), token.nfaEdgeList.end());
                    if (i != tokenValueList.size() - 1) {
                        nfaEdgeList.emplace_back(token.endState, token.endState + 1, '#');
                        state = token.endState + 1;
                    } else {
                        endState = token.endState;
                    }
                }
            }
            NFAToken token;
            token.nfaEdgeList = nfaEdgeList;
            token.endState = endState;
            return token;
        }
    }
};
#endif
