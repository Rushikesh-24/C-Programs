#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n;
int capacity;
int profit[MAX];
int weight[MAX];

int maxProfit = -1;
int include[MAX], bestSet[MAX];

float bound(int i, int currentProfit, int currentWeight) {
  int j;
  float b = currentProfit;
  int totalWeight = currentWeight;

  for (j = i; j < n; j++) {
    if (totalWeight + weight[j] <= capacity) {
      totalWeight += weight[j];
      b += profit[j];
    } else {
      b += (capacity - totalWeight) * (float)profit[j] / weight[j];
      break;
    }
  }

  return b;
}

void knapsack(int i, int currentProfit, int currentWeight) {
  if (currentWeight <= capacity && currentProfit > maxProfit) {
    maxProfit = currentProfit;
    for (int j = 0; j < n; j++) {
      bestSet[j] = include[j];
    }
  }

  if (i >= n) return;

  float b = bound(i, currentProfit, currentWeight);
  if (b <= maxProfit) return;  // Prune branch

  // LEFT CHILD (include item i)
  include[i] = 1;
  knapsack(i + 1, currentProfit + profit[i], currentWeight + weight[i]);

  // RIGHT CHILD (exclude item i)
  include[i] = 0;
  knapsack(i + 1, currentProfit, currentWeight);
}

int main() {
  printf("Enter the number of items: ");
  scanf("%d", &n);

  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);

  printf("Enter the profits of the items: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &profit[i]);
  }

  printf("Enter the weights of the items: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &weight[i]);
  }
  knapsack(0, 0, 0);
  printf("Maximum Profit: %d\n", maxProfit);
  for (int i = 0; i < n; i++) {
    if (bestSet[i] == 1) {
      {
        printf(" x%d=1 ", i + 1);
      }
    }
    else{
      printf(" x%d=0 ", i + 1);
    }
  }
  printf("\n");
  return 0;
}