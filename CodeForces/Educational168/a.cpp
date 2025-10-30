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
const int maxN = 500005;

void solve(){
    string s; cin>>s;
    char dif;
    loop(i, 1, s.size()){
        if(s[i] == s[i-1]){
            dif = s[i] == 'a'? 'b' : 'a';
            s = s.substr(0, i) + dif + s.substr(i);
            cout<<s<<"\n";
            return;
        }
    }
    
    dif = s[s.size()-1] == 'a'? 'b' : 'a';
    cout<<s<<dif<<"\n";
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