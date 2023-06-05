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
    void updateListData(ListNode* head, vector<int>& vec) {
    ListNode* current = head;
    size_t index = 0;

        while (current && index < vec.size()) 
        {
            current->val = vec[index];
            current = current->next;
            index++;
        }
    }
    ListNode* sortList(ListNode* head) {
        ListNode* parody= head;
        ListNode* ans= head;
        vector<int> vec;
        while(parody)
        {
            vec.push_back(parody->val);
            parody= parody->next;
        }
        sort(vec.begin(), vec.end());
        updateListData(ans, vec);
        return ans;
    }
};