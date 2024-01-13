class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> mp1(26, 0), mp2(26, 0);
        
        for(auto x:s)
            mp1[x-'a']++;
        for(auto x:t)
            mp2[x-'a']++;
        int ans=0;
        for(int i=0; i<26; i++)
        {
            ans+= abs(mp2[i]-mp1[i]);
        }
        
        return ans/2;
    }
};