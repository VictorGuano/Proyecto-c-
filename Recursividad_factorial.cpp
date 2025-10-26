#include <iostream>
using namespace std;

// Función recursiva para calcular factorial mostrando pasos
int factorial(int n) {
    cout << "Entrando a factorial(" << n << ")" << endl; // muestra la entrada a la función

    if (n == 0) { // caso base
        cout << "Caso base alcanzado: factorial(0) = 1" << endl;
        return 1;
    } else { // caso recursivo
        int resultado = n * factorial(n - 1); // aquí se hace la recursión
        cout << "Retornando: factorial(" << n << ") = " << resultado << endl; // muestra la salida
        return resultado;
    }
}

int main() {
    int num;

    cout << "Ingrese un número entero no negativo: ";
    cin >> num;

    if (num < 0) {
        cout << "El factorial no está definido para números negativos." << endl;
    } else {
        int fact = factorial(num);
        cout << "El factorial de " << num << " es: " << fact << endl;
    }

    return 0;
}

