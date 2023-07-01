class Solution {
public:
    int ans= INT_MAX;
    void dfs(vector<int> &cookies, vector<int> &child, int idk, int maxi)
    {
        if(idk>= cookies.size())
        {
            ans= min(ans, maxi);
            return;
        }    
        int c= cookies[idk];
        for(int i=0; i<child.size(); i++)
        {
            child[i]+= c;
            dfs(cookies, child, idk+1, max(maxi, child[i]));
            child[i]-= c;
        }
            
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dist(k, 0);
        dfs(cookies, dist, 0, 0);
        return ans;
    }
};