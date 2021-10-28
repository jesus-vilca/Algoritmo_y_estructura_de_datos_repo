#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Nodo
{
public:
	T m_Dato;
	Nodo<T> *m_pSon[2];

	Nodo(T d)
	{
		m_Dato = d;
		// hijo izquierdo
		m_pSon[0] = 0;
		// hijo derecho
		m_pSon[1] = 0;
	}
};

template <class T>
class Binary_Tree
{
	private:
		Nodo<T> *m_pRoot;

	public:
		Binary_Tree() : m_pRoot(0){};

		void insert(T d)
		{
			insert(d, m_pRoot);
		}
		void insert(T d, Nodo<T> *&p)
		{
			if (!p)
			{
				p = new Nodo<T>(d);
				return;
			}
			if (p->m_Dato == d)
				return;
			insert(d, p->m_pSon[p->m_Dato < d]);
		}

		void PrintpreOrden(Nodo<T> *r)
		{
			if (!r)
				return;
			cout << r->m_Dato << ' ';
			PrintpreOrden(r->m_pSon[0]);
			PrintpreOrden(r->m_pSon[1]);
		}
		void PrintpreOrden()
		{
			PrintpreOrden(m_pRoot);
			cout << '\n';
		}

		void PrintinOrden(Nodo<T> *r)
		{
			if (!r)
				return;
			PrintinOrden(r->m_pSon[0]);
			cout << r->m_Dato << ' ';
			PrintinOrden(r->m_pSon[1]);
		}
		void PrintinOrden()
		{
			PrintinOrden(m_pRoot);
			cout << '\n';
		}

		void PrintposOrden(Nodo<T> *r)
		{
			if (!r)
				return;
			PrintposOrden(r->m_pSon[0]);
			PrintposOrden(r->m_pSon[1]);
			cout << r->m_Dato << ' ';
		}
		void PrintposOrden()
		{
			PrintposOrden(m_pRoot);
			cout << '\n';
		}

		bool find(T d, Nodo<T> *p)
		{
			if (!p)
				return false;
			if (p->m_Dato == d)
			{
				return true;
			}
			return find(d, p->m_pSon[p->m_Dato < d]);
		}
		bool find(T d)
		{
			return find(d, m_pRoot);
		}

		void guardarPila(Nodo<T> *p, stack<Nodo<T> *> &pila)
		{
			if (!p)
				return;
			pila.push(p);
			guardarPila(p->m_pSon[0], pila);
			guardarPila(p->m_pSon[1], pila);
		}

		void remove(T d)
		{
			if (find(d))
			{
				Nodo<T> *q = m_pRoot;
				while (q->m_pSon[q->m_Dato < d]->m_Dato != d)
				{
					q = q->m_pSon[q->m_Dato < d];
				}
				stack<Nodo<T> *> pila;
				Nodo<T> *q2 = q->m_pSon[q->m_Dato < d];
				q->m_pSon[q->m_Dato < d] = nullptr;
				guardarPila(q2, pila);
				while (pila.size())
				{
					Nodo<T> *aux = pila.top();
					if (pila.size() != 1)
						insert(aux->m_Dato);
					pila.pop();
					delete aux;
				}
			}
		}
};

int main()
{
	Binary_Tree<int> A;
	A.insert(21);
	A.insert(35);
	A.insert(15);
	A.insert(18);
	A.insert(16);
	A.insert(20);
	A.insert(19);
	cout << "Arbol en preOrden" << endl;
	A.PrintpreOrden();
	cout << "Arbol en inOrden" << endl;
	A.PrintinOrden();
	cout << "Arbol en PosOrden" << endl;
	A.PrintposOrden();
	cout << "buscar:\n";
	cout << A.find(21) << "-" << A.find(180) << endl;
	cout << "elimina e imprime despues de eliminar\n";
	A.remove(18);
	cout << "Arbol en preOrden" << endl;
	A.PrintpreOrden();
	cout << "Arbol en inOrden" << endl;
	A.PrintinOrden();
	cout << "Arbol en PosOrden" << endl;
	A.PrintposOrden();
	return 1;
}