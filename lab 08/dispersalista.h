#ifndef DispersaLista_H
#define DispersaLista_H
#include "nodo.h"

template<typename T>
class DispersaLista
{
    private:
        Nodo<T>* punta;
    public:
        DispersaLista(int n , int m);
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
        Nodo<T> buscar(int f, int c);

};
template<typename T>
DispersaLista<T>::DispersaLista(int n , int m){
    Nodo<T> p,q,ant;
    int i=0,may=0;
    if(n>m){
        may=n;
    }else{
        may=m;
    }
    this -> punta = new Nodo(n,m,0);
    ant=punta;
    for(int i=1;i<may;i++){
        q = new Nodo(i,i,0);
        q.asignarLF(q);
        q.asignarLC(q);
        ant.asignarLiga(q);
        ant=q;
    }
    ant.asignarLiga(punta);
}
/*template<typename T>
void DispersaLista<T>::insertarDato( int f, int c, T d){
    Nodo<T> p,q;
    int s;
    p = buscar(n,m);
    if(p==nullptr){
        q= new Nodo(f,c,d);
        ligarFila(q);
        ligarColumna(q);
    }else{
        s=p.obtenerDato() + d;
        if(s=0){
            desligarFila(p);
            desligarColumna(p);
            libere(p);
        }else{
            p.asignarDato(s);
        }
    }
}*/
template<typename T>
Nodo<T> DispersaLista<T>::buscar(int f, int c){
    Nodo<T> p,q,res;
    res=NULL;
    p=punta.obtenerLiga();
    while(p.obtenerFila() < f){
        p=p.obtenerLiga();
    }
    q=p.obtenerLF();
    while(q==p && q.obtenerColumna()<c){
        q=q.obtenerLF();
    }
    if(q!=p && q.obtenerFila()=f && q.obtenerColumna()=c){
        res=q;
    }
    return res;
}

#endif
