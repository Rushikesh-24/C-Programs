#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define CHAR_SET_SIZE 256
void computeLast(char *P, int m, int last[]) {
  for (int i = 0; i < CHAR_SET_SIZE; i++)
    last[i] = -1;
  for (int i = 0; i < m; i++)
    last[(unsigned char)P[i]] = i;
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
void printPatternAt(char *P, int offset, int i, int j, int l) {
  printf("Pattern : ");
  for (int i = 0; i < offset; i++)
    printf(" ");
  for (int k = 0; k < strlen(P); k++)
    printf(" %c ", P[k]);
  printf(" i=%2d, j=%2d, l=%2d\n", i, j, l);
}
int BMMatch(char *T, char *P, int *comparisons) {
  int n = strlen(T);
  int m = strlen(P);
  int last[CHAR_SET_SIZE];
  computeLast(P, m, last);
  int i = m - 1;
  int j = m - 1;
  *comparisons = 0;
  printIndexLine(n);
  printTextLine(T);
  while (i < n) {
    int l = last[(unsigned char)T[i]];
    printPatternAt(P, i - j, i, j, l);
    (*comparisons)++;
    if (T[i] == P[j]) {
      if (j == 0) {
        printf("Match found at index: %d\n", i);
        return i;
      } else {
        i--;
        j--;
      }
    } else {
      i = i + m - (j < 1 + l ? j : 1 + l);
      j = m - 1;
    }
  }
  printf("There is no substring of text matching the pattern.\n");
  return -1;
}
int main() {
  char text[1000] = "aabaacbbaabaacaabaabacaccaca";
  char pattern[1000] = "aabacac";
  int comparisons = 0;
  clock_t t;
  t = clock();
  BMMatch(text, pattern, &comparisons);
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC * 1000;
  printf("Total comparisons made: %d\n", comparisons);
  printf("Execution time : %.2f milliseconds\n", time_taken);
  return 0;
}