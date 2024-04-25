# include <iostream>
using namespace std;

  int main(){
    int n = 0;
    int suma = 0;

    cout << "ingresa la cantidad de numeros que deseas sumar: ";
    cin >> n;

    for(int i = 1; i <= n; i ++){
      int numero;
      cout << "ingresa un numero; ";
      cin >> numero;

      suma += numero;
    }

    cout << "la suma de los numeros es: " << suma;
  }