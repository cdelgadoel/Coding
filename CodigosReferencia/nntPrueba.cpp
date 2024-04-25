#include <iostream>
#include <vector>
#include <complex>
#include <queue>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
#define vll vector<ll>
#define all(v) v.begin(),v.end()
#define vii vector<pair<ll,ll>>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define ff first
#define ss second
const ll MOD=1e9+7;   
//const ll MOD=998244353;
const int N=2e5+5;
const int LOG=21;
using cd = complex<double>;
const double PI = acos(-1);


int dfs(int i, vector<vector<vector<int> > > &mark){
    int ans=0;
    vi v(6,0);
    queue<int>q;
    rep(j,0,6){
        if(v[j]) continue;
        q.push(j);
        while(!q.empty()){
            int d=q.front();
            q.pop();
            //cout<<d<<" ";
            v[d]=1;
            ans++;
            rep(l,0,6){
                if(mark[i][d][l]==0 || v[l]) continue;
                q.push(l);
                v[l]=1;
            }
        }
        ans--;
        //cout<<ans<<'\n';
        // cout<<'\n';
    }
    return ans;
}

void solve(int test){
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    vector<vector<vector<int> > > mark(n);
    for(int i= 0; i < 6; ++i){
        mark[i].resize(6);
        for(int j= 0; j < 6; ++j){
            mark[i][j].resize(6);
            fill(mark[i][j].begin(), mark[i][j].end(), 0);
        }
    }
    vector<ll>v(n);
    vector<ll>u(m);
    rep(i,0,6){
        rep(j,0,6){
            if(i==j) continue;
            rep(k,0,n) {
                if(s[k]-'a'==i) v[k]=1;
                else v[k]=0;
            }
            rep(k,0,m){
                if(t[k]-'a'==j) u[m-1-k]=1;
                else u[m-1-k]=0;
            }
            vector<ll>w=mul(v,u);
            rep(k,0,n-m+1){
                if(w[k+m-1]) mark[k][i][j]=1,mark[k][j][i]=1;
            }
        }
    }
    
    rep(i,0,n-m+1){
        cout<<dfs(i, mark)<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
    rep(i,0,t){
       //cout<<"Case #"<<i+1<<" ";
        solve(i+1); 
    }
     
    return 0;
}