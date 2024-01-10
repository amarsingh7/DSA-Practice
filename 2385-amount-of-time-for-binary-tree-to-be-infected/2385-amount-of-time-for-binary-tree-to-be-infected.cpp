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

int ans = 0;
int trav(TreeNode *r, int start){//return -ve => start is in the subtree of the node, 
//absolute value gives distance from farthest leaf in subtree or from start node if it's present in subtree
    if(!r) return 0;
    int x = trav(r->left,start);        
    int y = trav(r->right,start);
    
    if(r->val == start){
        ans = max(ans,max(x,y));//current node is start node, farthest leaf in subtree can be answer
        return -1;//-ve to imply distance is from start node
    }
    if(x>=0 and y>=0) return max(x,y)+1;
    //not start node, start node not in subtree, the farthest leaf in subtree might
    //contribute to the answer return that
    
    ans = max(ans,abs(x)+abs(y));
    //start in the subtree of current node, the negative one from x & y
    //is distance from start
    return min(x,y)-1;//minimum will give distance from start node
}


class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        ans = 0;
        int k = trav(root,start);
        return ans;
    }
};