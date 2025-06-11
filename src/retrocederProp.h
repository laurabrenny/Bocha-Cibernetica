#ifndef RETROCEDERPROP_H
#define RETROCEDERPROP_H

#include "retangulo.h"
#include "circulo.h"
#include "texto.h"
#include "linha.h" 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/*
    Modulo de calculo para retrocesso de deslocamento, em casos que a area do alvo é significativamente
    maior que da ogiva, fazendo com que cada um retroceda na proporcao da area do outro em relacao a area 
    total.

    Este modulo contem funcoes para retroceder o deslocamento de formas geometricas pela metade,
    permitindo reverter parcialmente os efeitos de um movimento. A funcao retrocederMetade reduz 
    o deslocamento de uma forma pela metade, alterando sua posicao final.
*/

/// @brief Retrocede as formas proporcionalmente com base nas areas
/// @param areaOgiva Area da ogiva
/// @param areaAlvo Area do alvo
/// @param ogivaForma Ponteiro para a forma da ogiva
/// @param alvoForma Ponteiro para a forma do alvo
/// @param x1A Coordenada x1 do alvo
/// @param y1A Coordenada y1 do alvo
/// @param x2A Coordenada x2 do alvo
/// @param y2A Coordenada y2 do alvo
/// @param x1O Coordenada x1 da ogiva
/// @param y1O Coordenada y1 da ogiva
/// @param x2O Coordenada x2 da ogiva
/// @param y2O Coordenada y2 da ogiva 
void retrocederProporcional(double areaOgiva, double areaAlvo, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O);

#endif