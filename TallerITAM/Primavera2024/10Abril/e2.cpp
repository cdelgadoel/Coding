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
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;

const int maxN = 1005;
int n; 
int entry[maxN], out[maxN], color[maxN];
bool visited[maxN];
vector<int> adj[maxN];

bool sePuede = true;
void dfs(int u, int fu, int color_){
    color[u] = color_;
    visited[u] = true;

    for(int v : adj[u]){
        if(!visited[v])
        {
            dfs(v, u, color[u] == 1? 2 : 1);
        }
        else{
            if(color[v] == color[u]){
                sePuede = false;
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n;
    loop(i, 0, 2*n){
        int a; cin>>a;
        if(a > 0)
            entry[a] = i;
        else
            out[-a] = i;
    }

    loop(i, 1, n+1)
    loop(j, i+1, n+1){
        if( (entry[i] < entry[j] && entry[j] < out[i] && out[i] < out[j])
            || (entry[j] < entry[i] && entry[i] < out[j] && out[j] < out[i]))
        {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    loop(i, 1, n+1){
        if(!visited[i]){
            dfs(i, 0, 1);
        }
    }

    if(!sePuede){
        cout<<"*\n";
    }
    else{
        loop(i, 1, n+1){
            if(color[i] == 1)
                cout<<"G";
            else
                cout<<"S";
        }
        cout<<"\n";
    }
    return 0;
}