#ifndef NODE_H
#define NODE_H
 // creacion lo las variables principales
//int info donde se almacenarar el valor
//puntero Node Left
//Puntero Node right
struct node
{
	int info;
	struct node *left;
	struct node *right;
}*root;

#endif