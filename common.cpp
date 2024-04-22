#include<vector>
using namespace std;
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