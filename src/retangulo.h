#ifndef RETANGULO_H
#define RETANGULO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    Retangulo eh uma forma definida por sua coordenada ancora (x,y), posicionada em seu canto 
    superior esquerdo. Seu tamanho eh definido pelaa altura H, e largura W. Alem disso, possui
    tambem sua cor de preenchimento CORP, a cor de sua borda CORB, e um ID, responsavel por
    diferenciar e unificar cada forma.
*/

typedef void* RETANGULO;
typedef struct formaRetangulo formaRetangulo;

/// @brief Inicializa a forma retangulo com os parametros fornecidos
/// @param ID Id
/// @param X Coordenada x
/// @param Y Coordenada y
/// @param W Largura
/// @param H Altura
/// @param CORB Cor da borda
/// @param CORP Cor de preenchimento
/// @return Estrutura retangulo
RETANGULO inicializaRetangulo(int ID, double X, double Y, double W, double H, char* CORB, char* CORP);

/// @brief Retorna id do retangulo
/// @param retangulo Forma
/// @return Valor de id
int getIdRetangulo(RETANGULO retangulo);

/// @brief Retorna x do retangulo
/// @param retangulo Forma
/// @return Valor de x
double getXRetangulo(RETANGULO retangulo);

/// @brief Retorna y do retangulo
/// @param retangulo Forma
/// @return Valor de y
double getYRetangulo(RETANGULO retangulo);

/// @brief Retorna largura do retangulo
/// @param retangulo Forma
/// @return Valor de largura
double getWRetangulo(RETANGULO retangulo);

/// @brief Retorna altura do retangulo
/// @param retangulo Forma
/// @return Valor da altura
double getHRetangulo(RETANGULO retangulo);

/// @brief Retorna string corb
/// @param retangulo Forma
/// @return String de cor de borda
char* getCorbRetangulo(RETANGULO retangulo);

/// @brief Retorna string corp
/// @param retangulo Forma
/// @return String da cor de preenchimento
char* getCorpRetangulo(RETANGULO retangulo);

/// @brief Retorna tipo da forma
/// @param retangulo Forma
/// @return Char de tipo
char getTipoRetangulo(RETANGULO retangulo);

/// @brief Retorna area do retangulo
/// @param retangulo Forma
/// @return Valor da area
double getAreaRetangulo(RETANGULO retangulo);

/// @brief Atualiza x do retangulo
/// @param retangulo Forma
/// @param X Valor de x
void setXRetangulo(RETANGULO retangulo, double X);

/// @brief Atualiza y do retangulo
/// @param retangulo Forma
/// @param Y Valor de y
void setYRetangulo(RETANGULO retangulo, double Y);

#endif