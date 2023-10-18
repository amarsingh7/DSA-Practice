class Solution {
public:
    int minimumScore(string s, string t) {
        int ss= s.size();
        int ts= t.size();
        
        int k= ts-1;
        vector<int> dp(ts, -1);
        
        for(int i=ss-1; i>=0 and k>=0; i--)
        {
            if(s[i]==t[k])
                dp[k--]= i;
        }
        
        int res= k+1;  // k-0+1
        
        // minimizing the result
            
        for(int i=0, j=0; i<ss and j<ts and res>0; i++)
        {
            if(s[i]==t[j])
            {
                // updating k each unmatched chars unmtil we found next match
                for(; k<t.size() and dp[k]<=i; ++k); 
                res= min(res, k-(++j));
            }
            
        }
        return res;
    }
};
