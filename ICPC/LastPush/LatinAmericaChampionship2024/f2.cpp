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

const int maxN = 200000, maxSum = 200000, maxG = 200000;
int gcd(int a, int b){
    if(a == 0)
        return b;
    else    
        return gcd(b%a, a);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    int n;
    cin>>n;
    if(n == 1){
        cout<<"N\n";
        return 0;
    }

    int a = 0, bucket[maxG+5], sumG = 0;
    fill(bucket, bucket + maxG+5, 0);
    for(int i = 0, g, r; i < n; ++i){
        cin>>g>>r;
        ++bucket[g];
        sumG += g;
        a = gcd(a, r); 
    }

    if(a == 1){
        cout<<"Y\n";
        return 0;
    }
   
    bool isCandidate[maxSum+1];
    loop(i, 0, sumG+1){
        isCandidate[i] = ((2*i) % a) == sumG%a;
    }

    if(isCandidate[0] && bucket[0] > 0){
        cout<<"Y\n";
        return 0;
    }
    
    vector<int> distinct;
    loop(i, 0, sumG+1)
        if(bucket[i] > 0)
            distinct.pb(i);

    int dp[distinct.size()][sumG+1];
    // dp[i][sum] answers the number of elements with value i needed to have sum "sum" using only the values
    //            from id 0 to id i. 
    // dp[i][sum] == -1 if 
    for(int i = 0; i < distinct.size(); ++i){
        dp[i][0] = 0;
        for(int sum = 1; sum < sumG; ++sum){
            //cout<<i<<" "<<sum<<" "<<distinct[i]<<" "<<bucket[i]<<endl;
            if(i > 0 && dp[i-1][sum] >= 0)
                dp[i][sum] = 0;
            else if(dp[i][sum - distinct[i]] >= 0 && dp[i][sum - distinct[i]] < bucket[distinct[i]]){
                if(isCandidate[sum]){
                    cout<<"Y\n";
                    return 0;
                }
                dp[i][sum] = dp[i][sum - distinct[i]] + 1;
            }
            else{
                dp[i][sum] = -1;
            }
            // cout<<i<<" "<<sum<<" "<<dp[i][sum]<<endl;
        }
    }

    // no candidate was possible
    cout<<"N\n";

    return 0;
}