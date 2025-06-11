#include "retangulo.h"

typedef struct formaRetangulo{
    int id;
    double x, y, w, h;
    char* corb;
    char* corp;
    char tipo;
}formaRetangulo;


RETANGULO inicializaRetangulo(int ID, double X, double Y, double W, double H, char* CORB, char* CORP){
    formaRetangulo* ret = (formaRetangulo*)malloc(sizeof(formaRetangulo));
    if(ret == NULL){
        printf("Erro ao alocar memoria para retangulo.\n");
        free(ret);
        exit(1);
    }
    
    ret->id = ID;
    ret->x = X;
    ret->y = Y;
    ret->w = W;
    ret->h = H;
    ret->tipo = 'r';
    
    ret->corb = (char*)malloc(strlen(CORB)+1);
        if (ret->corb == NULL) {
        printf("Erro ao alocar memoria para corb do retangulo.\n");
        free(ret->corb);
        free(ret);
        exit(1);
    }
    strcpy(ret->corb, CORB);

    ret->corp = (char*)malloc(strlen(CORP)+1);
    if (ret->corp == NULL) {
        printf("Erro ao alocar memoria para corp do retangulo.\n");
        free(ret->corp);
        free(ret);
        exit(1);
    }
    strcpy(ret->corp, CORP);

    return ((formaRetangulo*)ret);
}

int getIdRetangulo(RETANGULO retangulo) {
    return ((formaRetangulo*)retangulo)->id;
}

double getXRetangulo(RETANGULO retangulo) {
    return ((formaRetangulo*)retangulo)->x;
}

double getYRetangulo(RETANGULO retangulo) {
    return ((formaRetangulo*)retangulo)->y;
}

double getWRetangulo(RETANGULO retangulo) {
    return ((formaRetangulo*)retangulo)->w;
}

double getHRetangulo(RETANGULO retangulo) {
    return ((formaRetangulo*)retangulo)->h;
}

char* getCorbRetangulo(RETANGULO retangulo) {
    return ((formaRetangulo*)retangulo)->corb;
}

char* getCorpRetangulo(RETANGULO retangulo) {
    return ((formaRetangulo*)retangulo)->corp;
}

char getTipoRetangulo(RETANGULO retangulo) {
    return ((formaRetangulo*)retangulo)->tipo;
}

double getAreaRetangulo(RETANGULO retangulo) {
    double W = ((formaRetangulo*)retangulo)->w;
    double H = ((formaRetangulo*)retangulo)->h;
    double a = (W * H);
    return a;
}

void setXRetangulo(RETANGULO retangulo, double X) {
    ((formaRetangulo*)retangulo)->x = X;
}

void setYRetangulo(RETANGULO retangulo, double Y) {
    ((formaRetangulo*)retangulo)->y = Y;
}

//setters

// void setIdRetangulo(RETANGULO retangulo, int ID) {
//     ((formaRetangulo*)retangulo)->id = ID;
// }



// void setWRetangulo(RETANGULO retangulo, double W) {
//     ((formaRetangulo*)retangulo)->w = W;
// }

// void setHRetangulo(RETANGULO retangulo, double H) {
//     ((formaRetangulo*)retangulo)->h = H;
// }

// void setCorbRetangulo(RETANGULO retangulo, char* CORB) {
//     ((formaRetangulo*)retangulo)->corb = strdup(CORB);
// }

// void setCorpRetangulo(RETANGULO retangulo, char* corp) {
//     // Libera a memória previamente alocada para a cor anterior, se necessário
//     free(((formaRetangulo*)retangulo)->corp);
//     // Aloca memória para a nova cor e copia a string
//     ((formaRetangulo*)retangulo)->corp = strdup(corp);
// }

// void setTipoRetangulo(RETANGULO retangulo, char tipo) {
//     ((formaRetangulo*)retangulo)->tipo = tipo;
// }