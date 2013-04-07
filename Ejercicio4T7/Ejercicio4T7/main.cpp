//
//  main.cpp
//  Ejercicio4T7
//
//  Created by Dani on 07/04/13.
//  Copyright (c) 2013 EDA. All rights reserved.
//

#include <iostream>
#include "Arbin.h"

using namespace std;

template <typename E>
void printArbol(const Arbin<E> &arbol);

template <typename E>
void printArbolAux(const Arbin<E> &arbol, int nivel);

int main(int argc, const char * argv[])
{

    Arbin<int> a(Arbin<int>(Arbin<int>(), 2, Arbin<int>(Arbin<int>(), 4, Arbin<int>())), 1, Arbin<int>(Arbin<int>(Arbin<int>(), 5, Arbin<int>()), 3, Arbin<int>()));
    
    printArbol(a);
    
    return 0;
}

template <typename E>
void printArbol(const Arbin<E> &arbol) {
    printArbolAux(arbol, 0);
}

template <typename E>
void printArbolAux(const Arbin<E> &arbol, int nivel) {
    
    for (int i =  0; i < nivel; i++) {
        cout << "...";
    }
    
    if (arbol.esVacio()) {
        cout << "<vacio>" << endl;
    }
    else if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
        cout << arbol.raiz() << endl;
    }
    else {
        cout << arbol.raiz() << endl;
        
        printArbolAux(arbol.hijoIz(), nivel+1);
        printArbolAux(arbol.hijoDr(), nivel+1);
    }
}