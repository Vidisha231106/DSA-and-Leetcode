#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

class Node{
public: 
    int data;
    Node* next;

    Node (int data1, Node* next1){
        data=data1;
        next=next1;
    }

    Node (int data1){
        data=data1;
        next=nullptr;
    }
};

Node* convertArr2SLL(vector <int> arr){
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i=1; i<arr.size(); i++){
        Node *temp = new Node(arr[i], nullptr);
        prev->next = temp;
        prev=temp;
    }
    return head;
}

void printSLL(Node *head){
    while (head!=nullptr){
        cout <<head->data<<" ";
        head=head->next;
    }
}

Node * reverseSLLBruteAlgo(Node*head){
    stack <int> st;
    Node* temp = head;
    while (temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    int new_value;
    while(temp!=nullptr){
        new_value = st.top();
        st.pop();
        temp->data=new_value;
        temp= temp->next;
    }
    return head;
}

Node * reverseSLLOptimalAlgo(Node * head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }

    Node * prev = nullptr;
    Node * current = head;
    

    while (current!=nullptr){
        Node * later = current->next;
        current->next=prev;
        prev =current;
        current=later;
        

    }
    head=prev;
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2SLL(arr);

    cout << "Original Singly Linked List: " << endl;
    printSLL(head);
    cout << endl;

    head = reverseSLLBruteAlgo(head);

    cout << "Reversed Singly Linked List - Brute Force Algorithm: " << endl;
    printSLL(head);
    cout << endl;

    head = reverseSLLOptimalAlgo(head);

    cout << "Reversed Singly Linked List - Optimal Algorithm: " << endl;
    printSLL(head);
    cout << endl;

    return 0;
}

