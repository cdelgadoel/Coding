#include <iostream>
using namespace std;
int main() {
  int n = 0;
  int sumaElementos = 0;
  int sumaPares = 0;
  int sumaImpares = 0;

  cout << "dame la cantidad de numeros que deseas sumar: ";
  cin >> n;

  for(int i = 0; i < n; i ++) {
    int numero;
    cout << "dame un numero";
    cin >> numero;
    if(i % 2 == 0)
      sumaPares += numero;
    else
      sumaImpares += numero;
  }

  sumaElementos = sumaPares - sumaImpares;
  cout << "la suma de los elementos es: :" << sumaElementos;
  
  return 0;
}