class Solution {
public:
    string orderlyQueue(string s, int k) {
        string p=s;
        sort(p.begin(), p.end());
        if(k>=2)
            return p;
        if(s.size()==1)
            return s;
        
        string ans= s;
        for(int i=0; i<s.size(); i++)
        {
            ans= min(ans, s.substr(i)+s.substr(0, i));
        }
        return ans;
    }
};