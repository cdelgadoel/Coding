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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    int n, k; cin>>k>>n;
    int in[2][k], resp[3][n];
    loop(i, 0, 3) fill(resp[i], resp[i] + n, -1);
    stack<int> p[4][4];

    F0R(i, k) cin>>in[0][i];
    F0R(i, k) cin>>in[1][i];
    F0R(i, k) {
        int a = in[0][i], b = in[1][i];
        p[b][a].push(i+1);
    }

    int it = 0;
    while(!p[3][3].empty()){
        int id = p[3][3].top();
        p[3][3].pop();
        F0R(i, 3) F0R(j, 3){
            resp[i][it+j] = id;
        }
        it += 3;
    }

    while(!p[3][2].empty()){
        int id = p[3][2].top();
        p[3][2].pop();
        F0R(i, 3) F0R(j, 2){
            resp[i][it+j] = id;
        }
        it += 2;
    }

    while(!p[2][2].empty()){
        int id = p[2][2].top();
        p[2][2].pop();
        F0R(i, 2) F0R(j, 2){
            resp[i][it+j] = id;
        }
        it += 2;
    }
    /// 
    int id;
    while(it < n){
        if(!p[3][1].empty()){
            id = p[3][1].top();
            p[3][1].pop();
            F0R(i, 3)
                resp[i][it] = id;
        }
        else if(!p[2][1].empty()){
            id = p[2][1].top();
            p[2][1].pop();
            F0R(i, 2)
                resp[i][it] = id;
        }else{
            F0R(i, 2){
                id = p[1][1].top();
                p[1][1].pop();
                resp[i][it] = id;;
            }
        }
        ++it;
    }

    it = 0;
    while(it < n){
        if(resp[2][it] == -1){
            int alto = 3;
            while(p[alto][1].empty())
                --alto;
            id = p[alto][1].top();
            p[alto][1].pop();
            F0R(j, alto)
                resp[2][it++] = id;
        }
        else{
            ++it;
        }
    }

    F0R(i, 3) F0R(j, n){
        cout<<resp[i][j]<<" \n"[j==n-1];
    }
    return 0;
}