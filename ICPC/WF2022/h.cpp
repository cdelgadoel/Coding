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
#include <cstdint>
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

const int maxN = 1e6+5;

int n; 
pair<pi, int> p[maxN];
bool comp(pair<pi, int> a, pair<pi, int> b){
    if(a.f.f == 0 && b.f.f == 0){
        return a.f.s > b.f.s;
    }
    else if(a.f.f == 0){
        return true;
    }
    else if(b.f.f == 0){
        return false;
    }
    else{
        // both negative
        if(a.f.f + a.f.s > 0){
            return b.f.f + b.f.s > 0? a.f.f > b.f.f : true;
        }
        else if(a.f.f + a.f.s == 0){
            if (b.f.f + b.f.s > 0)
                return false;
            else if (b.f.f + b.f.s == 0)
                return a.f.f < b.f.f;
            else
                return true;
        }
        else{   
            if( b.f.f + b.f.s >= 0) 
                return false;
            else 
                return a.f.s > b.f.s;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    stack<char> st;
    string ss;
    int a, b;
    cin>>n;
    loop(i, 0, n){
        cin>>ss;
        for(char c : ss){
            if(c == '(')
                st.push(c);
            else if(c==')')
            {
                if(st.empty() || st.top() == ')')
                    st.push(c);
                else
                    st.pop();
            }
        }
        a = 0; b = 0;
        while(!st.empty()){
            if(st.top() == '(')
                ++b;
            else 
                --a;
            st.pop();
        }
        p[i] = pair(pi(a, b), i+1);
    }

    sort(p, p+n, comp);
    bool possible = true;
    int acum = 0;
    loop(i, 0, n){
        if(p[i].f.f + acum < 0){
            possible = false;
            break;
        }
        acum += p[i].f.f;
        acum += p[i].f.s;
    }
    if(acum == 0 && possible){
        loop(i, 0, n){
            cout<<p[i].second<<"\n";
        }
    }
    else{
        cout<<"impossible\n";
    }
    return 0;
}