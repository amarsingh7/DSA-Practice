class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> v;
        while(n!=0)
        {
            v.push_back(n%10);
            n=n/10;
        }
        reverse(v.begin(), v.end());
        
        bool p= true;
        int ans=0;
        for(auto &it:v)
        {
            if(p)
            {
                ans+= it;
                p= false;
            }
            else
            {
                ans -= it;
                p= true;
            }
            
        }
        return ans;
        
    }
};