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
#include <unordered_map>
#define INF 1000000000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

using namespace std;
typedef pair<int,int> pii;
const int maxN = 100005;

int dp[maxN], f[5][4*maxN], lR[4*maxN], rR[4*maxN];
string a[maxN];
int n; 

void init(int it, int le, int ri){
    lR[it] = le; 
    rR[it] = ri;
    f[0][it] = f[1][it] = f[2][it] = f[3][it] = f[4][it] = 0;
    if(le != ri){
        int m = (le+ri)/2;
        init(it<<1, le, m);
        init((it<<1)+1, m+1, ri);
    }
}

void update(int indx, int value, int indxF){
    int it = 1; 
    while(lR[it] != rR[it]){
        if(indx <= rR[it<<1])
            it <<= 1;
        else
            it = (it<<1) + 1;
    }
    f[indxF][it] = value;
    it >>= 1;
    while(it != 0){
        f[indxF][it] = max(f[indxF][it<<1], f[indxF][(it<<1) + 1]);
        it >>= 1;
    }   
}

int query(int it, int le, int ri, int indxF){
    if(rR[it] < le || ri < lR[it])
        return 0;
    if( le <= lR[it] && rR[it] <= ri)
        return f[indxF][it];
    return max(query(it<<1, le, ri, indxF), query( (it<<1) + 1, le, ri, indxF));
}

int toInt(int indx){
    int resp = 0;
    for(int i = 1; i < a[indx].size(); ++i){
        resp *= 10;
        resp += (a[indx][i] - '0');
    }
    return resp;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n;
    init(1, 1, n);
    loop(i, 0, n){
        cin>>a[i];
    }

    int resp = 0; 
    unordered_map<char, int> mapa;
    char letters[5] = {'E', 'R', 'S', 'W', 'C'};
    do{
        mapa[letters[0]] = 0;
        mapa[letters[1]] = 1;
        mapa[letters[2]] = 2;
        mapa[letters[3]] = 3;
        mapa[letters[4]] = 4;
        loop(i, 0, 5)
            fill(f[i], f[i] + 4*(n+5), 0);

        for(int i = n-1, cat, num; i >= 0; --i){
            //soy el max de mi categoria o no 
            cat = mapa[a[i][0]];
            num = toInt(i);
            dp[i] = query(1, num+1, n, cat);
            loop(j, cat+1, 5){
                dp[i] = max(dp[i], query(1, 1, n, j));
            }
            // le agrego mi aporte
            dp[i] += 1;
            update(num, dp[i], cat);
        }

        int maxi = 0;
        loop(i, 0, n)
            maxi = max(maxi, dp[i]);
        resp = max(resp, maxi);
    }while(next_permutation(letters, letters + 4));
    cout<<n - resp<<"\n";
    return 0;
}