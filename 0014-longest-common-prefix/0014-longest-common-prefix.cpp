class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        if(n==1)
            return strs[0];
        string ans="";
        sort(strs.begin(), strs.end());
        
        for(int i=0; i<strs[0].size(); i++)
        {
            string x= strs[0], y= strs[n-1];
            if(x[i]==y[i])
                ans.push_back(x[i]);
            else
                break;
        }
        return ans;
    }
};