#include "Lista.h"
#include <cassert>

Lista::Lista() {
    _primero = nullptr;
    _ultimo = nullptr;
    _size = 0;
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    copiarNodos(l);
    *this = l;
    _size = longitud();

}

Lista::~Lista() {
    //destruirNodos();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    destruirNodos();
    copiarNodos(aCopiar);
    return *this;
}
//Modifico la del ejemplo para que me sirva en doble enlazada
void Lista::copiarNodos(const Lista &l) {
    Nodo* actual = l._primero;
    while (actual != nullptr) {
        agregarAtras(actual->valor);
        actual = actual->siguiente;
    }
}
void Lista::destruirNodos() {
    Nodo* actual = _primero;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    _primero = nullptr;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    if(longitud()==0){
        _primero = nuevo;
        _ultimo = nuevo;
        nuevo ->anterior = nullptr;
        nuevo ->siguiente = nullptr;
    } else{
        nuevo ->siguiente = _primero;
        _primero->anterior = nuevo;
        _primero = nuevo;
        nuevo ->anterior = nullptr;

    }
    _size++;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    if(longitud()==0){
        _primero = nuevo;
        _ultimo = nuevo;
        nuevo ->anterior = nullptr;
        nuevo ->siguiente = nullptr;
    } else{
        _ultimo->siguiente = nuevo;
        _ultimo = nuevo;
    }
    _size++;
}

void Lista::eliminar(Nat i) {
   Nodo* actual = _primero;
   for (int j = 0; j < i; ++j) {
       actual = actual -> siguiente;
   }
   if(actual -> anterior == nullptr){
       _primero = actual-> siguiente;
       (actual -> siguiente) -> anterior = nullptr;
   } else if (actual ->siguiente == nullptr){
       (actual -> anterior) -> siguiente = nullptr;
       _ultimo = actual-> anterior;
   } else{
       (actual -> anterior) -> siguiente = actual-> siguiente;
       (actual -> siguiente) -> anterior = actual-> anterior;
   }
   delete actual;
    _size--;
}

int Lista::longitud() const {
    return _size;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* nuevo = _primero;
    for (int i = 1; i <= i; i++) {
        nuevo = nuevo-> siguiente;
    }
    return nuevo-> valor; //Desreferencia el puntero al valor y da el valor
}

int& Lista::iesimo(Nat i) {
    Nodo* nuevo = _primero;
    for (int j = 1; j <= i; j++) {
        nuevo = nuevo-> siguiente;
    }
    return (nuevo-> valor); //Desreferencia el puntero al valor y da el valor
}

void Lista::mostrar(ostream& o) {
    // Completar
}
