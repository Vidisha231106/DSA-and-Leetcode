//143

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        if (head==nullptr || head->next ==nullptr){
            return head;
        }
        ListNode* new_head = reverseLL(head->next);
        head->next->next=head;
        head->next=nullptr;
        return new_head;
    }
    void reorderList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return;
        int count=0;
        ListNode* temp = head;
        ListNode* list1 = head;
        ListNode* list2 = nullptr;

        while (temp!=nullptr){
            temp=temp->next;
            count++;
        }
        temp = head;
        for (int i=0; i<(count-1)/2; i++){
            temp = temp->next;
        }
        list2=temp->next;
        temp->next = nullptr;
        
        list2 = reverseLL(list2);
        temp = list1;
        ListNode* new_temp = nullptr;
        ListNode* new_temp2= nullptr;
        while (list2 != NULL && temp != NULL){
            new_temp = temp->next;
            new_temp2 = list2->next;
            temp->next = list2;
            list2->next = new_temp;
            temp=new_temp;
            list2 = new_temp2;
            
        }
    }
};