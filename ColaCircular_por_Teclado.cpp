// COLA CIRCULAR
// Variante de la cola estática que reutiliza el espacio del arreglo
// cuando el final llega al final del arreglo, "regresa" al inicio
// utilizando la operación del módulo (%).

#include <iostream>
using namespace std;

const int MAXQ = 5; // Capacidad máxima de la cola

// ESTRUCTURA DE LA COLA CIRCULAR
struct ColaCircular {
    int data[MAXQ]; // Arreglo que almacena los elementos
    int front;      // Índice del frente (inicio)
    int rear;       // Índice del final
    int count;      // Cantidad de elementos actuales en la cola
};

// Inicializa la cola circular vacía
void inicializar(ColaCircular &c) {
    c.front = 0;
    c.rear = -1; // rear empieza en -1 porque aún no hay elementos
    c.count = 0;
}

// Verifica si la cola está vacía o llena
bool vacia(const ColaCircular &c) { return c.count == 0; }
bool llena(const ColaCircular &c) { return c.count == MAXQ; }

// Inserta un elemento al final de la cola
bool encolar(ColaCircular &c, int v) {
    if (llena(c)) return false; // No se puede insertar si está llena
    c.rear = (c.rear + 1) % MAXQ; // Avanza de forma circular
    c.data[c.rear] = v;           // Guarda el valor
    c.count++;                    // Aumenta la cantidad
    return true;
}

// Elimina un elemento del frente de la cola
bool desencolar(ColaCircular &c, int &out) {
    if (vacia(c)) return false; // No se puede eliminar si está vacía
    out = c.data[c.front];      // Guardamos el valor del frente
    c.front = (c.front + 1) % MAXQ; // Avanza circularmente
    c.count--;                      // Disminuye la cantidad
    return true;
}

// Función principal
int main() {
    ColaCircular c;
    inicializar(c);

    int n;
    cout << "¿Cuántos elementos deseas encolar? (max " << MAXQ << "): ";
    cin >> n;

    // Si el usuario ingresa más de los permitidos, se ajusta
    if (n > MAXQ) n = MAXQ;

    // Insertar los elementos desde teclado
    for (int i = 0; i < n; i++) {
        int valor;
        cout << "Ingrese el valor #" << i + 1 << ": ";
        cin >> valor;
        if (encolar(c, valor))
            cout << "Elemento " << valor << " encolado.\n";
        else
            cout << "Cola llena, no se pudo encolar.\n";
    }

    // Mostrar y eliminar los elementos de la cola
    cout << "\n--- Mostrando y vaciando la cola ---\n";
    int x;
    while (desencolar(c, x)) {
        cout << "Desencolado: " << x << endl;
    }

    cout << "\nCola vacía. Fin del programa.\n";
    return 0;
}

