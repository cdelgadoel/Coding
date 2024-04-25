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

int row(int x){ return x/3;}
int col(int x){ return x%3;}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    char letters[3][3];
    string resp = "CCC", it;
    loop(i, 0, 3)
    loop(j, 0, 3)
        cin>>letters[i][j];
    loop(l1, 0, 9)
    loop(l2, 0, 9)
    loop(l3, 0, 9){
        if( l1 != l2 && l1 != l3 && l2 != l3 &&
            abs(row(l1) - row(l2)) <= 1 && abs(col(l1) - col(l2))<=1
            && abs(row(l3) - row(l2)) <= 1 && abs(col(l3) - col(l2))<=1){
                it = "";
                it += letters[row(l1)][col(l1)];
                it += letters[row(l2)][col(l2)];
                it += letters[row(l3)][col(l3)];
                if(resp > it)
                    resp = it;
        }
    }
    cout<<resp<<"\n";

    return 0;
}