#ifndef NODOP_H
#define NODOP_H
#include<Producto.h>

class NodoP{
private:

    NodoP* sig;
    NodoP* pre;
    Producto dato;

public:

    NodoP(void);
    NodoP(Producto d, NodoP* s,NodoP* p);
    void muestraDato(void);
    void pideDatos(void);
    Producto dameDato(void);
    void modificaDato(Producto d);
    NodoP* dameSig(void);
    void modificaSig(NodoP* s);
    NodoP* damePre(void);
    void modificaPre(NodoP* p);
};

#endif // NODOP_H

