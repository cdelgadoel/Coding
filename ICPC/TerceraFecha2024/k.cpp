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

const int maxN = 500005;

int n; 
int a[105];

int halfSum;
// dp to get Alices indexes to get half
bool dp[105][10000+5], visited[105][10000+5];
bool DP(int indx, int running_sum){
    if(running_sum == halfSum)
        return true;
    if(indx == n)
        return false;

    if(!visited[indx][running_sum]){
        visited[indx][running_sum] = true;
        if(DP(indx+1, running_sum) || DP(indx+1, running_sum + a[indx]))
            dp[indx][running_sum] = true;
    }
    return dp[indx][running_sum];
}

void solve(){
    cin>>n;
    int sum = 0;
    loop(i, 0, n){
        cin>>a[i];
        sum += a[i];
    } 

    if(sum&1){
        cout<<"-1\n";
        return;
    } 
    
    halfSum = sum/2;
    int possible = DP(0, 0);
    if(!possible){
        cout<<"-1\n";
        return;
    }

    stack<int> Alice, Bob;
    int aliceSum = 0;
    for(int i = 0; i < n; ++i){
        if(DP(i+1, aliceSum)){
            Bob.push(a[i]);
        }
        else{
            Alice.push(a[i]);
            aliceSum += a[i];
        }
    }
    
    aliceSum = 0;
    int bobSum = 0, nextValue;
    loop(i, 0, n){
        if(aliceSum > bobSum){
            bobSum += Bob.top();
            nextValue = Bob.top();
            Bob.pop();
        }
        else{
            aliceSum += Alice.top();
            nextValue = Alice.top();
            Alice.pop();
        }
        cout<<nextValue<<" \n"[i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    solve();
    return 0;
}