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
typedef pair<int,int> pii;
const int maxN = 500005;
ll n, pos;
string s; 
stack<char> l;

void solve(){
    cin>>s>>pos;
    n = s.size();
    ll ini = 0, fin = n-1, m;
    while(ini != fin){
        m = (ini + fin)/2;
        if( n*(m+1) - m*(m+1)/2 >= pos)
            fin = m;
        else
            ini = m+1;
    }
    //quito length de los anteriores
    pos -=  (n*(ini) - (ini-1)*(ini)/2);
    while(!l.empty()) 
        l.pop();

    l.push(s[0]);
    int eliminados = 0, it = 1;
    // while(eliminados < ini && it < n){
    //     while(eliminados < ini && !l.empty() && s[it] < l.top()){
    //         l.pop();
    //         ++eliminados;
    //     }
    //     l.push(s[it]);
    //     ++it;
    // }
    // while(eliminados < ini){
    //     ++eliminados;
    //     l.pop();
    // }
    while(eliminados < ini){
        if(it == n){
            l.pop();
            ++eliminados;
        }
        else if(l.empty() || s[it] >= l.top()){
            l.push(s[it]);
            ++it;
        }
        else{
            ++eliminados;
            l.pop();
        }
    }

    if(l.size() >= pos){
        while(l.size() > pos)
            l.pop();
        cout<<l.top();
    }
    else{
        pos -= l.size();
        cout<<s[it + (pos - 1)];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}