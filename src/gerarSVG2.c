#include "gerarSVG2.h" 

FILE* abrirSVG2(char* nome) {
    char* nomesvg = concatenarComExtensao(nome, 's');
    FILE* file = fopen(nomesvg, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo svg geo-qry.\n");
        exit(1);
    }

    fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"100%%\" height=\"100%%\" viewBox=\"-300 -300 2900 2900\">\n");

    return file;
}

void printarDestruicaoAlvo(FILE* file, double x, double y){
    fprintf(file, "<text x=\"%lf\" y=\"%lf\" font-family=\"Arial\" font-size=\"30\" fill=\"red\">*</text>\n", x, y);
}

void printarDestruicaoErro(FILE* file, void* ogivaForma, double x, double y){
    if(getTipoTexto(ogivaForma) == 't'){
        char* texto = getTexto(ogivaForma);
        char* family = getFamilyTexto(ogivaForma);
        char* size = getSizeTexto(ogivaForma);
        char* weight = getWeightTexto(ogivaForma);
        char a = getATexto(ogivaForma);

        char* svgWeight;
        if (weight != NULL && weight[0] == 'b') {
            svgWeight = "bold";
        } else {
            svgWeight = "normal";
        }

        char* ancora;
        if (a == 'i' || a == 'I') {
            ancora = "start";
        } else if (a == 'm' || a == 'M') {
            ancora = "middle";
        } else if (a == 'f' || a == 'F') {
            ancora = "end";
        } else {
            ancora = "start";
        }
        fprintf(file, "<text x=\"%lf\" y=\"%lf\" font-family=\"%s\" font-weight=\"%s\" font-size=\"%s\" fill=\"red\" stroke=\"red\" stroke-width=\"1\" text-anchor=\"%s\">%s</text>\n", x, y, family, svgWeight, size, ancora, texto);
    }
    else{
        fprintf(file, "<text x=\"%lf\" y=\"%lf\" font-family=\"Arial\" font-size=\"30\" fill=\"red\">*</text>\n", x, y);
    }

}

void printarFormasRestantesSVG2(FILE* file, fila* filaR, fila* filaC, fila* filaL, fila* filaT){
    printarFilaSVG(filaR, file);
    printarFilaSVG(filaC, file);
    printarFilaSVG(filaL, file);
    printarFilaSVG(filaT, file);
}

void fecharSVG2(FILE* file){
    fprintf(file, "</svg>\n");
    fclose(file);
}