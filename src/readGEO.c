#include "readGEO.h"

FILE* abrirGEO(char* nomeGEO){
    FILE *file = fopen(nomeGEO, "r");
    if (file == NULL){
        printf("Erro ao abrir arquivo geo.\n");
        exit(1);
    }

    return file;
}

void processarGEO(FILE* file, fila* filaR, fila* filaC, fila* filaL, fila* filaT, int* formascriadas, int* intrucoes){
    int id;
    double x, y, raio, w, h, x1, x2, y1, y2;
    char *corb = NULL, *corp = NULL, *texto = NULL, *cor = NULL;
    char *family = NULL, *weight = NULL, *size = NULL;
    char a;
    char tipo[3];

    corb = (char*)malloc(20 * sizeof(char));
    corp = (char*)malloc(20 * sizeof(char));
    texto = (char*)malloc(600 * sizeof(char));
    cor = (char*)malloc(20 * sizeof(char));
    family = (char*)malloc(20 * sizeof(char));
    weight = (char*)malloc(20 * sizeof(char));
    size = (char*)malloc(20 * sizeof(char));

        if (corb == NULL || corp == NULL || texto == NULL || cor == NULL || family == NULL || weight == NULL || size == NULL) {
        printf("Erro ao alocar memoria para as strings (corb, corp, texto...).\n");
        exit(1);
    }

    while(fscanf(file, "%s", tipo) != EOF){
        
        //TS
        if (strcmp(tipo, "ts") == 0 || strcmp(tipo, "TS") == 0) {
            fscanf(file, "%s %s %s", family, weight, size);
        }

        //RETANGULO
        if(strcmp(tipo, "r") == 0 || strcmp(tipo, "R") == 0){ 
            fscanf(file, "%d %lf %lf %lf %lf %s %s", &id, &x, &y, &w, &h, corb, corp);

            formaRetangulo* novoRet = inicializaRetangulo(id, x, y, w, h, corb, corp);
            enfileirar(filaR, filaC, filaL, filaT, (void*)novoRet);
            atualizarFormasCriadas(formascriadas);
        }

        //CIRCULO
        else if(strcmp(tipo, "c") == 0 || strcmp(tipo, "C") == 0){ 
            fscanf(file, "%d %lf %lf %lf %s %s", &id, &x, &y, &raio, corb, corp);

            formaCirculo* novoCirc = inicializaCirculo(id, x, y, raio, corb, corp);
            enfileirar(filaR, filaC, filaL, filaT, (void*)novoCirc);
            atualizarFormasCriadas(formascriadas);
        }

        //LINHA
        else if(strcmp(tipo, "l") == 0 || strcmp(tipo, "L") == 0){ 
            fscanf(file, "%d %lf %lf %lf %lf %s", &id, &x1, &y1, &x2, &y2, cor);

            formaLinha* novaLinha = inicializaLinha(id, x1, x2, y1, y2, cor);
            enfileirar(filaR, filaC, filaL, filaT, (void*)novaLinha);
            atualizarFormasCriadas(formascriadas);
        }

        //TEXTO
        else if (strcmp(tipo, "t") == 0 || strcmp(tipo, "T") == 0) { 
            fscanf(file, "%d %lf %lf %s %s %c", &id, &x, &y, corb, corp, &a);
            fscanf(file, " %[^\n]", texto);

            formaTexto* novoTexto = inicializaTexto(id, x, y, corb, corp, a, texto);
            atualizarFormasCriadas(formascriadas);

            if (family != NULL && weight != NULL && size != NULL) {
                defineEstilo(novoTexto, family, weight, size);
            }

            enfileirar(filaR, filaC, filaL, filaT, (void*)novoTexto);
        }

        atualizarInstrucoes(intrucoes);

        fscanf(file, "\n");
    }
    fclose(file);
    free(corb);        
    free(corp);
    free(texto);
    free(cor);
}


int obterMaiorId(char* nomeGEO) {
    FILE* file = abrirGEO(nomeGEO);
    int maiorID = 0;
    char tipo[4];
    int id;
    rewind(file);
    while (fscanf(file, "%3s", tipo) != EOF){

        if (strcmp(tipo, "ts") == 0 || strcmp(tipo, "TS") == 0) {
            fscanf(file, "%*[^'\n']");
        }
        else if (strcmp(tipo, "r") == 0 || strcmp(tipo, "R") == 0) { 
            if (fscanf(file, "%d", &id) == 1) {
                if (id > maiorID) {
                    maiorID = id;
                }
            }
        }
        else if (strcmp(tipo, "c") == 0 || strcmp(tipo, "C") == 0) { 
            if (fscanf(file, "%d", &id) == 1) {
                if (id > maiorID) {
                    maiorID = id;
                }
            }    
        }
        else if (strcmp(tipo, "l") == 0 || strcmp(tipo, "L") == 0) { 
            if (fscanf(file, "%d", &id) == 1) {
                if (id > maiorID) {
                    maiorID = id;
                }
            }    
        }
        else if (strcmp(tipo, "t") == 0 || strcmp(tipo, "T") == 0) { 
            if (fscanf(file, "%d", &id) == 1) {
                if (id > maiorID) {
                    maiorID = id;
                }
            fscanf(file, "\n");
            }
        }
    }
    fclose(file);
    return (maiorID + 1);
}