#include "dadosTXT.h"

void atualizaPontos(double ponto, void* ogivaForma, double* pontosRet, double* pontosCirc, double* pontosLinha, double* pontosTxt){
    if (getTipoRetangulo(ogivaForma) == 'r') {
        *pontosRet = (*pontosRet) + ponto;
    }
    else if (getTipoCirculo(ogivaForma) == 'c') {
        *pontosCirc = (*pontosCirc) + ponto;
    }
    else if (getTipoLinha(ogivaForma) == 'l') {
        *pontosLinha = (*pontosLinha) + ponto;
    }
    else if (getTipoTexto(ogivaForma) == 't') {
        *pontosTxt = (*pontosTxt) + ponto;
    }  
}

double calcularPontoLancamento(double areaOgiva, double areaAlvo){
    double ponto = 0.0;
    ponto = (areaAlvo / areaOgiva ) * 100;

    return ponto;
}

void atualizarInstrucoes(int* intrucoes){
    (*intrucoes)++;
}

void atualizarLancamentos(int* lancamentos){
    (*lancamentos)++;
}

void atualizarFormasDestruidas(int* formasdestruidas){
    (*formasdestruidas)++;
}

void atualizarFormasCriadas(int* formascriadas){
    (*formascriadas)++;
}

int getInstrucoes(int* instrucoes) {
    return *instrucoes;
}

int getLancamentos(int* lancamentos) {
    return *lancamentos;
}

int getFormasDestruidas(int* formasDestruidas) {
    return *formasDestruidas;
}

int getFormasCriadas(int* formasCriadas) {
    return *formasCriadas;
}

double getPontosRet(double* pontosRet) {
    return *pontosRet;
}

double getPontosCirc(double* pontosCirc) {
    return *pontosCirc;
}

double getPontosLinha(double* pontosLinha) {
    return *pontosLinha;
}

double getPontosTxt(double* pontosTxt) {
    return *pontosTxt;
}