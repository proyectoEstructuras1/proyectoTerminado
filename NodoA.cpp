#include "NodoA.h"

NodoA::NodoA(void)
{
this->Izq=NULL;
this->Der=NULL;

}
NodoA::NodoA(Producto d, NodoA* i,NodoA* de)
{
this->dato=d;
this->Izq=i;
this->Der=de;

}
void NodoA::muestraDato(void)
{

this->dato.muestraDatos();

}
void NodoA::pideDatos(void)
{
this->dameDato().pideDatos();

}
Producto NodoA::dameDato(void)
{
 return this->dato;

}
void NodoA::modificaDato(Producto d)
{
this->dato=d;

}
NodoA* NodoA::dameIzq(void)
{
return this->Izq;

}
void NodoA::modificaIzq(NodoA* i)
{

this->Izq=i;

}
NodoA* NodoA::dameDer(void)
{
    return this->Der;

}
void NodoA::modificaDer(NodoA* d)
{
    this->Der=d;

}

