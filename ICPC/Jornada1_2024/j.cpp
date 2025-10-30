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
using namespace std;
const int maxN = 501;
string s;
short one = 1;
bool v[maxN][maxN][maxN];
short dp[maxN][maxN][maxN];

short ant[maxN][26];
short DP(short i, short j, short k){
    if(k == 0)
        return 0;
    if(j < i)
        return 500;
    if(k <= 1)
        return 0;
    if(j-i+1 < k)
        return 500;
    if(i+1 == j && k == 2)
        return s[i]==s[j]? 0 : 1;
    if(!v[i][j][k]){
        v[i][j][k] = true;
        if(s[i] == s[j])
            dp[i][j][k] = DP(i+1, j-1, k-2);
        else{
            dp[i][j][k] = min( ((short)(one + DP(i+1, j-1, k-2))), DP(i+1, j, k));
            if(ant[j][s[i]-'a'] > i)
                dp[i][j][k] = min(dp[i][j][k], DP(i+1, ant[j][s[i]-'a']-1, k-2));
        }
    }
    return dp[i][j][k];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n, K;
    cin>>n>>K;
    cin>>s;

    for(int j = 0; j < 26; ++j)
        ant[0][j] = -1;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < 26; ++j)
            ant[i][j] = ant[i-1][j];
        ant[i][s[i-1]-'a'] = i-1;
    }

    cout<<DP(0, n-1, K)<<"\n";
    return 0;
}