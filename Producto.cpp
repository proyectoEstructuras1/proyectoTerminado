#include "Producto.h"

void Producto::verifica(void)
{
if (this->numero<0)
{
numero=0;
float p;
cout<<"numero invalido"<<endl;
cout<<"cual es el numero:";cin>> p;
modificaNumero(p);
verifica();
}
if(this->precio<0)
{
precio=0.0;
float p;
cout<<"precio invalido"<<endl;
cout<<"cual es el precio:";cin>> p;
modificaPrecio(p);
verifica();
}

}
Producto::Producto(void)
{
Nombre="";
numero=0;
precio=0.0;

verifica();

}
Producto::Producto(string N, int n, float p)
{
this->Nombre=N;
this->numero=n;
this->precio=p;

verifica();
}
void Producto::pideDatos(void)
{
cout<<"Nombre del producto:";getline(cin,Nombre);
cout<<endl<<"Numero de producto:";cin>>this->numero;
cout<<endl<<"Precio del producto:";cin>>this->precio;
verifica();
}
void Producto::muestraDatos(void)
{
cout<<"--------------"<<endl
    <<"Producto:"<<this->Nombre<<endl
    <<"Numero:"<<this->numero<<endl
    <<"Precio:"<<this->precio<<endl
    <<"--------------"<<endl;
}

string Producto::dameNombre(void)
{
return this->Nombre;
}

void Producto::modificaNombre(string N)
{
this->Nombre=N;
}

int Producto::dameNumero(void)
{
return this->numero;
}

void Producto::modificaNumero(int n)
{
this->numero=n;
verifica();
}

float Producto::damePrecio(void)
{
return this->precio;
}

void Producto::modificaPrecio(float p)
{
this->precio=p;
verifica();
}

void Producto::modificaDatos(string N, int n, float p)
{
this->Nombre=N;
this->numero=n;
this->precio=p;
verifica();
}

void Producto::guardaLista(ofstream& salida)
{
salida<<Nombre<<","<<numero<<","<<precio<<endl;
}

void Producto::cargaLista(ifstream& entrada)
{
string datos;
string atributo;

getline(entrada,datos);

stringstream ss(datos);

getline(ss,atributo,',');
Nombre=atributo;

getline(ss,atributo,',');
numero=atoi(atributo.c_str());

getline(ss,atributo);
precio=atof(atributo.c_str());
}

istream& operator>>(istream& teclado, Producto& X)
{
    X.pideDatos();
    return teclado;
}

ostream& operator<<(ostream& monitor, Producto X){
    X.muestraDatos();
    return monitor;
}
bool operator==(Producto Izquierdo, Producto Derecho){
    return
            Izquierdo.dameNombre() == Derecho.dameNombre()
            &&
            Izquierdo.dameNumero() == Derecho.dameNumero()
            &&
            Izquierdo.damePrecio() == Derecho.damePrecio()
    ;
}
bool operator!=(Producto Izquierdo, Producto Derecho){
    return
            Izquierdo.dameNombre() != Derecho.dameNombre()
            ||
            Izquierdo.dameNumero() != Derecho.dameNumero()
            ||
            Izquierdo.damePrecio() != Derecho.damePrecio()
    ;
}
