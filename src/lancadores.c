#include "lancadores.h"

typedef struct lancador{
    char tipo;
    double g;
} lancador;

lancador* inicializalancador(char t, double grau){
    lancador* lanc = malloc(sizeof(lancador));
    if(lanc == NULL){
        printf("Erro ao alocar memoria para lancador do tipo %c.\n", t);
        exit(1);
    }
    lanc->g = grau;
    lanc->tipo = t;
    return((lancador*)lanc);
}

double getGrauLancador(lancador* lanc){
    if(lanc == NULL){
        printf("Lancador nulo.(getGrau)\n");
        exit(1);
    }
    return lanc->g;
}

char getTipoLancador(lancador* lanc){
    if(lanc == NULL){
        printf("Lancador nulo.(getTipo)\n");
        exit(1);
    }
    return lanc->tipo;
}

void posicionaLancadores(char tipoLancador, double grauLancador, ///. ){
    if (tipoLancador == 'R' || tipoLancador == 'r') {
        *lancR = inicializalancador(tipoLancador, grauLancador);
    }
    else if (tipoLancador == 'C' || tipoLancador == 'c') {
        *lancC = inicializalancador(tipoLancador, grauLancador);
    }
    else if (tipoLancador == 'T' || tipoLancador == 't') {
        *lancT = inicializalancador(tipoLancador, grauLancador);
    }
    else if (tipoLancador == 'L' || tipoLancador == 'l') {
        *lancL = inicializalancador(tipoLancador, grauLancador);
    }
}