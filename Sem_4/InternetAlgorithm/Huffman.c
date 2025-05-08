#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_CHAR 256
struct MinHeapNode {
  char data;
  int freq;
  struct MinHeapNode *left, *right;
};
struct MinHeap {
  int size;
  int capacity;
  struct MinHeapNode **array;
};
struct MinHeapNode *newNode(char data, int freq) {
  struct MinHeapNode *temp =
      (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
  temp->left = temp->right = NULL;
  temp->data = data;
  temp->freq = freq;
  return temp;
}
struct MinHeap *createMinHeap(int capacity) {
  struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity *
                                                 sizeof(struct MinHeapNode *));
  return minHeap;
}
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
  struct MinHeapNode *t = *a;
  *a = *b;
  *b = t;
}
void minHeapify(struct MinHeap *minHeap, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;
  if (left < minHeap->size &&
      minHeap->array[left]->freq < minHeap->array[smallest]->freq)
    smallest = left;
  if (right < minHeap->size &&
      minHeap->array[right]->freq < minHeap->array[smallest]->freq)
    smallest = right;
  if (smallest != idx) {
    swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

int isSizeOne(struct MinHeap *minHeap) { return (minHeap->size == 1); }
struct MinHeapNode *extractMin(struct MinHeap *minHeap) {
  struct MinHeapNode *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];
  --minHeap->size;
  minHeapify(minHeap, 0);
  return temp;
}

void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *node) {
  ++minHeap->size;
  int i = minHeap->size - 1;
  while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  minHeap->array[i] = node;
}
void buildMinHeap(struct MinHeap *minHeap) {
  int n = minHeap->size - 1;
  for (int i = (n - 1) / 2; i >= 0; i--)
    minHeapify(minHeap, i);
}
int isLeaf(struct MinHeapNode *node) { return !(node->left) && !(node->right); }
struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size) {
  struct MinHeap *minHeap = createMinHeap(size);
  for (int i = 0; i < size; ++i)
    minHeap->array[i] = newNode(data[i], freq[i]);
  minHeap->size = size;
  buildMinHeap(minHeap);
  return minHeap;
}
struct MinHeapNode *buildHuffmanTree(char data[], int freq[], int size) {
  struct MinHeapNode *left, *right, *top;
  struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);
  while (!isSizeOne(minHeap)) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);
    top = newNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    insertMinHeap(minHeap, top);
  }
  return extractMin(minHeap);
}
void printCodes(struct MinHeapNode *root, int arr[], int top) {
  if (root->left) {
    arr[top] = 0;
    printCodes(root->left, arr, top + 1);
  }
  if (root->right) {
    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }
  if (isLeaf(root)) {
    if (root->data == ' ')
      printf("sp: ");
    else
      printf("%c: ", root->data);
    for (int i = 0; i < top; ++i)
      printf("%d", arr[i]);
    printf("\n");
  }
}
void printTree(struct MinHeapNode *root, int space) {
  if (root == NULL)
    return;
  space += 10;
  printTree(root->right, space);
  printf("\n");
  for (int i = 10; i < space; i++)
    printf(" ");
  if (root->data == '$')
    printf("(%d)\n", root->freq);
  else {
    if (root->data == ' ')
      printf("sp(%d)\n", root->freq);
    else
      printf("%c(%d)\n", root->data, root->freq);
  }
  printTree(root->left, space);
}
int main() {
  char str[1000] = "the cub wanted to rub on the tree branch";
  int freq[MAX_CHAR] = {0};
  for (int i = 0; str[i] != '\0'; i++)
    freq[(unsigned char)str[i]]++;
  int d = 0;
  for (int i = 0; i < MAX_CHAR; i++)
    if (freq[i])
      d++;
  char *data = (char *)malloc(d * sizeof(char));
  int *f = (int *)malloc(d * sizeof(int));
  int index = 0;
  for (int i = 0; i < MAX_CHAR; i++) {
    if (freq[i]) {
      data[index] = (char)i;
      f[index] = freq[i];
      index++;
    }
  }
  clock_t t;
  t = clock();
  struct MinHeapNode *root = buildHuffmanTree(data, f, d);
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC * 1000;
  int arr[100], top = 0;
  printf("String: %s\n", str);
  printf("\nHuffman Tree Structure:\n");
  printTree(root, 0);
  printf("\nHuffman Codes:\n");
  printCodes(root, arr, top);
  printf("\n\nExecution time : %.2f milliseconds\n", time_taken);
  free(data);
  free(f);
  return 0;
}