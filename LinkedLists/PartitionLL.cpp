//86

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
    ListNode* partition(ListNode* head, int x) {
        if (head==NULL) return nullptr;
        ListNode* temp=head;
        while (temp->next!=NULL && temp->next->val>x){
            temp=temp->next;
        }
        ListNode* first_head = new ListNode(0, temp->next);
        temp =head;
        while (temp->next!=NULL && temp->next->val<x){
            temp=temp->next;
        }
        ListNode* other_head = new ListNode(0, temp->next); // pointer, for which next val is set to the first greater value node
        temp=head;
        ListNode* first_head_copy = first_head;
        ListNode* other_head_copy = other_head;
        while(temp!=NULL){
            if (temp->val <x){
                first_head->next =temp;
                first_head=first_head->next;
            }
            else{
                other_head->next = temp;
                other_head=other_head->next;
            }
            temp = temp->next;
        }
        other_head->next = nullptr;
        first_head->next = other_head_copy->next;
        return first_head_copy->next;
    }
};