// printf_tutorial.c
// Este arquivo demonstra o uso da função printf e os códigos de formatação em C

#include <stdio.h>

int main() {
    // Impressão de uma string simples
    printf("Olá, Mundo!\n");

    // Impressão de variáveis inteiras
    int inteiro = 42;
    printf("Inteiro: %d\n", inteiro);

    // Impressão de variáveis do tipo ponto flutuante
    float ponto_flutuante = 3.14159;
    printf("Ponto flutuante (float): %f\n", ponto_flutuante);
    printf("Ponto flutuante com duas casas decimais: %.2f\n", ponto_flutuante);

    double ponto_flutuante_duplo = 2.718281828459;
    printf("Ponto flutuante (double): %lf\n", ponto_flutuante_duplo);
    printf("Ponto flutuante com três casas decimais: %.3lf\n", ponto_flutuante_duplo);

    // Impressão de variáveis de caractere
    char caractere = 'A';
    printf("Caractere: %c\n", caractere);

    // Impressão de strings
    char string[] = "Exemplo de string";
    printf("String: %s\n", string);

    // Impressão de números em diferentes bases
    int numero = 255;
    printf("Número em decimal: %d\n", numero);
    printf("Número em hexadecimal: %x\n", numero);
    printf("Número em octal: %o\n", numero);

    // Impressão de ponteiros
    int *ponteiro = &inteiro;
    printf("Endereço do ponteiro: %p\n", (void *)ponteiro);

    // Impressão com larguras específicas
    printf("Inteiro com largura 5: %5d\n", inteiro);
    printf("Inteiro com largura 5 e preenchido com zeros: %05d\n", inteiro);

    // Impressão com alinhamento à esquerda
    printf("Inteiro alinhado à esquerda com largura 5: %-5d\n", inteiro);

    // Impressão de sinais e espaços
    printf("Inteiro com sinal positivo: %+d\n", inteiro);
    printf("Inteiro com espaço para sinal: % d\n", inteiro);

    return 0;
}
