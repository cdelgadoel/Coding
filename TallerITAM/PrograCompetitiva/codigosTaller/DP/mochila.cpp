#include <iostream>  // libreria para las funciones cin, cout
#include <algorithm> // libreria para la funcion max

using namespace std;
//aqui puedes ajustar las restricciones dependiendo del problema
//  mientras entren dentro del tiempo limite
// Complejidad de tiempo: O(n * pesoMax)
// Complejidad de memoria: O(maxN * maxP);
const int maxN = 1000, maxP = 1000;
int n, pesoMax;
int valor[maxN], peso[maxN];

int dp[maxP][maxN];
bool visitado[maxP][maxN];
//la funcion me regresa el maximo valor de entre los objetos apartir de este indice
// con la restriccion del pesoRestante
int mochila(int pesoRestante, int indice){
    //caso base: ya no hay objetos y el valor es cero
    //un caso base mas intuitivo es solo tener un objeto, y tomarlo si tengo suficiente pesoRestante
    //  pero esa logica esta contenida dentro del if donde calculas la respuesta 
    //  entonces puedes considerar este caso base y no volver a poner esa logica del if aqui  
    if(indice == n)
        return 0;

    //si no he calculado la respuesta a este caso, la calculo y la guardo
    //si ya la calcule, no la vuelvo a calcular, solo la devuelvo
    if(!visitado[pesoRestante][indice]){
        //super importante marcarlo como visitado
        visitado[pesoRestante][indice] = true;
        //la respuesta es el maximo entre tomarlo o no
        //solo lo tomo si tengo suficiente espacio
        if(pesoRestante < peso[indice])
            dp[pesoRestante][indice] =  mochila(pesoRestante, indice+1);
        else
            dp[pesoRestante][indice] = max(
                                        valor[indice] + mochila(pesoRestante - peso[indice], indice+1),
                                        mochila(pesoRestante, indice+1)
                                        );
    }
    //regreso la respuesta guardada
    return dp[pesoRestante][indice];
}

int main(){
    //leer la cantidad de objetos
    //leer el peso maximo
    cin>>n>>pesoMax;
    //leer para cada objeto el valor y el peso
    for(int i = 0; i < n; i++){
        cin>>valor[i]>>peso[i];
    }

    //imprimo el maximo valor con este peso restante y empezando en el primer objeto
    cout<<mochila(pesoMax, 0)<<"\n";

}