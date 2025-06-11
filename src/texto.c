#include "texto.h"

typedef struct estiloTexto{
    char* family;
    char* weight;
    char* size;
} estiloTexto;

typedef struct formaTexto{
    int id;
    double x, y;
    char* corb;
    char* corp;
    char a; //i=inicio, m=meio, f=fim
    char* texto;
    char tipo; //tipo t
    estiloTexto estilo;
}formaTexto;

TEXTO inicializaTexto (int ID, double X, double Y, char* CORB, char* CORP, char A, char* TEXTO){
    formaTexto* txt = (formaTexto*)malloc(sizeof(formaTexto));
    if(txt == NULL){
        printf("Erro ao alocar memoria para a forma texto.\n");
        exit(1);
    }

    txt->id = ID;
    txt->x = X;
    txt->y = Y;
    txt->a = A;
    txt->tipo = 't';

    txt->corb = (char*)malloc(strlen(CORB)+1);
    if(txt->corb == NULL){
        printf("Erro ao alocar memoria para corb de texto.\n");
        free(txt);
        exit(1);
    }
    strcpy(txt->corb, CORB);

    txt->corp = (char*)malloc(strlen(CORP)+1);
    if(txt->corp == NULL){
        printf("Erro ao alocar memoria para corp de texto.\n");
        free(txt->corb);
        free(txt);
        exit(1);
    }
    strcpy(txt->corp, CORP);

    txt->texto = (char*)malloc(strlen(TEXTO)+1);
    if(txt->texto == NULL){
        printf("Erro ao alocar memoria para o texto (da forma texto).\n");
        free(txt);
        free(txt->corb);
        free(txt->corp);
        exit(1);
    }
    strcpy(txt->texto, TEXTO);

    txt->estilo.family = NULL;
    txt->estilo.weight = NULL;
    txt->estilo.size = NULL;

    return ((formaTexto*)txt);
}

void defineEstilo(TEXTO t, char* FAMILY, char* WEIGHT, char* SIZE) {
    formaTexto* txt = (formaTexto*)t;

    txt->estilo.family = (char*)malloc(strlen(FAMILY) + 1);
    if (txt->estilo.family == NULL) {
        printf("Erro ao alocar memoria para family do texto.\n");
        exit(1);
    }
    strcpy(txt->estilo.family, FAMILY);

    txt->estilo.weight = (char*)malloc(strlen(WEIGHT) + 1);
    if (txt->estilo.weight == NULL) {
        printf("Erro ao alocar memoria para weight do texto.\n");
        free(txt->estilo.family);
        exit(1);
    }
    strcpy(txt->estilo.weight, WEIGHT);

    txt->estilo.size = (char*)malloc(strlen(SIZE) + 1);
    if (txt->estilo.size == NULL) {
        printf("Erro ao alocar memoria para size do texto.\n");
        free(txt->estilo.weight);
        free(txt->estilo.family);
        exit(1);
    }
    strcpy(txt->estilo.size, SIZE);
}

int getIdTexto(TEXTO t) {
    return ((formaTexto*)t)->id;
}

double getXTexto(TEXTO t) {
    return ((formaTexto*)t)->x;
}

double getYTexto(TEXTO t) {
    return ((formaTexto*)t)->y;
}

char* getCorbTexto(TEXTO t) {
    return ((formaTexto*)t)->corb;
}

char* getCorpTexto(TEXTO t) {
    return ((formaTexto*)t)->corp;
}

char getATexto(TEXTO t) {
    return ((formaTexto*)t)->a;
}

char* getTexto(TEXTO t) {
    return ((formaTexto*)t)->texto;
}

char getTipoTexto(TEXTO t) {
    return ((formaTexto*)t)->tipo;
}

char* getFamilyTexto(TEXTO t) {
    return ((formaTexto*)t)->estilo.family;
}

char* getWeightTexto(TEXTO t) {
    return ((formaTexto*)t)->estilo.weight;
}

char* getSizeTexto(TEXTO t) {
    return ((formaTexto*)t)->estilo.size;
}

int getNumCaracteresTexto(TEXTO t){
    char* txt = getTexto(t);
    return strlen(txt);
}

double getAreaTexto(TEXTO t) {
    int num = getNumCaracteresTexto(t);
    double a = num * 10.0;
    return a;
}

void setXTexto(TEXTO t, double X) {
    ((formaTexto*)t)->x = X;
}

void setYTexto(TEXTO t, double Y) {
    ((formaTexto*)t)->y = Y;
}