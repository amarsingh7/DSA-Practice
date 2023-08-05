class Solution {
public:
    vector<string> ans;
    void backtracking(string temp, string digits, int index)
    {
        vector<string> vec= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(index==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        string s= vec[digits[index]-'0'];
        for(int i=0; i<s.size();i++)
            backtracking(temp+s[i], digits, index+1);
        
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty())
            return {};
        backtracking("", digits, 0);
        return ans;
        
    }
};