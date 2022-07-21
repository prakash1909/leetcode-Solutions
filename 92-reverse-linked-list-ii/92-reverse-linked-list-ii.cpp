class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int> s;
        int i=1;
        ListNode* temp = head;  
        while(i <= right){
            if(i >= left) s.push(temp->val);
            temp = temp->next;
            i++;
        }
        i = 1;
        temp = head;
        while(i<=right){
            if(i >= left){
                temp->val = s.top();
                s.pop();
            }
            temp = temp->next;
            i++;
        }
        return head;
    }
};