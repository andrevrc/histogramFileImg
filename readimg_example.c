#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  // Arquivo. Leitura e Escrita.
  FILE *readfile = NULL;
  FILE *writefile = NULL;

  char str[100];

  // Inicializando o vetor resultado.
  int histogramResult[256], i = 0;
  for ( ; i < 256; i++)
    histogramResult[i] = 0;

  readfile = fopen("1.pgm", "r");
  writefile = fopen("histogramResultExample.txt", "w");

  int value_readed = 0;

  // Lendo a primeira linha.
  fscanf(readfile, "%s", str);
  printf("%s\n", str);

  if (strcmp("P2", str)) {
    printf("Formato do arquivo inválido\n");
    exit(0);
  }

  // Primeiro valor.
  fscanf(readfile, "%d", &value_readed);
  printf("Width: %d\n", value_readed);

  // Segundo valor.
  fscanf(readfile, "%d", &value_readed);
  printf("Height: %d\n", value_readed);

  // Terceiro valor.
  fscanf(readfile, "%d", &value_readed);
  printf("Max gray scale: %d\n", value_readed);

  // Lendo o arquivo da imagem.
  while (fscanf(readfile, "%d", &value_readed) != EOF) {
    histogramResult[value_readed]++;
    printf("%d ", value_readed);
  }

  printf("\n");

  for (i = 0; i < 256; i++) {
    printf("%d ", histogramResult[i]);
  }

  // Escrevendo o resultado no arquivo.
  for (i = 0; i < 256; i++) {
    fprintf(writefile, "%d ", histogramResult[i]);
  }

  // Fechando os arquivos abertos.
  fclose(readfile);
  fclose(writefile);

  printf("\n\n");

  return 0;
}
