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

string a[100][99];
void fill(){
    a[1][0] = "1";
    a[3][0] =  "196";
    a[3][1] = "961";
    a[3][2] = "169";
    for(int i = 5; i <= 99; i +=2){
        for(int j = 0; j < i-2; ++j){
            a[i][j] = a[i-2][j] + "00";
        } 

        a[i][i-2] = "9";
        a[i][i-1] = "1";
        for(int j =0; j < (i-3)/2; ++j){
            a[i][i-2] = a[i][i-2] + "0";
            a[i][i-1] = a[i][i-1] + "0";
        }
        a[i][i-2] = a[i][i-2] + "6";
        a[i][i-1] = a[i][i-1] + "6";
        for(int j =0; j < (i-3)/2; ++j){
            a[i][i-2] = a[i][i-2] + "0";
            a[i][i-1] = a[i][i-1] + "0";
        }
        a[i][i-2] = a[i][i-2] + "1";
        a[i][i-1] = a[i][i-1] + "9";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    fill();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        loop(i, 0, n){
            cout<<a[n][i]<<"\n";
        }
    }
    return 0;
}