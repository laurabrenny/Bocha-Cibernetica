#include "circulo.h"

typedef struct formaCirculo{
    int id;
    double x;
    double y;
    double raio;
    char* corb;
    char* corp;
    char tipo;
}formaCirculo;

CIRCULO inicializaCirculo(int ID, double X, double Y, double RAIO, char* CORB, char* CORP){
    formaCirculo* circ = (formaCirculo*)malloc(sizeof(formaCirculo));
    if(circ == NULL){
        printf("Erro ao alocar memoria para circulo.\n");
        exit(1);
    }

    circ->id = ID;
    circ->x = X;
    circ->y = Y;
    circ->raio = RAIO;
    circ->tipo = 'c';

    circ->corb = (char*)malloc(strlen(CORB)+1);
        if (circ->corb == NULL) {
        printf("Erro ao alocar memoria para corb do circulo.\n");
        free(circ);
        exit(1);
    }
    strcpy(circ->corb, CORB);

    circ->corp = (char*)malloc(strlen(CORP)+1);
    if (circ->corp == NULL) {
        printf("Erro ao alocar memoria para corp do circulo.\n");
        free(circ->corb);
        free(circ);
        exit(1);
    }
    strcpy(circ->corp, CORP);

    return ((formaCirculo*)circ);
}

int getIdCirculo(CIRCULO circulo) {
    return ((formaCirculo*)circulo)->id;
}

double getXCirculo(CIRCULO circulo) {
    return ((formaCirculo*)circulo)->x;
}

double getYCirculo(CIRCULO circulo) {
    return ((formaCirculo*)circulo)->y;
}

double getRaioCirculo(CIRCULO circulo) {
    return ((formaCirculo*)circulo)->raio;
}

char* getCorbCirculo(CIRCULO circulo) {
    return ((formaCirculo*)circulo)->corb;
}

char* getCorpCirculo(CIRCULO circulo) {
    return ((formaCirculo*)circulo)->corp;
}

char getTipoCirculo(CIRCULO circulo) {
    return ((formaCirculo*)circulo)->tipo;
}

double getAreaCirculo(CIRCULO circulo) {
    double r = ((formaCirculo*)circulo)->raio;
    double a = PI * (r * r); 
    return a;
}

void setXCirculo(CIRCULO circulo, double X) {
    ((formaCirculo*)circulo)->x = X;
}

void setYCirculo(CIRCULO circulo, double Y) {
    ((formaCirculo*)circulo)->y = Y;
}