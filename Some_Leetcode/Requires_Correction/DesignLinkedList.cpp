//707

//Inefficient code: 
/*Accepted
66 / 66 testcases passed

submitted at Dec 13, 2025 11:03

Editorial

Solution
Runtime
9
ms
Beats
47.93%
Analyze Complexity
Memory
25.88
MB
Beats
92.43%
*/

class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node (int x, Node* next_node = nullptr) : val(x), next(next_node) {}
    };

    Node* head;
    MyLinkedList() {
        head=nullptr;
    }
    
    int get(int index) {
        if (head==nullptr) return -1;
        if (index==0) return head->val;
        Node* temp = head;
        int i = 0;
        while (i<index && temp!=nullptr){
            temp=temp->next;
            i++;
        }
        if (temp== nullptr) return -1;
        return temp->val;       
    }
    
    void addAtHead(int val) {
        Node* new_node = new Node(val, head);
        head = new_node;
    }
    
    void addAtTail(int val) {
        if (head==nullptr){
            addAtHead(val);
            return;
        } 
        Node* new_node = new Node(val, nullptr);
        Node* temp = head;
        while (temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next = new_node;
    }
    
    void addAtIndex(int index, int val) {
        if (index==0){
            addAtHead(val);
            return;
        }
        Node* new_node = new Node(val, nullptr);
        Node* temp = head;
        int i = 0;
        while (i<index-1 && temp!=nullptr){
            temp=temp->next;
            i++;
        }
        if (temp!=nullptr){
            new_node->next=temp->next;
            temp->next = new_node;
        }
    }
    
    void deleteAtIndex(int index) {
        if (head==nullptr) return;
        if (head->next==nullptr && index==0) {
            Node* temp = head;
            head=nullptr;
            delete temp;
            return;
        }
        if (index==0 && head!=nullptr){
            Node* temp = head;
            head=head->next;
            delete temp;
            return;
        } 
        Node* temp = head;
        int i=0;
        while (i<index-1 && temp!=nullptr){
            temp=temp->next;
            i++;
        }
        if (temp==nullptr) return;
        if (temp->next!=nullptr){
            Node* to_delete=temp->next;
            temp->next=temp->next->next;
            delete to_delete; 
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */