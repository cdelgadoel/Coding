#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>
#include <cstdint>
#define INF 1000000000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define sz(a) a.size()

#define V vector
#define mp make_pair
#define pb push_back
#define f first
#define lb lower_bound
#define ub upper_bound
#define ft front()

const int maxN = 100005;
// Ahocorassick
const int K = 26;
struct Vertex {
    int next[K];
    bool leaf = false;
    vector<int> sizeLeafs;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);
void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].sizeLeafs.pb(s.size());
}
int go(int v, char ch);
int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}
int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

//from the sequence of links from me, give me the first one that is
// a leaf, or zero
// You can use it to check if some link to a given node is a leaf.
// This is helpful because you can have links that are end of word, but that is not
// necessarily reflected in your automaton.
const int maxWords = 2e5+5;
int nll[maxWords];
int nextLeafLink(int id){
    if(id == 0 || get_link(id) == 0)
        return 0;
    if(nll[id] == -1){
        int gl = get_link(id);
        nll[id] = t[gl].leaf? gl : nextLeafLink(gl);
    }
    return nll[id];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    fill(nll, nll + maxWords, -1);
    int n; cin>>n;
    string ss;
    F0R(i, n){
        cin>>ss;
        add_string(ss);
    }

    string word;
    cin>>word;
    word = '$' + word;
    
    int dp[word.size()];
    fill(dp, dp+word.size(), 0);
    dp[0] = 1;
    int itAutomaton = 0, itLeafs;
    loop(i, 1, word.size()){
        itAutomaton = go(itAutomaton, word[i]);
        itLeafs = t[itAutomaton].leaf? itAutomaton : nextLeafLink(itAutomaton);
        while(itLeafs > 0){
            for(int ls : t[itLeafs].sizeLeafs)
                dp[i] = (dp[i] + dp[i - ls])%MOD;
            itLeafs = nextLeafLink(itLeafs);
        }
    }
    cout<<dp[word.size()-1]<<"\n";
    return 0;
}