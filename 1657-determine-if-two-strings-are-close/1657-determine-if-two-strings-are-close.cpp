class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        vector<int> v1(26, 0), v2(26, 0);
        set<char> st1, st2;
        
        for(auto x:word1){
            v1[x-'a']++;
            st1.insert(x);
        }
            
        for(auto x:word2){
            v2[x-'a']++;
            st2.insert(x);
        }
            
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        return (v1==v2) and (st1==st2);
    }
};