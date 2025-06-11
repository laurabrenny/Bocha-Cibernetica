#ifndef LANCAMENTO_H
#define LANCAMENTO_H

#include "gerarSVG2.h"
#include "gerarTXT.h"
#include "colisao.h"
#include "deslocamento.h"
#include "lancadores.h"
#include "fila.h" 
#include "dadosTXT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/*
    Modulo de simulacao de lancamento de ogiva e alvo.

    Este modulo contem a implementacao do lancamento da ogiva e do alvo, realizando os calculos 
    do deslocamento das formas, verificando as colisoes, e atualizando os pontos e os contadores 
    de formas destruidas e criadas. O processo envolve o tratamento dos dados de lancamento, a 
    interacao com as funcoes de geracao de arquivos SVG e TXT, e a integracao com os modulos de 
    colisoes, deslocamento, lancadores e filas.
*/

/// @brief Simula o lancamento da ogiva e alvo, calculando o deslocamento, verificando colisoes e atualizando pontos e formas destruidas.
/// @param ptrTXT Ponteiro para o arquivo txt
/// @param ptrSVG Ponteiro para o arquivo svg
/// @param alvo Lancador do alvo
/// @param distAlvo Distancia do lancamento em relacao ao alvo
/// @param ogiva Lancador da ogiva
/// @param distOgiva Distancia do lancamento da ogiva
/// @param filaR Fila de retangulos
/// @param filaC Fila de circulos
/// @param filaL Fila de linhas
/// @param filaT Fila de textos
/// @param formasdestruidas Ponteiro para o contador de formas destruidas
/// @param pontosRet Ponteiro para o contador de pontos do lancador de retangulos
/// @param pontosCirc Ponteiro para o contador de pontos do lancador de circulos
/// @param pontosLinha Ponteiro para o contador de pontos do lancador de linhas
/// @param pontosTxt Ponteiro para o contador de pontos do lancador de textos
/// @param maiorID Ponteiro para o maior ID
/// @param formascriadas ponteiro para contador de formas criadas
void lancamentoAlvoOgiva(FILE* ptrTXT, FILE* ptrSVG, lancador* alvo, double distAlvo, lancador* ogiva, double distOgiva, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* maiorID, int* formascriadas);

#endif