#include "retrocederProp.h"

void retrocederProporcional(double areaOgiva, double areaAlvo, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O){
    double areaTotal = areaAlvo + areaOgiva;
    double propOgiva = (areaAlvo/areaTotal);
    double propAlvo = (areaOgiva/areaTotal);

//ogiva
    double x0, y0, x02, y02; 
    if (getTipoRetangulo(ogivaForma) == 'r') {
        x0 = getXRetangulo(ogivaForma);
        y0 = getYRetangulo(ogivaForma);
        x02 = x0;
        y02 = y0;
    } 
    else if (getTipoCirculo(ogivaForma) == 'c') {
        x0 = getXCirculo(ogivaForma);
        y0 = getYCirculo(ogivaForma);
        x02 = x0;
        y02 = y0;
    }
    else if (getTipoTexto(ogivaForma) == 't') {
        x0 = getXTexto(ogivaForma);
        y0 = getYTexto(ogivaForma);
        x02 = x0;
        y02 = y0;
    }
    else if (getTipoLinha(ogivaForma) == 'l' ) {
        x0 = getX1Linha(ogivaForma);
        y0 = getY1Linha(ogivaForma);
        x02 = getX2Linha(ogivaForma);
        y02 = getY2Linha(ogivaForma);
    }

//alvo
    double x0a, y0a, x02a, y02a; 
    if (getTipoRetangulo(alvoForma) == 'r') {
        x0a = getXRetangulo(alvoForma);
        y0a = getYRetangulo(alvoForma);
        x02a = x0a;
        y02a = y0a;
    } 
    else if (getTipoCirculo(alvoForma) == 'c') {
        x0a = getXCirculo(alvoForma);
        y0a = getYCirculo(alvoForma);
        x02a = x0a;
        y02a = y0a;
    }
    else if (getTipoTexto(alvoForma) == 't') {
        x0a = getXTexto(alvoForma);
        y0a = getYTexto(alvoForma);
        x02a = x0a;
        y02a = y0a;
    }
    else if (getTipoLinha(alvoForma) == 'l' ) {
        x0a = getX1Linha(alvoForma);
        y0a = getY1Linha(alvoForma);
        x02a = getX2Linha(alvoForma);
        y02a = getY2Linha(alvoForma);
    }

    double deltaXogiva = x1O - x0;
    double deltaYogiva = y1O - y0;
    double deltaX2ogiva = x2O - x02;
    double deltaY2ogiva = y2O - y02;

    double deltaXalvo = x1A - x0a;
    double deltaYalvo = y1A - y0a;
    double deltaX2alvo = x2A - x02a;
    double deltaY2alvo = y2A - y02a;

//ogiva
 if (getTipoRetangulo(ogivaForma) == 'r') {
        setXRetangulo(ogivaForma, x1O - (propOgiva * deltaXogiva));
        setYRetangulo(ogivaForma, y1O - (propOgiva * deltaYogiva));
    } 
    else if (getTipoCirculo(ogivaForma) == 'c') {
        setXCirculo(ogivaForma, x1O - (propOgiva * deltaXogiva));
        setYCirculo(ogivaForma, y1O - (propOgiva * deltaYogiva));
    }
    else if (getTipoTexto(ogivaForma) == 't') {
        setXTexto(ogivaForma, x1O - (propOgiva * deltaXogiva));
        setYTexto(ogivaForma, y1O - (propOgiva * deltaYogiva));
    }
    else if (getTipoLinha(ogivaForma) == 'l') {
        setX1Linha(ogivaForma, x1O - (propOgiva * deltaXogiva));
        setY1Linha(ogivaForma, y1O - (propOgiva * deltaYogiva));
        setX2Linha(ogivaForma, x2O - (propOgiva * deltaX2ogiva));
        setY2Linha(ogivaForma, y2O - (propOgiva * deltaY2ogiva));
    }

//alvo
    if (getTipoRetangulo(alvoForma) == 'r') {
        setXRetangulo(alvoForma, x1A - (propAlvo * deltaXalvo));
        setYRetangulo(alvoForma, y1A - (propAlvo * deltaYalvo));
    } 
    else if (getTipoCirculo(alvoForma) == 'c') {
        setXCirculo(alvoForma, x1A - (propAlvo * deltaXalvo));
        setYCirculo(alvoForma, y1A - (propAlvo * deltaYalvo));
    }
    else if (getTipoTexto(alvoForma) == 't') {
        setXTexto(alvoForma, x1A - (propAlvo * deltaXalvo));
        setYTexto(alvoForma, y1A - (propAlvo * deltaYalvo));
    }
    else if (getTipoLinha(alvoForma) == 'l') {
        setX1Linha(alvoForma, x1A - (propAlvo * deltaXalvo));
        setY1Linha(alvoForma, y1A - (propAlvo * deltaYalvo));
        setX2Linha(alvoForma, x2A - (propAlvo * deltaX2alvo));
        setY2Linha(alvoForma, y2A - (propAlvo * deltaY2alvo));
    }
}