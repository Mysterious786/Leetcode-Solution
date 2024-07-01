class Solution {
private:
    // Function to reverse the linked list from given head
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;

        // Finding the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list
        ListNode* secondHalf = reverse(slow->next);

        // Compare the first half and the reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalfCopy = secondHalf; // Keep a copy to restore the list later
        while (secondHalf != NULL) {
            if (firstHalf->val != secondHalf->val) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Restore the list (optional)
        slow->next = reverse(secondHalfCopy);

        return true;
    }
};
