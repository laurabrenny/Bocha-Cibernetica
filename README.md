# Bocha Cibernética

Bocha Cibernética é um simulador em C que processa comandos a partir de arquivos `.geo` e `.qry` para gerar arquivos de saída em `.svg` e `.txt`. O projeto simula um jogo de estratégia com formas geométricas e lançadores.

## Funcionalidades

- Leitura de arquivos `.geo` e `.qry`
- Criação e manipulação de formas: círculos, retângulos, linhas e textos
- Lançamento de formas com colisões e pontuação
- Geração de arquivos `.svg` com visualização gráfica
- Relatório em `.txt` com estatísticas finais

## Compilacao

Use o Makefile para compilar. Rode:

```bash
make PROJ_NAME=nome_do_executavel
