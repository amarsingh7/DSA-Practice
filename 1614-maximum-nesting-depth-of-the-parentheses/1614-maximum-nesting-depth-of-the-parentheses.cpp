class Solution {
public:
    int maxDepth(string s) {
        vector<int> vc= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int ans=0;
        int cur=0;
        int n= s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
                cur++;
            ans= max(ans, cur);
            if(s[i]==')')
                cur--;
        }
        return ans;
    }
};