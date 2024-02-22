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
typedef pair<double, pii> pdii;
 
const int maxN = 500005;
 
int h, w;
char mapa[705][705];
bool enqued[2*700+5][2*700+5];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
 
    cin>>h>>w;
    loop(i, 0, h)
    loop(j, 0, w){
        cin>>mapa[i][j];
    }
 
 
    priority_queue < pdii, vector<pdii>, greater<pdii> > minHeap; 
    minHeap.push(make_pair(0, make_pair(2*h, 2*w)));
    int i, j;
    double dist;
    double corner = 5*(1.57079632679489661923132169163975144);
    while(true){
        pdii top = minHeap.top();
        minHeap.pop();
        if(top.second == pii(0, 0)){
            cout<<fixed<<setprecision(8)<<top.first<<"\n";
            return 0;
        }
 
        dist = top.first;
        i = top.second.first;
        j = top.second.second;
        if(i & 1){
            if(!enqued[i-1][j]){
                enqued[i-1][j] = true;
                minHeap.push(pdii(dist + 5, pii(i-1, j)));
            }
            if(j > 0 && mapa[(i-1)/2][(j-2)/2] == 'O' && !enqued[i-1][j-1]){
                enqued[i-1][j-1] = true;
                minHeap.push(pdii(dist + corner, pii(i-1, j-1)));
            }
        }
        else{
            if(j&1){
                if(!enqued[i][j-1]){
                    enqued[i][j-1] = true;
                    minHeap.push(pdii(dist + 5, pii(i, j-1)));
                }
                if(i > 0 && mapa[(i-2)/2][(j-1)/2] == 'O' && !enqued[i-1][j-1]){
                    enqued[i-1][j-1] = true;
                    minHeap.push(pdii(dist + corner, pii(i-1, j-1)));
                }
            }
            else{
                if(j > 0 && !enqued[i][j-1]){
                    enqued[i][j-1] = true;
                    minHeap.push(pdii(dist + 5, pii(i, j-1)));
                }
                if(i > 0 && !enqued[i-1][j]){
                    enqued[i-1][j] = true;
                    minHeap.push(pdii(dist + 5, pii(i-1, j)));
                }
            }
        }        
    }
 
    return 0;
}