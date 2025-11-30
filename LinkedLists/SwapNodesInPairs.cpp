//24

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
    ListNode* swapPairs(ListNode* head) {
        if (head==NULL) return nullptr;
        if (head->next==NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        head=even;
        ListNode* continuation;
        ListNode* temp;
        while (even!=NULL){
            continuation=even->next;
            even->next = odd;
            if (continuation==NULL || continuation->next == NULL) {
                odd->next=continuation;
                return head;
            }
            odd->next=continuation->next;
            odd=continuation;
            even=odd->next;
        }
        return head;
    }
};