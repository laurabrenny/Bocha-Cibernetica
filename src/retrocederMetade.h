#ifndef RETROCEDERMETADE_H
#define RETROCEDERMETADE_H

#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/*
    Modulo de calculo de retrocesso de deslocamento, para o caso em que as areas do alvo e ogiva
    tem tamanhos semelhantes.
    Este modulo contem funcoes para retroceder o deslocamento de formas geometricas pela metade,
    permitindo reverter parcialmente os efeitos de um lancamento. A funcao retrocederMetade reduz 
    o deslocamento de uma forma pela metade, enquanto a funcao atualizarPosicao redefine suas 
    coordenadas para uma nova posicao especificada.
*/

/// @brief Retrocede a forma para metade do deslocamento.
/// @param forma Ponteiro para a forma a ser retrocedida
/// @param x1 Coordenada x1 da forma
/// @param y1 Coordenada y1 da forma
/// @param x2 Coordenada x2 da forma
/// @param y2 Coordenada y2 da forma
void retrocederMetade(void* forma, double x1, double y1, double x2, double y2);

/// @brief Atualiza a posicao de uma forma.
/// @param forma Ponteiro para a forma a ter a posicao atualizada
/// @param x1 Nova coordenada x1 da forma
/// @param y1 Nova coordenada y1 da forma
/// @param x2 Nova coordenada x2 da forma
/// @param y2 Nova coordenada y2 da forma 
void atualizarPosicao(void* forma, double x1, double y1, double x2, double y2);

#endif