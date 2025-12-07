// 1019

/*
Accepted
76 / 76 testcases passed
vidihsadewan
submitted at Dec 07, 2025 19:41


Solution
Runtime
7
ms
Beats
49.42%
Analyze Complexity
Memory
44.25
MB
Beats
84.39%
*/

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
#include <stack>
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        if (head==NULL || head->next==NULL) return head;
        ListNode* new_head = reverseLL(head->next);
        head->next->next=head;
        head->next=nullptr;
        return new_head;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector <int> answer;
        head = reverseLL(head); 
        stack <int> st;
        ListNode* temp = head;
        while (temp!=NULL){
            while (!st.empty() && st.top() <= temp->val){
                st.pop();
            }
            if (st.empty()) answer.push_back(0);
            else answer.push_back(st.top());

            st.push(temp->val);
            temp=temp->next;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};