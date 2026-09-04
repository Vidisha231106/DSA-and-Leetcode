// 138

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map <Node*, Node*> copies;
        Node* temp=head;
        while (temp!=nullptr){
            Node* curr=new Node(temp->val);
            copies[temp]=curr;
            temp=temp->next;
        }
        temp=head;
        Node* copy_head=copies[head];
        Node* copy_temp=copies[head];
        while (temp!=nullptr){
            copy_temp->next=(temp->next==nullptr) ? nullptr: copies[temp->next];
            copy_temp->random=(temp->random==nullptr) ? nullptr: copies[temp->random];
            temp=temp->next;
            copy_temp=copy_temp->next;
        }
        return copy_head;
    }
};