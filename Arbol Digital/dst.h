#ifndef DST_H
#define DST_H
// agregamos node.h
#include <iostream>
#include <cstdlib>
#include "node.h"

using namespace std;

class DST // clases principales
{
public: // principales funcionalidades
	void find(int, node **, node **);
	void insert(node * tree, node * newnode); // creamos 2 punteros
	void deletet(int);
	void case_a(node *, node *);
	void case_b(node *, node *);
	void case_c(node *, node *);

	void display(node *, int);
	DST()// comprueba si la raiz es nula
	{
		root = NULL;
	}
};

/*metodo para encontrar el valor*/
/*luego de encontrarlo sera envialo a delete para ser borrado*/
void DST::find(int item, node **par, node **loc)
{
	node *ptr, *ptrsave;
	if (root == NULL) // si la raiz esta vacia
	{
		*loc = NULL;
		*par = NULL;
		return; //retorno
	}
	if (item == root->info) // si es igual a la raiz
	{
		*loc = root; // root=5 y item =5
		*par = NULL;
		return;
	}
	if (item < root->info) // si es menor 
		ptr = root->left; // es menor
	else
		ptr = root->right; // se dirige hacia la derecha
	ptrsave = root;
	while (ptr != NULL)
	{
		if (item == ptr->info)
		{
			*loc = ptr;
			*par = ptrsave;
			return;
		}
		ptrsave = ptr;
		if (item < ptr->info)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	*loc = NULL;
	*par = ptrsave;
}

/***** primer caso del case. Insercion****/
void DST::insert(node *tree, node *newnode) // clade insertar
{
	if (root == NULL) // comprueba la raiz es null, lo usamos en el primer ingreso de datos
	{
		root = new node; // la variable de nuevo nodo se inicializa, se almacena el valor ingresado
		root->info = newnode->info; // se agrega el numero ingresado "info"
		root->left = NULL;
		root->right = NULL;
		cout << "Agregado al Nodo Raiz" << endl; //muestra el mensaje 
		return; // retorna
	}
	if (tree->info == newnode->info) // luego de haber ingresado en numero compara si existe
	{
		cout << "El Elemento ya Existe en el Arbol" << endl;
		return;
	}
	if (tree->info > newnode->info) // ingreso de nuevo dato , para ser comparado segun el numero
		// si el numero es menor 
	{
		if (tree->left != NULL) //cuando el nodo no esta vacio, es utilizado en la segunda insercion
		{
			insert(tree->left, newnode); // ingreso al nodo, insetar
		}
		else
		{
			tree->left = newnode; // hace el llamado a nuevo node
			(tree->left)->left = NULL; // hacigna a la izquierda
			(tree->left)->right = NULL;
			cout << "Nodo asignado a la izquierda" << endl;
			return;
		}
	}
	else // el valor llegar ahi si es el mayor del arbol
		//si el numero es mayor
	{
		if (tree->right != NULL) // cuando el nodo no esta vacio, es utilizado en la segunda insercion
		{
			insert(tree->right, newnode);  // ingreso al nodo, insetar
		}
		else
		{
			tree->right = newnode; // hace el lamado al nuevo nodeyuj
			(tree->right)->left = NULL;
			(tree->right)->right = NULL; //hacigna a la derecha
			cout << "Nodo asignado a la Derecha" << endl;
			return;
		}
	}
}


void DST::deletet(int item)
{
	node *parent, *location;
	if (root == NULL) // compara si el arbol esta vacio
	{
		cout << "Arbol vacio" << endl; // muetra el mensage
		return; // retorna al menu principal
	}
	find(item, &parent, &location);
	if (location == NULL) // no se encontro el numero
	{
		cout << "Elemento no Encontrado en el Arbol" << endl;
		return;
	}
	if (location->left == NULL && location->right == NULL)
		case_a(parent, location);
	if (location->left != NULL && location->right == NULL)
		case_b(parent, location);
	if (location->left == NULL && location->right != NULL)
		case_b(parent, location);
	if (location->left != NULL && location->right != NULL)
		case_c(parent, location);
	free(location);
}

/*
 * Mostrar la Estructura del Arbol
 */
void DST::display(node *ptr, int level) // mostarmos el arbol
{
	int i; // Creamos variable i
	if (ptr != NULL) // si no esta vacio
	{
		display(ptr->right, level + 1); // em el primer recorrido retona  al If
		cout << endl; // espacio
		if (ptr == root) // compara si es igual la raiz
			cout << "Raiz->:  "; //mostramos la raiz
		else
		{
			for (i = 0; i < level; i++)
				cout << "       "; // asignar espacio haco la derecha para crear la vista
		}
		cout << ptr->info; //muestra el mayor
		display(ptr->left, level + 1); // ,muetra el Menor
	}
}

#endif