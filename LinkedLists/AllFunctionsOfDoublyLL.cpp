#include <iostream>
#include <vector>

using namespace std;

class Node {
public: 
    int data;
    Node* next;
    Node* back;

    Node (int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector <int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

Node* insertAtHead(Node* head, int k){
    Node* newNode = new Node(k);
    if (head==nullptr){
        return newNode;
    }
    newNode->next=head;
    head->back=newNode;
    head=newNode;

    return head;
}

Node* insertAtIndex(Node* head, int k, int index){
    if (index==0){
        return insertAtHead(head, k);
    }
    Node* newNode = new Node(k);
    int count=0;
    Node* temp = head;
    while(temp!=nullptr){
        if (count == index-1){
            break;
        }
        count++;
        temp=temp->next;
    }
    // If index is invalid (greater than length), just return unchanged head
    if (temp == nullptr) {
        delete newNode; // prevent memory leak
        return head;
    }
    else{
        newNode->back=temp;
        newNode->next=temp->next;

        if (temp->next != nullptr) {
            temp->next->back = newNode;  // Fix the next node’s back pointer
        }
        temp->next = newNode;
        return head;
    }
}

Node* insertAtTail(Node* head, int k){
    Node* newNode = new Node(k);
    if (head==nullptr){
        return newNode;
    }
    Node* tail = head;
    while (tail ->next != nullptr){
        tail=tail->next;
    }
    tail->next = newNode;
    newNode->back = tail;

    return head;
}

Node* deleteHead(Node* head){
    if (head==nullptr){
        return nullptr;
    }
    Node* temp = head;
    head=head->next;
    if (head!=nullptr){
        head->back=nullptr;
    }
    delete temp;
    return head;
}

Node* deleteAtIndex(Node* head, int index){
    if (head==nullptr || index==0){
        return deleteHead(head);
    }

    Node* temp = head;
    int count=0;

    while(temp!=nullptr && count <index-1){
        temp=temp->next;
        count++;
    }

    if (temp == nullptr || temp->next == nullptr) {
        return head;
    }
    else{
        Node* temp2 = temp->next;
        temp->next=temp2->next;
        if (temp2->next !=nullptr){
            temp2->next->back =temp;
        }
        delete temp2;
        return head;
    }
}

Node* deleteByValue(Node* head, int value){
    if (head==nullptr){
        return deleteHead(head);
    }

    Node* temp = head;
    int count=0;
    while (temp!=nullptr){
        if (temp->data==value){
            break;
        }
        count++;
        temp=temp->next;
    }

    if (temp == nullptr){
        return head;
    } 

    return deleteAtIndex(head, count);
}

Node* deleteTail(Node* head){
    if (head==nullptr){
        return nullptr;
    }
    if (head->next == nullptr) {              
        delete head;
        return nullptr;
    }

    Node* temp=head;
    while (temp->next !=nullptr){
        temp = temp->next;
    }
    temp->back->next=nullptr;

    delete temp;
    return head;
}

void print(Node* head){
    while (head !=nullptr){
        cout <<head->data << " ";
        head = head->next;
    }
}

void printNumberOfNodesBasedOnValue(Node* head, int value){
    int count = 0;
    while (head !=nullptr){
        if (head->data==value){
            count++;
        }
        head = head->next;
    }
    cout <<"Number of nodes with value = " <<value <<" are: "<< count <<endl;
}

void printNumberOfNodes(Node* head){
    int count = 0;
    while (head !=nullptr){
        count++;
        head = head->next;
    }
    cout <<"Number of nodes = "<< count <<endl;
}


int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

    cout << "Initial Doubly Linked List: " << endl;
    print(head);
    cout << endl;

    // Insert at head
    cout << "After inserting 99 at the head: " << endl;
    head = insertAtHead(head, 99);
    print(head);
    cout << endl;

    // Insert at index
    cout << "After inserting 55 at index 3: " << endl;
    head = insertAtIndex(head, 55, 3);
    print(head);
    cout << endl;

    // Insert at tail
    cout << "After inserting 10 at the tail: " << endl;
    head = insertAtTail(head, 10);
    print(head);
    cout << endl;

    // Delete head
    cout << "After deleting the head: " << endl;
    head = deleteHead(head);
    print(head);
    cout << endl;

    // Delete at index
    cout << "After deleting node at index 2: " << endl;
    head = deleteAtIndex(head, 2);
    print(head);
    cout << endl;

    // Delete by value
    cout << "After deleting node with value 7: " << endl;
    head = deleteByValue(head, 7);
    print(head);
    cout << endl;

    // Delete tail
    cout << "After deleting the tail: " << endl;
    head = deleteTail(head);
    print(head);
    cout << endl;

    // Count nodes
    cout << "Counting nodes with value 5: " << endl;
    printNumberOfNodesBasedOnValue(head, 5);

    cout << "Counting total nodes: " << endl;
    printNumberOfNodes(head);

    return 0;
}