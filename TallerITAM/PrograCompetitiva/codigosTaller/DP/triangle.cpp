#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 105;
int n;

int valor[maxN][maxN];
int dp[maxN][maxN];
bool visitado[maxN][maxN];

int DP(int fila, int columna){
    if(fila == n-1)
        return valor[fila][columna];

    if(!visitado[fila][columna]){
        visitado[fila][columna] = 1;
        dp[fila][columna] = valor[fila][columna] + max(DP(fila+1,columna), DP(fila+1, columna+1));
    }
    return dp[fila][columna];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i <= n-1; ++i)
    for(int j = 0; j <= i; ++j){
        cin>>valor[i][j];
    }
    cout<<DP(0, 0)<<endl;
}


