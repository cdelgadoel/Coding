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

ll s;

ll area(double r){
    //cout<<"area "<<r<<endl;
    ll it = 1;
    ll a = 0;
    ll ini, fin, mid;
    while(it <= r){
        ini = 0, fin = r;
        while(ini != fin){
            //cout<<ini<<" "<<fin<<endl;
            mid = (ini + fin + 1)/2;
            if(mid*mid + it*it <= r*r){
                ini = mid;
            }
            else 
                fin = mid-1;
        }
        //cout<<ini<<endl;
        a += ini;
        ++it;
    }
    //cout<<"final "<<a<<endl;
    return a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    
    cin>>s;
    double ini = 0, fin = 37000, mid;
    loop(i, 0, 100){
        mid = (ini + fin)/2;
        if( 4*area(mid) > s){
            fin = mid;
        }
        else
            ini = mid;
    }

    cout<<fixed<<setprecision(8)<<ini<<"\n";
    return 0;
}