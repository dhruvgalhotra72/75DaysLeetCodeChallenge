class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node to handle edge case (like deleting head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        // Move fast pointer n+1 steps ahead
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move both pointers
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Delete the nth node from end
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        
        return dummy->next;
    }
};