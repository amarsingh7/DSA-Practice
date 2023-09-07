class Solution {
public:
    int ans=0;
    
    void backtrack(vector<string> &words, vector<int>&score, vector<int> &count, vector<int>& used, int ind, int res)
    {
        for(int i=0; i<26; i++)
        {
            if(used[i]>count[i])
                return;
        }
        ans= max(ans, res);
        for(int i=ind; i<words.size(); i++)
        {
            for(auto x:words[i])
            {
                used[x-'a']++;
                res+= score[x-'a'];
            }
            backtrack(words, score, count, used, i+1, res);
            for(auto x:words[i])
            {
                used[x-'a']--;
                res-= score[x-'a'];
            }
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        vector<int> count(26, 0), used(26, 0);
        
        for(auto x:letters)
            count[x-'a']++;
        backtrack(words, score, count, used, 0, 0);
        return ans;
    }
};