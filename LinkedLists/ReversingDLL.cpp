#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* back;

    Node (int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node (int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

Node * convertArr2DLL(vector <int> arr){
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i=1; i<arr.size(); i++){
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next =temp;
        prev=temp;
    }
    return head;
}

void printDLL(Node *head){
    while (head!=nullptr){
        cout <<head->data<<" ";
        head=head->next;
    }
}

Node* reverseDLLBruteAlgo(Node* head){
    stack <int> st;
    Node* temp = head;
    while (temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    temp = head;
    int new_value;
    while(temp!=nullptr){
        new_value = st.top();
        st.pop();
        temp->data=new_value;
        temp=temp->next;
    }
    return head;
}

Node * reverseDLLOptimalAlgo(Node * head){
    if (head==nullptr || head->next == nullptr){
        return head;
    }
    Node * prev = nullptr;
    Node * current = head;
    while (current!=nullptr){
        prev=current->back;
        current->back = current->next;
        current->next = prev;
        current = current->back;
    }
    head= prev->back;
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2DLL(arr);

    cout << "Original Doubly Linked List: " << endl;
    printDLL(head);
    cout << endl;

    head = reverseDLLBruteAlgo(head);

    cout << "Reversed Doubly Linked List - Brute Force Algorithm: " << endl;
    printDLL(head);
    cout << endl;

    head = reverseDLLOptimalAlgo(head);

    cout << "Reversed Doubly Linked List - Optimal Algorithm: " << endl;
    printDLL(head);
    cout << endl;

    return 0;
}
