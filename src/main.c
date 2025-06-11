#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "readGEO.h"
#include "readQRY.h"
#include "gerarSVG.h"
#include "gerarTXT.h"
#include "gerarSVG2.h"
#include "tratarArquivos.h"

int main(int argc, char* argv[]) {
    char *dirEntrada = NULL, *caminhoGeoComPonto = NULL, *caminhoQryComPonto = NULL, *dirSaida = NULL;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) {
            dirEntrada = tratarDir(argv[++i]);
        } else if (strcmp(argv[i], "-f") == 0) {
            caminhoGeoComPonto = argv[++i];
        } else if (strcmp(argv[i], "-q") == 0) {
            caminhoQryComPonto = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0) {
            dirSaida = tratarDir(argv[++i]);
        }
    }

    fila *filaR = NULL, *filaC = NULL, *filaL = NULL, *filaT = NULL;
    inicializarFila(&filaR);
    inicializarFila(&filaC);
    inicializarFila(&filaL);
    inicializarFila(&filaT);

    int* formascriadas = (int*)malloc(sizeof(int));
    int* instrucoes = (int*)malloc(sizeof(int));
    int *maiorID = (int*)malloc(sizeof(int));
    if (formascriadas == NULL || instrucoes == NULL || maiorID == NULL) {
        printf("Erro ao alocar memoria para os ponteiros dos contadores.\n");
        exit(1);
    }
    *maiorID = 0, *formascriadas = 0, *instrucoes = 0;
    char *nomeGeoSemExtensao = getNomeGeo(caminhoGeoComPonto);
    char* caminhoGeo = removerPontoInicial(caminhoGeoComPonto);
    //GEO
    char* pathgeo = CriarPathGeo(dirEntrada, caminhoGeo);
    FILE* geo = abrirGEO(pathgeo);
    // processarGEO(geo, filaR, filaC, filaL, filaT, formascriadas, instrucoes);
    *maiorID = obterMaiorId(pathgeo);
    // SVG GEO
    char* pathSvgGeo = concatenarPathArq(dirSaida, nomeGeoSemExtensao);
    FILE* ptrSVGgeo = abrirSVGgeo(pathSvgGeo);
    // gerarSVG_GEO(ptrSVGgeo, filaR, filaC, filaL, filaT);

    if(caminhoQryComPonto != NULL){
        double* pontosRet = (double*)malloc(sizeof(double)); 
        double* pontosCirc = (double*)malloc(sizeof(double));
        double* pontosLinha = (double*)malloc(sizeof(double));
        double* pontosTxt = (double*)malloc(sizeof(double));
        if (pontosRet == NULL || pontosCirc == NULL || pontosLinha == NULL || pontosTxt == NULL) {
            printf("Erro ao alocar memoria para os ponteiros de pontos.\n");
            exit(1);
        }
        *pontosRet = 0; *pontosCirc = 0; *pontosLinha = 0; *pontosTxt = 0; 
        int* lancamentos = (int*)malloc(sizeof(int));
        int* formasdestruidas = (int*)malloc(sizeof(int));
        if (lancamentos == NULL || formasdestruidas == NULL) {
            printf("Erro ao alocar memoria para os ponteiros dos contadores.\n");
            exit(1);
        }
        *lancamentos = 0; *formasdestruidas = 0;

        lancador *lancR = NULL, *lancC = NULL, *lancL = NULL, *lancT = NULL;

        // NOME GEO-QRY
        char *nomeQrySemExtensao = getNomeQry(caminhoQryComPonto);
        char* nomeGeoQry = concatenarGeoQry(nomeGeoSemExtensao, nomeQrySemExtensao); 

        // SVG GEO-QRY
        char* pathSvgGeoQry = concatenarPathArq(dirSaida, nomeGeoQry); 
        FILE* ptrSVG = abrirSVG2(pathSvgGeoQry); 

        // TXT GEO-QRY
        char* pathTXT = concatenarPathArq(dirSaida, nomeGeoQry);
        FILE* ptrTXT = abrirTXT(pathTXT);

        //QRY
        char* pathQrySemNomeArquivoQry = CriarPathQry(dirEntrada, caminhoGeo);
        char* arqQryComExtensao = concatenarComExtensao(nomeQrySemExtensao, 'q'); 
        char* pathQry = concatenarPathArq(pathQrySemNomeArquivoQry, arqQryComExtensao); 

        FILE* qry = abrirQRY(pathQry);
        processarQRY(ptrTXT, ptrSVG, qry, maiorID, filaR, filaC, filaL, filaT, &lancR, &lancC, &lancL, &lancT, instrucoes, lancamentos, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);

        //DADOS FINAIS SVG E TXT
        printarFormasRestantesSVG2(ptrSVG, filaR, filaC, filaL, filaT);
        fecharSVG2(ptrSVG);
        ImprimirDadosTXT(ptrTXT, instrucoes, lancamentos, formasdestruidas, formascriadas, pontosRet, pontosCirc, pontosLinha, pontosTxt);
        fecharTXT(ptrTXT);

        free(formasdestruidas);
        free(lancamentos);
        free(pathSvgGeoQry);
        free(pathTXT);
        free(pathQrySemNomeArquivoQry);
        free(arqQryComExtensao);
        free(pathQry);
        if (lancR != NULL) free(lancR);
        if (lancC != NULL) free(lancC);
        if (lancL != NULL) free(lancL);
        if (lancT != NULL) free(lancT);
        }
    free(formascriadas);
    free(instrucoes);
    free(maiorID);
    free(nomeGeoSemExtensao);
    free(caminhoGeo);
    free(pathgeo);
    free(pathSvgGeo);
    freeFila(filaR);
    freeFila(filaC);
    freeFila(filaL);
    freeFila(filaT);
    return 0;
}