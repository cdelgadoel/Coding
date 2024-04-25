#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 5e5+5;
vector<int> adj[maxN];
vector<pii> dead_ends;
bool visited[maxN];
int n;
bool cycle;
int root;

void checkCycle(int v, int fa){
    visited[v] = true;
    for(int x : adj[v]){
        if(visited[x]){
            if(x!=fa){
                root = v;
                cycle = true;
            }
        }
        else{
            checkCycle(x, v);
        }
    }
}

bool visited2[maxN];
void tree_deadEnds(int v){
    visited2[v] = true;
    if(adj[v].size() == 1){
        dead_ends.push_back(pii(v, adj[v][0]));
    }
    for(int x : adj[v]){
        if(!visited2[x])
            tree_deadEnds(x);
    }
}

bool cycle_deadEnds(int v, int fa){
    visited2[v] = true;
    bool have_backEdge = false, son_backEdge;
    vector<int> son_deadends;
    for(int x : adj[v]){
        if(x == fa) continue;
        if(visited2[x]){
            have_backEdge = true;
        }
        else{
            son_backEdge = cycle_deadEnds(x, v);
            if(son_backEdge){
                have_backEdge = true;
            }
            else{
                son_deadends.push_back(x);
            }
        }
    }
    if(have_backEdge){
        for(int x : son_deadends){
            dead_ends.push_back(pii(v, x));
        }
    }
    return have_backEdge;
}

void solve(int v){
    cycle = false;
    checkCycle(v, v);

    if(!cycle){
        tree_deadEnds(v);
    }
    else{
        cycle_deadEnds(root, root);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int m;
    cin>>n>>m;
    loop(i, 0, m){
        int a, b;
        cin>>a>>b;
        --a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    loop(i, 0, n){
        if(!visited[i])
            solve(i);
    }

    sort(dead_ends.begin(), dead_ends.end());
    cout<<dead_ends.size()<<"\n";
    for(pii p : dead_ends)
        cout<<1+p.first<<" "<<1+p.second<<"\n";

    return 0; 
}