class Solution {
public:
   
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *dummy=head;
        
        for(int i=0;i<k;i++)
        {
            if(!dummy)
            {
                return head;
            }
            dummy=dummy->next;
        }

        ListNode *prev=NULL,*c=head,*next=NULL;

        for(int i=0;i<k;i++)
        {
            next=c->next;
            c->next=prev;
            prev=c;
            c=next;
        }
        head->next=reverseKGroup(c,k);
        return prev;
    }
};
