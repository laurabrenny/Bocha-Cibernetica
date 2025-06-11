#include "colisao.h"

int colisaoRetRet(RETANGULO alvo, RETANGULO ogiva, double xAlvo, double yAlvo, double xOgiva, double yOgiva){
    double wA, hA;
    double wO, hO;

    wA = getWRetangulo(alvo);
    hA = getHRetangulo(alvo);

    wO = getWRetangulo(ogiva);
    hO = getHRetangulo(ogiva);

    if (xAlvo + wA < xOgiva || xOgiva + wO < xAlvo ||
        yAlvo + hA < yOgiva || yOgiva + hO < yAlvo) {
        return 0; // Nao ha colisao
    }

    return 1; // Colisao
}

int colisaoRetCirc(RETANGULO ret, CIRCULO circ, double xR, double yR, double xC, double yC){
    double wR = getWRetangulo(ret);
    double hR = getHRetangulo(ret);

    double rC = getRaioCirculo(circ);
    
    double xP = fmax(xR, fmin(xC, xR + wR));
    double yP = fmax(yR, fmin(yC, yR + hR));
    

    double dist = calcularDistanciaPontos(xP, yP, xC, yC);
    
    if (dist <= rC) {
        return 1;  // Colisao
    }
    
    return 0;  // Nao ha colisao
}

int colisaoRetLinha(RETANGULO ret, LINHA linha, double xR, double yR, double x1, double y1, double x2, double y2) {

    double wR = getWRetangulo(ret);
    double hR = getHRetangulo(ret);

    if ((x1 >= xR && x1 <= xR + wR && y1 >= yR && y1 <= yR + hR) ||
        (x2 >= xR && x2 <= xR + wR && y2 >= yR && y2 <= yR + hR)) {
        return 1; // Colisao
    }

    if (intersecaoSegmentos(xR, yR, xR + wR, yR, x1, y1, x2, y2)) return 1;
    if (intersecaoSegmentos(xR + wR, yR, xR + wR, yR + hR, x1, y1, x2, y2)) return 1;
    if (intersecaoSegmentos(xR + wR, yR + hR, xR, yR + hR, x1, y1, x2, y2)) return 1;
    if (intersecaoSegmentos(xR, yR + hR, xR, yR, x1, y1, x2, y2)) return 1;

    return 0; // Nao ha colisao
}

int colisaoRetTexto(RETANGULO retangulo, TEXTO texto, double xR, double yR, double xt, double yt) {
    double wR = getWRetangulo(retangulo);
    double hR = getHRetangulo(retangulo);

    int numCaracteres = getNumCaracteresTexto(texto);
    char ancor = getATexto(texto);

    double x1, y1, x2, y2;
    double comprimentoTexto = 10.0 * numCaracteres;

    if (ancor == 'i' || ancor == 'I') {
        x1 = xt;
        y1 = yt;
        x2 = xt + comprimentoTexto;
        y2 = yt;
    } else if (ancor == 'f' || ancor == 'F') {
        x1 = xt - comprimentoTexto;
        y1 = yt;
        x2 = xt;
        y2 = yt;
    } else if (ancor == 'm' || ancor == 'M') {
        x1 = xt - comprimentoTexto / 2;
        y1 = yt;
        x2 = xt + comprimentoTexto / 2;
        y2 = yt;
    }
    if (xR + wR < fmin(x1, x2) || fmax(x1, x2) < xR || yR + hR < fmin(y1, y2) || fmax(y1, y2) < yR) {
        return 0; // nao ha colisao
    }

    return 1; // Colisao
}

int colisaoCircCirc(CIRCULO c1, CIRCULO c2, double x1, double y1, double x2, double y2) {
    double r1 = getRaioCirculo(c1);
    double r2 = getRaioCirculo(c2);
    double distancia = calcularDistanciaPontos(x1, y1, x2, y2);

    if (distancia <= (r1 + r2)) {
        return 1; // Colisao
    }
    return 0; // Nao ha colisao
}

int colisaoCircLinha(CIRCULO c, LINHA l, double xc, double yc, double x1, double y1, double x2, double y2) {
    double r = getRaioCirculo(c);
    double t = ((xc - x1) * (x2 - x1) + (yc - y1) * (y2 - y1)) /
               (pow(x2 - x1, 2) + pow(y2 - y1, 2));

    if (t >= 0 && t <= 1) {
        double px = x1 + t * (x2 - x1);
        double py = y1 + t * (y2 - y1);
        double distancia = calcularDistanciaPontos(xc, yc, px, py);

        if (distancia <= r) {
            return 1; // Colisao
        }
    }

    double distancia1 = calcularDistanciaPontos(xc, yc, x1, y1);
    double distancia2 = calcularDistanciaPontos(xc, yc, x2, y2);

    if (distancia1 <= r || distancia2 <= r) {
        return 1; // Colisao
    }
    return 0; //Sem colisao
}

int colisaoCircTexto(CIRCULO c, TEXTO texto, double xc, double yc, double xt, double yt) {
    double r = getRaioCirculo(c);
    int numCaracteres = getNumCaracteresTexto(texto);
    char ancor = getATexto(texto);

    double x1, y1, x2, y2;
    double comprimentoTexto = 10.0 * numCaracteres;

    if (ancor == 'i' || ancor == 'I') {
        x1 = xt;
        y1 = yt;
        x2 = xt + comprimentoTexto;
        y2 = yt;
    } else if (ancor == 'f' || ancor == 'F') {
        x1 = xt - comprimentoTexto;
        y1 = yt;
        x2 = xt;
        y2 = yt;
    } else if (ancor == 'm' || ancor == 'M') {
        x1 = xt - comprimentoTexto / 2;
        y1 = yt;
        x2 = xt + comprimentoTexto / 2;
        y2 = yt;
    }

    double distanciaCanto1 = calcularDistanciaPontos(xc, yc, x1, y1);
    double distanciaCanto2 = calcularDistanciaPontos(xc, yc, x2, y2);

    if (distanciaCanto1 <= r || distanciaCanto2 <= r) {
        return 1; // Colisao com canto
    }
    if (xc + r < fmin(x1, x2) || xc - r > fmax(x1, x2) || yc + r < fmin(y1, y2) || yc - r > fmax(y1, y2)) {
        return 0; // Nao ha colisao com as bordas do texto
    }
    double t = ((xc - x1) * (x2 - x1) + (yc - y1) * (y2 - y1)) / (pow(x2 - x1, 2) + pow(y2 - y1, 2));
    if (t >= 0 && t <= 1) {
        double px = x1 + t * (x2 - x1);
        double py = y1 + t * (y2 - y1);
        double distancia = calcularDistanciaPontos(xc, yc, px, py);
        if (distancia <= r) {
            return 1; // Colisao com a linha do texto
        }
    }
    return 0; // Nao ha colisao
}

int colisaoLinhaLinha(LINHA l1, LINHA l2, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {

    double det = (x2 - x1) * (y4 - y3) - (y2 - y1) * (x4 - x3);
    if (det == 0) {
        return 0;
    } else {
        double t1 = ((x3 - x1) * (y4 - y3) - (y3 - y1) * (x4 - x3)) / det;
        double t2 = ((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)) / det;

        if (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1) {
            return 1; // Colisao
        } 
        return 0; // Nao ha colisao
    }
}

int colisaoLinhaTexto(LINHA linha, TEXTO texto, double xt, double yt, double xL1, double yL1, double xL2, double yL2) {
    int numCaracteres = getNumCaracteresTexto(texto);
    char ancor = getATexto(texto);

    double comprimentoTexto = 10.0 * numCaracteres;
    double x1, y1, x2, y2;

    if (ancor == 'i' || ancor == 'I') {
        x1 = xt;
        y1 = yt;
        x2 = xt + comprimentoTexto;
        y2 = yt;
    } else if (ancor == 'f' || ancor == 'F') {
        x1 = xt - comprimentoTexto;
        y1 = yt;
        x2 = xt;
        y2 = yt;
    } else if (ancor == 'm' || ancor == 'M') {
        x1 = xt - comprimentoTexto / 2;
        y1 = yt;
        x2 = xt + comprimentoTexto / 2;
        y2 = yt;
    }

    if (intersecaoSegmentos(xL1, yL1, xL2, yL2, x1, y1, x2, y2)) {
        return 1; // Colisao
    } 
    return 0; // Sem colisao
}

int colisaoTextoTexto(TEXTO texto1, TEXTO texto2, double xt1, double yt1, double xt2, double yt2) {
    int numCaracteres1 = getNumCaracteresTexto(texto1);
    char ancor1 = getATexto(texto1);

    double comprimentoTexto1 = 10.0 * numCaracteres1;
    double xf1, yf1, xf2, yf2;

    if (ancor1 == 'i' || ancor1 == 'I') {
        xf1 = xt1;
        yf1 = yt1;
        xf2 = xt1 + comprimentoTexto1;
        yf2 = yt1;
    } else if (ancor1 == 'f' || ancor1 == 'F') {
        xf1 = xt1 - comprimentoTexto1;
        yf1 = yt1;
        xf2 = xt1;
        yf2 = yt1;
    } else if (ancor1 == 'm' || ancor1 == 'M') {
        xf1 = xt1 - comprimentoTexto1 / 2;
        yf1 = yt1;
        xf2 = xt1 + comprimentoTexto1 / 2;
        yf2 = yt1;
    }

    int numCaracteres2 = getNumCaracteresTexto(texto2);
    char ancor2 = getATexto(texto2);
    double comprimentoTexto2 = 10.0 * numCaracteres2;
    double xf3, yf3, xf4, yf4;

    if (ancor2 == 'i' || ancor2 == 'I') {
        xf3 = xt2;
        yf3 = yt2;
        xf4 = xt2 + comprimentoTexto2;
        yf4 = yt2;
    } else if (ancor2 == 'f' || ancor2 == 'F') {
        xf3 = xt2 - comprimentoTexto2;
        yf3 = yt2;
        xf4 = xt2;
        yf4 = yt2;
    } else if (ancor2 == 'm' || ancor2 == 'M') {
        xf3 = xt2 - comprimentoTexto2 / 2;
        yf3 = yt2;
        xf4 = xt2 + comprimentoTexto2 / 2;
        yf4 = yt2;
    }

    if (intersecaoSegmentos(xf1, yf1, xf2, yf2, xf3, yf3, xf4, yf4)) {
        return 1; // Colisao
    }
    return 0; // Sem colisao
}

int intersecaoSegmentos(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double determinante = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (determinante == 0) {
        return 0;
    }
    double numeA = (x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4);
    double numeB = (x1 - x3) * (y1 - y2) - (y1 - y3) * (x1 - x2);

    double posicaoA = numeA / determinante;
    double posicaoB = numeB / determinante;

    if(posicaoA >= 0 && posicaoA <= 1 && posicaoB >= 0 && posicaoB <= 1){
        return 1;
    }
    else{
        return 0;
    }
}

void verificaColisao(FILE* ptrTXT, FILE* ptrSVG, lancador* ALVO, lancador* OGIVA, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* maiorID, int* formascriadas){
    
    XYaposDeslocamentoTXT(ptrTXT, alvoForma, ogivaForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O);
    char tipoAlvo = getTipoLancador(ALVO);
    
    if (tipoAlvo == 'c' || tipoAlvo == 'C') {
        colisaoCircAlvo(ptrTXT, ptrSVG, ALVO, OGIVA, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, maiorID, formascriadas);
    }

    if (tipoAlvo == 'r' || tipoAlvo == 'R') {
        colisaoRetAlvo(ptrTXT, ptrSVG, ALVO, OGIVA, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, maiorID, formascriadas);
    }

    if (tipoAlvo== 'l' || tipoAlvo == 'L') {
        colisaoLinhaAlvo(ptrTXT, ptrSVG, ALVO, OGIVA, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, maiorID, formascriadas);
    }

    if (tipoAlvo == 't' || tipoAlvo == 'T') {
        colisaoTxtAlvo(ptrTXT, ptrSVG, ALVO, OGIVA, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, maiorID, formascriadas);
    }
}

void colisaoCircAlvo(FILE* ptrTXT, FILE* ptrSVG, lancador* ALVO, lancador* OGIVA, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* maiorID, int* formascriadas){
    char tipoOgiva = getTipoLancador(OGIVA);
    if (tipoOgiva == 'c' || tipoOgiva == 'C') {
        if (colisaoCircCirc(alvoForma, ogivaForma, x1A, y1A, x1O, y1O) == 1) {
                efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
                semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
    if (tipoOgiva == 'r' || tipoOgiva == 'R') {
        if (colisaoRetCirc(ogivaForma, alvoForma, x1O, y1O, x1A, y1A) == 1) {
                efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
    if(tipoOgiva == 'l' || tipoOgiva == 'L') {
        if (colisaoCircLinha(alvoForma, ogivaForma, x1A, y1A, x1O, y1O, x2O, y2O) == 1) {
                efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
    if(tipoOgiva == 't' || tipoOgiva == 'T'){
        if (colisaoCircTexto(alvoForma, ogivaForma, x1A, y1A, x1O, y1O) == 1) {
            efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
}   

void colisaoRetAlvo(FILE* ptrTXT, FILE* ptrSVG, lancador* ALVO, lancador* OGIVA, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* maiorID, int* formascriadas){
    char tipoOgiva = getTipoLancador(OGIVA);

    if (tipoOgiva == 'c' || tipoOgiva == 'C') {
        if (colisaoRetCirc(alvoForma, ogivaForma, x1A, y1A, x1O, y1O) == 1) {
            efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
    if (tipoOgiva == 'r' || tipoOgiva == 'R') {
        if (colisaoRetRet(alvoForma, ogivaForma, x1A, y1A, x1O, y1O) == 1) {
            efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
    if (tipoOgiva == 'l' || tipoOgiva == 'L') {
        if (colisaoRetLinha(alvoForma, ogivaForma, x1A, y1A, x1O, y1O, x2O, y2O) == 1) {
            efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
    if (tipoOgiva == 't' || tipoOgiva == 'T') {
        if (colisaoRetTexto(alvoForma, ogivaForma, x1A, y1A, x1O, y1O) == 1) {
            efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
}

void colisaoLinhaAlvo(FILE* ptrTXT, FILE* ptrSVG, lancador* ALVO, lancador* OGIVA, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* maiorID, int* formascriadas){
    char tipoOgiva = getTipoLancador(OGIVA);

    if (tipoOgiva == 'c' || tipoOgiva == 'C') {
        if (colisaoCircLinha(ogivaForma, alvoForma, x1O, y1O, x1A, y1A, x2A, y2A) == 1) {
            efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
    if (tipoOgiva == 'r' || tipoOgiva == 'R') {
        if (colisaoRetLinha(ogivaForma, alvoForma, x1O, y1O, x1A, y1A, x2A, y2A) == 1) {
            efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
    if (tipoOgiva == 'l' || tipoOgiva == 'L') {
        if (colisaoLinhaLinha(alvoForma, ogivaForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O) == 1) {
            efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
    if (tipoOgiva == 't' || tipoOgiva == 'T') {
        if (colisaoLinhaTexto(alvoForma, ogivaForma, x1O, y1O, x1A, y1A, x1A, y2A) == 1) {
            efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
}

void colisaoTxtAlvo(FILE* ptrTXT, FILE* ptrSVG, lancador* ALVO, lancador* OGIVA, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* maiorID, int* formascriadas){
    char tipoOgiva = getTipoLancador(OGIVA);

    if (tipoOgiva == 'c' || tipoOgiva == 'C') {
        if (colisaoCircTexto(ogivaForma, alvoForma, x1O, y1O, x1A, y1A) == 1) {
            efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
    if (tipoOgiva == 'r' || tipoOgiva == 'R') {
        if (colisaoRetTexto(ogivaForma, alvoForma, x1O, y1O, x1A, y1A) == 1) {
            efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
    if (tipoOgiva == 'l' || tipoOgiva == 'L') {
        if (colisaoLinhaTexto(ogivaForma, alvoForma, x1A, y1A, x1O, y1O, x2O, y2O) == 1) {
            efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
    if (tipoOgiva == 't' || tipoOgiva == 'T') {
        if (colisaoTextoTexto(alvoForma, ogivaForma, x1A, y1A, x1O, y1O) == 1) {
            efeitosColisao(ptrTXT, ptrSVG, maiorID, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, formascriadas);
        }
        else{
            semColisao(ptrTXT, ptrSVG, ogivaForma, alvoForma, x1O, y1O, x2O, y2O, filaR, filaC, filaL, filaT, formasdestruidas, pontosRet, pontosCirc, pontosLinha, pontosTxt, x1A, y1A, x2A, y2A);
        }
    }
}

void efeitosColisao(FILE* ptrTXT, FILE* ptrSVG, int* maiorID, void* ogivaForma, void* alvoForma, double x1A, double y1A, double x2A, double y2A, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, int* formascriadas){
    double areaOgiva; 
    double areaAlvo;
    char identificarColisao;

    if (getTipoRetangulo(ogivaForma) == 'r') {
        areaOgiva = getAreaRetangulo(ogivaForma);
    } 
    else if (getTipoCirculo(ogivaForma) == 'c') {
        areaOgiva = getAreaCirculo(ogivaForma);
    } 
    else if (getTipoLinha(ogivaForma) == 'l') {
        areaOgiva = getAreaLinha(ogivaForma); 
    } 
    else if (getTipoTexto(ogivaForma) == 't') {
        areaOgiva = getAreaTexto(ogivaForma);
    }

    if(getTipoRetangulo(alvoForma) == 'r') {
        areaAlvo = getAreaRetangulo(alvoForma);
    } 
    else if(getTipoCirculo(alvoForma) == 'c') {
        areaAlvo = getAreaCirculo(alvoForma);
    } 
    else if(getTipoLinha(alvoForma) == 'l') {
        areaAlvo = getAreaLinha(alvoForma); 
    } 
    else if(getTipoTexto(alvoForma) == 't') {
        areaAlvo = getAreaTexto(alvoForma);
    }

    double diferencaAreas = fabs(areaOgiva - areaAlvo);
    double mediaAreas = (areaOgiva + areaAlvo) / 2.0;

    if (diferencaAreas > 0.1 * mediaAreas){ // Areas nao semelhantes

        if (areaOgiva > areaAlvo){
            identificarColisao = 'o'; // Ogiva maior
            efeitosLancamentoTXT(ptrTXT, identificarColisao);

            free(alvoForma);

            atualizarFormasDestruidas(formasdestruidas);
            printarDestruicaoAlvoSVG2(ptrSVG, x1A, y1A);

            double ponto = calcularPontoLancamento(areaOgiva, areaAlvo);
            atualizarPosicao(ogivaForma, x1O, y1O, x2O, y2O);
            formasDepoisTXTogiva(ptrTXT, ogivaForma, ponto);

            enfileirar(filaR, filaC, filaL, filaT, ogivaForma);

            atualizaPontos(ponto, ogivaForma, pontosRet, pontosCirc, pontosLinha, pontosTxt);
        }

        else if (areaAlvo > areaOgiva){
            identificarColisao = 'a'; // Alvo maior
            efeitosLancamentoTXT(ptrTXT, identificarColisao);
        
            retrocederProporcional(areaOgiva, areaAlvo, ogivaForma, alvoForma, x1A, y1A, x2A, y2A, x1O, y1O, x2O, y2O);
            enfileirar(filaR, filaC, filaL, filaT, ogivaForma);
            enfileirar(filaR, filaC, filaL, filaT, alvoForma);

            formasDepoisTXT(ptrTXT, ogivaForma, alvoForma);
        }
    }
    else if (diferencaAreas <= 0.1 * mediaAreas){ // Areas semelhantes
        identificarColisao = 's'; // Semelhantes
        efeitosLancamentoTXT(ptrTXT, identificarColisao);

        retrocederMetade(ogivaForma, x1O, y1O, x2O, y2O);
        retrocederMetade(alvoForma, x1A, y1A, x2A, y2A);

        formasDepoisTXT(ptrTXT, ogivaForma, alvoForma);

        void* cloneOgiva = clonarForma(ogivaForma, x1O, y1O, x2O, y2O, maiorID);
        void* cloneAlvo = clonarForma(alvoForma, x1A, y1A, x2A, y2A, maiorID);

        atualizarFormasCriadas(formascriadas);
        atualizarFormasCriadas(formascriadas);

        dadosClonesTXT(ptrTXT, cloneAlvo, cloneOgiva);

        enfileirar(filaR, filaC, filaL, filaT, alvoForma);
        enfileirar(filaR, filaC, filaL, filaT, ogivaForma);
        enfileirar(filaR, filaC, filaL, filaT, cloneAlvo);
        enfileirar(filaR, filaC, filaL, filaT, cloneOgiva);
    }

}

void semColisao(FILE* ptrTXT, FILE* ptrSVG, void* ogivaForma, void* alvoForma, double x1O, double y1O, double x2O, double y2O, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formasdestruidas, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt, double x1A, double y1A, double x2A, double y2A){
    char identificarColisao = 'n'; // Nao tem colisao
    efeitosLancamentoTXT(ptrTXT, identificarColisao);

    printarDestruicaoOgivaSVG2(ptrSVG, ogivaForma, x1O, y1O);

    free(ogivaForma);
    atualizarFormasDestruidas(formasdestruidas);

    atualizarPosicao(alvoForma, x1A, y1A, x2A, y2A);
    enfileirar(filaR, filaC, filaL, filaT, alvoForma);

    formasDepoisTXTalvo(ptrTXT, alvoForma);
}