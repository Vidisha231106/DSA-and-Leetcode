typedef struct Node{
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
    int count;
}MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue* ) malloc (sizeof(MyCircularQueue));
    obj->front=NULL;
    obj->rear=NULL;
    obj->count=0;
    obj->size = k;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size==obj->count ) return false;
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));

    if (obj->count==0){
        new_node->next=new_node;
        obj->front = new_node;
        obj->rear = new_node;
    }
    else{
        new_node->next = obj->front;
        obj->rear->next=new_node;
        obj->rear = new_node;
    }
    new_node->val = value;
    obj->count++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->count==0) return false;
    struct Node* temp = obj->front->next;
    obj->rear->next = temp;
    free(obj->front);
    obj->front=temp;
    obj->count--;
    if (obj->count==0) obj->rear=obj->front=NULL;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->front==NULL) return -1;
    return obj->front->val;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->rear == NULL ) return -1;
    return obj->rear->val;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->front==NULL) return true;
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->count == obj->size;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    struct Node* temp = obj->front;
    struct Node* curr = temp;
    while (temp!=obj->rear){
        curr=temp;
        temp=temp->next;
        free(curr);
    }
    free(temp);
    obj->count =0;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/