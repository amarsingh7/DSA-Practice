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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || head->next==NULL)
            return head;
        ListNode *ans= new ListNode(head->val);
        ListNode *temp= ans;
    
        while(head->next)
        {
            if(head->val != head->next->val)
            {    
                temp->next= new ListNode(head->next->val);
                temp= temp->next;
            }   
            head= head->next; 
        }
        return ans;
    }
};