#include "listaP.h"

listaP::listaP(void)
{

ini=NULL;
fin=NULL;

}
listaP::~listaP(void)
{
    cout<<endl<<endl<<"lista eliminada"<<endl;
    eliminaLista();


}
bool listaP::estaVacia(void)
{
if (ini==NULL&&fin==NULL)
    return true;
else
    return false;

}
void listaP::insertaNodo(Producto p)
{
    if(estaVacia())
        {
        ini= new NodoP(p,NULL,NULL);
         fin= ini;
        }
    else if(p.dameNumero()<ini->dameDato().dameNumero())
        {
        ini->modificaPre(new NodoP(p,ini,NULL));
        ini=ini->damePre();
        }
    else if(p.dameNumero()>fin->dameDato().dameNumero())
    {
        fin->modificaSig(new NodoP(p,NULL,fin));
        fin=fin->dameSig();

    }
    else
    {
        NodoP* a1=ini,* a2=fin;

        while(p.dameNumero()>=a1->dameDato().dameNumero()&& p.dameNumero()<=a2->dameDato().dameNumero())
        {
            a1=a1->dameSig();
            a2=a2->damePre();

        }
       if( a1==a2 && p.dameNumero()<=a1->dameDato().dameNumero() )
        {
            a2=a1->damePre();

       a2->modificaSig(new NodoP(p,a1,a2));
       a1->modificaPre(a2->dameSig());

        }
        else if( a1==a2 && p.dameNumero()>a1->dameDato().dameNumero() )
        {
            a1=a2->dameSig();
       a2->modificaSig(new NodoP(p,a1,a2));
       a1->modificaPre(a2->dameSig());


        }
        else if(a1->dameSig()==a2 && p.dameNumero() >= a1->dameDato().dameNumero() && p.dameNumero() <= a2->dameDato().dameNumero())
        {
            a1->modificaSig(new NodoP(p,a2,a1));
            a2->modificaPre(a1->dameSig());

        }
        else if(p.dameNumero() <= a1->dameDato().dameNumero())
        {

        a2=a1->damePre();
               a2->modificaSig(new NodoP(p,a1,a2));
       a1->modificaPre(a2->dameSig());

        }
        else{
                a1=a2->dameSig();
       a2->modificaSig(new NodoP(p,a1,a2));
       a1->modificaPre(a2->dameSig());

        }



    }


}
bool listaP::eliminaNodo(int p)
{
    if(!estaVacia())
    {NodoP *aux1;
    if(ini->dameDato().dameNumero()==p)
    {
        aux1=ini;
        ini=ini->dameSig();
        ini->modificaPre(NULL);
        aux1->dameDato().muestraDatos();
        delete aux1;
        return true;

    }
    else if(fin->dameDato().dameNumero()==p)
    {
         aux1=fin;
        fin=fin->damePre();
        fin->modificaSig(NULL);
        aux1->dameDato().muestraDatos();
        delete aux1;
        return true;

    }else
    {
    aux1=buscaNodo(p);
    if(aux1!=NULL)
    {
       NodoP* aux=aux1->damePre();

       aux->modificaSig(aux1->dameSig());
       aux->dameSig()->modificaPre(aux);
       aux1->dameDato().muestraDatos();
       delete aux1;
       return true;

    }
    return false;
    }
    } return false;
}
bool listaP::buscaNodo(void)
{
    int d;
    NodoP* a;
    cout<<"Que numero de producto busca? ";cin>>d;
    a=buscaNodo(d);
    if(a!=NULL)
    {
    a->dameDato().muestraDatos();
    return a != NULL;
    }
    else
    return false;



}
NodoP* listaP::buscaNodo(int d)
{
   if(!estaVacia())
    {
    NodoP* aux1=ini,* aux2=fin;
    while(aux1!=aux2->damePre()&&aux1!=aux2)
    {
        if(aux1->dameDato().dameNumero()==d)
            return aux1;
       else  if(aux2->dameDato().dameNumero()==d)
            return aux2;

        aux1=aux1->dameSig();
        aux2=aux2->damePre();

    }
            if(aux1->dameDato().dameNumero()==d)
            return aux1;
        else if(aux2->dameDato().dameNumero()==d)
            return aux2;

    }
    return NULL;


}
void listaP::muestraIniFin(void)
{
NodoP* aux=ini;
while(aux!=NULL)
{
    aux->dameDato().muestraDatos();
    aux=aux->dameSig();

}


}
void listaP::muestraFinIni(void)
{
NodoP* aux=fin;
while(aux!=NULL)
{
    aux->dameDato().muestraDatos();
    aux=aux->damePre();

}

}
void listaP::eliminaLista(void)
{
if(!estaVacia())
{

    NodoP* aux1=ini;
    NodoP* aux2=fin;
    while(aux1!=aux2->damePre()&& aux1!=aux2)
    {

        ini=ini->dameSig();
        aux1->dameDato().muestraDatos();

        delete aux1;
        aux1=ini;

        fin=fin->damePre();

        aux2->dameDato().muestraDatos();
        delete aux2;
        aux2=fin;



    }
    if(aux1==aux2->damePre())
    {

    aux1->dameDato().muestraDatos();
       delete aux1;
    aux2->dameDato().muestraDatos();
      delete aux2;
      ini=NULL;
      fin=ini;


    }
    else
    {
        aux1->dameDato().muestraDatos();
        delete aux1;

        ini=NULL;
        fin=ini;
    }


}


}
void listaP::cargaLista(void)
{
    Producto a;

    ifstream desdeArchivo("carga.txt");


    while (!desdeArchivo.eof())
    {
    a.cargaLista(desdeArchivo);
    insertaNodo(a);


    }
    desdeArchivo.close();

}
void listaP::guardaLista(void)
{
if(ini!=NULL)
{
    ofstream haciaArchivo("guarda.txt");
    NodoP* aux=ini;
    while (aux!=NULL)
    {
       aux->dameDato().guardaLista(haciaArchivo);
       aux=aux->dameSig();

    }

}

}
