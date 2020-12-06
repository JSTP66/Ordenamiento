/*
crear una lista doble que permita
insertar
eliminar
modificar repetidos
 
 a traves del uso del metodo de burbuja 
 para ordenar diferentes datos numericos
*/


#include<conio.h>
#include<iostream>


//estructura del nodo de la lista

struct nodo{
    int nro;
    struct nodo*sgte;
    
};

typedef struct nodo*TLista;

using namespace std;

//los metodos necesarios para el programa
void insertarAlInicio(TLista &, int);
void insertarAlFinal(TLista &, int);  //tarea
//insertarlo en una posicion en especifico
void insertarEnPosicion(TLista &, int, int);
void eliminarElemento(TLista &, int);
//para eliminar elementos repetidos
void eliminarRepetidos(TLista);  //tarea
void eliminarLista(TLista &);  //tarea
//metodo burbuja
void burbuja(TLista);
void imprimir(TLista, int);  //tarea :3
void modificar(TLista &, int, int);

//ahi lo hacen va ya me dio sueñito nwn

int main(){

    TLista lista = NULL;
    int opc, valor, pos;
    //elementos que se repita
    do{
        //aqui debe de estar el menu del programa
		cout<<"\n Elija el movimiento que desea realizar: ";
  	  	cout<<"\n 1.- Insertar al inicio";
  	 	cout<<"\n 2.- Insertar al final";
        cout<<"\n 3.- Insertar en posicion";
        cout<<"\n 4.- Eliminar elemento";
        cout<<"\n 5.- Eliminar repetidos";
  	 	cout<<"\n 6.- Eliminar lista";
        cout<<"\n 7.- Imprimir";
        cout<<"\n 8.- Modificar";
        cout<<"\n 9.- Burbuja";
        cout<<"\n 0.- Salir";
        cout<<"\n Seleccione una opcion ";
        cin>>opc;
        switch(opc){
            case 1:
            	cout<<"Ingrese el valor";
   				cin>>valor;
            	insertarAlInicio(lista, valor);
            break;
            case 2:
            	cout<<"ingrese valor a insertar al final: \n";
				cin>>valor;
				insertarAlFinal(lista,valor);
            	
			break;
            
            case 3:
            	cout<<"valor a insertar: \n";
 				cin>>valor;
 				cout<<"Posicion:\n ";cin>>pos;
 				insertarEnPosicion(lista,valor,pos);
            break;
            
            case 4:
            	cout<<endl<<"Elimina elemento :"<<endl;
        		cout<<"valor del elemento ";cin>>valor;
 				eliminarElemento(lista, valor);
            	
            break;
            
            case 5:
            	cout<<endl<<"..Eliminando"<<endl;
       			eliminarRepetidos(lista);
        break;
            break;
            
            case 6:
            	cout<<endl<<"..Elimina la lista "<<endl;
        		eliminarLista(lista);
            break;
            
            case 7:
            	cout<<endl<<"Listado \n"<<endl;
                imprimir(lista,valor) ;
            break;
            
            case 8:
            	cout<<"Ingrese la posicion a modificar:"<<endl;
       			cin>>pos;
       			cout<<"Ingrese el valor a ingresar:"<<endl;
       			cin>>valor;
       			modificar(lista,valor,pos);
            break;
            
            case 9:
            	 cout<<endl<<"Lista ordenada "<<endl;
 				 burbuja(lista);
 				 imprimir(lista, valor);
            break;
            default:
            cout<<"\nOpcion invalida\n";
        }

    }while(opc!=0);

}
	 
void insertarAlInicio(TLista &lista, int valor){
    TLista q;
    q = new(struct nodo);
    //apuntamos al inicio de la lista
    q->nro=valor;
    q->sgte=lista;
    lista=q; 
}

void insertarAlFinal(TLista &lista, int valor){
    //ahi lo terminan me dio mas sueñito
    TLista t, q=new(struct nodo);
q->nro=valor;
q->sgte=NULL;
if(lista==NULL)lista=q;
else {t=lista;
      while (t->sgte!=NULL) t=t->sgte;
      t->sgte=q;
      }
} 

void insertarEnPosicion(TLista &lista, int valor, int pos){
    TLista q, t;

    int i;

    q = new (struct nodo);
    q->nro=valor;

    //necesito saber donde esta la posicion antes o despues
    if(pos==1){
        q->sgte=lista;
        lista=q;
    }else{
        //entonces necesito otro n odo
        t = lista;
        for(i=1; t!=NULL; i++){
            //donde estoy
            if(pos==1){
                q->sgte=t->sgte;
                t->sgte=q;
                return;
            }
            t = t->sgte;
        }
    }
    //si me diste una posicion afuera del rango
    cout<<"Error la posicion es incorrecta"<<endl;
}


void eliminarElemento(TLista & lista, int valor){
    TLista q, ant;
    q=lista;

    while(q!=NULL){
        //primero necesitamos el valor que vamos a eliminar
        if(q->nro = valor){
            //tengo otra desicion donde diablos esta
            if(q==lista){
                lista = lista->sgte;

            }else{
                ant->sgte = q->sgte;
                delete(q);
                return;
            }
            
        }
        //ant->q;
        q=q->sgte;
    }
        
    
}

void modificar(TLista &lista, int v, int pos){
    TLista q, stge;
    q = lista;
    int i;
    for(i = 0; i<pos-1&&q->sgte!=NULL; i++){
        q = q->sgte;
        q->nro = v;
    }
}

void eliminarLista(TLista &lista)
{
TLista p;
while (lista!=NULL)
 { p=lista;
 lista=lista->sgte;
 delete(p);
 }
 }

void eliminarRepetidos(TLista lista)
{ TLista q,p,r,ant;
  int num;
  q=lista;
  while(q!=NULL)
  { num=q->nro;
    ant=q;
    r=q->sgte;
    while(r!=NULL)
    { if(num==r->nro)
      { ant->sgte=r->sgte;
      cout<<"Eliminando..."<<num<<endl;
      p=r;
      r=r->sgte;
      delete(p);
      }
    else { ant=r;
    r=r->sgte;
    }
    r=r->sgte;
    } //fin while
    q=q->sgte;
    } //fin while
  }
  
void imprimir(TLista lista, int valor)
{ int n=1;

while (lista!=NULL)
   {
   valor=valor+1;
   cout<<valor-2<<endl;
   lista=lista->sgte;
   
cout<<endl;
}
}

void burbuja(TLista lista){
    TLista actual, siguiente, marca;
    int i;
    marca = NULL;
    while(marca!=lista->sgte){
        actual=lista;
        siguiente=actual->sgte;
        //recorrer todos los elementos
        while(siguiente!=marca){
            //la comparacion para el ordenamiento
            if(actual->nro > siguiente->nro){
                i = siguiente->nro;
                siguiente->nro = actual->nro;
                actual->nro = i;
            }
            actual = actual->sgte;
            siguiente = actual->sgte;
        }
        marca=actual;
    }
}

