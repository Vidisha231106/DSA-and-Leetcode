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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* answer = new ListNode(0, head);
        ListNode* prev = answer;
        
        if (head==NULL) return nullptr;
        if (head->next==NULL) return head;
        ListNode* temp = head; 
        while (temp!=NULL){
            if (temp->next!=NULL && temp->val==temp->next->val){
                while (temp->next!=NULL && temp->next->val==temp->val){
                    temp=temp->next;
                }
                prev->next=temp->next;
            }
            else{
                prev=temp;
            }
            temp=temp->next;
        }
        return answer->next;        
    }
};