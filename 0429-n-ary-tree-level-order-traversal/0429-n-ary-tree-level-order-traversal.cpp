/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
            return {};
        vector<int> temp;
        vector<vector<int>> ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n= q.size();
            for(int i=0; i<n; i++)
            {
                Node* fck= q.front();
                q.pop();
                
                temp.push_back(fck->val);
            
                for(Node* child: fck->children)
                    q.push(child);
            }
            
            ans.push_back(temp);
            temp.clear();
        }
       
        return ans;
    }
    
};