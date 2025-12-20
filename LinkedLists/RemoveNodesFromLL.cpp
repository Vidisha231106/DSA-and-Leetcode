//2487

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
    ListNode* reverseLL(ListNode* head){ // iterative reversal improves the time complexity greatly
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head; 
        head=reverseLL(head);
        ListNode* temp = head;
        int max=head->val;
        while (temp!=nullptr && temp->next!=nullptr){
            if (temp->next->val<max){
                temp->next=temp->next->next;
                //no need to create a toDelete and delete it
            }
            else{
                max = temp->next->val;
                temp=temp->next;
            }
        }
        head= reverseLL(head);
        return head;
    }
};