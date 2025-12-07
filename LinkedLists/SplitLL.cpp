// 725

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> answer;
        ListNode* temp = head;
        int count=0;
        while (temp!=NULL){
            temp=temp->next;
            count++;
        }
        temp=head;
        if (count<k){
            while (temp!=NULL){
                ListNode* next_node = temp->next;
                temp->next=nullptr;
                answer.push_back(temp);
                temp=next_node;
            }
            int remaining = (k-answer.size()); 
            while (remaining!=0){
                answer.push_back(nullptr);
                remaining--;
            }
            return answer;
        }
        int subLL = count/k;
        int rem = count%k;
        int biggerLLs=0; //should be smaller than rem
        int counter=0;
        temp=head;
        answer.push_back(temp);
        while (temp!=nullptr){
            counter++;
            if (counter==subLL+1 && biggerLLs<rem){
                ListNode* next_node = temp->next;
                temp->next=nullptr;
                temp = next_node;
                if (temp!=nullptr) answer.push_back(temp);
                counter=0;
                biggerLLs++;
                continue;
            }
            if (counter==subLL && biggerLLs>=rem){
                ListNode* next_node = temp->next;
                temp->next=nullptr;
                temp=next_node;
                if (temp!=nullptr) answer.push_back(temp);
                counter=0;
                continue;
            }
            if (temp!=nullptr) temp=temp->next;            
        }
        return answer;
    }
};