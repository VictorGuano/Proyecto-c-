#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

/* ==========================
   Estructuras para Cursos
   Lista enlazada simple
   ========================== */

struct Curso {
    string nombre;
    string codigo;
    string docente;   // nombre del docente asignado
    int numAlumnos;
    Curso* siguiente;
    Curso(const string& n, const string& c, const string& d, int na)
        : nombre(n), codigo(c), docente(d), numAlumnos(na), siguiente(nullptr) {}
};

class ListaCursos {
private:
    Curso* cabeza;
public:
    ListaCursos() : cabeza(nullptr) {}
    ~ListaCursos() { liberar(); }

    void agregarCurso(const string& nombre, const string& codigo, const string& docente, int numAlumnos) {
        Curso* nuevo = new Curso(nombre, codigo, docente, numAlumnos);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        cout << "Curso agregado.\n";
    }

    Curso* buscarCurso(const string& codigo) {
        Curso* actual = cabeza;
        while (actual) {
            if (actual->codigo == codigo) return actual;
            actual = actual->siguiente;
        }
        return nullptr;
    }

    bool eliminarCurso(const string& codigo) {
        Curso* actual = cabeza;
        Curso* prev = nullptr;
        while (actual) {
            if (actual->codigo == codigo) {
                if (prev) prev->siguiente = actual->siguiente;
                else cabeza = actual->siguiente;
                delete actual;
                cout << "Curso eliminado.\n";
                return true;
            }
            prev = actual;
            actual = actual->siguiente;
        }
        cout << "Curso no encontrado.\n";
        return false;
    }

    void mostrarCursos() {
        if (!cabeza) {
            cout << "No hay cursos registrados.\n";
            return;
        }
        cout << "\n--- Lista de Cursos ---\n";
        Curso* actual = cabeza;
        while (actual) {
            cout << "Nombre: " << actual->nombre
                 << " | Codigo: " << actual->codigo
                 << " | Docente: " << actual->docente
                 << " | Alumnos: " << actual->numAlumnos << "\n";
            actual = actual->siguiente;
        }
    }

    // Recursivo: total de alumnos
    int totalAlumnosRec() { return totalAlumnosRecHelper(cabeza); }

    int contarCursosMasQue(int limite) { return contarCursosMasQueHelper(cabeza, limite); }

    Curso* obtenerCabeza() { return cabeza; }

    void liberar() {
        while (cabeza) {
            Curso* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

private:
    int totalAlumnosRecHelper(Curso* nodo) {
        if (!nodo) return 0;
        return nodo->numAlumnos + totalAlumnosRecHelper(nodo->siguiente);
    }

    int contarCursosMasQueHelper(Curso* nodo, int limite) {
        if (!nodo) return 0;
        int hoy = (nodo->numAlumnos > limite) ? 1 : 0;
        return hoy + contarCursosMasQueHelper(nodo->siguiente, limite);
    }
};

/* ==========================
   Cola de Inscripciones (FIFO)
   Cada solicitud: estudiante, codigoCurso
   ========================== */

struct Solicitud {
    string estudiante;
    string codigoCurso;
    Solicitud* siguiente;
    Solicitud(const string& e, const string& c) : estudiante(e), codigoCurso(c), siguiente(nullptr) {}
};

class ColaInscripciones {
private:
    Solicitud* frente;
    Solicitud* fin;
public:
    ColaInscripciones() : frente(nullptr), fin(nullptr) {}
    ~ColaInscripciones() { vaciar(); }

    void encolar(const string& estudiante, const string& codigoCurso) {
        Solicitud* s = new Solicitud(estudiante, codigoCurso);
        if (!fin) {
            frente = fin = s;
        } else {
            fin->siguiente = s;
            fin = s;
        }
        cout << "Solicitud encolada.\n";
    }

    bool desencolar() {
        if (!frente) {
            cout << "Cola vacía.\n";
            return false;
        }
        Solicitud* temp = frente;
        frente = frente->siguiente;
        if (!frente) fin = nullptr;
        delete temp;
        cout << "Solicitud procesada (desencolada).\n";
        return true;
    }

    Solicitud* verFrente() { return frente; }

    void mostrarCola() {
        if (!frente) {
            cout << "Cola vacía.\n";
            return;
        }
        cout << "\n--- Cola de Inscripciones ---\n";
        Solicitud* cur = frente;
        while (cur) {
            cout << "Estudiante: " << cur->estudiante << " | Curso: " << cur->codigoCurso << "\n";
            cur = cur->siguiente;
        }
    }

    // Procesar una solicitud: intenta inscribir al estudiante en el curso (incrementa numAlumnos).
    // Devuelve true si se procesó (encontró el curso) y elimina la solicitud.
    bool procesarPrimera(ListaCursos& lista) {
        if (!frente) {
            cout << "No hay solicitudes.\n";
            return false;
        }
        string cod = frente->codigoCurso;
        Curso* curso = lista.buscarCurso(cod);
        if (!curso) {
            cout << "Curso con código " << cod << " no existe. Eliminando solicitud.\n";
            desencolar();
            return false;
        }
        curso->numAlumnos += 1;
        cout << "Inscripción aceptada: " << frente->estudiante << " en curso " << cod << ".\n";
        desencolar();
        return true;
    }

    void vaciar() {
        while (frente) {
            Solicitud* t = frente;
            frente = frente->siguiente;
            delete t;
        }
        fin = nullptr;
    }
};

/* ==========================
   Pila de Historial (LIFO)
   Guarda cursos modificados (por codigo)
   ========================== */

struct NodoHistorial {
    string codigoCurso;
    NodoHistorial* abajo;
    NodoHistorial(const string& c) : codigoCurso(c), abajo(nullptr) {}
};

class PilaHistorial {
private:
    NodoHistorial* tope;
public:
    PilaHistorial() : tope(nullptr) {}
    ~PilaHistorial() { vaciar(); }

    void apilar(const string& codigo) {
        NodoHistorial* n = new NodoHistorial(codigo);
        n->abajo = tope;
        tope = n;
        cout << "Historial: curso " << codigo << " apilado.\n";
    }

    bool desapilar() {
        if (!tope) {
            cout << "Historial vacío.\n";
            return false;
        }
        NodoHistorial* t = tope;
        tope = tope->abajo;
        cout << "Historial: desapilado " << t->codigoCurso << endl;
        delete t;
        return true;
    }

    string verTope() {
        if (tope) return tope->codigoCurso;
        return "";
    }

    void mostrar() {
        if (!tope) {
            cout << "Historial vacío.\n";
            return;
        }
        cout << "\n--- Historial de cursos modificados (tope -> base) ---\n";
        NodoHistorial* cur = tope;
        while (cur) {
            cout << cur->codigoCurso << "\n";
            cur = cur->abajo;
        }
    }

    void vaciar() {
        while (tope) {
            NodoHistorial* t = tope;
            tope = tope->abajo;
            delete t;
        }
    }
};

/* ==========================
   Plantilla Docente<T> y Planilla (almacena genericamente)
   ========================== */

template <typename T>
class Docente {
public:
    T nombre;
    T especialidad;
    T tipoContrato;
    int cursosAsignados;

    Docente(const T& n, const T& e, const T& t, int c)
        : nombre(n), especialidad(e), tipoContrato(t), cursosAsignados(c) {}

    void mostrar() const {
        cout << "Nombre: " << nombre
             << " | Especialidad: " << especialidad
             << " | Contrato: " << tipoContrato
             << " | CursosAsignados: " << cursosAsignados << "\n";
    }

    // Sobrecarga de operadores para comparación por cursosAsignados
    bool operator>(const Docente& otro) const {
        return this->cursosAsignados > otro.cursosAsignados;
    }
    bool operator<(const Docente& otro) const {
        return this->cursosAsignados < otro.cursosAsignados;
    }
    bool operator==(const Docente& otro) const {
        return this->cursosAsignados == otro.cursosAsignados;
    }
};

template <typename T>
class PlanillaDocente {
private:
    vector<Docente<T>*> lista; // almacenamos punteros para gestionar memoria manualmente
public:
    PlanillaDocente() {}
    ~PlanillaDocente() { liberar(); }

    void agregar(const T& nombre, const T& especialidad, const T& tipoContrato, int cursosAsignados) {
        Docente<T>* d = new Docente<T>(nombre, especialidad, tipoContrato, cursosAsignados);
        lista.push_back(d);
        cout << "Docente agregado a la planilla.\n";
    }

    bool eliminarPorNombre(const T& nombre) {
        for (size_t i = 0; i < lista.size(); ++i) {
            if (lista[i]->nombre == nombre) {
                delete lista[i];
                lista.erase(lista.begin() + i);
                cout << "Docente eliminado.\n";
                return true;
            }
        }
        cout << "Docente no encontrado.\n";
        return false;
    }

    void mostrar() {
        if (lista.empty()) {
            cout << "Planilla vacía.\n";
            return;
        }
        cout << "\n--- Planilla Docentes ---\n";
        for (auto d : lista) d->mostrar();
    }

    // Buscar el docente con mas cursos (ejemplo de uso de operador sobrecargado)
    Docente<T>* docenteConMasCursos() {
        if (lista.empty()) return nullptr;
        Docente<T>* mayor = lista[0];
        for (size_t i = 1; i < lista.size(); ++i) {
            if (*lista[i] > *mayor) mayor = lista[i];
        }
        return mayor;
    }

    void liberar() {
        for (auto p : lista) delete p;
        lista.clear();
    }
};

/* ==========================
   Funciones utilitarias de entrada
   ========================== */

void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int leerEnteroSeguro(const string& prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) {
            limpiarEntrada();
            return x;
        }
        cout << "Entrada inválida. Intente de nuevo.\n";
        limpiarEntrada();
    }
}

string leerLinea(const string& prompt) {
    cout << prompt;
    string s;
    getline(cin, s);
    return s;
}

/* ==========================
   Menús y manejo de cada módulo
   ========================== */

void menuCursos(ListaCursos& lista, PilaHistorial& historial) {
    int op;
    do {
        cout << "\n--- Módulo Cursos ---\n";
        cout << "1. Agregar curso\n";
        cout << "2. Buscar curso por código\n";
        cout << "3. Eliminar curso por código\n";
        cout << "4. Mostrar todos los cursos\n";
        cout << "5. Modificar curso (nombre/docente/alumnos)\n";
        cout << "0. Volver\n";
        op = leerEnteroSeguro("Opción: ");
        if (op == 1) {
            string nombre = leerLinea("Nombre del curso: ");
            string codigo = leerLinea("Código del curso: ");
            string docente = leerLinea("Docente asignado: ");
            int alumnos = leerEnteroSeguro("Número de alumnos: ");
            lista.agregarCurso(nombre, codigo, docente, alumnos);
            historial.apilar(codigo); // registro de modificación (creación)
        } else if (op == 2) {
            string codigo = leerLinea("Código a buscar: ");
            Curso* c = lista.buscarCurso(codigo);
            if (c) {
                cout << "Encontrado: " << c->nombre << " | Docente: " << c->docente << " | Alumnos: " << c->numAlumnos << "\n";
            } else cout << "No existe el curso.\n";
        } else if (op == 3) {
            string codigo = leerLinea("Código a eliminar: ");
            lista.eliminarCurso(codigo);
            // opcional: registrar eliminación en historial
            historial.apilar(codigo);
        } else if (op == 4) {
            lista.mostrarCursos();
        } else if (op == 5) {
            string codigo = leerLinea("Código del curso a modificar: ");
            Curso* c = lista.buscarCurso(codigo);
            if (!c) {
                cout << "Curso no encontrado.\n";
            } else {
                cout << "1) Cambiar nombre\n2) Cambiar docente\n3) Cambiar número de alumnos\n";
                int scelta = leerEnteroSeguro("Opción: ");
                if (scelta == 1) {
                    string nuevo = leerLinea("Nuevo nombre: ");
                    c->nombre = nuevo;
                } else if (scelta == 2) {
                    string nuevo = leerLinea("Nuevo docente: ");
                    c->docente = nuevo;
                } else if (scelta == 3) {
                    int na = leerEnteroSeguro("Nuevo número de alumnos: ");
                    c->numAlumnos = na;
                } else cout << "Opción inválida.\n";
                historial.apilar(codigo); // registro de modificación
                cout << "Curso modificado.\n";
            }
        } else if (op != 0) {
            cout << "Opción inválida.\n";
        }
    } while (op != 0);
}

void menuDocentes(PlanillaDocente<string>& planilla) {
    int op;
    do {
        cout << "\n--- Módulo Docentes (Planilla) ---\n";
        cout << "1. Agregar docente\n";
        cout << "2. Eliminar docente por nombre\n";
        cout << "3. Mostrar planilla\n";
        cout << "4. Mostrar docente con más cursos\n";
        cout << "0. Volver\n";
        op = leerEnteroSeguro("Opción: ");
        if (op == 1) {
            string nombre = leerLinea("Nombre: ");
            string especial = leerLinea("Especialidad: ");
            string contrato = leerLinea("Tipo de contrato: ");
            int cursos = leerEnteroSeguro("Cantidad de cursos asignados: ");
            planilla.agregar(nombre, especial, contrato, cursos);
        } else if (op == 2) {
            string nombre = leerLinea("Nombre a eliminar: ");
            planilla.eliminarPorNombre(nombre);
        } else if (op == 3) {
            planilla.mostrar();
        } else if (op == 4) {
            auto d = planilla.docenteConMasCursos();
            if (d) {
                cout << "Docente con más cursos:\n";
                d->mostrar();
            } else cout << "Planilla vacía.\n";
        } else if (op != 0) {
            cout << "Opción inválida.\n";
        }
    } while (op != 0);
}

void menuInscripciones(ColaInscripciones& cola, ListaCursos& lista, PilaHistorial& historial) {
    int op;
    do {
        cout << "\n--- Módulo Inscripciones (Cola FIFO) ---\n";
        cout << "1. Agregar solicitud de inscripción\n";
        cout << "2. Mostrar cola de solicitudes\n";
        cout << "3. Procesar primera solicitud (inscribir)\n";
        cout << "4. Desencolar (eliminar) primera solicitud sin procesar\n";
        cout << "0. Volver\n";
        op = leerEnteroSeguro("Opción: ");
        if (op == 1) {
            string estudiante = leerLinea("Nombre del estudiante: ");
            string codigo = leerLinea("Código del curso: ");
            cola.encolar(estudiante, codigo);
        } else if (op == 2) {
            cola.mostrarCola();
        } else if (op == 3) {
            bool success = cola.procesarPrimera(lista);
            if (success) {
                // registrar en historial que el curso cambió por nueva inscripción
                // tomar curso procesado (verTope no aplica), vamos a apilar el codigo procesado:
                // Como procesarPrimera desencola y no devuelve codigo, buscamos el efecto:
                // Para simplicidad, apilamos el código de la última solicitud procesada consultando lista (difícil),
                // en este diseño llamaremos encolar(procesar)->apilar antes de desencolar, pero ya procesado,
                // Aquí no tenemos el código (porque se eliminó). Omitimos la apilada aquí.
                // (Nota: en funciones anteriores al procesar, podría apilarse antes de procesar)
            }
        } else if (op == 4) {
            cola.desencolar();
        } else if (op != 0) {
            cout << "Opción inválida.\n";
        }
    } while (op != 0);
}

void menuHistorial(PilaHistorial& historial) {
    int op;
    do {
        cout << "\n--- Módulo Historial (Pila) ---\n";
        cout << "1. Mostrar historial\n";
        cout << "2. Desapilar (eliminar último registro)\n";
        cout << "3. Ver tope\n";
        cout << "0. Volver\n";
        op = leerEnteroSeguro("Opción: ");
        if (op == 1) {
            historial.mostrar();
        } else if (op == 2) {
            historial.desapilar();
        } else if (op == 3) {
            string t = historial.verTope();
            if (t.empty()) cout << "Historial vacío.\n";
            else cout << "Tope: " << t << "\n";
        } else if (op != 0) {
            cout << "Opción inválida.\n";
        }
    } while (op != 0);
}

void menuRecursividad(ListaCursos& lista) {
    int op;
    do {
        cout << "\n--- Módulo Recursividad ---\n";
        cout << "1. Calcular total de alumnos (recursivo)\n";
        cout << "2. Contar cursos con más de N alumnos (recursivo)\n";
        cout << "0. Volver\n";
        op = leerEnteroSeguro("Opción: ");
        if (op == 1) {
            int total = lista.totalAlumnosRec();
            cout << "Total de alumnos inscritos (suma recursiva): " << total << "\n";
        } else if (op == 2) {
            int limite = leerEnteroSeguro("Ingrese límite N: ");
            int cont = lista.contarCursosMasQue(limite);
            cout << "Cantidad de cursos con más de " << limite << " alumnos: " << cont << "\n";
        } else if (op != 0) {
            cout << "Opción inválida.\n";
        }
    } while (op != 0);
}

/* ==========================
   Menú Principal
   ========================== */

int main() {
    ListaCursos lista;
    ColaInscripciones cola;
    PilaHistorial historial;
    PlanillaDocente<string> planilla; // usamos string como tipo T para los campos textuales

    int opcion;
    cout << "=== SISTEMA DE GESTIÓN DE CURSOS UNIVERSITARIOS ===\n";
    do {
        cout << "\n--- Menú Principal ---\n";
        cout << "1. Módulo Cursos (Lista Dinámica)\n";
        cout << "2. Módulo Docentes (Planilla - Plantilla)\n";
        cout << "3. Módulo Inscripciones (Cola FIFO)\n";
        cout << "4. Módulo Historial (Pila LIFO)\n";
        cout << "5. Recursividad (Cálculos sobre cursos)\n";
        cout << "9. Mostrar todo (debug)\n";
        cout << "0. Salir\n";
        opcion = leerEnteroSeguro("Seleccione una opción: ");

        switch (opcion) {
            case 1:
                menuCursos(lista, historial);
                break;
            case 2:
                menuDocentes(planilla);
                break;
            case 3:
                menuInscripciones(cola, lista, historial);
                break;
            case 4:
                menuHistorial(historial);
                break;
            case 5:
                menuRecursividad(lista);
                break;
            case 9:
                cout << "\n--- Estado actual (Resumen) ---\n";
                lista.mostrarCursos();
                planilla.mostrar();
                cola.mostrarCola();
                historial.mostrar();
                break;
            case 0:
                cout << "Saliendo... liberando memoria.\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 0);

    // Destructores liberan memoria automáticamente al terminar:
    // lista.~ListaCursos(); planilla.~PlanillaDocente(); cola.~ColaInscripciones(); historial.~PilaHistorial();
    // (No llamar explícitamente destructores; se liberan al salir del scope.)

    cout << "Programa finalizado.\n";
    return 0;
}

