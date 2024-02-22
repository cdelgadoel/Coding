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
const int maxN = 100005;
int a[maxN], d[maxN];

int solve(){
    int n; cin>>n;
    loop(i, 0, n) cin>>a[i];
    loop(i, 0, n-1){
        d[i] = a[i+1]-a[i];
    }
    d[n-1] = a[0] - a[n-1];

    int negs = 0, pos = 0;
    loop(i, 0, n){
        if(d[i] < 0) 
            ++negs;
        else if(d[i] > 0)
            ++pos;
    }
    
    if(negs == 0)
        return 0;
    if(negs > 1 && pos > 1)
        return -1;
    int firstPos = -1, firstNeg=-1, lastPos, lastNeg;
    loop(i, 0, n){
        if(d[i] > 0)
            lastPos = i;
        else if(d[i] < 0)
            lastNeg = i;
        if(firstPos == -1 && d[i] > 0)
            firstPos = i;
        if(firstNeg == -1 && d[i] < 0)
            firstNeg = i;
    }
    
    if(pos == 1 && negs == 1)
        return min( min(firstNeg+3, firstPos+1), min(n-1 - lastNeg, n-lastPos));
    if(pos == 1)
        return min(n - lastPos, firstPos+1);
    else 
        return min(n-1-lastNeg, firstNeg+3);
    
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