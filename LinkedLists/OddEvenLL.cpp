//328

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
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL) return nullptr;
        if (head->next==NULL) return head;
        ListNode* temp;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* second_head = even;
        temp=even->next;
        int count=0;
        while (temp!=NULL){
            count++;
            if (count%2!=0){
                odd->next=temp;
                odd=odd->next;
            }
            else{
                even->next=temp;
                even=even->next;
            }
            temp=temp->next;
        } 
        even->next = nullptr;
        odd->next=second_head;
        return head;    
    }
};