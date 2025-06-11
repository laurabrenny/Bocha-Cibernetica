#ifndef CLONAGEM_H
#define CLONAGEM_H
#include "fila.h"
#include "dadosTXT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    Modulo de clonagem das formas geometricas.
    
    Este modulo fornece uma funcao para clonar formas geometricas, criando uma nova 
    instancia da forma original com os mesmos atributos, exceto pelo ID, que eh unico,
    sendo atualizado a cada clonagem. A clonagem acontece em casos de colisoes entre 
    duas formas com areas semelhantes. Ademais, o clone eh posicionado na posicao de colisao.
    As formas podem ser retangulos, circulos, linhas ou textos.
*/

/// @brief Clona uma forma geometrica, criando uma nova com os mesmos atributos.
/// @param original Forma que deseja clonar
/// @param x Coordenada final x
/// @param y Coordenada final y
/// @param x2 Coordenada final x2
/// @param y2 Coordenada final y2
/// @param maiorID Ponteiro para o valor do maior ID
/// @return Ponteiro para a forma clonada
void* clonarForma(void* original, double x, double y, double x2, double y2, int *maiorID);

#endif