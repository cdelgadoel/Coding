/*
    idea central
        Como todos los numeros son diferentes, la secuencia completa 
        esta ordenada si al final están los numeros 
            1, 2, 3, ..., n

    entonces solo tengo que ver si el color que estaba inicialmente en una casilla
    es el mismo que el del numero que deberia ir ahi

    Por ejemplo, el color que tenia la casilla cero debera ser el mismo que el del 1

    Para implementar, leo el arreglo de pares inicial 
    lo ordeno y veo si el color que esta en una casilla coincide con el color
    que habia inicialmente

    Complejidad de tiempo O(nlogn)
        leer + ordenar el arreglo de n elementos + recorrer el arreglo
        O(n) + O (n log n) + O(n)
        Complejidad total: O(2*n + nlogn) = O(nlogn)
    
    Complejidad de memoria  O(n)
        arreglo de pares, arreglo de colores
        O(2*n)          O(n)
        Complejidad total O(n)

*/  
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;
	pii numeros[n];
	int colores[n];
	for(int i = 0; i < n; ++i){
        cin>>numeros[i].first>>numeros[i].second;
        colores[i] = numeros[i].second;
    }

    sort(numeros, numeros + n);
    bool sePuede = true;
    for(int i = 0; i < n; ++i){
        if(numeros[i].second != colores[i])
        sePuede = false;
    }

    if(sePuede)
        cout<<"Y\n";
    else
        cout<<"N\n";
    return 0;
}