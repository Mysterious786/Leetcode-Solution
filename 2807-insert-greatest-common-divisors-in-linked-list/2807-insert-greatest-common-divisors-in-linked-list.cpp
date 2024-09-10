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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp->next!=NULL)
        {
            ListNode* currNext = temp->next;
            int val = __gcd(temp->val,currNext->val);
            ListNode* newNode = new ListNode(val);
            temp->next =  newNode;
            newNode->next = currNext;
            temp = temp->next->next;
        }
        return head;
    }
};