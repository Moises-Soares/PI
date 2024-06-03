// variaveis.c
// Este arquivo demonstra como declarar variáveis em C

#include <stdio.h>

int main() {
    // Declaração de variáveis inteiras
    int inteiro = 10; // Variável do tipo inteiro inicializada com o valor 10
    int outro_inteiro; // Variável do tipo inteiro sem inicialização

    // Declaração de variáveis do tipo ponto flutuante
    float ponto_flutuante = 5.5; // Variável do tipo float inicializada com o valor 5.5
    double ponto_flutuante_duplo = 10.25; // Variável do tipo double inicializada com o valor 10.25

    // Declaração de variáveis de caractere
    char caractere = 'A'; // Variável do tipo char inicializada com o caractere 'A'

    // Declaração de variáveis do tipo string
    char string[20] = "Olá, Mundo!"; // Variável do tipo string inicializada com "Olá, Mundo!"
    char outra_string[20]; // Variável do tipo string sem inicialização

    // Impressão das variáveis
    printf("Valor da variável inteiro: %d\n", inteiro);
    printf("Valor da variável ponto_flutuante: %.2f\n", ponto_flutuante);
    printf("Valor da variável ponto_flutuante_duplo: %.2lf\n", ponto_flutuante_duplo);
    printf("Valor da variável caractere: %c\n", caractere);
    printf("Valor da variável string: %s\n", string);

    // Inicializando outra_string e imprimindo
    outra_string[0] = 'H';
    outra_string[1] = 'i';
    outra_string[2] = '\0'; // Caractere nulo para terminar a string
    printf("Valor da variável outra_string: %s\n", outra_string);

    return 0;
}
