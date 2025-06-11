#include "gerarSVG.h"

FILE* abrirSVGgeo(char* nome){
    char* nomesvg = concatenarComExtensao(nome, 's');
    FILE* file = fopen(nomesvg, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo svg geo.\n");
        exit(1);
    }

    return file;
}

void gerarSVG_GEO(FILE* file, fila* filaR, fila* filaC, fila* filaL, fila* filaT) {

    fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100%%\" height=\"100%%\" viewBox=\"0 0 2000 2000\">\n");
    printarFilaSVG(filaR, file);
    printarFilaSVG(filaC, file);
    printarFilaSVG(filaL, file);
    printarFilaSVG(filaT, file);

    fprintf(file, "</svg>\n");

    fclose(file);
}