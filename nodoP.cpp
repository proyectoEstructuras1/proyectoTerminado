#include "nodoP.h"

NodoP::NodoP(void){
    this->sig=NULL;
    this->pre=NULL;
}
NodoP::NodoP(Producto d, NodoP* s,NodoP* p){
    this->dato=d;
    this->sig=s;
    this->pre=p;
}
void NodoP::muestraDato(void){
    this->dato.muestraDatos();
}
void NodoP::pideDatos(void){
    this->dameDato().pideDatos();
}
Producto NodoP::dameDato(void){
    return this->dato;
}
void NodoP::modificaDato(Producto d){
    this->dato=d;
}
NodoP* NodoP::dameSig(void){
    return this->sig;
}
void NodoP::modificaSig(NodoP* s){
    this->sig=s;
}
NodoP* NodoP::damePre(void){
    return this->pre;
}
void NodoP::modificaPre(NodoP* p){
    this->pre=p;
}

