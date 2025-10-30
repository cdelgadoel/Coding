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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    int n, r, c; 
    cin>>n>>r>>c;
    --r; --c;

    int sr = 0, sc = n-1;
    bool alive[n];
    fill(alive, alive + n, 1);
    int totAlive = n;
    int rr, rc, mov;
    set<int> hired;

    while(totAlive > 0){
        if(totAlive <= 2){
            loop(i, 0, n)
            if(alive[i])
                hired.insert(i);
            break;
        }

        rr = r%totAlive;
        loop(i, 0, rr){
            do{
                sr = (sr + 1)%n;
            }
            while(!alive[sr]);
        }

        rc = c%totAlive;
        loop(i, 0, rc){
            do{
                sc = (sc + n - 1)%n;
            }
            while(!alive[sc]);
        }

        if(sr == sc){
            hired.insert(sr);
            alive[sr] = 0;
            totAlive -= 1;
        }
        else{
            alive[sr] = alive[sc] = 0;
            totAlive -= 2;
        }
        
        do{
            sr = (sr + 1)%n;
        }
        while(!alive[sr]);

        do{
            sc = (sc + n - 1)%n;
        }
        while(!alive[sc]);
    }   

    int x =0;
    for(int h : hired){
        ++x;
        cout<<h+1<<(x == hired.size()? "\n" : " ");
    }
    return 0;
}