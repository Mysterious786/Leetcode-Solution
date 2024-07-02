class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Find the length of both lists
        int countA = 0, countB = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        while (temp1 != NULL) {
            countA++;
            temp1 = temp1->next;
        }
        
        while (temp2 != NULL) {
            countB++;
            temp2 = temp2->next;
        }
        
        int diff = abs(countA - countB);
        
        // Reset temp1 and temp2 to headA and headB respectively
        temp1 = headA;
        temp2 = headB;
        
        // Move the pointer of the longer list by 'diff' nodes
        if (countA >= countB) {
            while (diff--) {
                temp1 = temp1->next;
            }
        } else {
            while (diff--) {
                temp2 = temp2->next;
            }
        }
        
        // Move both pointers until they collide
        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return temp1;
    }
};
