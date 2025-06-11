#include "fila.h"

typedef struct no{
    void* elemento;
    struct no* prox;
} no;

typedef struct fila{
    no* frente;
    no* tras;
} fila;

void inicializarFila(fila** f){
    *f = (fila*)malloc(sizeof(fila));
    if(*f == NULL){
        printf("Erro ao alocar memoria para a fila.\n");
        exit(1);
    }
    (*f)->frente = NULL;
    (*f)->tras = NULL;
}

void enfileirar(fila* filaR, fila* filaC, fila* filaL, fila* filaT, void* forma){
    no* novo = (no*)malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para no da fila.\n");
        exit(1);
    }

    novo->elemento = forma;
    novo->prox = NULL;

    if (getTipoRetangulo(forma) == 'r') {
        if (filaR->tras != NULL) {
            filaR->tras->prox = novo;
        }
        filaR->tras = novo;
        if (filaR->frente == NULL) {
            filaR->frente = novo;
        }
    } 
    else if (getTipoCirculo(forma) == 'c') {
        if (filaC->tras != NULL) {
            filaC->tras->prox = novo;
        }
        filaC->tras = novo;
        if (filaC->frente == NULL) {
            filaC->frente = novo;
        }
    } 
    else if (getTipoLinha(forma) == 'l') {
        if (filaL->tras != NULL) {
            filaL->tras->prox = novo;
        }
        filaL->tras = novo;
        if (filaL->frente == NULL) {
            filaL->frente = novo;
        }
    } 
    else if (getTipoTexto(forma) == 't') {
        if (filaT->tras != NULL) {
            filaT->tras->prox = novo;
        }
        filaT->tras = novo;
        if (filaT->frente == NULL) {
            filaT->frente = novo;
        }
    } 
}

void* getPrimeiroElemento(fila* f) {
    if (f->frente == NULL) {
        printf("Fila vazia. (getPrimeiroElemento)\n");
        return NULL;
    }

    no* temp = f->frente;
    void* elemento = temp->elemento;

    f->frente = temp->prox;

    if (f->frente == NULL) {
        f->tras = NULL;
    }

    free(temp);
    return elemento;
}

void printarFilaSVG(fila* f, FILE* arquivo){
    no* atual = f->frente;
    while (atual != NULL) {
        void* elemento = atual->elemento;

        if(getTipoCirculo(elemento) == 'c'){
            int id = getIdCirculo(elemento);
            double x = getXCirculo(elemento);
            double y = getYCirculo(elemento);
            double raio = getRaioCirculo(elemento);
            char* corp = getCorpCirculo(elemento);
            char* corb = getCorbCirculo(elemento);
            fprintf(arquivo, "<circle id=\"%d\" cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"2\" />\n", id, x, y, raio, corp, corb);
        }
        else if(getTipoRetangulo(elemento) == 'r' || getTipoRetangulo(elemento) == 'R') {
            int id = getIdRetangulo(elemento);
            double x = getXRetangulo(elemento);
            double y = getYRetangulo(elemento);
            double largura = getWRetangulo(elemento);
            double altura = getHRetangulo(elemento);
            char* corb = getCorbRetangulo(elemento);
            char* corp = getCorpRetangulo(elemento);
            fprintf(arquivo, "<rect id =\"%d\" x=\"%lf\" y=\"%lf\" width=\"%.6lf\" height=\"%.6lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"2\" />\n", id, x, y, largura, altura, corp, corb);
        }
        else if(getTipoLinha(elemento) == 'l') {
            int id = getIdLinha(elemento);
            double x1 = getX1Linha(elemento);
            double y1 = getY1Linha(elemento);
            double x2 = getX2Linha(elemento);
            double y2 = getY2Linha(elemento);
            char* cor = getCorLinha(elemento);
            fprintf(arquivo, "<line id = \"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"1\" />\n", id, x1, y1, x2, y2, cor);
        }

        else if(getTipoTexto(elemento) == 't') {
            int id = getIdCirculo(elemento);
            double x = getXTexto(elemento);
            double y = getYTexto(elemento);
            char* texto = getTexto(elemento);
            char* corb = getCorbTexto(elemento);
            char* corp = getCorpTexto(elemento);
            char* familia = getFamilyTexto(elemento); 
            char* weight = getWeightTexto(elemento); 
            char* size = getSizeTexto(elemento); 
            char a = getATexto(elemento);

            char* svgWeight;
            if(weight != NULL && weight[0] == 'b'){
                svgWeight = "bold";
            }
            else{
                svgWeight = "normal";
            }

            char* ancora;
            if(a == 'i' || a == 'I'){
                ancora = "start";
            } 
            else if (a == 'm' || a == 'M'){
                ancora = "middle";
            } 
            else if (a == 'f' || a == 'F'){
                ancora = "end";
            } 
            else{
                ancora = "start";
            }
            fprintf(arquivo, "<text id=\"%d\" x=\"%lf\" y=\"%lf\" font-family=\"%s\" font-weight=\"%s\" font-size=\"%s\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1\" text-anchor=\"%s\">%s</text>\n", id, x, y, familia, svgWeight, size, corp, corb, ancora, texto);
        }
        atual = atual->prox;
    }
}

void freeFila(fila* f) {
    if (f == NULL) return;
    no* atual = f->frente;
    no* temp;

    while (atual != NULL) {
        temp = atual;
        atual = atual->prox;

        if (temp->elemento != NULL) {
            free(temp->elemento);
        }

        free(temp);
    }

    free(f);
}