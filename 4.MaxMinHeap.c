#include <stdio.h>

#define MAX 100

/* Ortak swap */
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* ---------- MIN HEAP ---------- */
void minHeapify(int h[], int size, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && h[l] < h[smallest]) smallest = l;
    if (r < size && h[r] < h[smallest]) smallest = r;

    if (smallest != i) {
        swap(&h[i], &h[smallest]);
        minHeapify(h, size, smallest);
    }
}

void insertMin(int h[], int *size, int val) {
    int i = (*size)++;
    h[i] = val;

    while (i != 0 && h[(i-1)/2] > h[i]) {
        swap(&h[i], &h[(i-1)/2]);
        i = (i-1)/2;
    }
}

int extractMin(int h[], int *size) {
    int root = h[0];
    h[0] = h[--(*size)];
    minHeapify(h, *size, 0);
    return root;
}

/* ---------- MAX HEAP ---------- */
void maxHeapify(int h[], int size, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && h[l] > h[largest]) largest = l;
    if (r < size && h[r] > h[largest]) largest = r;

    if (largest != i) {
        swap(&h[i], &h[largest]);
        maxHeapify(h, size, largest);
    }
}

void insertMax(int h[], int *size, int val) {
    int i = (*size)++;
    h[i] = val;

    while (i != 0 && h[(i-1)/2] < h[i]) {
        swap(&h[i], &h[(i-1)/2]);
        i = (i-1)/2;
    }
}

int extractMax(int h[], int *size) {
    int root = h[0];
    h[0] = h[--(*size)];
    maxHeapify(h, *size, 0);
    return root;
}

/* ---------- MAIN ---------- */
int main() {
    int minHeap[MAX], maxHeap[MAX];
    int minSize = 0, maxSize = 0;

    int arr[] = {10, 4, 15, 20, 0};
    int n = 5;

    for (int i = 0; i < n; i++) {
        insertMin(minHeap, &minSize, arr[i]);
        insertMax(maxHeap, &maxSize, arr[i]);
    }

    printf("Min Heap root: %d\n", minHeap[0]);
    printf("Max Heap root: %d\n", maxHeap[0]);

    printf("Extract Min: %d\n", extractMin(minHeap, &minSize));
    printf("Extract Max: %d\n", extractMax(maxHeap, &maxSize));

    return 0;
}
