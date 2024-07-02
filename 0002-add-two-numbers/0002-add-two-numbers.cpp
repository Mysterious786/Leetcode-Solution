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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        int carry = 0;
        ListNode* revL1 =l1;
        ListNode* revL2 = l2;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (revL1 != NULL || revL2 != NULL || carry != 0) {
            int sum = carry;
            if (revL1 != NULL) {
                sum += revL1->val;
                revL1 = revL1->next;
            }
            if (revL2 != NULL) {
                sum += revL2->val;
                revL2 = revL2->next;
            }

            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        ListNode* ans = (dummy->next);
        delete dummy; // Free the allocated memory for dummy
        return ans;
    }
};
