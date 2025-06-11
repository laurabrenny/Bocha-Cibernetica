#include "deslocamento.h"

double calcularDeslocamentoX(double x, double distancia, double grau){
    double dx = distancia * cosseno(grau);
    return dx + x;
}

double calcularDeslocamentoY(double y, double distancia, double grau){
    double dy = distancia * seno(grau);
    return dy + y;
}

double seno(double graus){
    double anguloRad = graus * (PI / 180);
    return (sin(anguloRad));
}

double cosseno(double graus){
    double anguloRad = graus * (PI / 180);
    return (cos(anguloRad));
}

void determinarDeslocamento(void* forma, double dist, double grau, double* x1, double* y1, double* x2, double* y2){
    if (getTipoRetangulo(forma) == 'r' || getTipoRetangulo(forma) == 'R') {
        double X = getXRetangulo(forma);
        double Y = getYRetangulo(forma);
        *x1 = calcularDeslocamentoX(X, dist, grau);
        *y1 = calcularDeslocamentoY(Y, dist, grau);
        *x2 = *x1;
        *y2 = *y1;
    }
    else if (getTipoCirculo(forma) == 'c' || getTipoCirculo(forma) == 'C') {
        double X = getXCirculo(forma);
        double Y =getYCirculo(forma);
        *x1 = calcularDeslocamentoX(X, dist, grau);
        *y1 = calcularDeslocamentoY(Y, dist, grau);
        *x2 = *x1;
        *y2 = *y1;
    }
    else if (getTipoTexto(forma) == 't' || getTipoTexto(forma) == 'T') {
        double X = getXTexto(forma);
        double Y = getYTexto(forma);
        *x1 = calcularDeslocamentoX(X, dist, grau);
        *y1 = calcularDeslocamentoY(Y, dist, grau);
        *x2 = *x1;
        *y2 = *y1;
    }
    else if (getTipoLinha(forma) == 'l' || getTipoLinha(forma) == 'L') {
        double X1 = getX1Linha(forma);
        double Y1 = getY1Linha(forma);
        double X2 = getX2Linha(forma);
        double Y2 = getY2Linha(forma);
        *x1 = calcularDeslocamentoX(X1, dist, grau);
        *y1 = calcularDeslocamentoY(Y1, dist, grau);
        *x2 = calcularDeslocamentoX(X2, dist, grau);
        *y2 = calcularDeslocamentoY(Y2, dist, grau);
    }
}


void pontoMedio(double x1, double y1, double x2, double y2, double* xm, double* ym) {
     *xm = (x1 + x2) / 2;
     *ym = (y1 + y2) / 2;
}