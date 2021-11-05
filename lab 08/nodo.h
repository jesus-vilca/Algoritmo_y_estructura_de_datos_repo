#ifndef NODO_H
#define NODO_H

template<typename T>
class Nodo
{
    private:
        int fila,col;
        T dato;
        Nodo<T>* liga,*LF,*LC;
    public:
        Nodo( int , int , T );
        int obtenerFila();
        int obtenerColumna();
        T obtenerDato();
        Nodo<T>* obtenerLF();
        Nodo<T>* obtenerLC();
        Nodo<T>* obtenerLiga();
        void asignarFila( int );
        void asignarColumna( int );
        void asignarDato( T );
        void asignarLiga( Nodo<T>* );
        void asignarLF( Nodo<T>* );
        void asignarLC( Nodo<T>* );
};

template<typename T>
Nodo<T>::Nodo( int f, int c, T d)
{   
    fila = f;
    col = c;
    dato = d;
    liga = LF = LC = nullptr;
}   

template<typename T>
void Nodo<T>::asignarFila( int x )
{
    fila = x;
}

template<typename T>
void Nodo<T>::asignarColumna( int x )
{
    col = x;
}

template<typename T>
void Nodo<T>::asignarDato( T x )
{
    dato = x;
}

template<typename T>
void Nodo<T>::asignarLiga( Nodo<T>* x )
{
    liga = x;
}

template<typename T>
void Nodo<T>::asignarLF( Nodo<T>* x )
{
    LF = x;
}

template<typename T>
void Nodo<T>::asignarLC( Nodo<T>* x )
{
    LC = x;
}

template<typename T>
int Nodo<T>::obtenerFila()
{
    return fila;
}

template<typename T>
int Nodo<T>::obtenerColumna()
{
    return col;
}

template<typename T>
T Nodo<T>::obtenerDato()
{
    return dato;
}

template<typename T>
Nodo<T>* Nodo<T>::obtenerLiga()
{
    return liga;
}

template<typename T>
Nodo<T>* Nodo<T>::obtenerLF()
{
    return LF;
}

template<typename T>
Nodo<T>* Nodo<T>::obtenerLC()
{
    return LC;
}

#endif