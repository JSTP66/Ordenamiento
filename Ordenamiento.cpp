#include<iostream>
#include<string.h>
#include<conio.h>

#define MAX 50
struct fecha
 {
  char dia[3];
  char mes[3];
  char annio[5];

 };
 
struct nombrec{
	char apellido[MAX];
    char nombre[MAX];
};

struct codigoc{
	char codigo[9];
};
struct trabajador
 {
  struct fecha fecnac;
  struct nombrec nom;
  struct codigoc cod;
  

 };
 
 using namespace std;

 void leerpersonal(int,struct trabajador[]) ;
 void ordenaxfecha(int,struct trabajador[]) ;
 void ordenaxnombre(int,struct trabajador[]) ;
 void ordenaxcodigo(int,struct trabajador[]) ; 
 void listado(int,struct trabajador[]) ;
 int bBinariafecha(int,struct trabajador[],struct fecha) ;
 int bBinarianombre(int,struct trabajador[],struct nombrec) ;
 int bBinariacodigo(int,struct trabajador[],struct codigoc) ;


int main(void)
 {int n,pos,opc ;
struct fecha f;
struct nombrec t; 
struct codigoc c;                                                                              
struct trabajador x[MAX] ;
 


  do{
  	    cout<<"\n Elija el movimiento que desea realizar:";
  	 	cout<<"\n 1.- Realizar registro de datos";
  	 	cout<<"\n 2.- Ordenamiento de datos por fecha";
        cout<<"\n 3.- Ordenamiento de datos por nombre";
        cout<<"\n 4.- Ordenamiento de datos por codigo";
        cout<<"\n 0.- Salir";
        cout<<"\n Seleccione una opcion ";
        cin>>opc;
        switch (opc)
        {
        	case 1:
        		 cout<<"Ingresa el numero de trabajadores:" ;cin>>n ;
                 leerpersonal(n,x) ;
        	break;
        	case 2:
        		ordenaxfecha(n,x) ;
 				listado(n,x) ;
        	break;
        	case 3:
        		ordenaxnombre(n,x) ;
        		listado(n,x) ;
   				 
        	break;
            case 4:
            	ordenaxcodigo(n,x) ;
        		listado(n,x) ;
            break;
        default:
            cout<<"\nOpcion invalida\n";
        }

    }while(opc!=0);
 
 }


 void leerpersonal(int n,struct trabajador x[])
 {for(int i=0;i<n;i++)
 {cout<<"Ingresa el codigo:";cin>>x[i].cod.codigo;
 cout<<"Ingresa el apellido:";cin>>x[i].nom.apellido;
 cout<<"Ingresa el nombre:";cin>>x[i].nom.nombre;
 cout<<"Ingresa el dia nacimiento:";cin>>x[i].fecnac.dia;
 cout<<"Ingresa el mes nacimiento:";cin>>x[i].fecnac.mes;
 cout<<"Ingresa el annio nacimiento:";cin>>x[i].fecnac.annio;
 cout<<endl;
 }
}
 void ordenaxfecha(int n,struct trabajador x[])
 {
 struct trabajador temp;
 char f1[9],f2[9];
 for(int i=1;i<n;i++){
 for(int j=n-1;j>=1;j--)
 {strcpy(f1,"");strcpy(f2,"");
 strcat(f1,x[j-1].fecnac.annio);
 strcat(f1,x[j-1].fecnac.mes);
 strcat(f1,x[j-1].fecnac.dia);
 strcat(f2,x[j].fecnac.annio);
 strcat(f2,x[j].fecnac.mes);
 strcat(f2,x[j].fecnac.dia);
if(strcmp(f1,f2)>0)
{temp=x[j-1];
x[j-1]=x[j];
x[j]=temp;
}
}
}
}

void ordenaxnombre(int n,struct trabajador x[])
{
struct trabajador temp;
 char f1[9],f2[9];
 for(int i=1;i<n;i++){
 for(int j=n-1;j>=1;j--)
 {strcpy(f1,"");strcpy(f2,"");
 strcat(f1,x[j-1].nom.apellido);
 strcat(f1,x[j-1].nom.nombre);
 strcat(f2,x[j].nom.apellido);
 strcat(f2,x[j].nom.nombre);
if(strcmp(f1,f2)>0)
{temp=x[j-1];
x[j-1]=x[j];
x[j]=temp;
}
}
}
}

void ordenaxcodigo(int n,struct trabajador x[]){
 struct trabajador temp;
 char f1[9],f2[9];
 for(int i=1;i<n;i++){
 for(int j=n-1;j>=1;j--)
 {strcpy(f1,"");strcpy(f2,"");
 strcat(f1,x[j-1].cod.codigo);
 strcat(f2,x[j].cod.codigo);
if(strcmp(f1,f2)>0)
{temp=x[j-1];
x[j-1]=x[j];
x[j]=temp;

}
}
}
}



void listado(int n,struct trabajador x[])
{
cout<<endl<<"listado de empleados.-"<<endl;
for(int i=0;i<n;i++){
cout<<x[i].cod.codigo<<"\t"
<<x[i].nom.apellido<<"\t"
<<x[i].nom.nombre<<"\t"
<<x[i].fecnac.dia
<<"/"<<x[i].fecnac.mes<<"/"
<<x[i].fecnac.annio
<<endl;
cout<<endl;
}
}

