#ifndef CASE_H
#define CASE_H

/*
 * Case A
 */
void DST::case_a(node *par, node *loc)
{
	if (par == NULL) // si es igual a la raiz
	{
		root = NULL; // borrar la raiz
	}
	else
	{
		if (loc == par->left)
			par->left = NULL; // borrar izquierda	
		else
			par->right = NULL; // borrar derecha
	}
}
/*
 * Case B
 */
void DST::case_b(node *par, node *loc) // Izquierda
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
void DST::case_c(node *par, node *loc) //Derecha
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

#endif