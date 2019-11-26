#ifndef NODOA_H
#define NODOA_H
#include<iostream>
#include"producto.h"


using namespace std;
class NodoA
{
  private:

    NodoA* Izq;
    NodoA* Der;
    Producto dato;

public:

    NodoA(void);
    NodoA(Producto d, NodoA* i,NodoA* de);
    void muestraDato(void);
    void pideDatos(void);
    Producto dameDato(void);
    void modificaDato(Producto d);
    NodoA* dameIzq(void);
    void modificaIzq(NodoA* i);
    NodoA* dameDer(void);
    void modificaDer(NodoA* d);
};

#endif // NODOA_H

