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
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode dummy(0);
        ListNode* point = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                point->next = l1;
                l1 = l1->next;
            } else {
                point->next = l2;
                l2 = l2->next;
            }
            point = point->next;
        }
        if (l1 != nullptr) {
            point->next = l1;
        } else {
            point->next = l2;
        }
        return dummy.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        // Finding the midpoint of the list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevToSlow = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prevToSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prevToSlow->next = nullptr;

        // Recursively sort the sublists
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        // Merge the sorted sublists
        return mergeList(l1, l2);
    }
};
