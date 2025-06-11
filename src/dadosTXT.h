#ifndef DADOSTXT_H
#define DADOSTXT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"

/*
    Modulo de atualizacao e geracao de dados para pontuacao e estatisticas do jogo, dados registrados 
    posteriormente no arquivo txt.

    Este modulo possui funcoes para atualizar a pontuacao obtida no jogo, de acordo com o tipo de forma
    (retangulo, circulo, linha ou texto), calcular o ponto de lancamento com base nas areas da ogiva
    e do alvo, e atualizar contadores de instrucoes, lancamentos, formas criadas e formas destruidas.
    Adicionalmente, ha funcoes getters para obter os valores atuais desses contadores e das pontuacoes dos
    diferentes tipos de lancadores.
*/

/// @brief Atualiza os pontos de acordo com o tipo da forma (retangulo, circulo, linha ou texto).
/// @param ponto Valor do ponto a ser adicionado
/// @param ogivaForma Ponteiro para a forma da ogiva
/// @param pontosRet Ponteiro para o contador de pontos dos retangulos
/// @param pontosCirc Ponteiro para o contador de pontos dos circulos
/// @param pontosLinha Ponteiro para o contador de pontos das linhas
/// @param pontosTxt Ponteiro para o contador de pontos dos textos
void atualizaPontos(double ponto, void* ogivaForma, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt);

/// @brief Calcula o ponto de lançamento com base na area da ogiva e do alvo.
/// @param areaOgiva Área da ogiva
/// @param areaAlvo Área do alvo
/// @return O ponto de lançamento calculado
double calcularPontoLancamento(double areaOgiva, double areaAlvo);

/// @brief Atualiza o contador de instrucoes.
/// @param instrucoes Ponteiro para o contador de instrucoes
void atualizarInstrucoes(int* instrucoes);

/// @brief Atualiza o contador de lancamentos.
/// @param lancamentos Ponteiro para o contador de lancamentos
void atualizarLancamentos(int* lancamentos);

/// @brief Atualiza o contador de formas destruidas.
/// @param formasDestruidas Ponteiro para o contador de formas destruídas
void atualizarFormasDestruidas(int* formasDestruidas);

/// @brief Atualiza o contador de formas criadas.
/// @param formasCriadas Ponteiro para o contador de formas criadas
void atualizarFormasCriadas(int* formasCriadas);

/// @brief Retorna o valor final do contador de instrucoes.
/// @param instrucoes Ponteiro para o contador de instrucoes
/// @return Valor atual do contador de instrucoes
int getInstrucoes(int* instrucoes);

/// @brief Retorna o valor final do contador de lancamentos.
/// @param lancamentos Ponteiro para o contador de lancamentos
/// @return Valor atual do contador de lancamentos
int getLancamentos(int* lancamentos);

/// @brief Retorna o valor final do contador de formas destruidas.
/// @param formasDestruidas Ponteiro para o contador de formas destruidas
/// @return Valor atual do contador de formas destruidas
int getFormasDestruidas(int* formasDestruidas);

/// @brief Retorna o valor final do contador de formas criadas.
/// @param formasCriadas Ponteiro para o contador de formas criadas
/// @return Valor atual do contador de formas criadas
int getFormasCriadas(int* formasCriadas);

/// @brief Retorna o valor acumulado dos pontos para o lancador de  retangulos.
/// @param pontosRet Ponteiro para o contador de pontos dos retângulos
/// @return Valor atual dos pontos para o lançador de retângulos
double getPontosRet(double* pontosRet);

/// @brief Retorna o valor acumulado dos pontos para o lancador de circulos.
/// @param pontosCirc Ponteiro para o contador de pontos dos circulos
/// @return Valor atual dos pontos para o lançador de circulos
double getPontosCirc(double* pontosCirc);

/// @brief Retorna o valor acumulado dos pontos para o lancador de linhas.
/// @param pontosLinha Ponteiro para o contador de pontos das linhas
/// @return Valor atual dos pontos para o lancador de linhas
double getPontosLinha(double* pontosLinha);

/// @brief Retorna o valor acumulado dos pontos para o lancador de textos.
/// @param pontosTxt Ponteiro para o contador de pontos dos textos
/// @return Valor atual dos pontos para o lancador de textos
double getPontosTxt(double* pontosTxt);

#endif