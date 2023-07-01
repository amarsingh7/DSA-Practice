class Solution {
public:
    int ans= INT_MAX;
    void dfs(vector<int> &cookies, vector<int> &child, int i, int maxi)
    {
        if(i>= cookies.size())
        {
            ans= min(ans, maxi);
            return;
        }    
        int c= cookies[i];
        for(int j=0; j<child.size(); j++)
        {
            child[j]+= c;
            dfs(cookies, child, i+1, max(maxi, child[j]));
            child[j]-= c;
        }
            
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k, 0);
        dfs(cookies, child, 0, 0);
        return ans;
    }
};