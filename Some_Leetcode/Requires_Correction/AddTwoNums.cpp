//2

/*Runtime Error
1565 / 1569 testcases passed
Line 25: Char 16: runtime error: 1e+30 is outside the range of representable values of type 'long long' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:34:16
 
Last Executed Input
Use Testcase
l1 =
[1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
l2 =
[5,6,4]
Code
C++
Analyze Complexity*/
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
        long long sum=0;
        int count_digit=0;
        while (l1!=NULL){
            count_digit++;
            l1=l1->next;
        }
        l1=l1_copy;
        int tens=0;
        while (l1!=NULL){
            sum+=(pow(10, tens)*l1->val);
            l1=l1->next;
            tens++;
        }
        ListNode* l2_copy=l2;
        count_digit=0;
        while (l2!=NULL){
            count_digit++;
            l2=l2->next;
        }
        l2=l2_copy;
        tens=0;
        while (l2!=NULL){
            sum+=(pow(10,tens)*l2->val);
            l2=l2->next;
            tens++;
        }
        if (sum==0){
            return new ListNode(0);
        }
        ListNode * answer_head = new ListNode();
        ListNode * answer=answer_head;
        while (sum!=0){
            int digit = sum%10;
            sum=sum/10;
            answer->next=new ListNode(digit);
            answer=answer->next;
        }
        return answer_head->next;
    }
};


