#include <stdio.h>

#define MAX 100
#define MAX_PAIRS 1000

typedef struct {
    int p, w;
} Pair;

int Largest(Pair pair[], int t, int h, int i, int to) {
    for (int j = h - 1; j >= t; j--) {
        if (pair[j].w + i <= to) {
            return j;
        }
    }
    return t - 1;
}

void AlgorithmDKnap(int p[], int w[], int x[], int n, int to) {
    Pair pair[MAX_PAIRS];  
    int b[MAX] = {0};
    int t = 0, h = 1, next = 1;
    int i, j, k, u;

    pair[0].p = 0;
    pair[0].w = 0;
    b[0] = next;
    printf("S^0 = { (0,0) } \n");
    for (i = 0; i < n; i++) {
        if (w[i] > to) continue;

        k = t;
        u = Largest(pair, t, h, w[i], to);
        if (u < t) u = t;

        for (j = t; j <= u; j++) {
            int pp = pair[j].p + p[i];
            int ww = pair[j].w + w[i];

            while (k < h && pair[k].w < ww) {
                if (next >= MAX_PAIRS) return;
                pair[next++] = pair[k++];
            }

            if (k < h && pair[k].w == ww) {
                if (pp < pair[k].p) {
                    pp = pair[k].p;
                }
                k++;
            }

            if (next >= MAX_PAIRS) return;
            if (pp > pair[next - 1].p) {
                pair[next].p = pp;
                pair[next].w = ww;
                next++;
            }
            printf("S^%d = { ", i + 1);
            for (int z = t; z < next; z++) {
                printf("(%d,%d)", pair[z].p, pair[z].w);
                if (z < next - 1) printf(", ");
            }
            printf(" }\n");

            while (k < h && pair[k].p < pair[next - 1].p) {
                k++;
            }
        }

        printf("S^%d = { ", i + 1);
        int count = 0;
        int y;
        for(y=t; y<next; y++){
            if(pair[y].p == 0 && pair[y].w == 0){
                if(count != 1){
                    count++;
                }
                else{
                    break;
                }
            }
        }

        for (int z = y; z < next; z++) {
            printf("(%d,%d)", pair[z].p, pair[z].w);
            if (z < next - 1) printf(", ");
        }
        printf(" }\n");

        while (k < h) {
            if (next >= MAX_PAIRS) return;
            pair[next++] = pair[k++];
        }

        t = h;
        h = next;
        b[i + 1] = next;
    }

    int maxProfit = pair[h - 1].p;
    int remainingWeight = to;
    int isInitialZero = 0;
    for (int i = 0; i < b[1]; i++) { 
        if (pair[i].p == 0 && pair[i].w == 0) {
            isInitialZero = 1;
            break;
        }
    }

    for (i = n - 1; i >= 0; i--) {
        x[i] = 0;
        for (j = b[i]; j < b[i + 1]; j++) {
            if (pair[j].p == maxProfit && pair[j].w == remainingWeight) {
                if (isInitialZero && pair[j].p == 0 && pair[j].w == 0) {
                    continue;
                }
                x[i] = 1;
                remainingWeight -= w[i];
                maxProfit -= p[i];
                break;
            }
        }        
    }

}

int main() {
    int n = 7;
    int p[] = {3, 2, 4, 5, 3, 6, 5};
    int w[] = {5, 3, 2, 4, 2, 4, 5};
    int m = 20;
    int x[MAX] = {0};

    AlgorithmDKnap(p, w, x, n, m);

    printf("Selected items: ");
    for (int i = 0; i < n; i++) {
        if (x[i]) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    return 0;
}