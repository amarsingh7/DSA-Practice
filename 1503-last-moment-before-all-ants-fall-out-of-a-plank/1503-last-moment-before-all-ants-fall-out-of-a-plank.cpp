class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int ans=0;
        for(auto x:left)
            if(x>ans)
                ans=x;
        for(auto x:right)
            if(ans< n-x)
                ans= n-x;
        return ans;
    }
};