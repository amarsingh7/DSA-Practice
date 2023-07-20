class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> ump;
        for(auto x:s)
            
        for(char x:s)
        {
            ump[x]++;
            if(ump[x]>=2)
                return x;
        }
            
        return '.';
    }
};