//
//  main.cpp
//  01_Los_Hermanos_Dalton
//
//  Created by Joel Garcia Aparicio on 21/11/2020.
//
// NOMBRE Y APELLIDOS: Joel Garcia Aparicio
// E26

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool hermanosDalton(std::vector<int> &array, int tam){
    bool dalton = true;
    int i =0;
    while (i < tam-1 && dalton) {
        if(array[i] >= array[i+1]) dalton = false;
        ++i;
    }
    return dalton;
}

bool resuelveCaso() {
    int tam;
    std::cin >> tam;
    if (tam == 0)
        return false;
    std::vector<int> array(tam);
    for(int i = 0; i < tam; ++i)
        std::cin >> array[i];
    bool sol = hermanosDalton(array, tam);
    if(sol) std::cout << "DALTON\n";
    else std::cout << "DESCONOCIDOS\n";
    return true;
}


int main() {
    
    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/Joel/Desktop/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());
    
    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
