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
    void modifyLL(ListNode * list1, ListNode* list2, ListNode *& main_head){
        while (list1!=NULL && list2!=NULL){
            if (list1->val<list2->val){
                main_head->next = list1;
                list1=list1->next;
            }
            else{
                main_head->next = list2;
                list2=list2->next;
            }
            main_head=main_head->next;
        }
        if (list1!=NULL && list2==NULL){
            main_head->next = list1;
        }
        else{
            main_head->next = list2;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* main_head=list1;
        ListNode * copy_head;
        if (list1==NULL) return list2;
        if (list2==NULL) return list1;

        if (list1->val>=list2->val){
            copy_head= list2;
            main_head=list2;
            list2=list2->next;
            modifyLL(list1, list2, main_head);
        }
        else{
            copy_head= list1;
            main_head=list1;
            list1=list1->next;
            modifyLL(list2, list1, main_head);
        }
        return copy_head;
    }
};