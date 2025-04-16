#include <iostream>
#include <string>

// Para un programa en un lenguaje L, dado un cadena C escrito en L, muestre y cuente 
// la ocurrencia de la palabra E en C.

using namespace std;

// funcion para verificar si en la cadena hay una palabra reservada
bool reservada (const string& C, const string E[], int cont) {
    for (int i = 0; i < cont; ++i) {
        if (C == E[i]) {
            return true;
        }
    }
    return false;
}

//funcion que cuenta la cantidad de palabras reservadas
int contador (const string& C, const string E[], int cont1) {
    int cont = 0;
    string palabra;

    // Iterar sobre cada caracter del codigo
    for (char caracter : C) {
        // Si es un caraccter de espacio o un simbolo de puntuacion, termina la palabra actual
        if (isspace(caracter) || ispunct(caracter)) {
            // Verificar si la palabra actual es una palabra reservada
            if (reservada(palabra, E, cont1)) {
                cont++;
            }
            // Limpiar la palabra actual para comenzar una nueva palabra
            palabra.clear();
        } else {
            // Agregar el caracter actual a la palabra actual
            palabra.push_back(caracter);
        }
    }

    // Verificar si la ultima palabra del codigo es una palabra reservada
    if (!palabra.empty() && reservada(palabra, E, cont1)) {
        cont++;
    }

    return cont;
}

int main() {
  
    string C = "Universidad nacional Experimental de Guayana"; // Cadena a analizar
    string E[] = {"nacional", "de", "Guayana", "con"}; // palabras reservadas
    int cont = sizeof(E) / sizeof(E[0]);

    // Obtener el resumen
    int cantidad = contador(C, E, cont);
	printf("Contenido de la variable C: Universidad nacional Experimental de Guayana\n");
	printf("Palabras reservadas en E: nacional, de, Guayana, con\n");
    // Mostrar el resumen
    cout << "La cantidad de ocurrencias de E en C es : " << cantidad << endl;

    return 0;
}
