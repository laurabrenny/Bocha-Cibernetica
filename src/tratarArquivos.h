#ifndef TRATARARQUIVOS_H
#define TRATARARQUIVOS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*
    Modulo de manipulacao de paths e nomes de arquivos.

    Este modulo contem funcoes para lidar com a formatacao de diretorios e nomes de arquivos.
    Inclui funcoes para extrair nomes de arquivos, criar caminhos completos, adicionar extensoes
    e concatenar nomes de arquivos de maneira padronizada.
*/

/// @brief Cria uma copia dinamica de uma string.
/// @param string String a ser copiada
/// @return Ponteiro para a nova string copiada 
char* strdup(const char* string);

/// @brief Verifica se o diretorio fornecido ja possui '/', e se nao tiver, adiciona.
/// @param dir Diretorio
/// @return Diretorio com '/' se nao tiver, ou o proprio diretorio
char* tratarDir(const char* dir);

/// @brief Retorna apenas o nome do arquivo geo, sem a extensao ou o caminho.
/// @param arqgeo Caminho do arquivo geo
/// @return Nome do arquivo geo
char* getNomeGeo(const char* arqgeo);

/// @brief Retorna apenas o nome do arquivo qry, sem a extensao ou o caminho.
/// @param arqQry Caminho do arquivo qry
/// @return Nome do arquivo qry
char* getNomeQry(const char* arqqry);

/// @brief Cria o path para abrir o arquivo geo.
/// @param diretorio Diretorio de entrada
/// @param arqgeo Caminho do arquivo geo
/// @return Path para o arquivo geo
char* CriarPathGeo(const char* diretorio, const char* arqgeo);

/// @brief Cria o path para abrir o arquivo qry.
/// @param diretorio Diretorio de entrada
/// @param arqgeo Caminho do arquivo qry
/// @return Path para o arquivo qry
char* CriarPathQry(const char* diretorio, const char* arqqry);

/// @brief Concatena o nome do geo e o nome do qry, ficando da forma geo-qry.
/// @param nomegeo Nome do geo
/// @param nomeqry Nome do qry
/// @return Nome concatenado geo-qry
char* concatenarGeoQry(const char* nomegeo, const char* nomeqry);

/// @brief Adiciona a extensao '.geo', '.qry', '.svg' ou '.txt' ao nome do arquivo.
/// @param nome Nome do arquivo
/// @param i Pode ser 'g', 'q', 's' ou 't'
/// @return Nome do arquivo com extensao desejada
char* concatenarComExtensao(const char* nome, char i);

/// @brief Remove o ponto inicial de um caminho.
/// @param caminhoArq Caminho de um arquivo
/// @return Caminho sem ponto inicial, se tiver
char* removerPontoInicial(const char* caminhoArq);

/// @brief Concatena o nome do arquivo com o path.
/// @param caminho Caminho de um arquivo
/// @param arq Nome do arquivo
char* concatenarPathArq(char* caminho, char* arq);

#endif