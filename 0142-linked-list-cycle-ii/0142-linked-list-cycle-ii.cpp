/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL or head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* ret = head;
        while(fast and fast->next){
      
            fast = fast->next->next;
            slow = slow->next;
                  if(fast == slow){
                while(ret!=slow){
                    ret = ret->next;
                    slow = slow->next;
                }
                return ret;
            }
            
        }
        return NULL;
        
    }
};