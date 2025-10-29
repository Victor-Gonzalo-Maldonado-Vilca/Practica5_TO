#ifndef ESTRUCTURAS_DINAMICAS_H
#define ESTRUCTURAS_DINAMICAS_H

#include <iostream>
#include <stdexcept>
using namespace std;

// ==================== COLA (FIFO) - Para Sistema de Turnos ====================
template <class T>
class Cola {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
    };
    
    Nodo* frente;
    Nodo* final;
    int tamanio;

public:
    Cola() : frente(nullptr), final(nullptr), tamanio(0) {}
    
    ~Cola() {
        while (!estaVacia()) {
            eliminar();
        }
    }
    
    // Agregar elemento al final (encolar)
    void agregar(const T& elemento) {
        Nodo* nuevoNodo = new Nodo(elemento);
        
        if (estaVacia()) {
            frente = final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
        tamanio++;
    }
    
    // Eliminar elemento del frente (desencolar)
    T eliminar() {
        if (estaVacia()) {
            throw runtime_error("Cola vacía");
        }
        
        T valor = frente->dato;
        Nodo* temp = frente;
        frente = frente->siguiente;
        
        if (frente == nullptr) {
            final = nullptr;
        }
        
        delete temp;
        tamanio--;
        return valor;
    }
    
    // Ver el frente sin eliminar
    T verFrente() const {
        if (estaVacia()) {
            throw runtime_error("Cola vacía");
        }
        return frente->dato;
    }
    
    void mostrar() const {
        if (estaVacia()) {
            cout << "Cola de turnos vacía" << endl;
            return;
        }
        
        cout << "Cola de turnos: [ ";
        Nodo* actual = frente;
        int pos = 1;
        while (actual != nullptr) {
            cout << pos << ":" << actual->dato->getNombre() << " ";
            actual = actual->siguiente;
            pos++;
        }
        cout << "]" << endl;
    }
    
    bool estaVacia() const {
        return frente == nullptr;
    }
    
    int obtenerTamanio() const {
        return tamanio;
    }
};

// Estructura para registrar acciones en el historial
struct AccionBatalla {
    string descripcion;
    int turno;
    
    AccionBatalla(string desc = "", int t = 0)
        : descripcion(desc), turno(t) {}
    
    friend ostream& operator<<(ostream& os, const AccionBatalla& a) {
        os << "[Turno " << a.turno << "] " << a.descripcion;
        return os;
    }
};

#endif
