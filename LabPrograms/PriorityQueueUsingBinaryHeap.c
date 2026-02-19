#include <stdio.h>

#define MAX 50

int heap[MAX];
int size = 0;

/* Swap function */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify UP (for insertion) */
void heapifyUp(int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && heap[index] > heap[parent]) {
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

/* Insert into priority queue */
void insert(int value) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    heap[size] = value;
    heapifyUp(size);
    size++;
}

/* Heapify DOWN (for deletion) */
void heapifyDown(int index) {
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

/* Delete highest priority element */
int deleteMax() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return -1;
    }

    int max = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
    return max;
}

/* Display heap */
void display() {
    printf("Priority Queue:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(40);
    insert(20);
    insert(30);
    insert(10);
    insert(50);

    display();

    printf("Deleted: %d\n", deleteMax());

    display();

    return 0;
}
