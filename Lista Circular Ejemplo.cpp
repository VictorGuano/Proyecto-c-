#include <iostream>
using namespace std;

// Estructura lista circular
struct NodoCircular {
    int dato;
    NodoCircular* siguiente;
};

// Función lista circular (insertar al final)
void insertarCircular(NodoCircular*& cabeza, int valor) {
    NodoCircular* nuevo = new NodoCircular();
    nuevo->dato = valor;

    if (cabeza == nullptr) { // comparación correcta
        cabeza = nuevo;
        nuevo->siguiente = cabeza; // se apunta a sí mismo
    } else {
        NodoCircular* actual = cabeza;
        // Buscar el último nodo
        while (actual->siguiente != cabeza) {
            actual = actual->siguiente;
        }
        // Enlazar el nuevo nodo al final
        actual->siguiente = nuevo;
        nuevo->siguiente = cabeza; // Cierra el círculo
    }
}

// Mostrar lista circular
void mostrarCircular(NodoCircular* cabeza) {
    if (cabeza == nullptr) {
        cout << "\nLista circular vacía\n";
        return;
    }

    cout << "\nLista Circular: ";
    NodoCircular* actual = cabeza;
    do {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    } while (actual != cabeza);
    cout << "(vuelve al inicio)\n";
}

// MAIN
int main() {
    NodoCircular* cabeza = nullptr;
    int edad, opcion;

    do {
        cout << "\n--- MENU LISTA CIRCULAR (EDADES) ---\n";
        cout << "1) Insertar edad\n";
        cout << "2) Mostrar lista circular\n";
        cout << "3) Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese la edad: ";
                cin >> edad;
                insertarCircular(cabeza, edad);
                break;

            case 2:
                mostrarCircular(cabeza);
                break;

            case 3:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opción no válida.\n";
                break;
        }

    } while (opcion != 3);

    return 0;
}

