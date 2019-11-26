#ifndef LISTAP_H
#define LISTAP_H
#include"nodoP.h"
#include <iostream>

using namespace std;
class listaP
{
   private:

    NodoP* ini;
    NodoP* fin;
    NodoP* buscaNodo(int d);

   public:
    listaP(void);
    ~listaP(void);
    bool estaVacia(void);
    void insertaNodo(Producto p);
    bool eliminaNodo(int p);
    bool buscaNodo(void);
    void muestraIniFin(void);
    void muestraFinIni(void);
    void eliminaLista(void);
    void cargaLista(void);
    void guardaLista(void);


};


#endif // LISTAP_H
