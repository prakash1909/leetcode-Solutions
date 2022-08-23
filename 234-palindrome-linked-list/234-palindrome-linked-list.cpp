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
   bool isPalindrome(ListNode* head) {
        ListNode *nn=head;
        if(head->next==NULL)
            return true;
        vector<int>v;
        while(nn!=NULL){
            v.push_back(nn->val);
            nn=nn->next;
        }
        // for(int i=0;i<v.size();++i)
        //     cout<<v[i]<<" ";
        long long start=0,end=v.size()-1;
        while(start<end){
            if(v[start++]!=v[end--])
                return false;
        }
        return true;
    }
};