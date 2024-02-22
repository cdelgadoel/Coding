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
int n; int a[maxN];

bool trySolve(vector<int> &b){
    loop(i, 0, b.size()-1){
        if(b[i] > b[i+1])
            return false;
        else if(b[i] == b[i+1])
            ++b[i+1];
    }
    return true;
}

bool solve(){
    cin>>n;
    loop(i, 0, n) 
        cin>>a[i];

    vector<int> b;
    loop(i, 0, n-1){
        if(a[i] > a[i+1]){
            loop(j, 0, n)
                if(j != i+1)
                    b.push_back(a[j]);
            if(trySolve(b))
                return true;

            //try with the other
            b.clear();
            loop(j, 0, n)
                if(j != i)
                    b.push_back(a[j]);
            if(trySolve(b))
                return true;
            else 
                return false;
        }
        else if(a[i] == a[i+1]){
            ++a[i+1];
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        cout<<(solve()? "YES\n" : "NO\n");
    }
    return 0;
}