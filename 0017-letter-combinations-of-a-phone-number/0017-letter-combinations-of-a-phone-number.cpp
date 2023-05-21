class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> vec= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.empty())
            return {};
        vector<string> ans;
        ans.push_back("");
        
        int n= digits.size();
        for(auto digit:digits)
        {
            vector<string> temp;
            for(auto x:vec[digit-'0'])
            {
                for(auto s:ans)
                temp.push_back(s+x);
            }
            ans.swap(temp);
        }
        return ans;
        
    }
};