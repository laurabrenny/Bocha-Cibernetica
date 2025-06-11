#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tratarArquivos.h"

char* strdup(const char* string) {
    size_t len = strlen(string) + 1;
    char* copy = malloc(len);
    if (copy) {
        memcpy(copy, string, len);
    }
    return copy;
}

char* tratarDir(const char* dir) {
    size_t len = strlen(dir);
    char* result;

    if (dir[len - 1] == '/') {
        result = strdup(dir);
    } else {
        result = malloc(len + 2);
        if (!result) {
            printf("Erro ao alocar memoria para o diretorio.\n");
            exit(1);
        }
        sprintf(result, "%s/", dir);
    }
    return result;
}

char* getNomeGeo(const char* arqgeo) {
    if (arqgeo == NULL) {
        fprintf(stderr, "Erro: Caminho do arquivo geo e NULL.\n");
        exit(1);
    }
    const char* nomeInicio = strrchr(arqgeo, '/');
    nomeInicio = (nomeInicio) ? nomeInicio + 1 : arqgeo;

    int len = strcspn(nomeInicio, ".");

    char* nomegeo = (char*)malloc(len + 1);
    if (nomegeo == NULL) {
        fprintf(stderr, "Erro na alocacao de memoria para nomegeo.\n");
        exit(1);
    }

    strncpy(nomegeo, nomeInicio, len);
    nomegeo[len] = '\0';
    return nomegeo;
}

char* getNomeQry(const char* arqqry) {
    const char* nomeInicio = strrchr(arqqry, '/');
    if (!nomeInicio) {
        nomeInicio = arqqry;
    } else {
        nomeInicio++; 
    }

    const char* ponto = strrchr(nomeInicio, '.');
    if (!ponto) {
        printf("Erro, nome do arquivo nao contem extensao:\n %s", nomeInicio);
        exit(1);
    }

    size_t tamanho = ponto - nomeInicio;
    char* nomeqry = (char*)malloc(tamanho + 1); 
    if (nomeqry == NULL) {
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }

    strncpy(nomeqry, nomeInicio, tamanho);
    nomeqry[tamanho] = '\0'; 

    return nomeqry;
}

char* CriarPathGeo(const char* diretorio, const char* arqgeo) {
    if (arqgeo == NULL) {
        printf("Erro: Nome do arquivo geo e nulo.\n");
        exit(1);
    }

    size_t len_arqgeo = strlen(arqgeo);
    char* pathgeo;

    if(diretorio != NULL && strlen(diretorio) > 0) {
        char* dir_com_barra = tratarDir(diretorio);

        pathgeo = (char*)malloc(strlen(dir_com_barra) + len_arqgeo + 1);
        if (pathgeo == NULL) {
            printf("Erro na alocacao de memoria para pathgeo!\n");
            free(dir_com_barra);
            exit(1);
        }
        strcpy(pathgeo, dir_com_barra);
        strcat(pathgeo, arqgeo);

        free(dir_com_barra);
    } 
    else if(diretorio == NULL){
        pathgeo = (char*)malloc(len_arqgeo + 1);
        if (pathgeo == NULL) {
            printf("Erro na alocacao de memoria para pathgeo!\n");
            exit(1);
        }
        strcpy(pathgeo, arqgeo);
    }

    return pathgeo;
}

char* CriarPathQry(const char* diretorio, const char* arqgeo) {
    size_t len_arqgeo = strlen(arqgeo);
    char* aux = (char*)malloc(sizeof(char)*(len_arqgeo + 1)); 
    if (aux == NULL) {
        printf("Erro na alocacao de memoria para aux!\n");
        exit(1);
    }
    strcpy(aux, arqgeo);

    
    size_t ext_len = 4;  
    if (len_arqgeo >= ext_len && strcmp(aux + len_arqgeo - ext_len, ".geo") == 0) {
        aux[len_arqgeo - ext_len] = '\0';  
    }

    char* pathqry;
    if (diretorio != NULL) {
       
        size_t len_dire = strlen(diretorio);
        pathqry = (char*)malloc(sizeof(char)*(len_dire + strlen(aux) + 1));
        if (pathqry == NULL) {
            printf("Erro na alocacao de memoria para pathqry!\n");
            free(aux);
            exit(1);
        }

        strcpy(pathqry, diretorio);
        strcat(pathqry, aux);
    }
    else if (diretorio == NULL){
        pathqry = (char*)malloc(sizeof(char)*(strlen(aux) + 1)); 
        if (pathqry == NULL) {
            printf("Erro na alocacao de memoria para pathqry!\n");
            free(aux);
            exit(1);
        }

        strcpy(pathqry, aux);
    }

    free(aux);
    return pathqry;
}

char* concatenarGeoQry(const char* nomegeo, const char* nomeqry) {
    size_t tamanho = strlen(nomegeo) + strlen(nomeqry) + 2; 
    char* concatnome = (char*)malloc(tamanho);

    if (concatnome == NULL) {
        printf("Erro na alocacao de memoria da string!\n");
        exit(1);
    }
    concatnome[0] = '\0';

    strcat(concatnome, nomegeo);
    strcat(concatnome, "-");
    strcat(concatnome, nomeqry);

    return concatnome;
}

char* concatenarComExtensao(const char* nome, char i) {
    size_t len_nome = strlen(nome);
    char* resultado;
    
    if (i == 'g') {
        resultado = (char*)malloc(len_nome + 5);
        if (resultado == NULL) {
            printf("Erro na alocacao de memoria.\n");
            exit(1);
        }
        strcpy(resultado, nome);
        strcat(resultado, ".geo");
    } 
    else if (i == 'q') {
        resultado = (char*)malloc(len_nome + 5);
        if (resultado == NULL) {
            printf("Erro na alocacao de memoria!\n");
            exit(1);
        }
        strcpy(resultado, nome);
        strcat(resultado, ".qry");
    }
    else if (i == 's') {
        resultado = (char*)malloc(len_nome + 5);
        if (resultado == NULL) {
            printf("Erro na alocacao de memoria!\n");
            exit(1);
        }
        strcpy(resultado, nome);
        strcat(resultado, ".svg");
    }
    else if (i == 't') {
        resultado = (char*)malloc(len_nome + 5);
        if (resultado == NULL) {
            printf("Erro na alocacao de memoria!\n");
            exit(1);
        }
        strcpy(resultado, nome);
        strcat(resultado, ".txt");
    }
    return resultado;
}

char* concatenarPathArq(char* caminho, char* arq) {
    if (caminho == NULL || arq == NULL) {
        printf("Erro: caminho ou arquivo .qry inválido!\n");
        exit(1);
    }

    char* caminhoCorrigido = tratarDir(caminho);

    size_t len_caminho = strlen(caminhoCorrigido);
    size_t len_arqqry = strlen(arq);
    size_t total_len = len_caminho + len_arqqry + 1; 

    char* pathqry = (char*)malloc(sizeof(char) * total_len);
    if (pathqry == NULL) {
        printf("Erro na alocação de memória para pathqry!\n");
        free(caminhoCorrigido);
        exit(1);
    }

    strcpy(pathqry, caminhoCorrigido);
    strcat(pathqry, arq);

    free(caminhoCorrigido);

    return pathqry;
}

char* removerPontoInicial(const char* caminhoArq) {
    if (caminhoArq == NULL) {
        printf("Erro: caminhoArq é NULL.\n");
        exit(1);
    }
    if (caminhoArq[0] == '.' && caminhoArq[1] == '/') {
        return strdup(caminhoArq + 2);
    }
    return strdup(caminhoArq);
}