#include <string>
#include <cmath>
#include <stdio.h>
#include <iostream>

// Implemente la evaluación de expresiones aritméticas considerando los operadores +,-,*,/ y los operandos pueden ser ingresados en 
// notación científica (125E25,5E-8 para denotar 12x1025, 5x10-8 respectivamente), la entrada al programa será una cadena de caracteres 
// con la expresión, ejemplo de expresión a evaluar: (125E10 – 1e15)/5E-85*15.

using namespace std;

// Funcion para evaluar la expresion aritmetica
double evaluacion(const string& expresion) {
    double resultado = 0.0;
    char operador = '+'; 
    double number = 0.0;

    for (size_t i = 0; i < expresion.length(); ++i) {
        char c = expresion[i];

        if (isdigit(c) || c == 'E' || c == '.' || (c == '-' && i == 0)) {
            string numStr;
            while (isdigit(expresion[i]) || expresion[i] == '.' || expresion[i] == 'E' || (expresion[i] == '-' && i == 0)) {
                numStr += expresion[i++];
            }
            
            number = stod(numStr);
            --i; 

            switch (operador) {
                case '+':
                    resultado += number;
                    break;
                case '-':
                    resultado -= number;
                    break;
                case '*':
                    resultado *= number;
                    break;
                case '/':
                    resultado /= number;
                    break;
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Si es un operador, actualizar el operador actual
            operador = c;
        } else if (c == '(') {
            // Si es un parentesis de apertura, buscar el parentesis de cierre
            size_t j = i + 1;
            int count = 1;
            while (j < expresion.length() && count > 0) {
                if (expresion[j] == '(') ++count;
                else if (expresion[j] == ')') --count;
                ++j;
            }
            string subExpr = expresion.substr(i + 1, j - i - 2);
            number = evaluacion(subExpr); // Evaluar la subexpresion
            i = j - 1; // Actualizacion de indice
            // Aplicar el operador actual al resultado de la subexpresion y actualizar el resultado
            switch (operador) {
                case '+':
                    resultado += number;
                    break;
                case '-':
                    resultado -= number;
                    break;
                case '*':
                    resultado *= number;
                    break;
                case '/':
                    resultado /= number;
                    break;
            }
        }
    }

    return resultado;
}

//funcion principal main 
int main() {
    string expresion = "(125E10 – 1e15)/5E-85*15";
    double result = evaluacion(expresion);
    cout << "El resultado de la expresion \"" << expresion << "\" es: " << scientific << result << endl;

    return 0;
}
