#ifndef READQRY_H
#define READQRY_H

#include "gerarTXT.h"
#include "gerarSVG.h"
#include "deslocamento.h"
#include "colisao.h"
#include "lancamento.h"
#include "lancadores.h"
#include "fila.h" 
#include "dadosTXT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    Modulo de leitura e processamento do arquivo QRY.

    Este modulo contem funcoes para a abertura e leitura do arquivo QRY, que contem os comandos
    que serao aplicados sobre as formas geometricas lidas do arquivo GEO. A funcao abrirQRY abre
    o arquivo e retorna um ponteiro para o mesmo, enquanto a funcao processarQRY interpreta e 
    executa os comandos presentes no arquivo, alterando as formas e atualizando informacoes como 
    pontuacao, numero de lancamentos e destruicoes.
*/

/// @brief Abre o arquivo qry
/// @param nomeqry Path do aqruivo qry
/// @return Ponteiro para o arquivo qry
FILE* abrirQRY(char* nomeqry);

/// @brief Processa as informacoes contidas no arquivo .qry
/// @param ptrTXT Ponteiro para o arquivo txt
/// @param ptrSVG Ponteiro para o arquivo svg
/// @param file Ponteiro para o arquivo qry
/// @param maiorID Ponteiro para o maior id lido no arquivo geo
/// @param filaR Fila de retangulos
/// @param filaC Fila de circulos
/// @param filaL Fila de linhas
/// @param filaT Fila de textos
/// @param lancR Lancador de retangulos
/// @param lancC Lancador de circulos
/// @param lancL Lancador de linhas
/// @param lancT Lancador de textos
/// @param instrucoes Ponteiro para o contador de instrucoes
/// @param lancamentos Ponteiro para o contador de lancamentos
/// @param formasdestruidas Ponteiro para o contador de formas destruidas
/// @param pontosRet Ponteiro para o valor dos pontos do lancador de retangulos
/// @param pontosCirc Ponteiro para o valor dos pontos do lancador de circulos
/// @param pontosLinha Ponteiro para o valor dos pontos do lancador de linhas
/// @param pontosTxt Ponteiro para o valor dos pontos do lancador de textos
/// @param formascriadas Ponteiro para o contador de formas criadas
void processarQRY(FILE* ptrTXT, FILE* ptrSVG, FILE* file, int* maiorID, fila* filaR, fila* filaC, fila* filaL, fila* filaT, lancador** lancR, lancador** lancC, lancador** lancL, lancador** lancT, int* instrucoes, int* lancamentos, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* formascriadas);

#endif