#ifndef CIRCULO_H
#define CIRCULO_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    Circulo eh uma forma definida por sua coordenada ancora (x,y), posicionada em seu centro.
    Seu tamanho eh definido pelo seu raio. Alem disso, possui tambem sua cor de preenchimento
    CORP, a cor de sua borda CORB, e um ID, responsavel por diferenciar e unificar cada forma.
*/

#define PI 3.14159265358979323846
typedef void* CIRCULO;
typedef struct formaCirculo formaCirculo;

/// @brief Inicializa a forma circulo com os parâmetros fornecidos
/// @param ID  Id
/// @param X x
/// @param Y y
/// @param RAIO Raio
/// @param CORB Cor da borda
/// @param CORP Cor do preenchimento
/// @return Estrutura círculo
CIRCULO inicializaCirculo(int ID, double X, double Y, double RAIO, char* CORB, char* CORP);


/// @brief Retorna o valor do id do círculo
/// @param circulo Forma 
/// @return Valor do id
int getIdCirculo(CIRCULO circulo);


/// @brief Retorna x do círculo
/// @param circulo Forma
/// @return Valor do x
double getXCirculo(CIRCULO circulo);


/// @brief Retorna y do círculo
/// @param circulo Forma
/// @return Valor do y
double getYCirculo(CIRCULO circulo);


/// @brief Retorna raio do círculo
/// @param circulo Forma
/// @return Valor do raio
double getRaioCirculo(CIRCULO circulo);


/// @brief Retorna a string corb
/// @param circulo Forma
/// @return String cor da borda
char* getCorbCirculo(CIRCULO circulo);


/// @brief Retorna a string corp
/// @param circulo Forma
/// @return String cor de preenchimento
char* getCorpCirculo(CIRCULO circulo);


/// @brief Retorna o tipo da forma
/// @param circulo Forma
/// @return Char tipo
char getTipoCirculo(CIRCULO circulo);

/// @brief Retorna area do círculo
/// @param circulo Forma
/// @return Valor da area
double getAreaCirculo(CIRCULO circulo);

/// @brief Atualiza x do circulo
/// @param circulo Forma
/// @param X Valor de x
void setXCirculo(CIRCULO circulo, double X);

/// @brief Atualiza y do circulo
/// @param circulo Forma
/// @param Y Valor de y
void setYCirculo(CIRCULO circulo, double Y);

#endif
