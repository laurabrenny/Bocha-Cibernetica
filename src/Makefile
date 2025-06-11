PROJ_NAME=
LIBS=
OBJETOS=main.o retangulo.o circulo.o linha.o texto.o fila.o readGEO.o readQRY.o gerarSVG.o lancadores.o colisao.o deslocamento.o lancamento.o retrocederMetade.o retrocederProp.o gerarSVG2.o gerarTXT.o dadosTXT.o tratarArquivos.o clonagem.o


# compilador
CC=gcc


# Flags
CFLAGS= -ggdb -O0 -std=c99 -fstack-protector-all -Werror=implicit-function-declaration


LDFLAGS=-O0 -lm


$(PROJ_NAME): $(OBJETOS)
	$(CC) -o $(PROJ_NAME) $(OBJETOS) $(LDFLAGS) $(LIBS)


%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	rm -f $(OBJETOS) $(PROJ_NAME)


# COLOCAR DEPENDENCIAS DE CADA MODULO

main.o: main.c fila.h readGEO.h readQRY.h gerarSVG.h gerarSVG2.h
retangulo.o: retangulo.c retangulo.h
circulo.o: circulo.c circulo.h
linha.o: linha.c linha.h
texto.o: texto.c texto.h
fila.o: fila.c fila.h retangulo.h circulo.h linha.h texto.h
readGEO.o: readGEO.c readGEO.h fila.h dadosTXT.h
readQRY.o: readQRY.c readQRY.h fila.h dadosTXT.h gerarTXT.h
gerarSVG.o: gerarSVG.c gerarSVG.h fila.h tratarArquivos.h
lancadores.o: lancadores.c lancadores.h
colisao.o: colisao.c colisao.h fila.h lancadores.h gerarSVG2.h gerarTXT.h dadosTXT.h retrocederProp.h retrocederMetade.h clonagem.h
deslocamento.o: deslocamento.c deslocamento.h fila.h
lancamento.o: lancamento.c lancamento.h fila.h lancadores.h deslocamento.h colisao.h
dadosTXT.o: dadosTXT.c dadosTXT.h retangulo.h circulo.h linha.h texto.h
gerarSVG2.o: gerarSVG2.c gerarSVG2.h fila.h tratarArquivos.h
gerarTXT.o: gerarTXT.c gerarTXT.h retangulo.h circulo.h linha.h texto.h dadosTXT.h tratarArquivos.h
retrocederMetade.o: retrocederMetade.c retrocederMetade.h retangulo.h circulo.h linha.h texto.h
retrocederProp.o: retrocederProp.c retrocederProp.h retangulo.h circulo.h linha.h texto.h
tratarArquivos.o: tratarArquivos.c tratarArquivos.h
clonagem.o: clonagem.c fila.h dadosTXT.h