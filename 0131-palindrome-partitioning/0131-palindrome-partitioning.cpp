class Solution {
public:
    bool isPalindrome(string &s, int start, int end)
    {
        while(start<end)
        {
            if(s[start++] !=s[end--])
                return false;
        }
        return true;
    }
    void dfs(vector<vector<string>>& result, vector<string>& subset, string& s, int start) {
    if (start >= s.size()) 
            result.push_back(subset);
        
    for(int end= start; end<s.length(); end++)
    {
        if(isPalindrome(s, start, end))
        {
            subset.push_back(s.substr(start, end-start+1));
            dfs(result, subset, s, end+1);
            subset.pop_back();
        }
    }
       
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> subset;
    
    dfs(result, subset, s, 0);
    
    return result;
}

};