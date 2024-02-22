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

ll h, r, da, dw;

double f(double x){
    return ((dw-da)*x*x + da*h*h)/(2*((dw-da)*x + da*h));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    cin>>h>>r>>da>>dw;
    double ini = 0, fin = h, mid1, mid2;
    loop(i, 0, 100){
        mid1 = ini + (fin-ini)*1/3;
        mid2 = ini + (fin-ini)*2/3;
        if( f(mid1) >= f(mid2) )
            ini = mid1;
        else
            fin = mid2;
    }
    cout<<fixed<<setprecision(8)<<ini<<"\n";
    return 0;
}