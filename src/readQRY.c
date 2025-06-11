#include "readQRY.h"

FILE* abrirQRY(char* nomeqry){
    FILE* file = fopen(nomeqry, "r");
    if(file == NULL){
        printf("Erro ao abrir arquivo qry.\n");
        exit(1);
    }
    return file;
}

void processarQRY(FILE* ptrTXT, FILE* ptrSVG, FILE* file, int* maiorID, fila* filaR, fila* filaC, fila* filaL, fila* filaT, lancador** lancR, lancador** lancC, lancador** lancL, lancador** lancT, int* instrucoes, int* lancamentos, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* formascriadas){
    char comando [3];
    char tipoLancador;
    double grauLancador, distanciaLancador;
    char tipoLa, tipoLo;
    double distLa, distLo;

    while(fscanf(file, "%s", comando) != EOF){

        // comando rt
        if(strcmp(comando, "rt") == 0 || strcmp(comando, "RT") == 0 ){
            fscanf(file, " %c %lf", &tipoLancador, &grauLancador);

            printarRtTXT(ptrTXT, tipoLancador, grauLancador);
            posicionaLancadores(tipoLancador, grauLancador, lancR, lancC, lancL, lancT);
        }

        // comando lc
        else if(strcmp(comando, "lc") == 0 || strcmp(comando, "LC") == 0){
            fscanf(file, " %c %lf %c %lf", &tipoLa, &distLa, &tipoLo, &distLo);

            printarLcTXT(ptrTXT, tipoLa, tipoLo, distLa, distLo);

            lancador* alvo = NULL;
            lancador* ogiva = NULL;

            if(tipoLa == 'r' || tipoLa == 'R'){
                alvo = *lancR;
            } else if(tipoLa == 'c' || tipoLa == 'C'){
                alvo = *lancC;
            } else if(tipoLa == 'l' || tipoLa == 'L'){
                alvo = *lancL ;
            } else if(tipoLa == 't' || tipoLa == 'T'){
                alvo = *lancT;
            }
            if(tipoLo == 'r' || tipoLo == 'R'){
                ogiva = *lancR;
            } else if(tipoLo == 'c' || tipoLo == 'C'){
                ogiva = *lancC;
            } else if(tipoLo == 'l' || tipoLo == 'L'){
                ogiva = *lancL;
            } else if(tipoLo == 't' || tipoLo == 'T'){
                ogiva = *lancT;
            }
            atualizarLancamentos(lancamentos);
            atualizarLancamentos(lancamentos);

            lancamentoAlvoOgiva(ptrTXT, ptrSVG, alvo, distLa, ogiva, distLo, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, maiorID, formascriadas);
        }

        atualizarInstrucoes(instrucoes);
        fscanf(file, "\n");
    }
    fclose(file);
}