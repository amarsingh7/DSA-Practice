/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    int i=0;
    TreeNode* solve(string &temp, int index)
    {
        if(index>= temp.size())
            return NULL;
        string ans="";
        int x=0;
        int st= i;
        while(temp[i]=='-')
            i++, x++;
        if(x!=index){
            i= st; return NULL;
        }
            
        while(temp[i]!= '-' and i<temp.size()){
            ans+= temp[i]; i++;
        }
            
        int val= stoi(ans);
        
        TreeNode* res= new TreeNode(val);
        res->left= solve(temp, index+1);
        res->right= solve(temp, index+1);
        
        return res;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        
        return solve(traversal, 0);
    }
};