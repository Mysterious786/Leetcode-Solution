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
    ListNode* reverse(ListNode* head) {
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;

        // Dummy node to handle the edge case when head changes after the first reversal
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevToStart = dummy;
        ListNode* start = head;
        ListNode* end = head;

        while (end != NULL) {
            // Find the end of the k-group
            for (int i = 1; i < k && end != NULL; i++) {
                end = end->next;
            }

            if (end == NULL) break; // If less than k nodes remain, do not reverse

            // Store the next group's start node
            ListNode* temp = end->next;
            end->next = NULL; // Break the list to isolate the k-group

            // Reverse the k-group
            ListNode* rev = reverse(start);

            // Connect the reversed k-group with the previous part of the list
            prevToStart->next = rev;

            // Connect the end of the reversed k-group to the next group's start
            start->next = temp;

            // Move pointers to the next group
            prevToStart = start;
            start = temp;
            end = start;
        }

        return dummy->next;
    }
};
