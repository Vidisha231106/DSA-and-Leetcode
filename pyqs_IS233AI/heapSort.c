#include <stdio.h>
#include <stdlib.h>

void heapify(int *arr, int n, int i){
    int largest = i;
    int left = 2*i +1;
    int right=2*i + 2;

    if (left<n && arr[left]>arr[largest]) largest = left;
    if (right<n && arr[right]>arr[largest]) largest = right;

    if (largest!=i){
        int temp = arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n){
    for (int i=n/2-1; i>-1; i--){
        heapify(arr, n, i);
    }
    for (int i=n-1; i>0; i++){ // exclude the smallest number
        swap (arr[0], arr[i]);
        heapify(arr,i,0);
    }
}


/*
int main() {
    int arr[] = {4,10,3,5,1};
    int n =sizeof(arr)/sizeof(int);

    heapSort(arr, n);

    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}
*/

/*
TRACE TABLE: 

| Call | n | i | Swap? | New Array    |
| ---- | - | - | ----- | ------------ |
| 1    | 5 | 1 | No    | same         |
| 2    | 5 | 0 | Yes   | [10,4,3,5,1] |
| 3    | 5 | 1 | Yes   | [10,5,3,4,1] |
| 4    | 5 | 3 | No    | same         |
| 5    | 4 | 0 | Yes   | [5,1,3,4,10] |
| 6    | 4 | 1 | Yes   | [5,4,3,1,10] |
| 7    | 4 | 3 | No    | same         |
| 8    | 3 | 0 | Yes   | [4,1,3,5,10] |
| 9    | 3 | 1 | No    | same         |
| 10   | 2 | 0 | No    | same         |

[4,1,3,5,10] -> [3,1,4,5,10] -> [1,3,4,5,10]

When asked:
“Trace recursion of heap sort”
You ONLY trace: heapify calls
NOT the loop iterations.
*/