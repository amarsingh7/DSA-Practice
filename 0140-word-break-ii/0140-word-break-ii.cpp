class Solution {
public:
    int dp[1001];
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        int n= wordDict.size();
        
        unordered_set<string> st;
        for(auto x:wordDict)
            st.insert(x);
        string curr="";
        solve(0, s, st, curr, ans);
        return ans;
    }
    void solve(int index, string s, unordered_set<string> &st, string curr, vector<string> &ans)
    {
        if(index==s.size())
        {
            curr.pop_back();
            ans.push_back(curr);
        }    
        string str="";
        for(int i=index; i<s.size(); i++)
        {
            str.push_back(s[i]);
            if(st.count(str))
            {
                solve(i+1, s, st, curr+str+" ", ans);
            }
        }
    }
};