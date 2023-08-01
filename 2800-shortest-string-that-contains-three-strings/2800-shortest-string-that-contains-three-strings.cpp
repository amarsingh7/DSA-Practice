class Solution {
public:
    
    string hsolve(string &x, string &y)
    {
        if(x.find(y) !=string::npos)
                return x;
        for(int i=0; i<=x.size(); i++)
        {
            if(x.substr(i, x.size())== y.substr(0, x.size() -i))
                    return x+ y.substr(x.size() -i, y.size());
           
        }
        return x+y;
    }
    void solve(string &x, string &y, string &z, vector<string> &ans)
    {
        string xy= hsolve(x, y);
        string xyz= hsolve(xy, z);
        ans.push_back(xyz);
    }
    string minimumString(string a, string b, string c) {
        vector<string> ans;
        solve(a, b, c, ans);
        solve(a, c, b, ans);
        solve(c, a, b, ans);
        solve(b, a, c, ans);
        solve(b, c, a, ans);
        solve(c, b, a, ans);

        sort(ans.begin(), ans.end(), [](string a, string b){
            if(a.length()!=b.length()) 
                return a.length()<b.length();
            return a<b;
        });
        return ans[0];
    }
};