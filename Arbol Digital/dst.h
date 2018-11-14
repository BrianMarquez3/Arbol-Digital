#ifndef DST_H
#define DST_H
#include <iostream>
#include <cstdlib>
#include "node.h"

using namespace std;

class DST
{
public:
	void find(int, node **, node **);
	void insert(node * tree, node * newnode);
	void deletet(int);
	void case_a(node *, node *);
	void case_b(node *, node *);
	void case_c(node *, node *);
	void preorder(node *);
	void inorder(node *);
	void postorder(node *);
	void display(node *, int);
	DST()// cmprueba si la raiz es nula
	{
		root = NULL;
	}
};


void DST::find(int item, node **par, node **loc)
{
	node *ptr, *ptrsave;
	if (root == NULL)
	{
		*loc = NULL;
		*par = NULL;
		return;
	}
	if (item == root->info)
	{
		*loc = root;
		*par = NULL;
		return;
	}
	if (item < root->info)
		ptr = root->left;
	else
		ptr = root->right;
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


void DST::insert(node *tree, node *newnode)
{
	if (root == NULL) // comprueba la raiz
	{
		root = new node; // la variable de nuevo nodo se inicializa, se almacena el valor ingresado
		root->info = newnode->info;
		root->left = NULL;
		root->right = NULL;
		cout << "Agregado al Nodo Raiz" << endl; //muestra el mensaje 
		return;
	}
	if (tree->info == newnode->info)
	{
		cout << "El Elemento ya Existe en el Arbol" << endl;
		return;
	}
	if (tree->info > newnode->info)
	{
		if (tree->left != NULL)
		{
			insert(tree->left, newnode);
		}
		else
		{
			tree->left = newnode;
			(tree->left)->left = NULL;
			(tree->left)->right = NULL;
			cout << "Nodo asignado a la izquierda" << endl;
			return;
		}
	}
	else
	{
		if (tree->right != NULL)
		{
			insert(tree->right, newnode);
		}
		else
		{
			tree->right = newnode;
			(tree->right)->left = NULL;
			(tree->right)->right = NULL;
			cout << "Nodo asignado a la Derecha" << endl;
			return;
		}
	}
}


void DST::deletet(int item)
{
	node *parent, *location;
	if (root == NULL)
	{
		cout << "Arbol vacio" << endl;
		return;
	}
	find(item, &parent, &location);
	if (location == NULL)
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
void DST::display(node *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		cout << endl;
		if (ptr == root)
			cout << "Raiz->:  ";
		else
		{
			for (i = 0; i < level; i++)
				cout << "       ";
		}
		cout << ptr->info;
		display(ptr->left, level + 1);
	}
}

#endif