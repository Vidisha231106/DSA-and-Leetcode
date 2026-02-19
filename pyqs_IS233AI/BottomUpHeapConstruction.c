/*
Also called:
- Build Heap
- Floyd’s Algorithm
- Heapify Bottom-Up
*/


/*
Starting index = n/2 − 1
Why?
Because:
Nodes from n/2 → n−1 are leaves
Leaves don’t need heapify.
*/

#include <stdio.h>
#include <stdlib.h>

void heapify(int * arr, int n, int i){
    int largest =i;
    int left = 2*i +1;
    int right = 2*i +2;

    if (left<n && arr[left]>arr[largest]) largest = left;
    if (right<n && arr[right]> arr[largest]) largest=right;
    if (largest!=i){
        int temp = arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int *arr, int n){
    for (int i=n/2-1; i>=0; i++){
        heapify(arr, n, i);
    }
}

/*
int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr)/sizeof(int);

    buildMaxHeap(arr, n);

    printf("Max Heap: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}*/