//
//  main.cpp
//  Fuga_De_Prision
//
//  Created by Joel Garcia Aparicio on 8/12/20.
//
//NOMBRE y APELLIDOS Joel Garcia Aparicio
// E 26


#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

char fugaPrision(std::vector<char> array, int ini, int fin, char prim, char ult){
    if(ini + 1 == fin){ //caso base
        if(array[ini] == prim) return array[ini]+1;
        else return array[ini]-1;
    }else{
        if(prim != array[ini]) return prim; //si el primer elemento no coincide con el extremo izquierdo
        else if(ult != array[fin-1]) return ult; //si el ultimo elemento no coincide con el extremo derecho
        
        int m = (ini + fin) / 2;
        
        if(array[m] - array[ini] == m - ini) return fugaPrision(array, m, fin, array[m], ult);
        else return fugaPrision(array, ini, m, prim, array[m-1]);
    }
}

void resuelveCaso() {
    char ini, fin;
    std::cin >> ini >> fin;
    
    int tam = fin - ini;
    
    std::vector<char> array(tam);
    for(int i = 0; i < tam; ++i) std::cin >> array[i];
    
    char sol = fugaPrision(array, 0, tam, ini, fin);
    std::cout << sol << "\n";
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("/Users/Joel/Desktop/casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
