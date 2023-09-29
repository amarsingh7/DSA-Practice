class Solution {
public:
    int minPartitions(string s) {
        int ans=0;
        int sz= s.size();
        for(int i=0; i<sz; i++)
        {
            ans= max(ans, s[i]-'0');
        }
        return ans;
    }
};