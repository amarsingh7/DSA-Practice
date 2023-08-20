class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n= s.size();
        int prev=0;
        // bool dp[n];
        // memset(dp, false, sizeof(dp));
        vector<bool> dp(n, false);
        dp[0]= true;
        
        for(int i=1; i<n; i++)
        {
            if(i >=minJump)
                prev+= dp[i-minJump];
            if(i> maxJump)
                prev-= dp[i-maxJump-1];
            
            dp[i]= prev>0 and s[i]=='0';
                
        }
        return dp[n-1];
    }
};