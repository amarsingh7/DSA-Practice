class Solution {
public:
    
    string lcs(string s, string r) {
    int m = s.size();
    int n = r.size();
    vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == r[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + s[i - 1];
            else
                dp[i][j] = (dp[i - 1][j].size() > dp[i][j - 1].size()) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    return dp[m][n];
}
    
    string shortestCommonSupersequence(string a, string b) {
        int i=0, j=0;
        string res="";
        
        for(auto c: lcs(a, b))
        {
            while(a[i] !=c)
                res+= a[i++];
            while(b[j] !=c)
                res+= b[j++];
            res+= c;
            i++; j++;
        }
        res+= a.substr(i) +b.substr(j);
        
        return res;
    }
};