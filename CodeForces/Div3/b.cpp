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
const int maxN = 200005;
int n, a[3];

int solve(){
    cin>>n;
    int sumMod = 0;
    int num;
    a[0] = a[1] = a[2] = 0;
    loop(i, 0, n){
        cin>>num;
        sumMod = (sumMod + num)%3;
        ++a[num%3];
    }
    if(sumMod == 0){
        return 0;
    }
    else if(a[sumMod] > 0 || sumMod == 2)
        return 1;
    else
        return 2;
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