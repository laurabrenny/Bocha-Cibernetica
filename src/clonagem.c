#include "clonagem.h"


void* clonarForma(void* original, double x, double y, double x2, double y2, int *maiorID){
    char* corb = "#d400aa";
    void* clone;

    if (getTipoRetangulo(original) == 'r') {
        double w = getWRetangulo(original);
        double h = getHRetangulo(original);
        char* corp = getCorpRetangulo(original);

        clone = (void*)inicializaRetangulo(*maiorID, x, y, w, h, corb, corp);
    }

    else if (getTipoCirculo(original) == 'c') {
        double raio = getRaioCirculo(original);
        char* corp = getCorpCirculo(original);

        clone = (void*)inicializaCirculo(*maiorID, x, y, raio, corb, corp);
    }

    else if (getTipoLinha(original) == 'l') {
        clone = (void*)inicializaLinha(*maiorID, x, x2, y, y2, corb);
    }

    else if (getTipoTexto(original) == 't') {
        char* texto = getTexto(original);
        char* corp = getCorpTexto(original);
        char* family = getFamilyTexto(original); 
        char* weight = getWeightTexto(original); 
        char* size = getSizeTexto(original); 
        char a = getATexto(original);

        clone = (void*)inicializaTexto(*maiorID, x, y, corb, corp, a, texto);
        defineEstilo(clone, family, weight, size);
    }
    
    (*maiorID)++;
    return clone;
}