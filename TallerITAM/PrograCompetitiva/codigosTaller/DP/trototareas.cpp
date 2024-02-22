#include <iostream>
#define INF 500001
using namespace std;

const int maxN = 500 + 5, maxS = 100 + 5;
int DP[maxN][maxS];
bool visitado[maxN][maxS];
int v[maxN], t[maxN];
int N, S;

//me dice cual es el tiempo minimo de generar esa cantidad de puntos
//con tareas apartir del indice indicado
int dp(int indice,int puntajeFaltante){
    if(puntajeFaltante <= 0)
        return 0;
    if(indice == N)
        return INF;
	if(!visitado[indice][puntajeFaltante]){
        visitado[indice][puntajeFaltante] = true;
		//tomo el tiempo minimo entre tomar esta tarea o no
        DP[indice][puntajeFaltante] = 
            min(
                dp(indice + 1, puntajeFaltante), 
                t[indice] + dp(indice + 1, puntajeFaltante - v[indice])
                );
	}
    return DP[indice][puntajeFaltante];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>S;
	for(int i = 0; i < N; i++)
		cin>>v[i]>>t[i];
	cout<<dp(0, S)<<endl;
	return 0;
}