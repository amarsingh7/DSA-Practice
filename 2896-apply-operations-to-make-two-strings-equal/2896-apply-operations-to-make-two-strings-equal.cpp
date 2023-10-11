class Solution {
public:
    
    int dp[501][501];
    int solve(int left, int right, vector<int> &vec, int x)
    {
        if(left>=right)
            return 0;
        if(dp[left][right] != -1)
            return dp[left][right];
        dp[left][right]= min({min(x, vec[left+1]-vec[left])+ solve(left+2, right, vec, x),
                            min(x, vec[right]-vec[left])+ solve(left+1, right-1, vec, x),
                              min(x, vec[right]-vec[right-1])+ solve(left, right-2, vec, x)});
        
        return dp[left][right];
    }
    int minOperations(string s1, string s2, int x) {
        int n= s1.size();
        int count=0;
        for(int i=0; i<n; i++)
        {
            if(s1[i] != s2[i])
                count++;
        }
        if(count%2 !=0)
            return -1;
        
        vector<int> vec;
        for(int i=0; i<s1.size(); i++)
        {
            if(s1[i] != s2[i])
                vec.push_back(i);
        }
        memset(dp, -1, sizeof(dp));
        
        return solve(0, vec.size()-1, vec, x);
        
        // return 0;
    }
};