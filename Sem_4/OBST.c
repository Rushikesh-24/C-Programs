#include <limits.h>
#include <stdio.h>

int find(int n, int c[][n], int r[][n], int i, int j) {
  int min = INT_MAX;
  int l = r[i][j - 1];

  for (int m = r[i][j - 1]; m <= r[i][j - 1]; m++) {
    if (m < n && c[i][m - 1] + c[m][j] < min) {
      min = c[i][m - 1] + c[m][j];
      l = m;
    }
  }
  return l;
}
void printtables(int n, int a[][n], int b[][n], int c[][n]) {
  for (int d = 0; d < n; d++) {
    for (int i = 0; i < n - d; i++) {
      int j = i + d;
      if (a[i][j] == INT_MAX) {
        printf(" INF ");
      } else {
        printf("w[%d][%d] = %3d   ", i, j, a[i][j]);
      }
    }
    printf("\n");
    for (int i = 0; i < n - d; i++) {
      int j = i + d;
      if (a[i][j] == INT_MAX) {
        printf(" INF ");
      } else {
        printf("c[%d][%d] = %3d   ", i, j, b[i][j]);
      }
    }
    printf("\n");
    for (int i = 0; i < n - d; i++) {
      int j = i + d;
      if (a[i][j] == INT_MAX) {
        printf(" INF ");
      } else {
        printf("r[%d][%d] = %3d   ", i, j, c[i][j]);
      }
    }
    printf("\n");
    printf("\n");
  }
}
void print_ascii_tree(int n, int i, int j, int r[][n], const char *keys[], int level, char* prefix, int is_left) {
    if (i >= j) {
        printf("%s%s NULL\n", prefix, is_left ? "└── " : "┌── ");
        return;
    }
    
    printf("%s%s %s\n", prefix, is_left ? "└── " : "┌── ", keys[r[i][j] - 1]);
    
    // Prepare prefixes for children
    char new_prefix[1024];
    sprintf(new_prefix, "%s%s", prefix, is_left ? "    " : "│   ");
    
    // Print right child first (will appear below)
    if (r[i][j] < j) {
        print_ascii_tree(n, r[i][j], j, r, keys, level + 1, new_prefix, 0);
    } else {
        printf("%s┌── NULL\n", new_prefix);
    }
    
    // Print left child
    if (i < r[i][j] - 1) {
        print_ascii_tree(n, i, r[i][j] - 1, r, keys, level + 1, new_prefix, 1);
    } else {
        printf("%s└── NULL\n", new_prefix);
    }
}

// Wrapper for ASCII tree function
void print_optimal_ascii_tree(int n, int r[][n], const char *keys[]) {
    char prefix[1024] = "";
    print_ascii_tree(n, 0, n - 1, r, keys, 0, prefix, 1);
}

void obst(int p[], int q[], int n, const char *keys[]) {
  int w[n][n];
  int c[n][n];
  int r[n][n];

  for (int i = 0; i < n; i++) {
    w[i][i] = q[i];
    c[i][i] = 0;
    r[i][i] = 0;
  }
  for (int i = 0; i < n - 1; i++) {
    int j = i + 1;
    w[i][j] = q[i] + p[i] + q[j];
    c[i][j] = w[i][j];
    r[i][j] = j;
  }

  for (int m = 2; m < n; m++) {
    for (int i = 0; i < n - m; i++) {
      int j = i + m;
      w[i][j] = w[i][j - 1] + p[j - 1] + q[j];

      int min = INT_MAX;
      int k_opt = i + 1;

      for (int k = i + 1; k <= j; k++) {
        int cost = c[i][k - 1] + c[k][j];
        if (cost < min) {
          min = cost;
          k_opt = k;
        }
      }

      r[i][j] = k_opt;
      c[i][j] = w[i][j] + min;
    }
  }
  printtables(n, w, c, r);
  printf("\nMinimum cost of optimal BST: %d\n", c[0][n - 1]);
  printf("\nOptimal BST:\n");


  print_optimal_ascii_tree(n, r, keys);

}

int main() {
  const char *keys[] = {"case", "double", "return", "switch","union"};
  int p[] = {5, 3, 6, 4, 5};
  int q[] = {4, 6, 4, 5, 6, 7};
  printf("\n");
  obst(p, q, 6, keys);
  return 0;
}