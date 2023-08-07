class Solution {
public:
    bool isPalindrome(string &s)
    {
		int n = s.size();
		int i = 0, j = n - 1;
		while (i < j) {
			if (s[i++] != s[j--])
				return false;
		}
		return true;
    }
    void dfs(vector<vector<string>>& result, vector<string>& subset, string& s, int start) {
    if (start == s.size()) 
    {
        result.push_back(subset);
        return;
    }
     
    string t;
    for(int i= start; i<s.size(); i++)
    {
        t.push_back(s[i]);
        if(isPalindrome(t))
        {
            subset.push_back(t);
            dfs(result, subset, s, i+1);
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