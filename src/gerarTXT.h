#ifndef GERARTXT_H
#define GERARTXT_H

#include "tratarArquivos.h"
#include "dadosTXT.h"
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/*
    Modulo de geracao do arquivo TXT, que contem informacoes sobre cada lancamento e seus efeitos,
    assim como os dados finais sobre quantidade de formas criadas, pontuacao etc.

    Este modulo contem funcoes para a geracao e manipulacao de um arquivo TXT que registra os 
    comandos e os resultados das operacoes realizadas no programa. No arquivo TXT sao impressas diversas 
    informacoes, incluindo os parametros das formas antes e depois do lancamento, os comandos rt e lc, 
    os efeitos dos lancamentos e os dados dos clones. Alem disso, sao registrados os valores finais de 
    pontuacao, numero de instrucoes, lancamentos, formas destruidas e formas criadas. Esse modulo permite 
    abrir, escrever e fechar o arquivo TXT, facilitando a geracao de um relatorio detalhado das operacoes realizadas.
*/

/// @brief Abre o arquivo txt
/// @param nomeTXT Nome do arquivo
/// @return Ponteiro para o arquivo txt
FILE* abrirTXT(char* nomeTXT);

/// @brief Imprime cada comando [*] rt, informando o tipo do lancador, e seu grau de lancamento, no arquivo txt
/// @param ptrTXT Ponteiro para o arquivo txt
/// @param tipoLancador Tipo do lancador (R, C, L, T)
/// @param grauLancador Grau de lancamento do lancador
void printarRtTXT(FILE* ptrTXT, char tipoLancador, double grauLancador);

/// @brief Imprime cada comando [*] lc, informando o alvo, ogiva e suas distancias, no arquivo txt
/// @param ptrTXT Ponteiro para o arquivo txt
/// @param alvo Tipo do alvo (R, C, L, T)
/// @param ogiva Tipo da ogiva (R, C, L, T)
/// @param dA Distancia do alvo
/// @param dO Distancia da ogiva
void printarLcTXT(FILE* ptrTXT, char alvo, char ogiva, double dA, double dO);

/// @brief Imprime todos os parametros as formas antes do lancamento
/// @param txt Ponteiro para o arquivo txt
/// @param formaAlvo Alvo
/// @param formaOgiva Ogiva
void formasAntesTXT(FILE* txt, void* formaAlvo, void* formaOgiva);

/// @brief Imprime, no txt, as coordenadas X e Y do alvo e da ogiva apos o deslocamento
/// @param txt Ponteiro para o arquivo txt
/// @param formaAlvo Estrutura do alvo
/// @param formaOgiva Estrutura da ogiva
/// @param x1A x1 do alvo
/// @param y1A y1 do alvo
/// @param x2A x2 do alvo
/// @param y2A y2 do alvo
/// @param x1O x1 da ogiva
/// @param y1O y1 da ogiva
/// @param x2O x2 da ogiva
/// @param y2O y2 da ogiva
void XYaposDeslocamentoTXT(FILE* txt, void* formaAlvo, void* formaOgiva, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O);

/// @brief Imprime todos os parametros das formas depois do lancamento
/// @param nomeTXT Ponteiro para o arquivo
/// @param ogiva Estrutura da ogiva
/// @param alvo Estrutura do alvo
void formasDepoisTXT(FILE* txt, void* ogiva, void* alvo);

/// @brief Imprime todos os parametros da ogiva depois do lancamento (alvo destruido)
/// @param txt Ponteiro para o arquivo txt
/// @param formaOgiva Estrutura da ogiva
/// @param ponto Pontuacao pelo lancamento
void formasDepoisTXTogiva(FILE* txt, void* formaOgiva, double ponto);

/// @brief Imprime todos os parametros do alvo apos lancamento (ogiva destruida)
/// @param txt Ponteiro para o arquivo txt
/// @param formaAlvo Alvo
void formasDepoisTXTalvo(FILE* txt, void* formaAlvo);

/// @brief Reporta os dados dos clones formados
/// @param txt Ponteiro para o arquivo txt
/// @param cloneAlvo Forma do alvo clonada
/// @param cloneOgiva Forma da ogiva clonada
void dadosClonesTXT(FILE* txt, void* cloneAlvo, void* cloneOgiva);

/// @brief Imprime se teve colisao ou nao, e caso tiver, se a colisao foi de formas: com areas semelhantes ou alguma area maior
/// @param txt Ponteiro para o arquivo txt
/// @param identificador Identifica o tipo de colisao (s,o,a), ou se nao teve colisao (n)
void efeitosLancamentoTXT(FILE* txt, char identificador);

/// @brief Imprime os valores finais de: pontuacao, num de instrucoes, lancamentos, formas destruidas e formas criadas
/// @param txt Ponteiro para o arquivo txt
/// @param intrucoes Ponteiro para o contador de intrucoes executadas
/// @param lancamentos Ponteiro para o contador de lancamentos feitos
/// @param formasDestruidas Ponteiro para o contador de formas destruidas
/// @param formasCriadas Ponteiro para o contador de formas criadas
/// @param pontosRet Ponteiro para o contador de pontos do lancador de retangulos
/// @param pontosCirc Ponteiro para o contador de pontos do lancador de círculos
/// @param pontosLinha Ponteiro para o contador de pontos do lancador de linhas
/// @param pontosTxt Ponteiro para o contador de pontos do lancador de textos
void ImprimirDadosTXT(FILE* txt, int* intrucoes, int* lancamentos, int* formasDestruidas, int* formasCriadas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt);

/// @brief Fecha o arquivo txt
/// @param txt Ponteiro para o arquivo txt
void fecharTXT(FILE* txt);

#endif