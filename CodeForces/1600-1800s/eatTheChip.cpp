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

string solve(){
    int h, w, xa, ya, xb, yb;
    cin>>h>>w>>ya>>xa>>yb>>xb;
    int d = yb - ya;
    if(d  <= 0){
        return "Draw";
    }

    if(d&1){
        if(xa < xb){
            xa = min(w, xa + d/2);
            xb = min(w, xb + d/2);
        }
        else
        {
            xa = max(xa - d/2, 1);
            xb = max(xb - d/2, 1);
        }
        return (abs(xa - xb) <= 1? "Alice" : "Draw");
    }
    else{
        if(xa < xb){
            xa = max(xa - d/2, 1);
            xb = max(xb - (d/2-1), 1);
        }
        else
        {
            xa = min(w, xa + d/2);
            xb = min(w, xb + (d/2 - 1));
        }
        return (abs(xa - xb) <= 1? "Bob" : "Draw");
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
    return 0;
}