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
    bool hasCycle(ListNode *head) {
        if(head==NULL) return head;
        ListNode *fp=head;
        ListNode *sp=head;
        while(fp!=NULL && fp->next!=NULL){
            fp=fp->next->next;
            sp=sp->next;

            if(sp==fp)
                return true;
        }
        return false;
    }
};