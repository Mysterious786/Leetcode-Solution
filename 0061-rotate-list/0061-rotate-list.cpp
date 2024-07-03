class Solution {
private:
	int lengthOfList(ListNode* head){
		if(head==NULL) return 0;
		if(head->next==NULL) return 1;
		ListNode* temp = head;
		int count =0;
		while(temp!=NULL){
			count++;
			temp = temp->next;
		}
		return count;

	}
private:
	ListNode* reverse(ListNode* head){
		if(head == NULL  or head->next == NULL) return head;
		ListNode* rest = reverse(head->next);
		ListNode* front = head->next;
		front->next=head;
		head->next = NULL;
		return rest;
	}
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
    	int len = lengthOfList(head);
        if(len==0) return head;
    	k%=len;
    	if(k==0){
    		return head;

    	}
    	//lest go to the n+1th node;
    	ListNode* slow = head;
    	ListNode* fast = head;
    	ListNode* prevToSlow = NULL;
    	for(int i=0;i<k;i++) fast=fast->next;
    	while(fast->next!=NULL){
    		
    		slow = slow->next;
            fast=fast->next;
    	}
    	ListNode* newHead = slow->next;
        slow->next = NULL;
        fast->next = head;
        return newHead;
    	




        
    }
};