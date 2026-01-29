//148 - INEFFICIENT PROGRAM

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
    ListNode* sortList(ListNode* head) {
        multimap <int, ListNode*> mp;
        ListNode* temp = head;
        while (temp!=nullptr){
            mp.insert({temp->val, temp});
            temp=temp->next;
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* new_list_copy=dummy;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            dummy->next=it->second;
            dummy=dummy->next;
            dummy->next=nullptr;
        }
        head=new_list_copy->next;
        return head;
    }
};