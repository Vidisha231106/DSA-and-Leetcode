//92

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
    ListNode* reverseList(ListNode* head){
        if (head==NULL || head->next==NULL) return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return new_head; 
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head==NULL || left==right) return head;
        ListNode* temp = head;
        ListNode* before_left_node;
        ListNode* left_node;
        ListNode* right_node;
        ListNode* after_right_node;
        int position=0;
        if (left==1){
            before_left_node=NULL;
            left_node=head;
        }
        else{
            while (temp->next!=NULL){
                position++;
                if (position==left-1) {
                    left_node=temp->next;
                    before_left_node=temp;
                    break;
                }
                temp = temp->next;
            }
        }
        temp=left_node;
        position=left;
        while (temp!=NULL){
            if (position==right){
                right_node=temp;
                after_right_node = temp->next;
            }
            temp=temp->next;
            position++;
        }
        if (left!=1) before_left_node->next=NULL;
        right_node->next=NULL;
        left_node=reverseList(left_node);
        if (left==1) head=left_node;
        else before_left_node->next=left_node;
        temp = left_node;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=after_right_node;
        return head;
    }
};