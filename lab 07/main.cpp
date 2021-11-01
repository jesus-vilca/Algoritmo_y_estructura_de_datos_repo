#include <iostream>
#include "searchbinarytree.h"
using namespace std;

int main()
{
	cout<<"\nCREACION DE ARBOL BINARIO DE BUSQUEDA VACIO\n";
	SearchBinaryTree<int> A;
	cout<<"\nINSERTANDO ELEMENTOS\n";
	cout<<"INSERTANDO 4, 80, 6, 11, 22, 52, 54, 34, 1, 21, 65, 5, 2, 12, 23\n";
	A.insert(4);
    A.insert(80);
    A.insert(6);
    A.insert(11);
    A.insert(22);
    A.insert(52);
    A.insert(54);
    A.insert(34);
    A.insert(1);
    A.insert(21);
    A.insert(65);
    A.insert(5);
    A.insert(2);
    A.insert(12);
    A.insert(23);
	cout<<"\nTAMANIO DEL ARBOL: "<<A.size()<<'\n';
	cout<<"\nMOSTRANDO ARBOL PREORDEN\n";
	cout<<A.preOrder();
	cout<<"\nMOSTRANDO ARBOL INORDEN\n";
	cout<<A.inOrder();
	cout<<"\nMOSTRANDO ARBOL POSTORDEN\n";
	cout<<A.postOrder();

	cout<<"\n\nGRAFICANDO ARBOL\n";
	A.graficar("antes_de_eliminar.dot");
	system("dot antes_de_eliminar.dot -o antes_de_eliminar.png -Tpng");             // "dot arbolBinario.dot -o arbolBinario.png -Tpng"
    system("antes_de_eliminar.png");

	cout<<"\nELIMINANDO NODO 65\n";
	if( A.remove(65) )
	{
		cout<<"\nTAMANIO DEL ARBOL: "<<A.size()<<'\n';
		cout<<"\nMOSTRANDO ARBOL PREORDEN\n";
		cout<<A.preOrder();
		cout<<"\nMOSTRANDO ARBOL INORDEN\n";
		cout<<A.inOrder();
		cout<<"\nMOSTRANDO ARBOL POSTORDEN\n";
		cout<<A.postOrder();
	}
	cout<<"\n\nBUSCANDO ELEMENTO 4: ";
	if( A.find( 4 ) )
		cout<<"se encontro\n";
	else cout<<"no se encontro\n";
	cout<<"\nBUSCANDO ELEMENTO 65: ";
	if( A.find( 65 ) )
		cout<<"se encontro\n";
	else cout<<"no se encontro\n";

	cout<<"\nGRAFICANDO ARBOL\n";
	A.graficar("despues_de_eliminar.dot");
	system("dot despues_de_eliminar.dot -o despues_de_eliminar.png -Tpng");             // "dot arbolBinario.dot -o arbolBinario.png -Tpng"
    system("despues_de_eliminar.png");

	cout<<"\nVACIANDO ARBOL\n";
	A.clear();
	cout<<"\nTAMANIO DEL ARBOL: "<<A.size()<<'\n';
	cout<<"\nBUSCANDO ELEMENTO 4: ";
	if( A.find( 4 ) )
		cout<<"se encontro\n";
	else cout<<"no se encontro\n";
	cout<<"\nBUSCANDO ELEMENTO 34: ";
	if( A.find( 34 ) )
		cout<<"se encontro\n";
	else cout<<"no se encontro\n";
	cout<<"\nBUSCANDO ELEMENTO 11: ";
	if( A.find( 11 ) )
		cout<<"se encontro\n";
	else cout<<"no se encontro\n";

	cout<<"\nGRAFICANDO ARBOL\n";
	A.graficar("arbol_vacio.dot");
	system("dot arbol_vacio.dot -o arbol_vacio.png -Tpng");             // "dot arbolBinario.dot -o arbolBinario.png -Tpng"
    system("arbol_vacio.png");
}




