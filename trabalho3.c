#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  char nome[30];
  int celular;
  char twitter[20];
} registro;
void ordena(registro agenda[], int n) {
  registro aux;
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (strcmp(agenda[j].nome, agenda[j + 1].nome) > 0) {
        aux = agenda[j];
        agenda[j] = agenda[j+1];
        agenda[j+1] = aux;
      }
    }
  }
}
int main(void) {
  FILE *arq;
  registro agenda[100];
  int i;
  if ((arq = fopen("agenda.csv", "rt")) == NULL) {
    puts("Erro de abertura");
    exit(10);
  } else {
    for (i = 0; !feof(arq); i++) {
      fscanf(arq, "%[^;]s", agenda[i].nome);
      fgetc(arq);
      fscanf(arq, "%d", &agenda[i].celular);
      fgetc(arq);
      fscanf(arq, "%[^\n]s", agenda[i].twitter);
      fgetc(arq);
    }
    ordena(agenda, i);
    arq = fopen("agenda-ord.csv", "w");
    for (int j = 0; j < i; j++) {
      fprintf(arq, "%s;%d;%s\n", agenda[j].nome, agenda[j].celular,
              agenda[j].twitter);
    }
    fclose(arq);
  }
}
