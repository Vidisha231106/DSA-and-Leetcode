// 142

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head==nullptr || head->next==nullptr) return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) break;
        }
        if (fast==nullptr || fast->next==nullptr) return nullptr;
        ListNode* new_head= new ListNode(0);

        slow=head;
        while (slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};