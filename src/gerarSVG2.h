#ifndef GERARSVG2_H
#define GERARSVG2_H

#include "tratarArquivos.h"
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"
#include "fila.h" 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    Modulo de geracao de arquivo SVG, apos as alteracoes feitas (lancamentos, colisoes, destruicoes)
    pelas informacoes contidas no arquivo qry.

    Este modulo contem funcoes para abrir e gerar um arquivo SVG que contem as alteracoes realizadas
    pelo modulo QRY. Um arquivo SVG eh um arquivo de imagem vetorial baseado em XML. No formato SVG,
    as imagens sao representadas por formas geometricas (como retangulos, circulos, linhas e textos)
    que podem ser escaladas para qualquer tamanho.

    As funcoes deste modulo possibilitam abrir o arquivo segundo SVG, imprimir marcacoes para a destruicao
    do alvo e da ogiva, imprimir as formas restantes contidas nas filas e fechar o arquivo ao final.
*/

/// @brief Abre o arquivo svg que contem alteraçoes feitas pelo qry
/// @param nome Nome do arquivo svg
/// @return Ponteiro para o arquivo svg
FILE* abrirSVG2(char* nome);

/// @brief Imprime no svg * no lugar da destruiçao do alvo
/// @param file Ponteiro para o arquivo svg
/// @param x x
/// @param y y
void printarDestruicaoAlvoSVG2(FILE* file, double x, double y);

/// @brief Imprime no svg * no lugar da destruiçao da ogiva
/// @param file Ponteiro para o arquivo svg
/// @param ogivaForma Forma da ogiva
/// @param x x
/// @param y y
void printarDestruicaoOgivaSVG2(FILE* file, void* ogivaForma, double x, double y);

/// @brief Imprime as formas presentes nas filas no arquivo svg
/// @param file Ponteiro para o arquivo svg
/// @param filaR Fila de retangulos
/// @param filaC Fila de circulos
/// @param filaL Fila de linhas
/// @param filaT Fila de textos
void printarFormasRestantesSVG2(FILE* file, fila* filaR, fila* filaC, fila* filaL, fila* filaT);

/// @brief Fecha o arquivo svg
/// @param file Ponteiro para o arquivo svg
void fecharSVG2(FILE* file);

#endif