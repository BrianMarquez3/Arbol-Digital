# include "dst.h"
# include "node.h"
# include "case.h"

int main()
{
	int choice, num;
	DST dst;
	node *temp;
	while (1)
	{
		
		cout << "				" << endl;//
		cout << "				" << endl;
		//system("COLOR E9");
		cout << "***************************" << endl;
		cout << "*ARBOL DE BUSQUEDA DIGITAL*" << endl;
		cout << "***************************" << endl;
		
		cout << "1.Insertar Elemento " << endl;
		cout << "2.Borrar Elemento " << endl;
		cout << "3.Inorder" << endl;
		cout << "4.Preorder" << endl;
		cout << "5.Postorder" << endl;
		cout << "6.Mostar" << endl;
		cout << "7.Salir" << endl;
		cout << "Elige una Opcion: <1-7> ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			temp = new node;
			cout << "Ingrese un Elemento : ";
			cin >> temp->info;
			dst.insert(root, temp);
			break;
		case 2:
			if (root == NULL)
			{
				cout << "El Arbol esta vacio, no se puede Eliminar Elementos" << endl;
				continue;
			}
			cout << "Ingrese el Numero para ser Eliminado : ";
			cin >> num;
			dst.deletet(num);
			break;
		case 3:
			cout << "Inorder:" << endl;
			dst.inorder(root);
			cout << endl;
			break;
		case 4:
			cout << "Preorder:" << endl;
			dst.preorder(root);
			cout << endl;
			break;
		case 5:
			cout << "Postorder:" << endl;
			dst.postorder(root);
			cout << endl;
			break;
		case 6:
			cout << "Mostrar Arbol:" << endl;
			dst.display(root, 1);
			cout << endl;
			break;
		case 7:
			exit(1);
		default:
			cout << "Elige Otra Opcion" << endl;
		}
	}
}
