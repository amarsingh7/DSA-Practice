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
        ListNode* temp= head; 
        vector<int> ans;
        
        while(temp != NULL)
        {
            ans.push_back(temp->val);
            temp= temp->next;
                
        }
        
        int n= ans.size();
        for (int i = 0; i < ans.size(); i += k) {
            int start = i;
            int end = i + k-1;  // Calculate the end index directly
            bool check= false;
            if (end >= ans.size()) {
                check= true;
            }
            if(check)
                break;
            std::reverse(ans.begin() + start, ans.begin() + end+1);
        }
        int i=0;
        temp= head;
        while(temp)
        {
            temp->val= ans[i]  ;
            i++;
            temp= temp->next;
        }
        return head;
    }
};