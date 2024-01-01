class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int n= 0, m= 0;
        int ans=0;
        while(n<s.size() and m<g.size())
        {
            if(s[n]>= g[m])
            {
                ans++; m++;
            }
            n++;
        }
        return ans;
    }
};