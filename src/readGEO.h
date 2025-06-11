#ifndef READGEO_H
#define READGEO_H

#include "fila.h"
#include "dadosTXT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    Modulo de leitura e processamento do arquivo GEO.

    Este modulo contem funcoes para a abertura e leitura do arquivo GEO, que contem as
    informacoes de formas geometricas a serem utilizadas posteriormente. A funcao abrirGEO abre
    o arquivo e retorna um ponteiro para o mesmo, enquanto a funcao processarGEO le e processa as
    informacoes contidas no arquivo, organizando as formas em filas e atualizando contadores de
    formas criadas e de instrucoes lidas. Alem disso, a funcao obterMaiorId le o arquivo GEO para
    determinar o maior id presente, incrementando-o para ser utilizado na criacao de clones.
*/

/// @brief Abre o arquivo geo.
/// @param nomeGEO Path do arquivo geo
/// @return Ponteiro para o arquivo geo
FILE* abrirGEO(char* nomeGEO);

/// @brief Processa as informacoes contidas no arquivo geo.
/// @param file Ponteiro para o arquivo geo
/// @param filaR Fila de retangulos
/// @param filaC Fila de circulos
/// @param filaL Fila de linhas
/// @param filaT Fila de textos
/// @param formascriadas Ponteiro para o contador de formas criadas
/// @param intrucoes Ponteiro para o contador de instrucoes (linhas lidas)
void processarGEO(FILE* file, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formascriadas, int* intrucoes);

/// @brief Obtem o maior id lido de um arquivo geo, e incrementa 1, para ser usado nos clones.
/// @param nomeGEO Path do arquivo geo
/// @return Maior id +1
int obterMaiorId(char* nomeGEO);

#endif