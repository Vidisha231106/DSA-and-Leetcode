//Inefficient Code - 2074

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
    ListNode* reverse (ListNode* head){
        if (head==nullptr || head->next==nullptr) return head;
        ListNode* new_head = reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        return new_head;
    }

    int biggest_factorial(int k, int num, int fact){
        if (fact>k) return fact-num;
        return biggest_factorial(k, num+1, fact+num);
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;
        
        ListNode* temp = head;
        ListNode* curr_head = head;
        ListNode* next_head = head;
        ListNode* end = nullptr;
        ListNode* prev = new ListNode(-1, head);
        ListNode* dummy = prev;

        int count=0;
        int bigger_count=0; // bigger_count maintains the number of groups that need to be processed
        int num_nodes=1;
        while (temp!=nullptr){
            temp=temp->next;
            count++;
        } 
        temp = head;
        bigger_count = biggest_factorial(count, 1, 1); // count = number of nodes, k= size of each group
        count=0;
        while (bigger_count>=0 && prev->next!=nullptr){
            count=0;
            curr_head = prev->next;
            temp = curr_head;

            while (count<num_nodes-1 && temp->next!=nullptr){
                temp = temp->next;
                count++;
            }

                end =temp;
                next_head = end->next;
                end->next =nullptr;
            
            if ((count+1)%2==0){
                ListNode* reversed_head = reverse(curr_head);
                prev->next = reversed_head;
                curr_head->next = next_head;
                prev = curr_head;
            }
            else{
                end->next = next_head;  
                prev=end;
            }
            
            bigger_count-=(num_nodes);
            num_nodes++;
        }
        return dummy->next;
    }
};

