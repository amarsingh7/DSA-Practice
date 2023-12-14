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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head;
        ListNode* prev= NULL, *next=NULL;
        
        int count=0;
        
        ListNode *temp= head;
        while(temp !=NULL)
        {
            count++;
            temp= temp->next;
        }
        
        if(count <k)
            return head;
        int counter=0;
        while(cur!=NULL and counter <k)
        {
            next= cur->next;
            cur->next= prev;
            prev= cur;
            cur= next;
            
            counter++;
        }
        if(next !=NULL)
            head->next= reverseKGroup(next, k);
        
        return prev;
            
    }
};
