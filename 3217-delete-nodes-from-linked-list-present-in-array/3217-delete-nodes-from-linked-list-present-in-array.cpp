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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int> mp;
        for(auto it : nums) mp[it]++;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = NULL;
        dummy->next = head;
        prev = dummy;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            if(mp.find(curr->val)==mp.end())
            {
                curr = curr->next;
                prev = prev->next;

            }
            else
            {
                ListNode* currFront = curr->next;
                prev->next = currFront;
                ListNode* left = curr;
                curr = curr->next;
                left->next = NULL;
                delete(left);

            }
        }
        return dummy->next;
    }
};