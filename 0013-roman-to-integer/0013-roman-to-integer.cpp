class Solution {
public:
    int romanToInt(string str) {
        unordered_map<char, int> ump={
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int res=0;
        int pval=0;
        for(int i=str.length(); i>=0; i--)
        {
            int cval= ump[str[i]];
            if(cval< pval)
                res-= cval;
            else
                res+= cval;
            pval= cval;
        }
        return res;
    }
};