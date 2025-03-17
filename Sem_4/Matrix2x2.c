#include <stdio.h>
#include <time.h>

void strassen(int A[3][3], int B[3][3], int C[3][3]) {
  int P, Q, R, S, T, U, V;
  P = (A[1][1] + A[2][2]) * (B[1][1] + B[2][2]);
  Q = (A[2][1] + A[2][2]) * B[1][1];
  R = (A[1][1]) * (B[1][2] - B[2][2]);
  S = (A[2][2]) * (B[2][1] - B[1][1]);
  T = (A[1][1] + A[1][2]) * B[2][2];
  U = (A[2][1] - A[1][1]) * (B[1][1] + B[1][2]);
  V = (A[1][2] - A[2][2]) * (B[2][1] + B[2][2]);

  C[1][1] = P + S - T + V;
  C[1][2] = R + T;
  C[2][1] = Q + S;
  C[2][2] = P + R - Q + U;
  printf("P: %d, Q: %d, R: %d, S: %d, T: %d, U: %d, V: %d\n", P, Q, R, S, T, U,V);
  printf("C[1][1]: %d, C[1][2]: %d, C[2][1]: %d, C[2][2]: %d\n", C[1][1],C[1][2], C[2][1], C[2][2]);
  return;
}

int main() {
  int A[3][3], B[3][3];
  printf("Enter the elements of matrix A:\n");
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 2; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  printf("Enter the elements of matrix B:\n");
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 2; j++) {
      scanf("%d", &B[i][j]);
    }
  }
  int C[3][3];
  clock_t t;
  t = clock();
  strassen(A, B, C);
  double time_taken = ((double)t) / CLOCKS_PER_SEC;
  printf("The matrix C is:\n");
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 2; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
  printf("strassen fun() took %f seconds to execute \n", time_taken);
  return 0;
}