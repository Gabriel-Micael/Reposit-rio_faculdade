#include <stdio.h>

int main(void) {
  float vendas[20][40], somalinha[40], somacoluna[20];
  int M, N;
  scanf("%d%d", &M, &N);
  for (int j = 0; j < N; j++) {
    // somalinha[j]=0;
    for (int i = 0; i < M; i++) {
      scanf("%f", &vendas[i][j]);
      somalinha[j] += (float)vendas[i][j];
      somacoluna[i] += (float)vendas[i][j];
    }
  }
  printf("\n   Tabela de Vendas (p = produtos, v = vendedor)\n\n");
  for (int i = 0; i < 1; i++) {
    printf("   ");
    if (i == 0) {
      for (int j = 0; j < N; j++) {
        printf("        v%d", j + 1);
      }
      for (int i = 0; i < 1; i++) {
        printf("\n   +");
        for (int j = 0; j < N; j++) {
          printf("----------");
        }
        printf("+");
      }
    }
  }
  for (int i = 0; i < M + 1; i++) {
    if (i < M) {
      printf("\np%d", i + 1);
      printf(" |");
      for (int j = 0; j < N; j++) {
        printf("%10.2f", vendas[i][j]);
      }
      printf("|");
      printf("%9.2f", somacoluna[i]);
    }
  }
  for (int i = 0; i < 1; i++) {
    printf("\n   +");
    for (int j = 0; j < N; j++) {
      printf("----------");
    }
    printf("+");
  }
  for (int i = 0; i < 1; i++) {
    printf("\n");
    printf("    ");
    for (int j = 0; j < N; j++) {
      printf("%10.2f", somalinha[j]);
    }
  }
}
