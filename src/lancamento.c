#include "lancamento.h"

void lancamentoAlvoOgiva(FILE* ptrTXT, FILE* ptrSVG, lancador* ALVO, double distAlvo, lancador* OGIVA, double distOgiva, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* maiorID, int* formascriadas){
    if(ALVO == NULL || OGIVA == NULL){
        printf("Erro ao acessar lancadores (comando LC).\n");
    } 
    else if(filaC == NULL || filaR == NULL || filaL == NULL || filaT == NULL){
        printf("Erro ao acessar filas das formas (comando LC).\n"); 
    }

    void* alvoForma;
    double *x1A = malloc(sizeof(double));
    double *x2A = malloc(sizeof(double));
    double *y1A = malloc(sizeof(double));
    double *y2A = malloc(sizeof(double));

    if (x1A == NULL || y1A == NULL || x2A == NULL || y2A == NULL) {
        printf("Erro de alocaçao de memoria para x1A, y1A, x2A, y2A.\n");
        exit(1);
    }
    char tipoAlvo = getTipoLancador(ALVO);

    if(tipoAlvo == 'c' || tipoAlvo == 'C'){
        alvoForma = getPrimeiroElemento(filaC); 
        double gA = getGrauLancador(ALVO);
        determinarDeslocamento(alvoForma, distAlvo, gA, x1A, y1A, x2A, y2A);
    } 
    if(tipoAlvo == 'r' || tipoAlvo == 'R'){
        alvoForma = getPrimeiroElemento(filaR);
        double gA = getGrauLancador(ALVO);
        determinarDeslocamento(alvoForma, distAlvo, gA, x1A, y1A, x2A, y2A);
    } 
    if(tipoAlvo == 't' || tipoAlvo == 'T'){
        alvoForma = getPrimeiroElemento(filaT);
        double gA = getGrauLancador(ALVO);
        determinarDeslocamento(alvoForma, distAlvo, gA, x1A, y1A, x2A, y2A);
    } 
    if(tipoAlvo == 'l' || tipoAlvo == 'L'){
        alvoForma = getPrimeiroElemento(filaL);
        double gA = getGrauLancador(ALVO);
        determinarDeslocamento(alvoForma, distAlvo, gA, x1A, y1A, x2A, y2A);
    }

    void* ogivaForma;
    double *x1O = malloc(sizeof(double));
    double *y1O = malloc(sizeof(double));
    double *x2O = malloc(sizeof(double));
    double *y2O = malloc(sizeof(double));

    if (x1O == NULL || y1O == NULL || x2O == NULL || y2O == NULL) {
        printf("Erro de alocaçao de memoria para x1O, y1O, x2O, y2O.\n");
        exit(1); 
    }

    char tipoOgiva = getTipoLancador(OGIVA);

    if(tipoOgiva == 'c' || tipoOgiva == 'C'){
        ogivaForma = getPrimeiroElemento(filaC);
        double gO = getGrauLancador(OGIVA);
        determinarDeslocamento(ogivaForma, distOgiva, gO, x1O, y1O, x2O, y2O);
    }
    if(tipoOgiva == 'r' || tipoOgiva == 'R'){
        ogivaForma = getPrimeiroElemento(filaR);
        double gO = getGrauLancador(OGIVA);
        determinarDeslocamento(ogivaForma, distOgiva, gO, x1O, y1O, x2O, y2O);
    }
    if(tipoOgiva == 't' || tipoOgiva == 'T'){
        ogivaForma = getPrimeiroElemento(filaT);
        double gO = getGrauLancador(OGIVA);
        determinarDeslocamento(ogivaForma, distOgiva, gO, x1O, y1O, x2O, y2O);
    }
    if(tipoOgiva == 'l' || tipoOgiva == 'L'){
        ogivaForma = getPrimeiroElemento(filaL);
        double gO = getGrauLancador(OGIVA);
        determinarDeslocamento(ogivaForma, distOgiva, gO, x1O, y1O, x2O, y2O);
    }

    formasAntesTXT(ptrTXT, alvoForma, ogivaForma);

    double x1a = *x1A;
    double y1a = *y1A;
    double x2a = *x2A;
    double y2a = *y2A;
    double x1o = *x1O;
    double y1o = *y1O;
    double x2o = *x2O;
    double y2o = *y2O;
    free(x1O);
    free(y1O);
    free(x2O);
    free(y2O);
    free(x1A);
    free(y1A);
    free(x2A);
    free(y2A);

    verificaColisao(ptrTXT, ptrSVG, ALVO, OGIVA, ogivaForma, alvoForma, x1a, y1a, x2a, y2a, x1o, y1o, x2o, y2o, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, maiorID, formascriadas);
}