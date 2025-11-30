// 430. Flatten a Multilevel Doubly Linked List

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void recursion(Node *previous, Node* temp) {
        if (temp==NULL) {
            return;
        }
        if (temp->child==NULL){
            if (previous!=NULL){
                previous->next=temp;
            }
            temp->prev = previous;
            recursion(temp, temp->next);
        }
        else{
            Node * child_head=temp->child;
            Node * child_tail = temp->next;

            temp->next = child_head;
            child_head->prev=temp;
            temp->child=NULL;

            recursion(temp, child_head);
            Node* child_temp = child_head;
            while (child_temp->next!=NULL) {
                child_temp=child_temp->next;
            }
            if (child_tail!=NULL){
                child_tail->prev = child_temp;
                child_temp->next = child_tail;
            }
            recursion(child_temp, child_tail);            
        }

    }
    Node* flatten(Node* head) {
        if (head==NULL) return nullptr;
        recursion(nullptr, head);
        return head;
    }
};