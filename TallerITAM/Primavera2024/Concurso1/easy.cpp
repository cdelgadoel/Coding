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

const int maxN = 500005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    char letters[3][3];
    string resp = "CCC", it;
    loop(i, 0, 3)
    loop(j, 0, 3)
        cin>>letters[i][j];
    loop(l1i, 0, 3)
    loop(l1j, 0, 3)
        loop(l2i, 0, 3)
        loop(l2j, 0, 3)
            loop(l3i, 0, 3)
            loop(l3j, 0, 3){
                if( !(l1i == l2i && l1j == l2j) 
                    && !(l3i == l2i && l3j == l2j)
                    && !(l1i == l3i && l1j == l3j) 
                    && abs(l1i - l2i) <= 1 && abs(l1j - l2j)<=1
                    && abs(l3i - l2i) <= 1 && abs(l3j - l2j)<=1){
                        it = "";
                        it += letters[l1i][l1j];
                        it += letters[l2i][l2j];
                        it += letters[l3i][l3j];
                        if(resp > it)
                            resp = it;
                    }
                    
            }
    cout<<resp<<"\n";

    return 0;
}