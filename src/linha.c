#include "linha.h"

typedef struct formaLinha{
    int id;
    double x1, x2, y1, y2;
    char* cor;
    char tipo;
}formaLinha;

LINHA inicializaLinha(int ID, double X1, double X2, double Y1, double Y2, char* COR){
    formaLinha* linha = (formaLinha*)malloc(sizeof(formaLinha));
    if(linha == NULL){
        printf("Erro ao alocar memoria para linha.\n");
        exit(1);   
    }

    linha->id = ID;
    linha->x1 = X1;
    linha->x2 = X2;
    linha->y1 = Y1;
    linha->y2 = Y2;
    linha->tipo = 'l';

    linha->cor = (char*)malloc(strlen(COR)+1);
    if(linha->cor == NULL){
        printf("Erro ao alocar memoria para cor da linha.\n");
        free(linha->cor);
        free(linha);
        exit(1);
    }
    strcpy(linha->cor, COR);

    return ((formaLinha*)linha);
}

int getIdLinha(LINHA linha) {
    return ((formaLinha*)linha)->id;
}

double getX1Linha(LINHA linha) {
    return ((formaLinha*)linha)->x1;
}

double getY1Linha(LINHA linha) {
    return ((formaLinha*)linha)->y1;
}

double getX2Linha(LINHA linha) {
    return ((formaLinha*)linha)->x2;
}

double getY2Linha(LINHA linha) {
    return ((formaLinha*)linha)->y2;
}

char* getCorLinha(LINHA linha) {
    return ((formaLinha*)linha)->cor;
}

char getTipoLinha(LINHA linha) {
    return ((formaLinha*)linha)->tipo;
}


double getAreaLinha(LINHA linha) {
    double x1 = getX1Linha(linha);
    double x2 = getX2Linha(linha);
    double y1 = getY1Linha(linha);
    double y2 = getY2Linha(linha);

    double comprimento = calcularDistanciaPontos(x1, y1, x2, y2);

    return (comprimento * 1.5);
}

double calcularDistanciaPontos(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void setX1Linha(LINHA linha, double X1) {
    ((formaLinha*)linha)->x1 = X1;
}

void setY1Linha(LINHA linha, double Y1) {
    ((formaLinha*)linha)->y1 = Y1;
}

void setX2Linha(LINHA linha, double X2) {
    ((formaLinha*)linha)->x2 = X2;
}

void setY2Linha(LINHA linha, double Y2) {
    ((formaLinha*)linha)->y2 = Y2;
}