#ifndef NODE_H
#define NODE_H

struct node
{
	int info;
	struct node *left;
	struct node *right;
}*root;

#endif