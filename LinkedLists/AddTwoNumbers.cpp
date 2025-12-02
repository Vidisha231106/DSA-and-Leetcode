//2

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
#include <cmath>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_copy=l1;
        int digit=0;
        int count_digit=0;
        int carry=0;
        int num=0;
        int x,y;
        ListNode * answer_head = new ListNode();
        ListNode * answer=answer_head;
        while (l1!=NULL || l2!=NULL || carry!=0){
            count_digit++;
            if (l1==NULL){
                x=0;
            }
            else{
                x= l1->val;
            }
            if (l2==NULL){
                y=0;
            }
            else{
                y=l2->val;
            }

            num = x+y+carry;
            carry = num/10;
            digit = num%10;
            answer->next=new ListNode(digit);
            answer=answer->next;

            if (l1!=NULL) l1=l1->next;
            if (l2!=NULL) l2=l2->next;
        }
        return answer_head->next;
    }
};