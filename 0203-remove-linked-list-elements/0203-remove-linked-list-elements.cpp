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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next= head;
        ListNode *prev= &dummy;
        
        while(prev->next)
        {
            if(prev->next->val ==val)
            {
                ListNode *temp= prev->next;
                prev->next= temp->next;
                delete temp;;
            }
            else
                prev= prev->next;
        }
        return dummy.next;
    }
};