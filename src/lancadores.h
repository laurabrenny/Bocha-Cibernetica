#ifndef LANCADORES_H
#define LANCADORES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    Modulo de manipulacao de lancadores.

    Um  lancador eh uma estrutura que armazena a inclinacao em graus dos lancamentos, existindo um 
    lancador de cada tipo (R, C, L e T), logo, um para cada forma geometrica.
    Este modulo contem as definicoes e operacoes basicas para o manuseio dos lancadores, como inicializar
    um novo lancador com os parametros fornecidos e funcoes getters para retornar o grau e tipo do
    lancador especificado.
*/

typedef struct lancador lancador;

/// @brief Inicializa um lancador com os parametros grau e tipo fornecidos.
/// @param 
/// @param grau Grau do lancador
/// @return Ponteiro para o lancador
lancador* inicializalancador( ///, double grau);

/// @brief Inicia os lancadores das formas e os posiciona com seu grau de lancamento informado, de acordo com cada tipo (R, C, L e T).
/// @param tipoLancador Tipo do lancador
/// @param grauLancador Grau do lancador 
/// @param lancR Lancador de retangulos
/// @param lancC Lancador de circulos
/// @param lancL Lancador de linhas
/// @param lancT Lancador de textos
void posicionaLancadores(char tipoLancador, double grauLancador, lancador** lancR, lancador** lancC, lancador** lancL, lancador** lancT);

/// @brief Retorna o grau do lancador.
/// @param lanc Estrutura lancador
/// @return Grau
double getGrauLancador(lancador* lanc);

/// @brief Retorna o tipo do lancador. 
/// @param lanc Estrutura lancador
/// @return Tipo (l, c, r, t)
char getTipoLancador(lancador* lanc);

#endif