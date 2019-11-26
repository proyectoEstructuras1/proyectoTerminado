#ifndef PRODUCTO_H
#define PRODUCTO_H
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stdlib.h>

using namespace std;
class Producto
{
  private:
    string Nombre;
    int numero;
    float precio;
    void verifica(void);
public:
    Producto(void);
    Producto(string N, int n, float p);
    void pideDatos(void);
    void muestraDatos(void);
    string dameNombre(void);
    void modificaNombre(string N);
    int dameNumero(void);
    void modificaNumero(int n);
    float damePrecio(void);
    void modificaPrecio(float p);
    void modificaDatos(string N, int n, float p);
    void guardaLista(ofstream & salida);
    void cargaLista(ifstream& entrada);

};
istream& operator>>(istream& teclado, Producto& X);	
ostream& operator<<(ostream& monitor, Producto X);	
bool operator==(Producto Izquierdo, Producto Derecho);	
bool operator!=(Producto Izquierdo, Producto Derecho);
#endif // PRODUCTO_H
