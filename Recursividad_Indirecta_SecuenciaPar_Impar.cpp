#include <iostream>
// Recursividad directa (no indirecta realmente)
// Este ejemplo genera una secuencia basada en el número:
// - Si es par ? divide entre 2
// - Si es impar ? multiplica por 3 y suma 1
// La secuencia termina cuando n == 1
using namespace std;

class SecuenciaParImpar {
public:
    void generarSecuencia(int n) {
        cout << n << " "; // Mostrar el número actual

        if (n == 1) return; // Caso base: detener la recursión al llegar a 1

        if (n % 2 == 0) {
            generarSecuencia(n / 2); // Caso recursivo: número par
        } else {
            generarSecuencia(3 * n + 1); // Caso recursivo: número impar
        }
    }
};

int main() {
    SecuenciaParImpar spi;
    cout << "Secuencia para 7: " << endl;
    spi.generarSecuencia(7);
    cout << endl;
    return 0;
}

