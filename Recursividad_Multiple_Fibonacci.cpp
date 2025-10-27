#include <iostream>
using namespace std;
//Recursividad
//El siguiente programa implementa el cálculo de la serie de Fibonacci usando
//recursión múltiple.
class Fibonacci {
public:

    // Función recursiva para calcular el término n de Fibonacci
    int calcularFibonacci(int n) {
        // Caso base: cuando n es 0 o 1 se retorna directamente el valor de n
        if (n <= 1) {
            return n;
        } else {
            /* Aquí se aplica la RECURRENCIA MÚLTIPLE:
               La función se llama a sí misma DOS veces,
               una con (n-1) y otra con (n-2),
               lo que genera un árbol de llamadas recursivas. */
            return calcularFibonacci(n - 1) + calcularFibonacci(n - 2);
        }
    }

    // Imprime la secuencia hasta n términos
    void imprimirSecuencia(int n) {
        cout << "Secuencia de Fibonacci hasta " << n << ": ";
        for (int i = 0; i < n; ++i) {
            cout << calcularFibonacci(i) << " ";
        }
        cout << endl;
    }
};

int main() {
    Fibonacci fibonacci;
    int n = 10;
    fibonacci.imprimirSecuencia(n);
    return 0;
}

