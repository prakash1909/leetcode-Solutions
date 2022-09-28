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
   ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL)
            return 0;
        
        ListNode* p= head;
        int c=0;
        
        while(p){
            c++;
            p=p->next;
        }
        
        int k= c-n+1;
        
        ListNode* temp=NULL;
        
        if(k==1){
            temp=head;
            head=head->next;
            
        }
        
        else if(k==c){
            temp= head;
            for(int i=1;i<k-1;i++){
                temp=temp->next;
            }
            ListNode* m= temp->next;
            temp->next= NULL;
           
        }
        
        else{
            temp=head;
            for(int i=1;i<k-1;i++){
                temp=temp->next;
            }
            cout<<temp->val;
            ListNode* m= temp->next;
            cout<<m->val;
            temp->next=m->next;
            
        }
        
        return head;
    }   
};