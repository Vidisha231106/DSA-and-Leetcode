//1721

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int total = 0; // total will have the highest index
        while (temp!=nullptr){
            temp=temp->next;
            total++;
        }
        ListNode* first_kth=nullptr;
        ListNode* second_kth=nullptr;
        temp = head;
        int counter = 1;
        while (temp!=nullptr && (first_kth==nullptr || second_kth==nullptr)){
            if (counter == k){
                first_kth = temp;
            }
            if (counter==total-k+1){
                second_kth = temp;
            }
            temp = temp->next;
            counter++;    
        }
        int temp_val = first_kth->val;
        first_kth->val = second_kth->val;
        second_kth->val = temp_val;
        return head;
    }
};