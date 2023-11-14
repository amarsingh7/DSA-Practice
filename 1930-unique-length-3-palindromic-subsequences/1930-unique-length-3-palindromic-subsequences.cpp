class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n= s.size();
        
        vector<int> vec(26, 0);
        
        for(int i=0; i<n; i++)
            vec[s[i]-'a']++;
        int ans=0;
        for(int i=0; i<26; i++)
        {
            if(vec[i]<=1)
                continue;
            int first= -1, last= -1;
            for(int j=0; j<n; j++)
            {
                if((s[j]-'a')==i){
                    first= j;
                    break;
                }
            }
            for(int j=n-1; j>=0; j--)
            {
                if((s[j]-'a')==i){
                    last= j;
                    break;
                }
            }
            unordered_set<int> us;
            for(int k=first+1; k<last; k++)
                us.insert((s[k]-'a'));
            ans+= us.size();
        }
        
        
        return ans;
    }
};