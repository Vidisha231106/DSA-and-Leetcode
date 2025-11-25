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
#include <cstdlib>

class Solution {
public:
ListNode * head;
    Solution(ListNode* head) {
        this->head = head;
    }
    int getRandom(){
        ListNode * temp= head;
        int count =0;
        while (temp!=NULL){
            count++;
            temp=temp->next;
        }
        int random_num = getRandomNumberedNode(count);
        temp=head;
        count=0;
        while(count<random_num){
            temp=temp->next;
            count++;
        }
        return temp->val;
    }
    int getRandomNumberedNode(int count) {
        int a = 0, b = count-1;
        int ranged = a + rand() % (b - a + 1);
        return ranged;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */