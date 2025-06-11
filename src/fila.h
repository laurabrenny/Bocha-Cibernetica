#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"

/*
    Uma fila eh uma estrutura de dados que segue a logica FIFO (First In, First Out).
    Dessa forma, o primeiro elemento inserido eh o primeiro a ser removido. Esse 
    comportamento garante que os dados sejam processados na mesma ordem em que foram 
    adicionados. Na implementacao de uma fila, as operacoes basicas sao o enfileiramento, 
    que adiciona um novo elemento ao final da fila, e o desenfileiramento, que remove o 
    elemento que esta no inicio.
    Este modulo possui funcoes que operam sobre as filas, como inicializar, enfileirar,
    imprimir todos os seus elementos, remover (desenfileirar) o primeiro elemento, e por fim,
    liberar a memoria da fila e todos seus nos.
*/

typedef struct no no;
typedef struct fila fila;

/// @brief Inicializa uma fila.
/// @param f Fila para inicializar
void inicializarFila(fila** f);

/// @brief Insere o elemento fornecido na fila que corresponde a sua forma.
/// @param filaR Fila de retangulos
/// @param filaC Fila de circulos
/// @param filaL Fila de linhas
/// @param filaT Fila de textos
/// @param forma Forma geometrica a ser inserida
void enfileirar(fila* filaR, fila* filaC, fila* filaL, fila* filaT, void* forma);

/// @brief Percorre todos os elementos da fila e os imprime no arquivo SVG.
/// @param f Fila 
/// @param arquivo Ponteiro para o arquivo svg
void printarFilaSVG(fila* f, FILE *arquivo);

/// @brief Retira o primeiro elemento da fila e retorna um ponteiro para ele.
/// @param f Fila
/// @return Ponteiro para o primeiro elemento da fila
void* getPrimeiroElemento(fila* f);

/// @brief Liberar memoria da fila
/// @param f Fila
void freeFila(fila* f);

#endif