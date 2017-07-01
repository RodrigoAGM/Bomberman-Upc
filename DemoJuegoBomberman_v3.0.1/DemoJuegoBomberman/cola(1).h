#ifndef __COLA_H__
#define __COLA_H__
#include "Nodo.h"

template <class T>
class Cola{
public:
	Nodo<T>*inicio;
	Cola(){ inicio == nullptr; }

	void Insertar(T v);
	void Elimina();
};
template <class T>
void Cola<T>::Insertar(T v){
	Nodo<T>*nodo;
	nodo = new Nodo<T>(v);
	if (inicio == nullptr){ inicio = v; }
	else{
		Nodo<T>*aux = inicio;
		while (aux->siguiente!=nullptr)
		{
			aux = aux->siguiente;
		}
		aux->siguiente = nodo;
	}
}

template <class T>
void Cola<T>::Elimina(){

	if (inicio != nullptr){
		Nodo<T>*aux = inicio;
		inicio = aux->siguiente;
	}
	else return;
}


#endif 