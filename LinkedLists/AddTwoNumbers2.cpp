//445

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
        if (head==NULL || head->next==NULL){
            return head;
        }
        ListNode* new_head = reverseLL(head->next);
        head->next->next=head;
        head->next=nullptr;
        return new_head;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);
        ListNode* answer = new ListNode();
        ListNode* head = answer;
        int num, x, y;
        int carry=0;
        while (l1 != NULL || l2 != NULL || carry != 0){
            x = (l1!=NULL)? l1->val:0;
            y = (l2!=NULL)? l2->val:0;
            num=x+y+carry;
            carry = num/10;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
            answer->val = num%10;
            if (l1 != NULL || l2 != NULL || carry != 0) {
                answer->next = new ListNode();
                answer = answer->next;
            }
        }
        return reverseLL(head);
    }
};