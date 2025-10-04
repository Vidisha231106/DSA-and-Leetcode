//3217

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// TIME LIMIT EXCEEDED FOR THIS CODE 

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    struct ListNode* temp = head;
    struct ListNode* prev = NULL;

    while (temp != NULL) {
        int matched = 0;

        for (int i = 0; i < numsSize; i++) {
            if (temp->val == nums[i]) {
                matched = 1;
                break;  // no need to check further
            }
        }

        if (matched) {
            if (temp == head) {
                head = temp->next;
                temp = head;
            } else {
                prev->next = temp->next;
                temp = temp->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}
