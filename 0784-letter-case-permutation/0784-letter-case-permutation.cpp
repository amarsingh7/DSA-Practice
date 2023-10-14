class Solution {
public:
    
    void solve(vector<string> &ans, string &s, int index)
    {
        if(index==s.size()){
            ans.push_back(s);
            return;
        }
        if(isdigit(s[index])){
            solve(ans, s, index+1);
            return;
        }
        else{
            s[index] = toupper(s[index]);
            solve(ans, s, index+1);
            
            s[index] = tolower(s[index]);
            solve(ans, s, index+1);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        int n= s.size();
        vector<string> ans;
        
        solve(ans, s, 0);
        
        return ans;
    }
};