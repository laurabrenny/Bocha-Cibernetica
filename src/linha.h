#ifndef LINHA_H
#define LINHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/*
    Linha eh uma forma definida por suas coordenadas ancoras (x1, y1) e (x2, y2), 
    posicionadas em suas extremidades. Alem disso, possui tambem sua cor e um ID, 
    responsavel por diferenciar e unificar cada forma.
*/

typedef void* LINHA;
typedef struct formaLinha formaLinha;

/// @brief Inicializa uma estrutura de linha com os dados fornecidos
/// @param ID Id
/// @param X1  X do primeiro ponto da linha
/// @param X2  X do segundo ponto da linha
/// @param Y1  Y do primeiro ponto da linha
/// @param Y2  Y do segundo ponto da linha
/// @param COR Cor da linha
/// @return Estrutura LINHA inicializada
LINHA inicializaLinha(int ID, double X1, double X2, double Y1, double Y2, char* COR);

/// @brief Retorna o id da linha
/// @param linha Estrutura linha
/// @return ID da linha
int getIdLinha(LINHA linha);

/// @brief Retorna a coordenada X do primeiro ponto da linha
/// @param linha Estrutura linha
/// @return Coordenada X1 da linha
double getX1Linha(LINHA linha);

/// @brief Retorna a coordenada Y do primeiro ponto da linha
/// @param linha Estrutura linha
/// @return Coordenada Y1 da linha
double getY1Linha(LINHA linha);

/// @brief Retorna a coordenada X do segundo ponto da linha
/// @param linha Estrutura linha.
/// @return Coordenada X2 da linha
double getX2Linha(LINHA linha);

/// @brief Retorna a coordenada Y do segundo ponto da linha
/// @param linha Estrutura linha
/// @return Coordenada Y2 da linha
double getY2Linha(LINHA linha);

/// @brief Retorna a cor da linha
/// @param linha Estrutura linha
/// @return Cor da linha
char* getCorLinha(LINHA linha);

/// @brief Retorna o tipo da forma 
/// @param linha Estrutura linha.
/// @return Tipo da linha 
char getTipoLinha(LINHA linha);

/// @brief Retorna a area associada à linha 
/// @param linha Estrutura linha.
/// @return Area da linha 
double getAreaLinha(LINHA linha);

/// @brief Calcula a distancia entre dois pontos
/// @param x1 Coordenada X do primeiro ponto
/// @param y1 Coordenada Y do primeiro ponto
/// @param x2 Coordenada X do segundo ponto.
/// @param y2 Coordenada Y do segundo ponto
/// @return Distancia entre os dois pontos
double calcularDistanciaPontos(double x1, double y1, double x2, double y2);

/// @brief Define a coordenada X do primeiro ponto da linha
/// @param linha Estrutura linha
/// @param X1 Nova coordenada X1
void setX1Linha(LINHA linha, double X1);

/// @brief Define a coordenada Y do primeiro ponto da linha
/// @param linha Estrutura linha
/// @param Y1 Nova coordenada Y1
void setY1Linha(LINHA linha, double Y1);

/// @brief Define a coordenada X do segundo ponto da linha
/// @param linha Estrutura linha
/// @param X2 Nova coordenada X2
void setX2Linha(LINHA linha, double X2);

/// @brief Define a coordenada Y do segundo ponto da linha
/// @param linha Estrutura linha
/// @param Y2 Nova coordenada Y2
void setY2Linha(LINHA linha, double Y2);

#endif