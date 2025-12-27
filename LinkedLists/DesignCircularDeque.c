typedef struct Node{
    int val;
    struct Node* next;
}Node;

typedef struct {
    Node* front;
    Node* rear;
    int count;
    int size;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*) malloc (sizeof(MyCircularDeque));
    obj->front=NULL;
    obj->rear=NULL;
    obj->count=0;
    obj->size=k;
    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->count==obj->size) return false;
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->val = value;
    if (obj->front==NULL){
        new_node->next = new_node;
        obj->front = new_node;
        obj->rear= new_node;
    }
    else{
        new_node->next=obj->front;
        obj->rear->next=new_node;
        obj->front = new_node;
    }
    obj->count++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->count==obj->size) return false;
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->val = value;
    if (obj->front==NULL){
        obj->front = new_node;
        obj->rear= new_node;
    }
    else{
        obj->rear->next=new_node;
        new_node->next=obj->front;
        obj->rear = new_node;
    }
    obj->count++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->front==NULL) return false;
    if (obj->front==obj->rear){
        free(obj->front);
        obj->front=NULL;
        obj->rear=NULL;
    }
    else{
        Node* temp = obj->front->next;
        free(obj->front);
        obj->front = temp;
        
    }
    obj->count--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->rear==NULL) return false;
    if (obj->front==obj->rear){
        free(obj->rear);
        obj->front=NULL;
        obj->rear=NULL;
    }
    else{
        Node* temp = obj->front;
        while (temp->next!=obj->rear){
            temp=temp->next;
        }
        free(temp->next);
        obj->rear=temp;
        obj->rear->next= obj->front;
       
    }
    obj->count--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->front ==NULL) return -1;
    return obj->front->val;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->rear==NULL) return -1;
    return obj->rear->val;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return (obj->front==NULL);
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return (obj->size==obj->count);
}

void myCircularDequeFree(MyCircularDeque* obj) {
    Node* temp = obj->front;
    Node* curr = obj->rear;
    while (temp!=obj->rear){
        curr=temp;
        temp=temp->next;
        free(curr);
    }
    free(obj->rear);
    obj->front=NULL;
    obj->rear=NULL;
    obj->count=0;
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/