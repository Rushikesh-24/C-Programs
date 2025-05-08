#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void computeKMPFailureFunction(char *P, int m, int *f) {
  int i = 1, j = 0;
  f[0] = 0;
  while (i < m) {
    if (P[i] == P[j]) {
      j++;
      f[i] = j;
      i++;
    } else if (j > 0) {
      j = f[j - 1];
    } else {
      f[i] = 0;
      i++;
    }
  }
}
void printIndexLine(int n) {
  printf("Index : ");
  for (int i = 0; i < n; i++)
    printf("%2d ", i);
  printf("\n");
}
void printTextLine(char *T) {
  printf("Text : ");
  for (int i = 0; i < strlen(T); i++)
    printf(" %c ", T[i]);
  printf("\n");
}
void printPatternAt(char *P, int offset, int i, int j, int fj) {
  printf("Pattern : ");
  for (int k = 0; k < offset; k++)
    printf(" ");
  for (int k = 0; k < strlen(P); k++)
    printf(" %c ", P[k]);
  printf(" i=%2d, j=%2d", i, j);
  printf("\n");
}
int KMPMatch(char *T, char *P, int *comparisons) {
  int n = strlen(T);
  int m = strlen(P);
  int *f = (int *)malloc(sizeof(int) * m);
  computeKMPFailureFunction(P, m, f);
  printIndexLine(n);
  printTextLine(T);
  int i = 0, j = 0;
  *comparisons = 0;
  while (i < n) {
    printPatternAt(P, i - j, i, j, j > 0 ? f[j - 1] : -1);
    (*comparisons)++;
    if (P[j] == T[i]) {
      if (j == m - 1) {
        printf("Match found at index: %d\n", i - m + 1);
        free(f);
        return i - m + 1;
      }
      i++;
      j++;
    } else if (j > 0) {
      j = f[j - 1];
    } else {
      i++;
    }
  }
  free(f);
  return -1;
  printf("There is no substring of text matching the pattern.\n");
}
int main() {
  char text[1000] = "aabaacbbaabaacaabaabacaccaca";
  char pattern[1000] = "aabacac";
  int comparisons = 0;
  clock_t t;
  t = clock();
  KMPMatch(text, pattern, &comparisons);
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC * 1000;
  printf("Total comparisons made: %d\n", comparisons);
  printf("Execution time : %.2f milliseconds\n", time_taken);
  return 0;
}