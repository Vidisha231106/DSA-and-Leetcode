// 25

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
        if (head==nullptr || head->next==nullptr) return head;
        ListNode* new_head = reverseLL(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head==nullptr || head->next==nullptr|| k==1) return head;
        
        ListNode* temp = head;
        ListNode* curr_head = head;
        ListNode* next_head = head;
        ListNode* end = nullptr;
        ListNode* prev = new ListNode(-1, head);
        ListNode* dummy = prev;

        int count=0;
        int bigger_count=0; // bigger_count maintains the number of groups that need to be processed
        while (temp!=nullptr){
            temp=temp->next;
            count++;
        } 
        temp = head;
        bigger_count = (count/k); // count = number of nodes, k= size of each group
        count=0;
        while (bigger_count>0){
            count=0;
            curr_head = prev->next;
            temp = curr_head;

            while (count<k-1){
                temp = temp->next;
                count++;
            }
            end =temp;
            next_head = end->next;
            end->next =nullptr;
            
            ListNode* reversed_head = reverseLL(curr_head);
            prev->next = reversed_head;
            end = curr_head;
            end->next = next_head;
            prev = end;
            bigger_count--;
        }
        return dummy->next;
    }
};