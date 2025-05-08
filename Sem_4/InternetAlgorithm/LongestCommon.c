#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void printMatrix(int **L, char *X, char *Y, int n, int m) {
  printf("\n");
  printf(" L  ");
  for (int j = 0; j <= m; j++) {
    if (j == 0)
      printf(" Y ");
    else
      printf("  %c ", Y[j - 1]);
  }
  printf("\n");
  for (int i = 0; i <= n; i++) {
    if (i == 0)
      printf(" X ");
    else
      printf(" %c ", X[i - 1]);
    for (int j = 0; j <= m; j++)
      printf("%3d ", L[i][j]);
    printf("\n");
  }
}
void LCS(char *X, char *Y) {
  int n = strlen(X);
  int m = strlen(Y);
  int **L = (int **)malloc((n + 1) * sizeof(int *));
  for (int i = 0; i <= n; i++)
    L[i] = (int *)malloc((m + 1) * sizeof(int));
  for (int i = 0; i <= n; i++)
    L[i][0] = 0;
  for (int j = 0; j <= m; j++)
    L[0][j] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (X[i - 1] == Y[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;
      else
        L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
    }
  }
  printMatrix(L, X, Y, n, m);
  printf("\nLength of LCS: %d\n", L[n][m]);
  int index = L[n][m];
  char *lcs = (char *)malloc((index + 1) * sizeof(char));
  lcs[index] = '\0';
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (X[i - 1] == Y[j - 1]) {
      lcs[--index] = X[i - 1];
      i--;
      j--;
    } else if (L[i - 1][j] > L[i][j - 1])
      i--;
    else
      j--;
  }
  printf("LCS: %s\n", lcs);
  for (int i = 0; i <= n; i++)
    free(L[i]);
  free(L);
  free(lcs);
}
int main() {
  char X[100] = "GCTAGTTACG", Y[100] = "ATGACTAAGCCTAGT";
  printf("X: %s\n", X);
  printf("Y: %s\n", Y);
  clock_t t;
  t = clock();
  LCS(X, Y);
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC * 1000;
  printf("Execution time : %.2f milliseconds\n", time_taken);
  return 0;
}