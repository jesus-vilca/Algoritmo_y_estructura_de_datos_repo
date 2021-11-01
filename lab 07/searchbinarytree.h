#ifndef SEARCHBINARYTREE_H
#define SEARCHBINARYTREE_H
#include "nodo.h"
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>

template <class T>
class SearchBinaryTree
{
	private:
		Nodo<T> *m_pRoot;
        int _size;
        bool find( T d , Nodo<T> *);                    // funcion recursiva para buscar
        void preOrder( Nodo<T> * , std::string& );      // funcion recursiva preorden
        void inOrder( Nodo<T> * , std::string& );       // funcion recursiva inorden
        void postOrder( Nodo<T> * , std::string& );     // funcion recursiva postorden
        void graficar( Nodo<T>* , std::ofstream& );     // funcion recursiva para graficar
	public:
        // constructor, construye arbol vacio
		SearchBinaryTree() : m_pRoot(0),_size(0){}
        // destructor
        ~SearchBinaryTree();        
        int size(){ return _size; }
        // inserta un elemento y calcula los FE
		void insert( T );           
        // rotaciones simples       
        void rotarLL( Nodo<T>*& );
        void rotarRR( Nodo<T>*& );
        // rotaciones dobles        
        void rotarLR( Nodo<T>*& );
        void rotarRL( Nodo<T>*& );
        // elimina un nodo
        bool remove( T );          
        void guardarCola( Nodo<T> * , std::queue<Nodo<T>*> & );     // funcion auxiliar
        // busca un elemento
		bool find( T );
        // devuelve string con los elementos del arbol en preorden
		std::string preOrder();
        // devuelve string con los elementos del arbol en inorden
		std::string inOrder();
        // devuelve string con los elementos del arbol en postorden
        std::string postOrder();
        // vacia el arbol
        void clear();
        // grafica el arbol	
        void graficar( std::string );	

        void print( Nodo<T>* );
        void print();
};

template<typename T>
SearchBinaryTree<T>::~SearchBinaryTree()
{
    m_pRoot->autoDestruir( m_pRoot );
    std::cout<<"\nse destruyo correctamente\n";
}

template<typename T>
void SearchBinaryTree<T>::insert( T value )                             
{
    Nodo<T>* pNuevo = new Nodo<T>(value);               // nuevo nodo
    Nodo<T>* tmp = m_pRoot;                               // tmp avanza por el arbol
    if( !m_pRoot ) m_pRoot = pNuevo;                        // si m_pRoot null, primer elemento
    else
    {
        while( tmp->m_pSon[ tmp->m_Dato < value ] )        // mientras exista un hijo
            tmp = tmp->m_pSon[ tmp->m_Dato < value ];      // avanza
        if( tmp->m_Dato == value ) return;               // si el valor se repite, termina
        tmp->m_pSon[ tmp->m_Dato < value ] = pNuevo;       // nuevo hijo
        pNuevo->m_pSon[2] = tmp;                          // agrega el padre
    }
    _size++;
    while( tmp )
    {
        if( value < tmp->m_Dato )
            tmp->FE--;
        else
            tmp->FE++;
        // std::cout<<tmp->FE<<'\n';
        if( tmp->FE == 2 )                              // rotacion der
        {
            if( tmp->m_pSon[1]->FE == -1 )                // si tmp->der->FE == -1, rotacion DI
            {
                std::cout<<"ROTACION DI"<<'\n';
                if( tmp==m_pRoot ) rotarRL( m_pRoot );       // si tmp es la raiz, pasa una referencia a la raiz
                else rotarRL( tmp->m_pSon[2]->m_pSon[ tmp->m_pSon[2]->m_Dato < tmp->m_Dato ] );   // si tmp no es la raiz, pasa un referencia a tmp->padre->der
            }
            else                                        // sino tmp->der->FE == 1, rotacion DD
            {
                std::cout<<"ROTACION DD"<<'\n';
                if( tmp==m_pRoot ) rotarRR( m_pRoot );       // si tmp es la raiz, pasa una referencia a la raiz
                else rotarRR( tmp->m_pSon[2]->m_pSon[ tmp->m_pSon[2]->m_Dato < tmp->m_Dato ] );   // si tmp no es la raiz, pasa un referencia a tmp->padre->der
            }
            break;
        }
        else if( tmp->FE == -2 )                        // rotacion izq
        {
            if( tmp->m_pSon[0]->FE == 1 )                 // si tmp->izq->FE == 1, rotacion ID
            {
                std::cout<<"ROTACION ID"<<'\n';
                if( tmp==m_pRoot ) rotarLR( m_pRoot );       // si tmp es la raiz, pasa una referencia a la raiz
                else rotarLR( tmp->m_pSon[2]->m_pSon[ tmp->m_pSon[2]->m_Dato < tmp->m_Dato ] );   // si tmp no es la raiz, pasa un referencia a tmp->padre->izq
            }
            else                                        // sino tmp->izq->FE == -1, rotacion II
            {
                std::cout<<"ROTACION II"<<'\n';
                if( tmp==m_pRoot ) rotarLL( m_pRoot );       // si tmp es la raiz, pasa una referencia a la raiz
                else rotarLL( tmp->m_pSon[2]->m_pSon[ tmp->m_pSon[2]->m_Dato < tmp->m_Dato ] );   // si tmp no es la raiz, pasa un referencia a tmp->padre->izq
            }
            break;
        }
        else if( tmp->FE == 0 ) break;                  // si FE es 0, todas las ramas hijas equilibradas
        value = tmp->m_Dato;                             // guarda el valor del padre
        tmp = tmp->m_pSon[2];                             // apunta al padre
    }
}

template<typename T>
void SearchBinaryTree<T>::rotarRR( Nodo<T>*& p )
{
    Nodo<T>* q = p->m_pSon[1];
    Nodo<T>* x = q->m_pSon[0];

    q->m_pSon[0] = p;
    p->m_pSon[1] = x;

    q->m_pSon[2] = p->m_pSon[2];
    p->m_pSon[2] = q;
    if( x ) x->m_pSon[2] = p;
    if( q->FE == 1 || q->FE == -1 )
        p->FE = q->FE = 0;
    p = q;
}

template<typename T>
void SearchBinaryTree<T>::rotarLL( Nodo<T>*& p )
{
    Nodo<T>* q = p->m_pSon[0];
    Nodo<T>* x = q->m_pSon[1];

    q->m_pSon[1] = p;
    p->m_pSon[0] = x;

    q->m_pSon[2] = p->m_pSon[2];
    p->m_pSon[2] = q;
    if( x ) x->m_pSon[2] = p;
    if( q->FE == 1 || q->FE == -1 )
        p->FE = q->FE = 0;
    p = q;
}

template<typename T>
void SearchBinaryTree<T>::rotarLR( Nodo<T>*& p )
{
    Nodo<T>* q = p->m_pSon[0];
    Nodo<T>* r = q->m_pSon[1];
    Nodo<T>* x = r->m_pSon[0];
    Nodo<T>* y = r->m_pSon[1];

    r->m_pSon[0] = q;
    r->m_pSon[1] = p;
    q->m_pSon[1] = x;
    p->m_pSon[0] = y;

    r->m_pSon[2] = p->m_pSon[2];
    p->m_pSon[2] = q->m_pSon[2] = r;

    if( x ) x->m_pSon[2] = q;
    if( y ) y->m_pSon[2] = p;

    if( r->FE == 0 ) q->FE = p->FE = 0;
    else if( r->FE == 1 ) 
    {
        q->FE = 0;
        p->FE = -1;
    }
    else if( r->FE == -1 )
    {
        q->FE = 1;
        p->FE = 0;
    }
    if( p->m_pSon[1] )                              
        p->FE += 1;                      
    if( q->m_pSon[0] )                                
        q->FE += -1;                     
    r->FE += p->FE + q->FE;                         
    p = r; 
}

template<typename T>
void SearchBinaryTree<T>::rotarRL( Nodo<T>*& p )
{
    Nodo<T>* q = p->m_pSon[1];
    Nodo<T>* r = q->m_pSon[0];
    Nodo<T>* x = r->m_pSon[1];
    Nodo<T>* y = r->m_pSon[0];

    r->m_pSon[1] = q;
    r->m_pSon[0] = p;
    q->m_pSon[0] = x;
    p->m_pSon[1] = y;

    r->m_pSon[2] = p->m_pSon[2];
    p->m_pSon[2] = q->m_pSon[2] = r;

    if( x ) x->m_pSon[2] = q;
    if( y ) y->m_pSon[2] = p;

    if( r->FE == 0 ) q->FE = p->FE = 0;
    else if( r->FE == 1 ) 
    {
        q->FE = -1;
        p->FE = 0;
    }
    else if( r->FE == -1 )
    {
        q->FE = 0;
        p->FE = 1;
    }
    if( p->m_pSon[0] )                               
        p->FE += -1;                     
    if( q->m_pSon[1] )                                
        q->FE += 1;                    
    r->FE += p->FE + q->FE;                       
    p = r; 
}

template<typename T>
void SearchBinaryTree<T>::guardarCola( Nodo<T> *p, std::queue<Nodo<T> *> &cola )
{
    if (!p)
        return;
    cola.push(p);
    guardarCola(p->m_pSon[0], cola);
    guardarCola(p->m_pSon[1], cola);
}

template<typename T>
bool SearchBinaryTree<T>::remove( T d )
{
    if (find(d))
    {
        Nodo<T> *q = m_pRoot;
        while ( q->m_Dato != d ) 
            q = q->m_pSon[q->m_Dato < d];
        std::queue<Nodo<T> *> cola;
        Nodo<T> *q2 = q;
        if( q == m_pRoot ) m_pRoot = nullptr;
        else
            q->m_pSon[2]->m_pSon[ q->m_pSon[2]->m_Dato < d ] = nullptr;
        guardarCola(q2, cola);
        _size = _size - cola.size(); 
        Nodo<T> *aux = cola.front();
        cola.pop();
        delete aux;
        while (cola.size())
        {
            aux = cola.front();
            insert(aux->m_Dato);
            cola.pop();
            delete aux;
        }
        return true;
    }
    return false;
}

template<typename T>
bool SearchBinaryTree<T>::find(T d, Nodo<T> *p)
{
    if (!p)
        return false;
    if (p->m_Dato == d)
    {
        return true;
    }
    return find( d , p->m_pSon[p->m_Dato < d] );
}

template<typename T>
bool SearchBinaryTree<T>::find( T d )
{
    return find( d, m_pRoot );
}

template<typename T>
std::string SearchBinaryTree<T>::preOrder()
{
    std::string cadena;
    preOrder( m_pRoot , cadena );
    return cadena;
}

template<typename T>
void SearchBinaryTree<T>::preOrder( Nodo<T> *r , std::string& s )
{
    if (!r)
        return;
    s += std::to_string(r->m_Dato) + ",";
    preOrder( r->m_pSon[0] , s );
    preOrder( r->m_pSon[1] , s );
}

template<typename T>
std::string SearchBinaryTree<T>::inOrder()
{
    std::string cadena;
    inOrder( m_pRoot,cadena );
    return cadena;
}

template<typename T>
void SearchBinaryTree<T>::inOrder( Nodo<T> *r , std::string& s)
{
    if (!r)
        return;
    inOrder( r->m_pSon[0] , s );
    s += std::to_string(r->m_Dato) + ",";
    inOrder( r->m_pSon[1] , s );
}

template<typename T>
std::string SearchBinaryTree<T>::postOrder()
{
    std::string cadena;
    postOrder( m_pRoot,cadena );
    return cadena;
}

template<typename T>
void SearchBinaryTree<T>::postOrder( Nodo<T> *r , std::string& s)
{
    if (!r)
        return;
    postOrder( r->m_pSon[0] , s );
    postOrder( r->m_pSon[1] , s );
    s += std::to_string(r->m_Dato) + ",";
}

template<typename T>
void SearchBinaryTree<T>::clear()
{
    m_pRoot->autoDestruir( m_pRoot );
    m_pRoot = nullptr;
    _size = 0;
}

template<typename T>
void SearchBinaryTree<T>::graficar( std::string dir )
{
    std::ofstream f;
    f.open(dir);
    f<<"graph A {\n";
    graficar( m_pRoot , f );
    f<<"}\n";
    f.close();
}

template<typename T>
void SearchBinaryTree<T>::graficar( Nodo<T>* p , std::ofstream& f )
{
    if( !p ) return;
    if( p->m_pSon[2] != nullptr)
        f<<p->m_pSon[2]->m_Dato<<" -- "<<p->m_Dato<<";\n";
    graficar( p->m_pSon[0] , f );
    graficar( p->m_pSon[1] , f );
}

template<typename T>
void SearchBinaryTree<T>::print()
{
    print( m_pRoot );
}

template<typename T>
void SearchBinaryTree<T>::print( Nodo<T>* p )
{
    if( !p ) return;
    print( p->m_pSon[0] );
    std::cout<<p->m_Dato<<" FE: "<<p->FE<<'\n';
    print( p->m_pSon[1] );
}

#endif