class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int cur=0;
        int n= s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
                cur++, ans= max(ans, cur);
            else if(s[i]==')')
                cur--;
        }
        return ans;
    }
};