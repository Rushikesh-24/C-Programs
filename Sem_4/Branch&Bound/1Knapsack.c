#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int level;
    int profit;
    int weight;
    float bound;
    int include[10];
} Node;

int n = 3;
int W = 20; 
int weight[] = {8, 12, 5};
int profit[] = {32, 24, 6};


float bound(Node u) {
    int j, k;
    int totweight;
    float result;

    if (u.weight >= W)
        return 0;
    else {
        result = u.profit;
        j = u.level + 1;
        totweight = u.weight;

        while (j < n && totweight + weight[j] <= W) {
            totweight += weight[j];
            result += profit[j];
            j++;
        }

        if (j < n)
            result += (W - totweight) * (float)profit[j] / weight[j];

        return result;
    }
}

void knapsack() {
    Node Q[MAX];
    int front = 0, rear = 0;

    Node u, v;
    int i;

    v.level = -1;
    v.profit = 0;
    v.weight = 0;
    for (i = 0; i < n; i++) v.include[i] = 0;
    v.bound = bound(v);
    Q[rear++] = v;

    int maxProfit = 0;
    int bestSet[10];

    while (front != rear) {
        v = Q[front++];
        if (v.bound > maxProfit) {
            u.level = v.level + 1;

            u.weight = v.weight + weight[u.level];
            u.profit = v.profit + profit[u.level];

            for (i = 0; i < n; i++) u.include[i] = v.include[i];
            u.include[u.level] = 1;

            if (u.weight <= W && u.profit > maxProfit) {
                maxProfit = u.profit;
                for (i = 0; i < n; i++) bestSet[i] = u.include[i];
            }

            u.bound = bound(u);
            if (u.bound > maxProfit)
                Q[rear++] = u;

            u.weight = v.weight;
            u.profit = v.profit;
            for (i = 0; i < n; i++) u.include[i] = v.include[i];
            u.include[u.level] = 0;
            u.bound = bound(u);
            if (u.bound > maxProfit)
                Q[rear++] = u;
        }
    }

    printf("Maximum Profit: %d\n", maxProfit);
    printf("Items included (x1, x2, x3): ");
    for (i = 0; i < n; i++)
        printf("%d ", bestSet[i]);
    printf("\n");
}

int main() {
    knapsack();
    return 0;
}