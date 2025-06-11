#ifndef COLISAO_H
#define COLISAO_H

#include "clonagem.h"
#include "lancadores.h"
#include "fila.h" 
#include "dadosTXT.h"
#include "retrocederMetade.h"
#include "retrocederProp.h"
#include "gerarSVG2.h"
#include "gerarTXT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/*
    Modulo de deteccao e tratamento de colisoes entre as diferentes formas geometricas.
    
    Este modulo contem diversas funcoes para verificar se houve colisoes entre retangulos, circulos, 
    linhas e textos, retornando 1 para colisao, e 0 se nao houve colisao. Tambem eh presente a funcao 
    verificaColisao, para calcular os efeitos das colisoes, incluindo a destruicao de formas, clonagem
    e a pontuacao para os diferentes tipos de lançadores (R, C, L e T). 
    Alem disso, a funcao semColisao trata os efeitos para os casos que nao houveram colisao entre as formas.
*/

/// @brief Verifica se houve colisao entre dois retangulos.
/// @param alvo Forma do alvo
/// @param ogiva Forma da ogiva
/// @param xAlvo x do alvo
/// @param yAlvo y do alvo
/// @param xOgiva x do alvo
/// @param yOgiva y da ogiva
/// @return 1 se teve colisao, 0 se não teve colisao
int colisaoRetRet(RETANGULO alvo, RETANGULO ogiva, double xAlvo, double yAlvo, double xOgiva, double yOgiva);

/// @brief Verifica se houve colisao entre um retangulo e um circulo.
/// @param ret Retangulo
/// @param circ Circulo
/// @param xR x do retangulo
/// @param yR y do retangulo
/// @param xC x do círculo
/// @param yC y do círculo
/// @return 1 se teve colisao, 0 se não teve colisao.
int colisaoRetCirc(RETANGULO ret, CIRCULO circ, double xR, double yR, double xC, double yC);

/// @brief Verifica se houve colisao entre um retangulo e uma linha.
/// @param ret Retangulo
/// @param linha Linha
/// @param xR x do retangulo
/// @param yR y do retangulo
/// @param x1 x da linha
/// @param y1 y da linha
/// @param x2 x2 da linha
/// @param y2 y2 da linha
/// @return 1 se teve colisao, 0 se não teve colisao.
int colisaoRetLinha(RETANGULO ret, LINHA linha, double xR, double yR, double x1, double y1, double x2, double y2);

/// @brief Verifica se houve colisao entre um retangulo e um texto.
/// @param retangulo Retangulo
/// @param texto Texto
/// @param xR x do retângulo
/// @param yR y do retângulo
/// @param xt x do texto
/// @param yt y do texto
/// @return 1 se teve colisao, 0 se não teve colisao
int colisaoRetTexto(RETANGULO retangulo, TEXTO texto, double xR, double yR, double xt, double yt);

/// @brief Verifica se houve colisao entre dois circulos.
/// @param c1 Circulo 1
/// @param c2 Circulo2
/// @param x1 x do primeiro circulo
/// @param y1 y do primeiro circulo
/// @param x2 x do segundo circulo
/// @param y2 y do segundo circulo
/// @return 1 se teve colisao, 0 se nao teve colisao
int colisaoCircCirc(CIRCULO c1, CIRCULO c2, double x1, double y1, double x2, double y2);

/// @brief Verifica se houve colisao entre um circulo e uma linha.
/// @param c Círculo
/// @param l Linha
/// @param xc x do círculo
/// @param yc y do círculo
/// @param x1 x da linha
/// @param y1 y da linha
/// @param x2 x2 da linha
/// @param y2 y2 da linha
/// @return 1 se teve colisao, 0 se nao teve colisao
int colisaoCircLinha(CIRCULO c, LINHA l, double xc, double yc, double x1, double y1, double x2, double y2);

/// @brief Verifica se houve colisao entre um texto e um circulo.
/// @param c círculo
/// @param texto Texto
/// @param xc x do círculo
/// @param yc y do círculo
/// @param xt x do texto
/// @param yt y do texto
/// @return 1 se teve colisao, 0 se nao teve colisao
int colisaoCircTexto(CIRCULO c, TEXTO texto, double xc, double yc, double xt, double yt);

/// @brief Verifica se houve colisao entre duas linhas.
/// @param l1 Linha 1
/// @param l2 Linha 2
/// @param x1 x da linha 1
/// @param y1 y da linha 1
/// @param x2 x2 da linha 1
/// @param y2 y2 da linha 1
/// @param x3 x da linha 2
/// @param y3 y da linha 2
/// @param x4 x2 da linha 2
/// @param y4 y2 da linha 2
/// @return 1 se teve colisao, 0 se nao teve colisao
int colisaoLinhaLinha(LINHA l1, LINHA l2, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

/// @brief Verifica se houve colisao entre um texto e uma linha.
/// @param linha Linha
/// @param texto Texto
/// @param xt x do texto
/// @param yt y do texto
/// @param xL1 x da linha 
/// @param yL1 y da linha
/// @param xL2 x2 da linha
/// @param yL2 y2 da linha
/// @return 1 se teve colisao, 0 se nao teve colisao
int colisaoLinhaTexto(LINHA linha, TEXTO texto, double xt, double yt, double xL1, double yL1, double xL2, double yL2);

/// @brief Verifica se houve colisao entre dois textos.
/// @param texto1 Texto 1
/// @param texto2 Texto 2
/// @param xt1 x do texto 1
/// @param yt1 y do texto 1
/// @param xt2 x do texto 2
/// @param yt2 y do texto 2
/// @return 1 se teve colisao, 0 se nao teve colisao
int colisaoTextoTexto(TEXTO texto1, TEXTO texto2, double xt1, double yt1, double xt2, double yt2);

/// @brief Verifica se houve intersecao entre dois segmentos.
/// @param x1 x1 do primeiro segmento
/// @param y1 y1 do primeiro segmento
/// @param x2 x2 do primeiro segmento
/// @param y2 y2 do primeiro segmento
/// @param x3 x1 do segundo segmento
/// @param y3 y1 do segundo segmento
/// @param x4 x2 do segundo segmento
/// @param y4 y2 do segundo segmento
/// @return 1 se teve intersecao, 0 se nao teve intersecao
int intersecaoSegmentos(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

/// @brief Recebe as formas do alvo, ogiva e seus lancadores e os direciona para as funcoes de colisao.
/// @param ptrTXT Ponteiro para o arquivo txt
/// @param ptrSVG Ponteiro para o arquivo svg
/// @param ALVO Lançador do alvo
/// @param OGIVA Lançador da ogiva
/// @param ogivaForma Forma da ogiva
/// @param alvoForma Forma do alvo
/// @param x1A x1 do alvo
/// @param y1A y1 do alvo
/// @param x2A x2 do alvo
/// @param y2A y2 do alvo
/// @param x1O x1 da ogiva
/// @param y1O y1 da ogiva
/// @param x2O x2 da ogiva
/// @param y2O y2 da ogiva
/// @param filaR Fila de retangulos
/// @param filaC Fila de circulos
/// @param filaL Fila de linhas
/// @param filaT Fila de textos
/// @param formasdestruidas Ponteiro para o contador de formas destruidas
/// @param pontosRet Ponteiro para a pontuacao de lancador de retângulos
/// @param pontosCirc Ponteiro para a pontuacao de lancador de circulos
/// @param pontosLinha Ponteiro para a pontuacao de lancador de linhas
/// @param pontosTxt Ponteiro para a pontuacao de lancador de textos
/// @param maiorID Ponteiro para o valor do maior ID lido
/// @param formascriadas ponteiro para contador de formas criadas
void verificaColisao(FILE* ptrTXT, FILE* ptrSVG, lancador* ALVO, lancador* OGIVA, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* maiorID, int* formascriadas);

/// @brief Calcula e realiza os efeitos causados pela colisao entre as formas.
/// @param ptrTXT ponteiro para arquivo de texto
/// @param ptrSVG ponteiro para arquivo SVG
/// @param maiorID ponteiro para maior ID
/// @param ogivaForma ponteiro para forma da ogiva
/// @param alvoForma ponteiro para forma do alvo
/// @param x1A coordenada x1 do alvo
/// @param y1A coordenada y1 do alvo
/// @param x2A coordenada x2 do alvo
/// @param y2A coordenada y2 do alvo
/// @param x1O coordenada x1 da ogiva
/// @param y1O coordenada y1 da ogiva
/// @param x2O coordenada x2 da ogiva
/// @param y2O coordenada y2 da ogiva
/// @param filaR fila de retangulos
/// @param filaC fila de circulos
/// @param filaL fila de linhas
/// @param filaT fila de triagulos
/// @param formasdestruidas ponteiro para contador de formas destruidas
/// @param pontosRet ponteiro para pontos de retangulos
/// @param pontosCirc ponteiro para pontos de circulos
/// @param pontosLinha ponteiro para pontos de linhas
/// @param pontosTxt ponteiro para pontos de texto
/// @param formascriadas ponteiro para contador de formas criadas
void efeitosColisao(FILE* ptrTXT, FILE* ptrSVG, int* maiorID, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* formascriadas);

/// @brief Realiza os efeitos quando nao ocorre colisao entre as formas.
/// @param ptrTXT Ponteiro para o arquivo de texto
/// @param ptrSVG Ponteiro para o arquivo SVG
/// @param ogivaForma Ponteiro para a forma da ogiva
/// @param alvoForma Ponteiro para a forma do alvo
/// @param x1O Coordenada x1 da ogiva
/// @param y1O Coordenada y1 da ogiva
/// @param x2O Coordenada x2 da ogiva
/// @param y2O Coordenada y2 da ogiva
/// @param filaR Fila de retangulos
/// @param filaC Fila de circulos
/// @param filaL Fila de linhas
/// @param filaT Fila de triagulos
/// @param formasdestruidas Ponteiro para o contador de formas destruidas
/// @param pontosRet Ponteiro para os pontos de retangulos
/// @param pontosCirc Ponteiro para os pontos de circulos
/// @param pontosLinha Ponteiro para os pontos de linhas
/// @param pontosTxt Ponteiro para os pontos de texto
/// @param x1A Coordenada x1 do alvo
/// @param y1A Coordenada y1 do alvo
/// @param x2A Coordenada x2 do alvo
/// @param y2A Coordenada y2 do alvo
void semColisao(FILE* ptrTXT, FILE* ptrSVG, void* ogivaForma, void* alvoForma, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, double x1A, double y1A, double x2A, double y2A);

/// @brief Verifica a colisao entre uma ogiva e um alvo do tipo circulo e aplica os efeitos correspondentes.
/// @param ptrTXT Ponteiro para o arquivo txt
/// @param ptrSVG Ponteiro para o arquivo svg
/// @param ALVO Lançador do alvo
/// @param OGIVA Lançador da ogiva
/// @param ogivaForma Forma da ogiva
/// @param alvoForma Forma do alvo
/// @param x1A x1 do alvo
/// @param y1A y1 do alvo
/// @param x2A x2 do alvo
/// @param y2A y2 do alvo
/// @param x1O x1 da ogiva
/// @param y1O y1 da ogiva
/// @param x2O x2 da ogiva
/// @param y2O y2 da ogiva
/// @param filaR Fila de retangulos
/// @param filaC Fila de circulos
/// @param filaL Fila de linhas
/// @param filaT Fila de textos
/// @param formasdestruidas Ponteiro para o contador de formas destruidas
/// @param pontosRet Ponteiro para a pontuacao de lancador de retângulos
/// @param pontosCirc Ponteiro para a pontuacao de lancador de circulos
/// @param pontosLinha Ponteiro para a pontuacao de lancador de linhas
/// @param pontosTxt Ponteiro para a pontuacao de lancador de textos
/// @param maiorID Ponteiro para o valor do maior ID lido
/// @param formascriadas ponteiro para contador de formas criadas
void colisaoCircAlvo(FILE* ptrTXT, FILE* ptrSVG, lancador* ALVO, lancador* OGIVA, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* maiorID, int* formascriadas);

/// @brief Verifica a colisao entre uma ogiva e um alvo do tipo retangulo e aplica os efeitos correspondentes.
/// @param ptrTXT Ponteiro para o arquivo txt
/// @param ptrSVG Ponteiro para o arquivo svg
/// @param ALVO Lançador do alvo
/// @param OGIVA Lançador da ogiva
/// @param ogivaForma Forma da ogiva
/// @param alvoForma Forma do alvo
/// @param x1A x1 do alvo
/// @param y1A y1 do alvo
/// @param x2A x2 do alvo
/// @param y2A y2 do alvo
/// @param x1O x1 da ogiva
/// @param y1O y1 da ogiva
/// @param x2O x2 da ogiva
/// @param y2O y2 da ogiva
/// @param filaR Fila de retangulos
/// @param filaC Fila de circulos
/// @param filaL Fila de linhas
/// @param filaT Fila de textos
/// @param formasdestruidas Ponteiro para o contador de formas destruidas
/// @param pontosRet Ponteiro para a pontuacao de lancador de retângulos
/// @param pontosCirc Ponteiro para a pontuacao de lancador de circulos
/// @param pontosLinha Ponteiro para a pontuacao de lancador de linhas
/// @param pontosTxt Ponteiro para a pontuacao de lancador de textos
/// @param maiorID Ponteiro para o valor do maior ID lido
/// @param formascriadas ponteiro para contador de formas criadas
void colisaoRetAlvo(FILE* ptrTXT, FILE* ptrSVG, lancador* ALVO, lancador* OGIVA, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* maiorID, int* formascriadas);

/// @brief Verifica a colisao entre uma ogiva e um alvo do tipo linha e aplica os efeitos correspondentes.
/// @param ptrTXT Ponteiro para o arquivo txt
/// @param ptrSVG Ponteiro para o arquivo svg
/// @param ALVO Lançador do alvo
/// @param OGIVA Lançador da ogiva
/// @param ogivaForma Forma da ogiva
/// @param alvoForma Forma do alvo
/// @param x1A x1 do alvo
/// @param y1A y1 do alvo
/// @param x2A x2 do alvo
/// @param y2A y2 do alvo
/// @param x1O x1 da ogiva
/// @param y1O y1 da ogiva
/// @param x2O x2 da ogiva
/// @param y2O y2 da ogiva
/// @param filaR Fila de retangulos
/// @param filaC Fila de circulos
/// @param filaL Fila de linhas
/// @param filaT Fila de textos
/// @param formasdestruidas Ponteiro para o contador de formas destruidas
/// @param pontosRet Ponteiro para a pontuacao de lancador de retângulos
/// @param pontosCirc Ponteiro para a pontuacao de lancador de circulos
/// @param pontosLinha Ponteiro para a pontuacao de lancador de linhas
/// @param pontosTxt Ponteiro para a pontuacao de lancador de textos
/// @param maiorID Ponteiro para o valor do maior ID lido
/// @param formascriadas ponteiro para contador de formas criadas
void colisaoLinhaAlvo(FILE* ptrTXT, FILE* ptrSVG, lancador* ALVO, lancador* OGIVA, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* maiorID, int* formascriadas);

/// @brief Verifica a colisao entre uma ogiva e um alvo do tipo texto e aplica os efeitos correspondentes.
/// @param ptrTXT Ponteiro para o arquivo txt
/// @param ptrSVG Ponteiro para o arquivo svg
/// @param ALVO Lançador do alvo
/// @param OGIVA Lançador da ogiva
/// @param ogivaForma Forma da ogiva
/// @param alvoForma Forma do alvo
/// @param x1A x1 do alvo
/// @param y1A y1 do alvo
/// @param x2A x2 do alvo
/// @param y2A y2 do alvo
/// @param x1O x1 da ogiva
/// @param y1O y1 da ogiva
/// @param x2O x2 da ogiva
/// @param y2O y2 da ogiva
/// @param filaR Fila de retangulos
/// @param filaC Fila de circulos
/// @param filaL Fila de linhas
/// @param filaT Fila de textos
/// @param formasdestruidas Ponteiro para o contador de formas destruidas
/// @param pontosRet Ponteiro para a pontuacao de lancador de retângulos
/// @param pontosCirc Ponteiro para a pontuacao de lancador de circulos
/// @param pontosLinha Ponteiro para a pontuacao de lancador de linhas
/// @param pontosTxt Ponteiro para a pontuacao de lancador de textos
/// @param maiorID Ponteiro para o valor do maior ID lido
/// @param formascriadas ponteiro para contador de formas criadas
void colisaoTxtAlvo(FILE* ptrTXT, FILE* ptrSVG, lancador* ALVO, lancador* OGIVA, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* maiorID, int* formascriadas);

#endif