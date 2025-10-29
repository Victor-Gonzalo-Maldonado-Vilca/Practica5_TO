#ifndef PILA_H
#define PILA_H

#include <iostream>
using namespace std;

template <class T>
class Pila {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
    };

    Nodo* cima;   // Último elemento agregado
    int tamanio;  // Número de elementos

public:
    Pila() : cima(nullptr), tamanio(0) {}
    ~Pila();

    void apilar(const T& valor);   // Push
    T desapilar();                 // Pop
    bool estaVacia() const;        // Verifica si está vacía
    void mostrar() const;          // Muestra el contenido
};

// Destructor: libera memoria
template <class T>
Pila<T>::~Pila() {
    while (!estaVacia()) {
        desapilar();
    }
}

// Agregar elemento (Push)
template <class T>
void Pila<T>::apilar(const T& valor) {
    Nodo* nuevo = new Nodo(valor);
    nuevo->siguiente = cima;
    cima = nuevo;
    tamanio++;
}

// Eliminar elemento (Pop)
template <class T>
T Pila<T>::desapilar() {
    if (estaVacia()) {
        throw runtime_error("La pila está vacía");
    }
    Nodo* temp = cima;
    T valor = temp->dato;
    cima = cima->siguiente;
    delete temp;
    tamanio--;
    return valor;
}

// Verificar si está vacía
template <class T>
bool Pila<T>::estaVacia() const {
    return cima == nullptr;
}

// Mostrar elementos de la pila
template <class T>
void Pila<T>::mostrar() const {
    Nodo* actual = cima;
    cout << "Historial de acciones (últimas primero):" << endl;
    while (actual != nullptr) {
        cout << "- " << actual->dato << endl;
        actual = actual->siguiente;
    }
}

#endif
