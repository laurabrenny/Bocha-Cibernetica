#ifndef GERARSVG_H
#define GERARSVG_H

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
    Modulo de geracao do arquivo SVG, referente ao arquivo geo.

    Um arquivo SVG eh um arquivo de imagem vetorial baseado em XML. Esse formato 
    permite que as imagens sejam representadas como um conjunto de formas geometricas 
    (linhas, retangulos, circulos, etc). O arquivo svg é utilizado para mostrar graficamente
    as formas geometricas, suas cores, tamanhos, coordenadas etc.
    
    Este modulo contem funcoes para abrir e gerar o arquivo SVG a partir dos elementos presentes
    nas filas de formas geometricas. A funcao abrirSVGgeo abre o arquivo para escrita e a
    funcao gerarSVG_GEO imprime no arquivo os elementos contidos nas filas de retangulos,
    circulos, linhas e textos, permitindo a visualizacao dos dados.
*/

/// @brief Abre o arquivo svg do geo
/// @param nome Nome do arquivo svg
/// @return Ponteiro para o arquivo svg
FILE* abrirSVGgeo(char* nome);

/// @brief Imprime no svg todos os elementos contidos no arquivo geo 
/// @param file Ponteiro para o arquivo svg
/// @param filaR Fila de retangulos
/// @param filaC Fila de circulos
/// @param filaL Fila de linhas
/// @param filaT Fila de textos
void gerarSVG_GEO(FILE* file, fila* filaR, fila* filaC, fila* filaL, fila* filaT);

#endif