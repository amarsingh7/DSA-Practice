class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> vec;
        ListNode* temp = head;
        
        // Store values from the linked list in the vector
        while (temp != nullptr) {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        
        // Reverse the subsequence in the vector
        reverse(vec.begin() + left - 1, vec.begin() + right); // Adjust indices
        
        // Reset temp pointer to the head of the linked list
        temp = head;
        
        int i = 0;
        
        // Update the linked list with the reversed values from the vector
        while (temp != nullptr) {
            temp->val = vec[i];
            i++;
            temp = temp->next;
        }
        
        return head; // Return the updated head of the linked list
    }
};
