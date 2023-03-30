class Solution {
public:
    unordered_map<string, bool> mp;
    
    bool solve(string s1, string s2)
    {
        if(s1==s2)
            return true;
        
        string copys1= s1, copys2= s2;
        sort(copys1.begin(), copys1.end());
        sort(copys2.begin(), copys2.end());
        
        if(copys1 != copys2)
            return false;
        
        bool flag= false;
        
        string key= s1 +" "+ s2;
        
        int n= s1.length();
        if(mp.find(key) != mp.end())
            return mp[key];
        for(int i=1; i<n; i++)
        {
            if(solve(s1.substr(0, i), s2.substr(0, i)) and
              solve(s1.substr(i, n-i), s2.substr(i, n-i)))
            {
                flag= true;
                return true;
            }
            if(solve(s1.substr(0, i), s2.substr(n-i, i)) and
              solve(s1.substr(i, n-i), s2.substr(0, n-i)))
            {
                flag= true;
                return true;
            }
        }
        mp[key]= flag;
        return false;
    }
    
    bool isScramble(string s1, string s2) {
        mp.clear();
        return solve(s1, s2);
    }
};