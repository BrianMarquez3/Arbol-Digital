//Definimos los Aarchivos.h
# include "dst.h"
# include "node.h"
# include "case.h"

int main() // menu principal iniciador 
{
	int choice, num; //definimos choise el cual lo utilizaremos para elegir el el menu 
	DST dst; //
	node *temp; // ingresa al dst.h y comprueba el null, se ingresa mediente el puntero *
	while (1)// bucle de 7 opciones
	{
		// a continuacion se empiesan a mostrar las opciones
		//Menu principal
		//Menu principal
		cout << "				" << endl;//
		cout << "				" << endl;
		//system("COLOR E9");
		//cambiar el fondo de pantalla a color amarillo///
		cout << "***************************" << endl;
		cout << "*ARBOL DE BUSQUEDA DIGITAL*" << endl;
		cout << "***************************" << endl;
		
		cout << "1.Insertar Elemento " << endl;
		cout << "2.Borrar Elemento " << endl;
		//cout << "3.Inorder" << endl;
		//cout << "4.Preorder" << endl;
		//cout << "5.Postorder" << endl;
		cout << "6.Mostar" << endl;
		cout << "7.Salir" << endl;
		cout << "Elige una Opcion: <1-7> ";
		cin >> choice; //se espera el ingreso de un valor del 1 al 7
		switch (choice) // seguin el valor elejido se ingresa a case
		{
		case 1:
			temp = new node; //creacion de variables para el nuevo numero
			cout << "Ingrese un Elemento : ";
			cin >> temp->info; //
			dst.insert(root, temp);// captura del numero , nos envia a la clase insertar. dst.h
			break; // fin de las instruccines, no vuelve a enviar a menu principal
		case 2:
			if (root == NULL) // compara si el nodo esta vacio
			{
				cout << "El Arbol esta vacio, no se puede Eliminar Elementos" << endl;
				continue;
			}
			cout << "Ingrese el Numero para ser Eliminado : ";
			cin >> num; // la vaciable donde se almacena el numero para comparar
			dst.deletet(num); // nos envia a la clase para eliminar
			break;

		/*case 3:
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
			break;*/

		case 6: // mostar el arbol
			cout << "Mostrar Arbol:" << endl;
			dst.display(root, 1); // no envia a la case Mostar
			cout << endl;
			break;
		case 7: // orden de terminar el proceso
			exit(1);
		default: // ecepcion para elegir otra opcion
			cout << "Elige Otra Opcion" << endl; // mensage
		}
	}
}
