#ifndef DESLOCAMENTO_H
#define DESLOCAMENTO_H

#include "lancadores.h"
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
    Modulo de calculo de deslocamento da forma e operacoes geometricas complementares, utilizados nos
    lançamentos das ogivas.

    Este modulo contem funcoes para calcular o deslocamento em x e y com base em uma distancia
    e um angulo de lancamento. Alem disso, ha funcoes auxiliares para o calculo do seno e do
    cosseno de um angulo. O modulo permite determinar as posicoes finais de uma forma apos um
    lancamento, bem como calcular o ponto medio entre dois pontos.
*/

/// @brief Calcula o deslocamento para o x.
/// @param x x inicial
/// @param distancia Distancia a ser percorrida
/// @param grau Grau de lançamento
/// @return Nova posiçao de x
double calcularDeslocamentoX(double x, double distancia, double grau);

/// @brief Calcula o deslocamento para o y.
/// @param y y inicial
/// @param distancia Distancia a ser percorrida
/// @param grau Grau de laçamento
/// @return Nova posicao de y
double calcularDeslocamentoY(double y, double distancia, double grau);

/// @brief Calcula seno de um angulo.
/// @param graus Angulo em graus
/// @return Valor do seno
double seno(double graus);

/// @brief Calcula cosseno de um angulo.
/// @param graus Angulo em graus
/// @return Valor do cosseno
double cosseno(double graus);

/// @brief Determina o x e y finais apos o deslocamento.
/// @param forma Forma geometrica
/// @param dist Distancia do lançamento
/// @param grau Grau de lançamento
/// @param x1 x1 final
/// @param y1 y1 final
/// @param x2 x2 final
/// @param y2 y2 final
void determinarDeslocamento(void* forma, double dist, double grau, double* x1, double* y1, double* x2, double* y2);

/// @brief Funcao que calcula o ponto medio entre dois pontos (x1, y1) e (x2, y2).
/// @param x1 x1
/// @param y1 y1
/// @param x2 x2
/// @param y2 y2
/// @param xm x no ponto medio
/// @param ym y no ponto medio
void pontoMedio(double x1, double y1, double x2, double y2, double* xm, double* ym);

/// @brief Calcula a distancia entre dois pontos
/// @param x1 
/// @param y1 
/// @param x2 
/// @param y2 
/// @return Valor dessa distancia
double distanciaEntrePontos(double x1, double y1, double x2, double y2);

#endif