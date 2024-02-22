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

bool trySolve(vector<int> &b, bool oneMore){
    //loop(i, 0, b.size())
    //    cout<<b[i]<<" ";
    //cout<<endl;
    loop(i, 0, b.size()-1){
        if(b[i] > b[i+1])
            return false;
    }

    // all satisfy <= 
    // find first equal 
    
    int indxE1 = 1, indxE2;
    bool diff;
    while(indxE1 < b.size() && b[indxE1] > b[indxE1-1])
        ++indxE1;
    if(indxE1 == b.size()) 
        return true;
    indxE2 = indxE1+1;

    while(indxE2 < n){
        while(indxE2 < b.size() && b[indxE2] > b[indxE2-1])
            ++indxE2;
        if(indxE2 == b.size())
            return true;

        diff = false;
        loop(i, indxE1, indxE2)
            if(b[i+1] - b[i] > 1){
                diff = true;
                break;
            }
        if(!diff){
            if(oneMore)
                oneMore = false;
            else   
                return false;
        }
        indxE1 = indxE2;
        ++indxE2;                
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
            // take out i
            loop(j, 0, n){
                if(j != i)
                    b.push_back(a[j]);
            }
            if(trySolve(b, false))
                return true;
            
            //take out i+1
            b.clear();
            loop(j, 0, n){
                if(j != i+1)
                    b.push_back(a[j]);
            }
            if(trySolve(b, false))
                return true;
            else
                return false;
        }   
    }
    // all satisfy <= 
    loop(i, 0, n)
        b.push_back(a[i]);
    return trySolve(b, true);
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