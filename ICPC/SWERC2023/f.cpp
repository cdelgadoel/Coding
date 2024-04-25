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
const int maxN = 100005;

int ids[maxN], scores[maxN];
string name[maxN];
bool f(int id1, int id2){
    if(scores[id1] != scores[id2])
        return scores[id1] > scores[id2];
    else   
        return id1 < id2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n; cin>>n;
    
    iota(ids, ids+n, 0);
    int score, c, e[6];
    loop(i, 0, n){
        cin>>name[i];
        score = 0;
        cin>>c;
        loop(i, 0, 6)
            cin>>e[i];
        sort(e, e+6);
        score = c*10;
        loop(i, 1, 5)
            score += e[i];
        scores[i] = score;
    }
    sort(ids, ids+n, f);
    loop(i, 0, 3){
        cout<<name[ids[i]]<<" "<<scores[ids[i]]<<"\n";
    }
    int i = 3;
    while(i<n && scores[ids[i]] == scores[ids[2]]){
        cout<<name[ids[i]]<<" "<<scores[ids[i]]<<"\n";
        ++i;
    }

    return 0;
}