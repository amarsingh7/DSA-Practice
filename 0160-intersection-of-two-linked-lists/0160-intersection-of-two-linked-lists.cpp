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
    ListNode *getIntersectionNode(ListNode *listA, ListNode *listB) {
        ListNode *headA= listA;
        ListNode *headB= listB;
        while(headA != headB)
        {
            headA= headA ? headA->next : listB;
            headB= headB ? headB->next : listA;
        }
        return headA;
    }
};