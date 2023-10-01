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
        ListNode* temp = head;  // Pointer to traverse the linked list
        vector<int> ans;  // Vector to store values of the linked list nodes
        
        // Extract values from the linked list and store them in the vector
        while (temp != NULL) {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        
        int n = ans.size();  // Total number of elements in the vector
        
        // Reverse subarrays of size 'k' in the vector
        for (int i = 0; i < ans.size(); i += k) {
            int start = i;
            int end = i + k - 1;  // Calculate the end index directly
            
            bool check = false;
            if (end >= ans.size()) {
                check = true;  
                // Set check to true if the end index exceeds the vector size
            }
            
            if (check)
                break;  
            // Break the loop if the end index exceeds the vector size
            
            // Reverse the subarray in the vector
            std::reverse(ans.begin() + start, ans.begin() + end + 1);
        }
        
        int i = 0;
        temp = head;  // Reset temp to the head of the linked list
        
        // Update the linked list with reversed values from the vector
        while (temp) {
            temp->val = ans[i];
            i++;
            temp = temp->next;
        }
        
        return head;  // Return the modified head of the linked list
    }
};
