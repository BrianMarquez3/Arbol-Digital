#ifndef CASE_H
#define CASE_H

/*
 * Case A
 */
void DST::case_a(node *par, node *loc)
{
	if (par == NULL)
	{
		root = NULL;
	}
	else
	{
		if (loc == par->left)
			par->left = NULL;
		else
			par->right = NULL;
	}
}
/*
 * Case B
 */
void DST::case_b(node *par, node *loc)
{
	node *child;
	if (loc->left != NULL)
		child = loc->left;
	else
		child = loc->right;
	if (par == NULL)
	{
		root = child;
	}
	else
	{
		if (loc == par->left)
			par->left = child;
		else
			par->right = child;
	}
}

/*
 * Case C
 */
void DST::case_c(node *par, node *loc)
{
	node *ptr, *ptrsave, *suc, *parsuc;
	ptrsave = loc;
	ptr = loc->right;
	while (ptr->left != NULL)
	{
		ptrsave = ptr;
		ptr = ptr->left;
	}
	suc = ptr;
	parsuc = ptrsave;
	if (suc->left == NULL && suc->right == NULL)
		case_a(parsuc, suc);
	else
		case_b(parsuc, suc);
	if (par == NULL)
	{
		root = suc;
	}
	else
	{
		if (loc == par->left)
			par->left = suc;
		else
			par->right = suc;
	}
	suc->left = loc->left;
	suc->right = loc->right;
}

/*
 * Pre Order Traversal
 */

void DST::preorder(node *ptr)
{
	if (root == NULL)
	{
		cout << "Arbol Vacio" << endl;
		return;
	}
	if (ptr != NULL)
	{
		cout << ptr->info << "  ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
/*
 * In Order Traversal
 */
void DST::inorder(node *ptr)
{
	if (root == NULL)
	{
		cout << "Arbol Vacio" << endl;
		return;
	}
	if (ptr != NULL)
	{
		inorder(ptr->left);
		cout << ptr->info << "  ";
		inorder(ptr->right);
	}
}

/*
 * Postorder Traversal
 */
void DST::postorder(node *ptr)
{
	if (root == NULL)
	{
		cout << "Arbol Vacio" << endl;
		return;
	}
	if (ptr != NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->info << "  ";
	}
}

#endif