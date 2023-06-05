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
    void bkc(ListNode* head, vector<int>& vec) {
        ListNode* ans = head;
        int n = vec.size();
        int index = 0;
        while (ans && n > 0) {
            ans->val = vec[index];
            ans = ans->next;
            index++;
            n--;
        }
    }

    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* res = head;
        ListNode* temp = head;
        vector<int> v;

        while (res) {
            v.push_back(res->val);
            res = res->next;
        }

        int n = v.size();
        if(n==0)
            return temp;
        if(k==0|| k==n)
            return temp;
        if(k>n)
            k= k%n;
        rotate(v.rbegin(), v.rbegin() +k, v.rend());  // Updated line
        bkc(temp, v);
        return temp;
    }
};