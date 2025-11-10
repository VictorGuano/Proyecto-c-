#include <iostream>
using namespace std;

// Estructura del nodo de la cola
struct Nodo {
    string  dato;             // valor almacenado en el nodo
    Nodo *siguiente;      // puntero al siguiente nodo
};

// Estructura de la cola con dos punteros principales
struct Cola {
    Nodo *front;  // apunta al primer nodo (frente de la cola)
    Nodo *rear;   // apunta al último nodo (final de la cola)
};

// Inicializa la cola vacía
void inicializar(Cola &c) {
    c.front = c.rear = nullptr;  // ambos punteros apuntan a nada
}

// Verifica si la cola está vacía
bool estaVacia(Cola c) {
    return c.front == nullptr;   // si front es nulo, no hay elementos
}

// Inserta un nuevo elemento al final de la cola
void encolar(Cola &c, string valor) {
    // Se crea un nuevo nodo con el valor y sin siguiente
    Nodo *nuevo = new Nodo{valor, nullptr};

    // Si la cola está vacía, el nuevo nodo será el primero y el último
    if (estaVacia(c)) {
        c.front = c.rear = nuevo;
    } else {
        // Si no está vacía, el último nodo apunta al nuevo
        c.rear->siguiente = nuevo;
        // Actualiza el puntero rear al nuevo nodo
        c.rear = nuevo;
    }
}

// Elimina y devuelve el elemento al frente de la cola
string desencolar(Cola &c) {
    // Si no hay elementos, muestra mensaje y retorna -1
    if (estaVacia(c)) {
        cout << "Cola vacia.\n";
        return " ";
    } else {
        // Guarda el nodo frontal en una variable temporal
        Nodo *temp = c.front;
        // Guarda el valor del nodo que se va a eliminar
        string  valor = temp->dato;
        // Mueve el puntero front al siguiente nodo
        c.front = c.front->siguiente;
        // Libera la memoria del nodo eliminado
        delete temp;
        // Retorna el valor eliminado
        return valor;
    }
}

// Función principal
int main() {
    Cola c;               // Se crea una cola llamada 'c'
    inicializar(c);       // Se inicializa vacía
	
	int cantidad;
	cout<<"Ingrese la cantidad de escripciones "<<endl ;
	cin >> cantidad  ;
	//Ingresar
	for(int i=0;i<cantidad;i++){
	string letra;
	cout<<"ingrese  inscripcion "<<i+1<<endl;
	cin>>letra;
	encolar(c, letra);	
	} 
    //Mostrar
    for(int i=0;i<cantidad;i++){
	cout << "Desencolado: " << desencolar(c) << endl;	
	}
    return 0; // Fin del programa
}
