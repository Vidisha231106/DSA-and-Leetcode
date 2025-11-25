//3217. Delete Linked List Nodes present in an array - Extremely Inefficient code
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
#include <set>
#include <vector>
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set <int> s;
        for (int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        while (s.find(head->val) != s.end() && head!=NULL){
            head=head->next;
        }
        if (head == NULL) return NULL; 
        ListNode* copy_head=head;
        ListNode* temp=head;
        while (temp!=NULL && temp->next!=NULL){
            if (s.find(temp->next->val) != s.end()){
                temp->next = temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        return copy_head;
    }
};