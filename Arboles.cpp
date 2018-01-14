/*
Estructura de Datos
Auth0r: Krasn4ck
 Proyecto: Arboles Binarios.
 V. 1.3.43
 */
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct Nodo
{
	int n_control;
	string nombre;
	Nodo *der;
	Nodo *izq;	
	Nodo *padre;
};
//funciones prototipo
Nodo *crearnodo(int, string, Nodo *);
Nodo *arbol=NULL;
void menu();
void insertarnodo(Nodo *&, int, string,Nodo *);
bool consultarnodo(Nodo *,int);
void mostrarnodo(Nodo *, int);
int modificarnodo(Nodo *, int);
void eliminarnodo(Nodo *, int);
void eliminar(Nodo *);
Nodo *minimo(Nodo *);
void reemplazo(Nodo *, Nodo *);
void destruirnodo(Nodo *);
string nom;
int conta=0;
int main()
{
	menu();
	getch();
	return 0;
}
void menu()//menu del programa
{
	int opc,dato;
	do
	{
		system("cls");
		cout<<"+-----Menu------+";
		cout<<"\n| 1.- Insertar  |";
		cout<<"\n| 2.- Consultar |";
		cout<<"\n| 3.- Mostrar   |";
		cout<<"\n| 4.- Modificar |";
		cout<<"\n| 5.- Bajas     |";
		cout<<"\n| 6.- Salir     |";
		cout<<"\n+---------------+";
		cout<<"\nOpcion:";
		cin>>opc;
		switch(opc)
		{
			case 1:
				system("cls");
				cout<<"";
				cout<<"\nIngrese su No.de Control:";
				cin>>dato;
				cout<<"\nIngrese su Nombre:";
				cin>>nom;
				insertarnodo(arbol,dato,nom,NULL);
				cout<<"\n Dato Guardado\n";
				system("pause");
			break;
			case 2:
					system("cls");
					cout<<"Consultas";
					cout<<"\nIngrese su No.de Control:";
					cin>>dato;
					if(consultarnodo(arbol,dato)==true)
					{
						cout<<"\nElemento Encontrado "<<dato<<" en el arbol";
					}
					else
					{
						cout<<"\nElemento no Encontrado";
					}
					cout<<"\n";
					system("pause");
			break;
			case 3:
				system("cls");
				cout<<"Mostrar Arbol"<<endl;
				mostrarnodo(arbol,conta);
				cout<<"\n";
				system("pause");
			break;
			case 4:
					system("cls");
					cout<<"Modificar";
					cout<<"\nIngrese su No.de Control:";
					cin>>dato;
					modificarnodo(arbol,dato);
					cout<<"\n";
					system("pause");
			break;
			case 5:
				system("cls");
				cout<<"Eliminar (Cualquier Campo)";
				cout<<"\n Ingrese el No.de Control:";
				cin>>dato;
				eliminarnodo(arbol,dato);
				cout<<"\n";
				system("pause");
			break;
			case 6:
				system("exit");
			break;
			default:
				system("cls");
				cout<<"Esa opcion no existe";
			break;
		}
	}while(opc!=8);
	
}
Nodo *crearnodo(int n, string name,Nodo *padre )
{
	Nodo *n_nodo= new Nodo();
	n_nodo->n_control=n;
	n_nodo->nombre=name;
	n_nodo->der=NULL;
	n_nodo->izq=NULL;
	n_nodo->padre=padre;
	return n_nodo;
}
void insertarnodo(Nodo *&arbol, int n, string name, Nodo *padre)
{
	if(arbol==NULL)
	{
		Nodo *n_nodo=crearnodo(n,name,padre);
		arbol=n_nodo;
	}
	else
	{
		int valor=arbol->n_control;
		if(n<valor)
		{
			insertarnodo(arbol->izq,n,name,arbol);
		}
		else
		{
			insertarnodo(arbol->der,n,name,arbol);
		}
	}
}
bool consultarnodo(Nodo *arbol, int n)
{
	if(arbol==NULL)
	{
		return false;
	}
	else if(arbol->n_control==n)
	{
		return true;		
	}
	else if(n<arbol->n_control)
	{
		return consultarnodo(arbol->izq,n);
	}
	else 
	{
		return consultarnodo(arbol->der,n);
	}
}
void mostrarnodo(Nodo *arbol,int cont)
{
	if(arbol==NULL)
	{
		return;
	}
	else
	{
		mostrarnodo(arbol->der,cont+1);
		for(int i=0;i<cont;i++)
		{
			cout<<"   ";
		}
		cout<<arbol->n_control<<" "<<arbol->nombre<<endl;
		mostrarnodo(arbol->izq,cont+1);
	}
}
int modificarnodo(Nodo *arbol,int n)
{//modificacion de la variable que contiene la estrucutura
		if(arbol==NULL)
	{
		cout<<"lista vacia";
	}
	else if(arbol->n_control==n)
	{
		system("cls");
		cout<<"Reescriba el dato:";
		cin>>arbol->nombre;
	}
	else if(n<arbol->n_control)
	{
		return modificarnodo(arbol->izq,n);
	}
	else 
	{
		return modificarnodo(arbol->der,n);
	}
}
void eliminarnodo(Nodo*arbol,int n)
{//eliminacion del nodo
	if(arbol==NULL)
	{
		return;
	}
	else if(n<arbol->n_control)//si el valor es menor buscas por la izquierda
	{
		eliminarnodo(arbol->izq,n);
	}
	else if(n>arbol->n_control)//si el valor es mayor buscar por la derecha
	{
		eliminarnodo(arbol->der,n);
	}
	else
	{
		eliminar(arbol);
	}
	//cout<<"\nDato eliminado";
}
Nodo *minimo(Nodo *arbol)
{
	if(arbol==NULL)
	{
		return NULL;
	}
	if(arbol->izq)
	{
		return minimo(arbol->izq);
	}
	else
	{
		return arbol;
	}
}
//funcion para reemplazar dos nodos
void reemplazo(Nodo *arbol, Nodo *n_nodo)
{
	if(arbol->padre)
	{
		if(arbol->n_control==arbol->padre->izq->n_control)
		{
			arbol->padre->izq=n_nodo;
		}
		else if(arbol->n_control==arbol->padre->der->n_control)
		{
			arbol->padre->der=n_nodo;
		}
	}
	if(n_nodo)
	{
		n_nodo->padre=arbol->padre;
	}
}
void destruirnodo(Nodo *nodo)
{//destruciion del nodo definitiva
	nodo->izq=NULL;
	nodo->der=NULL;
	delete nodo;
}
void eliminar(Nodo *elnodo)
{
	if(elnodo->izq&&elnodo->der)
	{
		Nodo *menor=minimo(elnodo->der);
		elnodo->n_control=menor->n_control;
		eliminar(menor);
	}
	else if(elnodo->izq)
	{
		reemplazo(elnodo,elnodo->izq);
		destruirnodo(elnodo);
	}
	else if(elnodo->der)
	{
		reemplazo(elnodo, elnodo->der);
		destruirnodo(elnodo);
	}
	else
	{
		reemplazo(elnodo,NULL); 
		destruirnodo(elnodo);
	}
}
