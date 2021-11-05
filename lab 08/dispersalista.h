#ifndef DispersaLista_H
#define DispersaLista_H
#include "nodo.h"

template<typename T>
class DispersaLista
{
    private:
        Nodo<T>* punta;
    public:
        DispersaLista( T mat** , int n , int m );
        void mostrarMayorFila();
        int sumaColumnas();
        void mostrarParesFilas();
        bool find_col(int f, int c, Nodo<T>**& q) {
            q = &fila[f];
            while (*q) {
                if ((*q)->col == c) return true;
                if ((*q)->col > c) return false;
                q = &((*q)->LC);
            }return false;
        }
        bool find_fil(int f, int c, Nodo<T>**& p) {
            p = &col[c];
            while (*p) {
                if ((*p)->fila == f) return true;
                if ((*p)->fila > f) return false;
                p = &((*p)->LF);
            }return false;
        }
        void insertarDato(int f, int c, T d) {
            Nodo<T>** p;
            Nodo<T>** q;
            bool a = find_fil(f, c, p);
            bool b = find_col(f, c, q);
            if (!a && !b) {
            Nodo<T>* pNuevo = new Nodo<T>(f, c, d);
               pNuevo->LF = *p;
               pNuevo->LC = *q;
               *p = *q = pNuevo;
            }
        }
        void Print() {
            Nodo<int>** q;
            for (int i = 0; i < fila; i++) {
                for (int j = 0; j <col; j++) {
                    if (find_fil(i, j, q))
                        cout << (*q)->dato << " ";
                    else
                        cout << "0 ";
                }
                cout << endl;
            }
        }
        void eliminarDato(int f, int c);
        void eliminarPares();
        void eliminarMayor();
        void eliminarMayorFila();

};


#endif