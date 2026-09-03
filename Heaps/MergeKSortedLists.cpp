// 

// Better Time complexity: 

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;
        int n=lists.size();
        for(int i=0; i<n; i++){
            if (lists[i]!=nullptr) pq.push({lists[i]->val, lists[i]});
        }
        if (pq.empty()==true) return nullptr;
        ListNode* head=pq.top().second;
        ListNode* temp=nullptr;
        ListNode* prev=new ListNode(0); // IMPORTANT
        
        while (pq.empty()==false){
            temp=pq.top().second;
            pq.pop();
            prev->next=temp;
            prev=temp;
            
            if (temp->next!=nullptr) pq.push({temp->next->val,temp->next});
        }
        prev->next=nullptr;
        return head;
    }
};

// Worse Time complexity: 

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;
        ListNode* head=nullptr;
        int n=lists.size();
        for(int i=0; i<n; i++){
            ListNode* curr=lists[i];
            while (curr!=nullptr) {
                pq.push({curr->val, curr});
                curr=curr->next;
            }
        }
        if (pq.empty()==true) return nullptr;
        head=pq.top().second;
        ListNode* temp=head;
        pq.pop();
        while(pq.empty()!=true){
            temp->next=pq.top().second;
            temp=temp->next;
            pq.pop();
        }
        return head;
    }
};