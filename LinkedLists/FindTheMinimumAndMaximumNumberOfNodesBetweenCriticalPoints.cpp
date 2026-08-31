// 2058

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head==NULL) return {-1, -1};
        if (head->next==NULL) return {-1, -1};
        int mind=INT_MAX;
        int maxd=INT_MIN;
        ListNode* temp=head;
        int prev=head->val;
        temp=temp->next;
        int first=-1;
        int last=-1;
        int prev_point=-1 ;
        int count=1;
        while (temp->next!=NULL){
            if ((temp->val>prev && temp->val>temp->next->val) || (temp->val<prev && temp->val<temp->next->val)){
                if (prev_point!=-1) mind=min(mind, abs(prev_point-count));
                prev_point=count;
                last=count;
                if (first==-1) first=count; 
                cout<<count<<" "<<temp->val<<endl;
                cout<<mind;
            }
            prev=temp->val;
            temp=temp->next;
            count++;
        }
        //if (count<2) return {-1, -1};
        if (first==-1 && last==-1) return {-1, -1};
        maxd=max(maxd, last-first);
        //if (first==last) return {first, first};
        if (mind==INT_MAX || maxd==INT_MIN) return {-1, -1};
        return {mind, maxd};
    }
};