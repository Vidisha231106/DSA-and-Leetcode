//My code: (Almost Correct)
//Fails for some test cases
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tempA = headA;
    struct ListNode *tempB = headB;

	if (headA->next==NULL || headB->next==NULL){
			if (headA->val==headB->val){
					return headA;
			}
	}
	while (tempA!=NULL){
			tempB=headB;
			while(tempB!=NULL){
					if (tempA->next==tempB->next){
							return tempB->next;
					}
					tempB=tempB->next;
			}
			tempA=tempA->next;
	}
	tempA=headA;
	tempB=headB;
	while (tempB!=NULL){
			tempA=headA;
			while(tempA!=NULL){
					if (tempA->next==tempB->next){
							return tempA->next;
					}
					tempA=tempA->next;
			}
			tempB=tempB->next;
	}
	return NULL;
}

//Better Code:

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tempA = headA;
    struct ListNode *tempB = headB;

    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    while (tempA != NULL) {
        tempB = headB;
        while (tempB != NULL) {
            if (tempA == tempB) {   // check the actual node, not .next
                return tempA;
            }
            tempB = tempB->next;
        }
        tempA = tempA->next;
    }

    return NULL;
}