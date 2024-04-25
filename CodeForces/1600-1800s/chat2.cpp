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

#define V vector
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ft front()

const int maxN = 200005;

int n, k;
vector<int> ss[maxN];
int theone[maxN];
string solve(){
    cin>>n>>k;
    loop(i, 0, k){
        ss[i].resize(n);
        loop(j, 0, n){
            cin>>ss[i][j];
        }
    }

    if(k == 1)
        return "YES";
    
    loop(i, 0, n-1)
        theone[i] = ss[0][i+1];

    int numBeforeOne = 0, numBeforeTwo = 0;
    loop(i, 2, n){
        if(ss[0][i] == ss[1][0])
            numBeforeTwo = ss[0][i-1];
    }
    loop(i, 2, n){
        if(ss[1][i] == ss[0][0])
            numBeforeOne = ss[1][i-1];
    }

    if(numBeforeOne == numBeforeTwo){
        if(k > 2)
        {
            int it = 1;
            while(ss[2][it] != ss[0][0] && ss[2][it] != ss[1][0])
                ++it;
            if(ss[2][it] == ss[0][0]){
                int i = n-2;
                while(theone[i] != ss[1][0]){
                    theone[i+1] = theone[i];
                    --i;
                }
                theone[i+1] = theone[i];
                theone[i] = ss[0][0];
            }
            else{
                int i = n-2;
                while(theone[i] != ss[1][0]){
                    theone[i+1] = theone[i];
                    --i;
                }
                theone[i+1] = ss[0][0];
            }
        }
        else{
            int i = n-2;
            while(theone[i] != ss[1][0]){
                theone[i+1] = theone[i];
                --i;
            }
            theone[i+1] = ss[0][0];
        }
    }
    else{
        int i = n-2;
        while(theone[i] != numBeforeOne){
            theone[i+1] = theone[i];
            --i;
        }
        theone[i+1] = ss[0][0];
    }

    // loop(i, 0, n)
    //     cout<<theone[i]<<" \n"[i==n-1];

    loop(i, 0, k){
        // cout<<"checando "<<i<<endl;
        int it = 0;
        loop(j, 1, n){
            if(theone[it] == ss[i][0])
                ++it;
            // cout<<j<<endl;
            // cout<<theone[it]<<" "<<ss[i][j]<<endl;
            if(theone[it] != ss[i][j])
                return "NO";
            ++it;
        }
    }
    return "YES";
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