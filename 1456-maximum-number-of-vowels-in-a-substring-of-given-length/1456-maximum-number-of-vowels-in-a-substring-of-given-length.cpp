class Solution {
public:
    int maxVowels(string s, int k) {
        string btc= "aeiou";
        int res=0, ans=0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(btc.find(s[i]) != string::npos) 
                res++;
            if(i>=k and btc.find(s[i-k]) != string::npos)
                res--;
            ans= max(ans, res);
        }
        return ans;
        
    }
};