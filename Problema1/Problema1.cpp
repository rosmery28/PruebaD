#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 1) Dado una cadena C, valide si C se encuentra en notación 
// FEN (Forsyth-Edwards Notation), Forsyth–Edwards Notation.
// El usuario ingresara la cadena y la funcion indicara si esta o no esta en notacion FEN


int notacionFEN(const char *C) {
    if (C == NULL) {
        return 0; // Indica que la cadena es nulla
    }

    int fila = 0; //
    int columna = 0;
    int i = 0;

    while (C[i] != '\0' && C[i] != ' ') {
        if (isdigit(C[i])) {
            columna += C[i] - '0';
        } else if (strchr("PNBRQKpnbrqk", C[i]) != NULL) {
            columna++;
        } else if (C[i] == '/') { //Simbolo de sepacion
            if (columna != 8) {
                return 0; // Sale de la funcion cuando el tiene número incorrecto de columnas en la fila
            }
            fila++;
            columna = 0;
        } else {
            return 0; // Sale de la funcion cuando tiene  carácter no válido
        }
        i++;
    }

    if (fila != 7 || columna != 8) {
        return 0; // Número incorrecto de filas o columnas
    }

    return 1; // Cadena FEN válida
}

int main() {
    char c[] = "";
    
    printf("Ingrese la cadena a evaluar: ");
    scanf("%s", c);

    printf("'%s' La cadena : %s\n", c, notacionFEN(c) ? "Si es Notacion FEN" : "No es Notacion FEN");


    return 0;
}

