class Solution {
public:
    void ans(vector<string> &vec, int op, int cl, string s)
    {
        if(op==0 and cl==0)
        {
            vec.push_back(s);
            return;
        }
            
        if(op!=0)
        {
            string opf= s+'(';
            ans(vec, op-1, cl, opf);
        }
        if(op<cl)
        {
            string ops= s+')';
            ans(vec, op, cl-1, ops);
        }
    }
    vector<string> generateParenthesis(int n) {
        int op=n;
        int cl=n;
        string s= "";
        vector<string> vec;
        ans(vec, op, cl, s);
        
        return vec;
    }
};