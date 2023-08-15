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
    ListNode* partition(ListNode* head, int x) {
        // Create two dummy nodes to hold the partitions
        ListNode node1(0); // For nodes with values less than x
        ListNode node2(0); // For nodes with values greater than or equal to x
        
        ListNode* p1 = &node1; // Pointer to the end of the first partition
        ListNode* p2 = &node2; // Pointer to the end of the second partition
        
        // Traverse the original linked list
        while (head) {
            if (head->val < x) {
                // Append the current node to the first partition
                p1 = p1->next = head;
            } else {
                // Append the current node to the second partition
                p2 = p2->next = head;
            }
            head = head->next;
        }
        
        // Close the second partition
        p2->next = NULL;
        
        // Combine the two partitions by connecting the end of the first partition to the start of the second partition
        p1->next = node2.next;
        
        // Return the updated linked list with the desired partition
        return node1.next;
    }
};
