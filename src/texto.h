#ifndef TEXTO_H
#define TEXTO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    Texto eh uma forma definida por sua coordenada ancora (x,y), que pode estar posicionada 
    no inicio, meio ou fim de seu texto. O texto depende de tres parametros: familia da fonte, 
    peso da fonte (normal, bold) e tamanho. Possui cor de preenchimento CORP, a cor de sua 
    borda CORB, e um ID, responsavel por diferenciar e unificar cada forma.
*/

typedef void* TEXTO;
typedef struct formaTexto formaTexto;
typedef struct estiloTexto estiloTexto;

/// @brief Inicializa a forma texto com os parametros fornecidos.
/// @param ID Id do texto
/// @param X x do texto
/// @param Y y do texto
/// @param CORB Cor de borda do texto
/// @param CORP Cor de preenchimento do texto
/// @param A Ancora do texto
/// @param TEXTO String texto do texto
/// @return Estrutura texto
TEXTO inicializaTexto (int ID, double X, double Y, char* CORB, char* CORP, char A, char* TEXTO);

/// @brief Define as caracteristicas do estilo do texto.
/// @param t Estrutura texto
/// @param FAMILY Familia do texto
/// @param WEIGHT Weight (peso) do texto
/// @param SIZE Tamanho do texto
void defineEstilo(TEXTO t, char* FAMILY, char* WEIGHT, char* SIZE);

/// @brief Retorna o id do texto.
/// @param t Estrutura texto
/// @return Id
int getIdTexto(TEXTO t);

/// @brief Retorna o x do texto.
/// @param t Estrutura texto
/// @return x
double getXTexto(TEXTO t);

/// @brief Retorna o y do texto.
/// @param t Estrutura texto
/// @return y
double getYTexto(TEXTO t);

/// @brief Retorna a cor de borda do texto.
/// @param t Estrutura texto
/// @return Corb
char* getCorbTexto(TEXTO t);

/// @brief Retorna a cor de preenchimento do texto.
/// @param t Estrutura texto
/// @return Corp
char* getCorpTexto(TEXTO t);

/// @brief Retorna a ancora do texto.
/// @param t Estrutura texto
/// @return a
char getATexto(TEXTO t);

/// @brief Retorna a string texto do texto.
/// @param t Estrutura texto
/// @return texto
char* getTexto(TEXTO t);

/// @brief Retorna o tipo (t) do texto.
/// @param t Estrutura texto
/// @return tipo
char getTipoTexto(TEXTO t);

/// @brief Retorna a familia do texto.
/// @param t Estrutura texto
/// @return family
char* getFamilyTexto(TEXTO t);

/// @brief Retorna o peso da fonte do texto.
/// @param t Estrutura texto
/// @return weight
char* getWeightTexto(TEXTO t);

/// @brief Retorna o tamanho da fonte do texto.
/// @param t Estrutura texto
/// @return size
char* getSizeTexto(TEXTO t);

/// @brief Retorna a area do texto.
/// @param t Estrutura texto
/// @return area
double getAreaTexto(TEXTO t);

/// @brief Retorna o numero de caracteres do texto.
/// @param t Estrutura texto
/// @return Num de caracteres
int getNumCaracteresTexto(TEXTO t);

/// @brief Define o x de um texto.
/// @param t Estrutura texto
/// @param X Novo x
void setXTexto(TEXTO t, double X);

/// @brief Define o y de um texto.
/// @param t Estrutura texto
/// @param Y Novo y
void setYTexto(TEXTO t, double Y);

#endif