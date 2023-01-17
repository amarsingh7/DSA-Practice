class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans=0, f=0;
        for(char c: s)
        {
            if(c=='1')
                f++;
            else if(f>0)
            {
                ++ans;
                --f;
            }
          
        }
          return ans;
    }
};