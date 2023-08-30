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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vec;
        
        while(head)
        {
            vec.push_back(head->val);
            head= head->next;
        }
        vector<int> ans(vec.size(), 0);
        stack<int> st;
        for(int i=0; i<vec.size(); i++)
        {
            while(!st.empty() and vec[st.top()] <vec[i])
            {
                int small= st.top();
                ans[small]= vec[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};