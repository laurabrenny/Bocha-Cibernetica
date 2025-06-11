#include "retrocederMetade.h"

void retrocederMetade(void* forma, double x1, double y1, double x2, double y2) {
    double x0, y0, x02, y02;

    if (getTipoRetangulo(forma) == 'r') {
        x0 = getXRetangulo(forma);
        y0 = getYRetangulo(forma);
        x02 = x0;
        y02 = y0;
    } 
    else if (getTipoCirculo(forma) == 'c') {
        x0 = getXCirculo(forma);
        y0 = getYCirculo(forma);
        x02 = x0;
        y02 = y0;
    }
    else if (getTipoTexto(forma) == 't') {
        x0 = getXTexto(forma);
        y0 = getYTexto(forma);
        x02 = x0;
        y02 = y0;
    }
    else if (getTipoLinha(forma) == 'l' ) {
        x0 = getX1Linha(forma);
        y0 = getY1Linha(forma);
        x02 = getX2Linha(forma);
        y02 = getY2Linha(forma);
    }

    double deslocX = x1 - x0;
    double deslocY = y1 - y0;
    double deslocX2 = x2 - x02;
    double deslocY2 = y2 - y02;
    double metadeDeslocX = deslocX / 2;
    double metadeDeslocY = deslocY / 2;
    double metadeDeslocX2 = deslocX2 / 2;
    double metadeDeslocY2 = deslocY2 / 2;

    if (getTipoRetangulo(forma) == 'r') {
        double novoX = x1 - metadeDeslocX;
        double novoY = y1 - metadeDeslocY;
        setXRetangulo(forma, novoX);
        setYRetangulo(forma, novoY);
    }
    else if (getTipoCirculo(forma) == 'c') {
        double novoX = x1 - metadeDeslocX;
        double novoY = y1 - metadeDeslocY;
        setXCirculo(forma, novoX);
        setYCirculo(forma, novoY);
    }
    else if (getTipoTexto(forma) == 't') {
        double novoX = x1 - metadeDeslocX;
        double novoY = y1 - metadeDeslocY;
        setXTexto(forma, novoX);
        setYTexto(forma, novoY);
    }
    else if (getTipoLinha(forma) == 'l') {
        double novoX1 = x1 - metadeDeslocX;
        double novoY1 = y1 - metadeDeslocY;
        double novoX2 = x2 - metadeDeslocX2;
        double novoY2 = y2 - metadeDeslocY2;
        setX1Linha(forma, novoX1);
        setY1Linha(forma, novoY1);
        setX2Linha(forma, novoX2);
        setY2Linha(forma, novoY2);
    }
}

void atualizarPosicao(void* forma, double x1, double y1, double x2, double y2){
    if (getTipoRetangulo(forma) == 'r') {
        setXRetangulo(forma, x1);
        setYRetangulo(forma, y1);
    } 
    else if (getTipoCirculo(forma) == 'c') {
        setXCirculo(forma, x1);
        setYCirculo(forma, y1);
    }
    else if (getTipoTexto(forma) == 't') {
        setXTexto(forma, x1);
        setYTexto(forma, y1);
    }
    else if (getTipoLinha(forma) == 'l' ) {
        setX1Linha(forma, x1);
        setY1Linha(forma, y1);
        setX2Linha(forma, x2);
        setY2Linha(forma, y2);
    }

}