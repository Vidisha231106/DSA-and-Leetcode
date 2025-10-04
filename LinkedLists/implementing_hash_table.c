#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    int count;
    struct Node *next;

} Node;

// Hash function (division method)
int hash(int key, int table_size)
{
    if (key < 0)
        key = -key; // handle negatives
    return key % table_size;
}

// Insert key into hash table
void insert(Node **table, int table_size, int key)
{
    int idx = hash(key, table_size);

    Node *head = table[idx];
    Node *temp = head;

    // check if key already exists in chain
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    // if not found, insert new node at head
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = head;
    table[idx] = newNode;
}

// Print all frequencies
void printFrequencies(Node **table, int table_size)
{
    for (int i = 0; i < table_size; i++)
    {
        Node *temp = table[i];
        while (temp != NULL)
        {
            printf("%d -> %d\n", temp->key, temp->count);
            temp = temp->next;
        }
    }
}

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // choose hash table size (prime near 2n for good distribution)
    int table_size = 2 * n + 1;

    // allocate hash table (array of linked list heads)
    Node **table = (Node **)calloc(table_size, sizeof(Node *));

    // insert all elements
    for (int i = 0; i < n; i++)
    {
        insert(table, table_size, arr[i]);
    }

    // print frequencies
    printf("\nFrequencies:\n");
    printFrequencies(table, table_size);

    // free memory
    for (int i = 0; i < table_size; i++)
    {
        Node *temp = table[i];
        while (temp != NULL)
        {
            Node *del = temp;
            temp = temp->next;
            free(del);
        }
    }
    free(table);
    free(arr);

    return 0;
}

/*
Same program in CPP:


#include <bits/stdc++.h>
using namespace std;

void Frequency(int arr[], int n)
{
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    // Traverse through map and print frequencies
    for (auto x : map)
        cout << x.first << " " << x.second << endl;
}

int main()
{
    int arr[] = {10,5,10,15,10,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Frequency(arr, n);
    return 0;
}
*/