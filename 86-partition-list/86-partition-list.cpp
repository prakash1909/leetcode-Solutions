class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       ListNode* smaller=new ListNode(0);
        ListNode* greater=new ListNode(0);
        ListNode* ans=smaller;
        ListNode* greaterhead=greater;
        while(head){
            if(head->val<x){
                smaller->next=head;
                smaller=smaller->next;
            }
            else{
                greater->next=head;
                greater=greater->next;
            }
            head=head->next;
        }
        greater->next=NULL;
        smaller->next=greaterhead->next;
        return ans->next;
    }
};